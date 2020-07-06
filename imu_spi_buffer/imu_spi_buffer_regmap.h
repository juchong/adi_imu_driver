/* iSensor SPI Buffer registers */
/* https://github.com/ajn96/iSensor-SPI-Buffer */

#define		REG_ISENSOR_PAGE_ID		            0xFD00
#define		REG_ISENSOR_BUF_CONFIG		        0xFD02
#define		REG_ISENSOR_BUF_LEN		            0xFD04
#define		REG_ISENSOR_BUF_MAX_CNT		        0xFD06
#define		REG_ISENSOR_DIO_INPUT_CONFIG		0xFD08
#define		REG_ISENSOR_DIO_OUTPUT_CONFIG		0xFD0A
#define		REG_ISENSOR_WATERMARK_INT_CONFIG	0xFD0C
#define		REG_ISENSOR_ERROR_INT_CONFIG		0xFD0E
#define		REG_ISENSOR_IMU_SPI_CONFIG		    0xFD10
#define		REG_ISENSOR_USER_SPI_CONFIG		    0xFD12
#define		REG_ISENSOR_USB_CONFIG		        0xFD14
#define		REG_ISENSOR_USER_COMMAND		    0xFD16
#define		REG_ISENSOR_USER_SCR_0		        0xFD18
#define		REG_ISENSOR_USER_SCR_1		        0xFD1A
#define		REG_ISENSOR_USER_SCR_2		        0xFD1C
#define		REG_ISENSOR_USER_SCR_3		        0xFD1E
#define		REG_ISENSOR_USER_SCR_4		        0xFD20
#define		REG_ISENSOR_USER_SCR_5		        0xFD22
#define		REG_ISENSOR_USER_SCR_6		        0xFD24
#define		REG_ISENSOR_USER_SCR_7		        0xFD26
#define		REG_ISENSOR_FW_REV		            0xFD28
#define		REG_ISENSOR_ENDURANCE		        0xFD2A
#define		REG_ISENSOR_STATUS		            0xFD40
#define		REG_ISENSOR_BUF_CNT		            0xFD42
#define		REG_ISENSOR_FAULT_CODE		        0xFD44
#define		REG_ISENSOR_UTC_TIMESTAMP_LWR		0xFD46
#define		REG_ISENSOR_UTC_TIMESTAMP_UPR		0xFD48
#define		REG_ISENSOR_TIMESTAMP_LWR		    0xFD4A
#define		REG_ISENSOR_TIMESTAMP_UPR		    0xFD4C
#define		REG_ISENSOR_FW_DAY_MONTH		    0xFD70
#define		REG_ISENSOR_FW_YEAR		            0xFD72
#define		REG_ISENSOR_DEV_SN_0		        0xFD74
#define		REG_ISENSOR_DEV_SN_1		        0xFD76
#define		REG_ISENSOR_DEV_SN_2		        0xFD78
#define		REG_ISENSOR_DEV_SN_3		        0xFD7A
#define		REG_ISENSOR_DEV_SN_4		        0xFD7C
#define		REG_ISENSOR_DEV_SN_5		        0xFD7E
#define		REG_ISENSOR_BUF_WRITE_0		        0xFE10
#define		REG_ISENSOR_BUF_WRITE_1		        0xFE12
#define		REG_ISENSOR_BUF_WRITE_2		        0xFE14
#define		REG_ISENSOR_BUF_WRITE_3		        0xFE16
#define		REG_ISENSOR_BUF_WRITE_4		        0xFE18
#define		REG_ISENSOR_BUF_WRITE_5		        0xFE1A
#define		REG_ISENSOR_BUF_WRITE_6		        0xFE1C
#define		REG_ISENSOR_BUF_WRITE_7		        0xFE1E
#define		REG_ISENSOR_BUF_WRITE_8		        0xFE20
#define		REG_ISENSOR_BUF_WRITE_9		        0xFE22
#define		REG_ISENSOR_BUF_WRITE_10		    0xFE24
#define		REG_ISENSOR_BUF_WRITE_11		    0xFE26
#define		REG_ISENSOR_BUF_WRITE_12		    0xFE28
#define		REG_ISENSOR_BUF_WRITE_13		    0xFE2A
#define		REG_ISENSOR_BUF_WRITE_14		    0xFE2C
#define		REG_ISENSOR_BUF_WRITE_15		    0xFE2E
#define		REG_ISENSOR_BUF_WRITE_16		    0xFE30
#define		REG_ISENSOR_BUF_WRITE_17		    0xFE32
#define		REG_ISENSOR_BUF_WRITE_18		    0xFE34
#define		REG_ISENSOR_BUF_WRITE_19		    0xFE36
#define		REG_ISENSOR_BUF_WRITE_20		    0xFE38
#define		REG_ISENSOR_BUF_WRITE_21		    0xFE3A
#define		REG_ISENSOR_BUF_WRITE_22		    0xFE3C
#define		REG_ISENSOR_BUF_WRITE_23		    0xFE3E
#define		REG_ISENSOR_BUF_WRITE_24		    0xFE40
#define		REG_ISENSOR_BUF_WRITE_25		    0xFE42
#define		REG_ISENSOR_BUF_WRITE_26		    0xFE44
#define		REG_ISENSOR_BUF_WRITE_27		    0xFE46
#define		REG_ISENSOR_BUF_WRITE_28		    0xFE48
#define		REG_ISENSOR_BUF_WRITE_29		    0xFE4A
#define		REG_ISENSOR_BUF_WRITE_30		    0xFE4C
#define		REG_ISENSOR_BUF_WRITE_31		    0xFE4E
#define		REG_ISENSOR_FLASH_SIG_DRV		    0xFE7C
#define		REG_ISENSOR_FLASH_SIG		        0xFE7E
#define		REG_ISENSOR_STATUS_1		        0xFF02
#define		REG_ISENSOR_BUF_CNT_1		        0xFF04
#define		REG_ISENSOR_BUF_RETRIEVE		    0xFF06
#define		REG_ISENSOR_BUF_TIMESTAMP_LWR		0xFF08
#define		REG_ISENSOR_BUF_TIMESTAMP_UPR		0xFF0A
#define		REG_ISENSOR_BUF_DELTA_TIME		    0xFF0C
#define		REG_ISENSOR_BUF_SIG		            0xFF0E
#define		REG_ISENSOR_BUF_DATA_0		        0xFF10
#define		REG_ISENSOR_BUF_DATA_1		        0xFF12
#define		REG_ISENSOR_BUF_DATA_2		        0xFF14
#define		REG_ISENSOR_BUF_DATA_3		        0xFF16
#define		REG_ISENSOR_BUF_DATA_4		        0xFF18
#define		REG_ISENSOR_BUF_DATA_5		        0xFF1A
#define		REG_ISENSOR_BUF_DATA_6		        0xFF1C
#define		REG_ISENSOR_BUF_DATA_7		        0xFF1E
#define		REG_ISENSOR_BUF_DATA_8		        0xFF20
#define		REG_ISENSOR_BUF_DATA_9		        0xFF22
#define		REG_ISENSOR_BUF_DATA_10		        0xFF24
#define		REG_ISENSOR_BUF_DATA_11		        0xFF26
#define		REG_ISENSOR_BUF_DATA_12		        0xFF28
#define		REG_ISENSOR_BUF_DATA_13		        0xFF2A
#define		REG_ISENSOR_BUF_DATA_14		        0xFF2C
#define		REG_ISENSOR_BUF_DATA_15		        0xFF2E
#define		REG_ISENSOR_BUF_DATA_16		        0xFF30
#define		REG_ISENSOR_BUF_DATA_17		        0xFF32
#define		REG_ISENSOR_BUF_DATA_18		        0xFF34
#define		REG_ISENSOR_BUF_DATA_19		        0xFF36
#define		REG_ISENSOR_BUF_DATA_20		        0xFF38
#define		REG_ISENSOR_BUF_DATA_21		        0xFF3A
#define		REG_ISENSOR_BUF_DATA_22		        0xFF3C
#define		REG_ISENSOR_BUF_DATA_23		        0xFF3E
#define		REG_ISENSOR_BUF_DATA_24		        0xFF40
#define		REG_ISENSOR_BUF_DATA_25		        0xFF42
#define		REG_ISENSOR_BUF_DATA_26		        0xFF44
#define		REG_ISENSOR_BUF_DATA_27		        0xFF46
#define		REG_ISENSOR_BUF_DATA_28		        0xFF48
#define		REG_ISENSOR_BUF_DATA_29		        0xFF4A
#define		REG_ISENSOR_BUF_DATA_30		        0xFF4C
#define		REG_ISENSOR_BUF_DATA_31		        0xFF4E

