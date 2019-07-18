#pragma once
#include "GILC_IMU_Dev.h"
#include "GILC_Vehicle_lib.h"

/*-------------------------------IMU TYPE-----------------------------*/
#define IMU_DEV_TYPE               IMU_DEV_IMU381
#if (IMU_DEV_TYPE == IMU_DEV_ADIS16445)
#include "GILC_IMU_Config_adis16445.h"
#elif (IMU_DEV_TYPE == IMU_DEV_ADIS16465)
#include "GILC_IMU_Config_adis16465.h"
#elif (IMU_DEV_TYPE == IMU_DEV_IMU380)
#include "GILC_IMU_Config_imu380.h"
#elif (IMU_DEV_TYPE == IMU_DEV_IMU381)
#include "GILC_IMU_Config_imu381.h"
#endif

/*--------------------------------LEVER(m)-----------------------------*/
#define CFG_ARM_ANT_X    0.0
#define CFG_ARM_ANT_Y    0.0
#define CFG_ARM_ANT_Z    0.0

/*----------------------------TEST RAW FILE-------------------------*/
#ifdef WIN32
//#define WORK_PATH  "E:/���Ե���/���ݴ���/"
#define WORK_PATH  "D:/YM-data/�ļ�/P2��Ŀ/CGI-410�ܳ�����/"
#else
#define WORK_PATH  "/mnt/gilc-data/"
#endif

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181017/"
//#define TEST_RAW_FILE_NAME	   "011610_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181019/"
//#define TEST_RAW_FILE_NAME	   "060137_raw.txt"/*԰������*/
//#define TEST_RAW_FILE_NAME	   "063038_raw.txt"/*ӭ����·-����-����-԰������*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181020/"
//#define TEST_RAW_FILE_NAME	   "004012_raw.txt"/*����-����-�ζ�������*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181022/"
//#define TEST_RAW_FILE_NAME	   "115236_raw.txt"/*԰������*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181023/"
//#define TEST_RAW_FILE_NAME	   "033824_raw.txt"/*ӭ����·���ڻ��߼�*/
//#define TEST_RAW_FILE_NAME	   "060110_raw.txt"/*ӭ����·���ڻ��߼�*/
//#define TEST_RAW_FILE_NAME	   "231617_raw.txt"/*ӭ����·���ڻ��߼�------------����*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181024/"
//#define TEST_RAW_FILE_NAME	   "004900_raw.txt"/*ӭ����·���ڻ��߼�*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181029/"
//#define TEST_RAW_FILE_NAME	   "232459_raw.txt"/*ӭ����·���ڻ��߼�*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181030/"
//#define TEST_RAW_FILE_NAME	   "113637_raw.txt"/*��Ԣ����԰�����궨*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181031/"
//#define TEST_RAW_FILE_NAME	   "101805_raw.txt"/*԰���������ָ����궨*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181102/"
//#define TEST_RAW_FILE_NAME	   "005109_raw.txt"/*OBD����*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181106/"
//#define TEST_RAW_FILE_NAME	   "130643_raw.txt"/*�������ȼ�����Ż�����*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/imu381/20181107/"
//#define TEST_RAW_FILE_NAME	   "122144_raw.txt"/*�������ȼ�����Ż�+ʵʱ�ں� ����*/


//#define TEST_RAW_FILE_NAME	   "075533_nodelay_raw.txt"/*gnssʱ���ӳٲ���*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"6.3/410/"
//#define TEST_RAW_FILE_NAME	   "140004_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"20190318/"
//#define TEST_RAW_FILE_NAME	   "025311_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"5.30����/CGI410-89/"
//#define TEST_RAW_FILE_NAME	   "052950_raw.txt"


//#define TEST_RAW_FILE_PATH	 WORK_PATH"6.5/�ڶ���/UB482+IMU381-200/"
//#define TEST_RAW_FILE_NAME	   "055920_raw.txt"


#define TEST_RAW_FILE_PATH	 WORK_PATH
#define TEST_RAW_FILE_NAME	   "062024_raw.txt"


//#define TEST_RAW_FILE_PATH	 WORK_PATH"6.5/�ڶ���/OEM718D+IMU381-400/"
//#define TEST_RAW_FILE_NAME	   "test_data.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"6.5/��һ��/OEM718D+IMU381-200/"
//#define TEST_RAW_FILE_NAME	   "033455_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"6.5/��һ��/UB482+IMU381-400/"
//#define TEST_RAW_FILE_NAME	   "033551_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"5.30����/CGI410-02/"
//#define TEST_RAW_FILE_NAME	   "051711_raw.txt"


//#define TEST_RAW_FILE_PATH	 WORK_PATH"5.25/410/"
//#define TEST_RAW_FILE_NAME	   "075533_raw.txt"

/*--------------------------------TEST_OUT/TMP_FILE_PATH-----------------------------*/
#define TEST_OUT_FILE_PATH    TEST_RAW_FILE_PATH"OUT/"
#define TEST_TMP_FILE_PATH    "D:/TMP/"

/*--------------------------------TEST_RST_FILE_NAME----------------------------*/
#define TEST_RST_FILE_NAME     "gilc_vehicle_rst.nmea"

/*--------------------------------RAW CFG-----------------------------*/
#define CFG_POS_STD_USE 1
#define CFG_VEL_STD_USE 1
#define CFG_GNSSPOS_MODE GILC_GNSSPOS_MODE__LLA_DEG
#define CFG_GNSSVEL_MODE GILC_GNSSVEL_MODE__ECEF

#define GILC_NMEA_OUT_PERIOD_MS    100    /*dsf90: ���50Hz*/
