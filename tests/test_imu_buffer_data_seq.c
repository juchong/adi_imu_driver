#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "adi_imu_driver.h"
#include "spi_driver.h"
#include "imu_spi_buffer.h"

void printbuf(const char* header, uint16_t* buf, int buflen)
{
    printf("%s", header);
    for (int i=0; i<buflen; i++)
        printf("0x%04X ", buf[i]);
    printf("\n");
}

void cleanup(adi_imu_Device_t *imu)
{
    uint16_t curBufCnt = 0;
    int ret = 0;
    imubuf_StopCapture(imu, &curBufCnt);

    // read any error flags
    imubuf_DevInfo_t imuBufInfo;
    imubuf_GetInfo(imu, &imuBufInfo);
    imubuf_PrintInfo(imu, &imuBufInfo);
    exit(0);
}

int main()
{
    /* Exit if buffer board support was not compiled */
    if (!BUFF_EN) {
        return adi_imu_UnsupportedHardware_e;
    }
    
    adi_imu_Device_t imu;
    imu.prodId = 16545;
    imu.g = 1.0;
    imu.spiDev = "/dev/spidev0.1";
    imu.spiSpeed = 12000000;
    imu.spiMode = 3;
    imu.spiBitsPerWord = 8;
    imu.spiDelay = 0; 

    /* initialize spi device */
    int ret = spi_Init(&imu);
    if (ret < 0) return ret;

    /* Initialize IMU BUF first to stop any activity*/
    ret = imubuf_init(&imu);
    if (ret != adi_imu_Success_e) return ret;

    /* Read and print iSensor SPI Buffer info and config*/
    imubuf_DevInfo_t imuBufInfo;
    if ((ret = imubuf_GetInfo(&imu, &imuBufInfo)) < 0) return ret;
    if ((ret = imubuf_PrintInfo(&imu, &imuBufInfo)) < 0) return ret;

    /* software reset */
    // if ((ret = imubuf_SoftwareReset(&imu)) < 0) return ret;
    
    /* Initialize IMU */
    ret = adi_imu_Init(&imu);
    if (ret != adi_imu_Success_e) return ret;

    /* Set DATA ready pin */
    if ((ret = adi_imu_ConfigDataReady(&imu, DIO1, POSITIVE)) < 0) return ret;
    if ((ret = adi_imu_SetDataReady(&imu, ENABLE)) < 0) return ret;

    /* Set output data rate */
    if ((ret = adi_imu_SetOutputDataRate(&imu, 2000)) < 0) return ret;
    
    /* Read and print IMU device info and config */
    adi_imu_DevInfo_t imuInfo;
    if ((ret = adi_imu_GetDevInfo(&imu, &imuInfo)) < 0) return ret;
    if ((ret = adi_imu_PrintDevInfo(&imu, &imuInfo)) < 0) return ret;

    /* set DIO pin config (both input and output) for iSensor SPI buffer */
    imubuf_ImuDioConfig_t dioConfig;
    dioConfig.dataReadyPin = IMUBUF_DIO1;
    dioConfig.dataReadyPolarity = RISING_EDGE;
    dioConfig.ppsPin = 0x00;
    dioConfig.ppsPolarity = 0x0;
    dioConfig.passThruPin = 0x00;
    dioConfig.watermarkIrqPin = IMUBUF_DIO2;
    dioConfig.overflowIrqPin = 0x00;
    dioConfig.errorIrqPin = 0x00;
    if ((ret = imubuf_ConfigDio(&imu, dioConfig)) < 0) return ret;

    #define MAX_BUF_LENGTH 1000 // should greater than (imu_output_rate / fetch_rate). Ex: (4000Hz / 200Hz) = 20
    typedef struct {
        int16_t dummy1; // dummy response from previous last transaction
        int16_t dummy2; // dummy response for buf_retrieve command
        uint16_t sysEFlag;
        int16_t tempOut;
        int32_t gyroX;
        int32_t gyroY;
        int32_t gyroZ;
        int32_t acclX;
        int32_t acclY;
        int32_t acclZ;
        uint16_t dataCntOrTimeStamp;
        uint32_t crc;
        // uint32_t ts;
    } __attribute__ ((packed)) BufOutputRaw_t;

    BufOutputRaw_t bufRawOut[MAX_BUF_LENGTH] = {0};
    adi_imu_BurstOutput_t burstOut = {0};

    /* set register pattern to read/write IMU registers after every data ready interrupt */
     uint16_t bufPattern[] = {REG_SYS_E_FLAG, REG_TEMP_OUT,\
                            REG_X_GYRO_LOW, REG_X_GYRO_OUT, REG_Y_GYRO_LOW, REG_Y_GYRO_OUT, REG_Z_GYRO_LOW, REG_Z_GYRO_OUT,\
                            REG_X_ACCL_LOW, REG_X_ACCL_OUT, REG_Y_ACCL_LOW, REG_Y_ACCL_OUT, REG_Z_ACCL_LOW, REG_Z_ACCL_OUT, \
                            REG_DATA_CNT, REG_CRC_LWR, REG_CRC_UPR}; //, REG_ISENSOR_BUF_TIMESTAMP_LWR, REG_ISENSOR_BUF_TIMESTAMP_UPR};
    // uint16_t bufPattern[] = {REG_SYS_E_FLAG, REG_DATA_CNT, REG_TEMP_OUT };
    uint16_t bufPatternLen = (uint16_t) (sizeof(bufPattern)/sizeof(uint16_t));
    if ((ret = imubuf_SetPatternAuto(&imu, bufPatternLen, bufPattern)) < 0) return ret;

    if ((ret = imubuf_GetInfo(&imu, &imuBufInfo)) < 0) return ret;
    if ((ret = imubuf_PrintInfo(&imu, &imuBufInfo)) < 0) return ret;

    /* start capture */
    uint16_t curBufCnt = 0;
    if ((ret = imubuf_StartCapture(&imu, IMUBUF_TRUE, &curBufCnt)) < 0) return ret;
    imu.spiDelay = 0;  // kernel latency is large enough for stall time

    uint16_t buf_len = 0;
    int32_t readBufCnt = 0;
    uint16_t curDataCnt = 0;
    for(int j=0; j<10000; j++){
        if ((ret = imubuf_ReadBufferAutoMax(&imu, 10, &readBufCnt, (uint16_t *)bufRawOut, &buf_len)) < 0) return ret;
        for (int n=0; n<readBufCnt; n++) {
            uint8_t* buf = (uint8_t*)(bufRawOut + n) + 4;
			adi_imu_ScaleBurstOut_1(&imu, buf, FALSE, &burstOut);
            uint16_t dc = burstOut.dataCntOrTimeStamp;
            // if (j == 24444 && n == 0) dc = 0x9; // insert fail condition
            if (dc != 0 && dc != curDataCnt) {
                if (dc % 1000 == 0) printf("%d\n", dc);
                if (curDataCnt != 0 && dc != (curDataCnt+1)){
                    printf("%d\n%d ##", curDataCnt, dc);
                    printf("\nTEST FAILED\n");
                    cleanup(&imu);
                }
                curDataCnt = dc;
            }
        }
    }
    /* stop capture */
    if (( ret = imubuf_StopCapture(&imu, &curBufCnt)) < 0) return ret;
    printf("\n\nTEST PASSED\n");

    return 0;
}