/* REG_ISENSOR_FW_* */
#define     IMU_BUF_FIRM_REV_UPPER(val)     ( ((val) >> 8 ) & 0xFF )
#define     IMU_BUF_FIRM_REV_LOWER(val)     ( (val) & 0xFF )
#define     IMU_BUF_FIRM_DAY(val)               ( ((val) >> 8 ) & 0xFF )
#define     IMU_BUF_FIRM_MONTH(val)             ( (val) & 0xFF )

/* REG_ISENSOR_BUF_CONFIG */
#define     BITP_ISENSOR_BUF_CFG_OVERFLOW           (0)
#define     BITP_ISENSOR_BUF_CFG_SPIWORDSIZE        (8)
#define     BITM_ISENSOR_BUF_CFG_OVERFLOW           (0x1)
#define     BITM_ISENSOR_BUF_CFG_SPIWORDSIZE        ((0xFF) << BITP_ISENSOR_BUF_CFG_SPIWORDSIZE)

/* REG_ISENSOR_DIO_INPUT_CONFIG */
#define     BITP_ISENSOR_DIO_IN_CFG_DR_SEL          (0)
#define     BITP_ISENSOR_DIO_IN_CFG_DR_POL          (4)
#define     BITP_ISENSOR_DIO_IN_CFG_PPS_SEL         (8)
#define     BITP_ISENSOR_DIO_IN_CFG_PPS_POL         (12)
#define     BITM_ISENSOR_DIO_IN_CFG_DR_SEL          (0xF)
#define     BITM_ISENSOR_DIO_IN_CFG_DR_POL          ((0x1) << BITP_ISENSOR_DIO_IN_CFG_DR_POL)
#define     BITM_ISENSOR_DIO_IN_CFG_PPS_SEL         ((0xF) << BITP_ISENSOR_DIO_IN_CFG_PPS_SEL)
#define     BITM_ISENSOR_DIO_IN_CFG_PPS_POL         ((0x1) << BITP_ISENSOR_DIO_IN_CFG_PPS_POL)

/* REG_ISENSOR_DIO_OUTPUT_CONFIG */
#define     BITP_ISENSOR_DIO_OUT_CFG_PIN_PASS       (0)
#define     BITP_ISENSOR_DIO_OUT_CFG_WTRMRK         (4)
#define     BITP_ISENSOR_DIO_OUT_CFG_OVRFLW         (8)
#define     BITP_ISENSOR_DIO_OUT_CFG_ERROR          (12)
#define     BITM_ISENSOR_DIO_OUT_CFG_PIN_PASS       (0xF)
#define     BITM_ISENSOR_DIO_OUT_CFG_WTRMRK         ((0xF) << BITP_ISENSOR_DIO_OUT_CFG_WTRMRK)
#define     BITM_ISENSOR_DIO_OUT_CFG_OVRFLW         ((0xF) << BITP_ISENSOR_DIO_OUT_CFG_OVRFLW)
#define     BITM_ISENSOR_DIO_OUT_CFG_ERROR          ((0xF) << BITP_ISENSOR_DIO_OUT_CFG_ERROR)

/* REG_ISENSOR_STATUS */
#define     BITP_ISENSOR_STATUS_BUF_WTRMRK          (0)
#define     BITP_ISENSOR_STATUS_BUF_FULL            (1)
#define     BITP_ISENSOR_STATUS_SPI_ERROR           (2)
#define     BITP_ISENSOR_STATUS_SPI_OVRFLW          (3)
#define     BITP_ISENSOR_STATUS_OVERRUN             (4)
#define     BITP_ISENSOR_STATUS_DMA_ERROR           (5)
#define     BITP_ISENSOR_STATUS_PPS_UNLOCK          (6)
#define     BITP_ISENSOR_STATUS_FLASH_ERROR         (12)
#define     BITP_ISENSOR_STATUS_FLASH_UPD_ERROR     (13)
#define     BITP_ISENSOR_STATUS_FAULT               (14)
#define     BITP_ISENSOR_STATUS_WATCHDOG            (15)
#define     BITM_ISENSOR_STATUS_BUF_WTRMRK          (1)
#define     BITM_ISENSOR_STATUS_BUF_FULL            ((1) << BITP_ISENSOR_STATUS_BUF_FULL)
#define     BITM_ISENSOR_STATUS_SPI_ERROR           ((1) << BITP_ISENSOR_STATUS_SPI_ERROR)
#define     BITM_ISENSOR_STATUS_SPI_OVRFLW          ((1) << BITP_ISENSOR_STATUS_SPI_OVRFLW)
#define     BITM_ISENSOR_STATUS_OVERRUN             ((1) << BITP_ISENSOR_STATUS_OVERRUN)
#define     BITM_ISENSOR_STATUS_DMA_ERROR           ((1) << BITP_ISENSOR_STATUS_DMA_ERROR)
#define     BITM_ISENSOR_STATUS_PPS_UNLOCK          ((1) << BITP_ISENSOR_STATUS_PPS_UNLOCK)
#define     BITM_ISENSOR_STATUS_FLASH_ERROR         ((1) << BITP_ISENSOR_STATUS_FLASH_ERROR)
#define     BITM_ISENSOR_STATUS_FLASH_UPD_ERROR     ((1) << BITP_ISENSOR_STATUS_FLASH_UPD_ERROR)
#define     BITM_ISENSOR_STATUS_FAULT               ((1) << BITP_ISENSOR_STATUS_FAULT)
#define     BITM_ISENSOR_STATUS_WATCHDOG            ((1) << BITP_ISENSOR_STATUS_WATCHDOG)