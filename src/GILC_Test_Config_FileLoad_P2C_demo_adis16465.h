#pragma once
#include "GILC_IMU_Dev.h"
#include "GILC_Vehicle_lib.h"

/*-------------------------------IMU TYPE-----------------------------*/
#define IMU_DEV_TYPE               IMU_DEV_ADIS16465
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
#define CFG_ARM_ANT_X    0
#define CFG_ARM_ANT_Y    0
#define CFG_ARM_ANT_Z    0

/*----------------------------TEST RAW FILE-------------------------*/
#ifdef WIN32
#define WORK_PATH  "E:/���Ե���/���ݴ���/"
#else
#define WORK_PATH  "/mnt/gilc-data/"
#endif

//#define TEST_RAW_FILE_PATH	 WORK_PATH"20180830_P2_ADIS16465/"
//#define TEST_RAW_FILE_NAME	   "070320_raw.txt"/*�����궨����*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/adis16465/20180925/"
//#define TEST_RAW_FILE_NAME	   "010912_raw.txt"/*ӭ����·���ڻ��߼�*/
//#define TEST_RAW_FILE_NAME	   "073614_raw.txt"/*ӭ����·������-���裬����Ӧ����ҵ������*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/adis16465/20180927/"
//#define TEST_RAW_FILE_NAME	   "022808_raw.txt"/*ӭ����·������-���裬����Ӧ����ҵ������*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/adis16465/20180928/"
//#define TEST_RAW_FILE_NAME	   "035153_raw.txt"/*ӭ����·������-���裬����Ӧ����ҵ������*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/adis16465/20180929/"
//#define TEST_RAW_FILE_NAME	   "p2_raw.txt"/*ӭ����·������-���裬����Ӧ����ҵ������*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/adis16465/20180930/"
//#define TEST_RAW_FILE_NAME	   "044423_raw.txt"/*ӭ����·������-���裬����Ӧ����ҵ������*/
//#define TEST_RAW_FILE_NAME	   "050133_raw.txt"/*ӭ����·������-���裬����Ӧ����ҵ������*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/adis16465/20181008/"
//#define TEST_RAW_FILE_NAME	   "082425_raw.txt"/*ӭ����·������-���裬����Ӧ����ҵ������*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/adis16465/20181022/"
//#define TEST_RAW_FILE_NAME	   "071430_raw.txt"/*ӭ����·������-���裬����Ӧ����ҵ������*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/adis16465/20181023/"
//#define TEST_RAW_FILE_NAME	   "032329_raw.txt"/*ӭ����·���ڻ��߼�*/

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/adis16465_1234567/20181121/"   /*����������ʦ����̼Ʋ���*/
//#define TEST_RAW_FILE_NAME	   "085351_raw.txt"
//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/adis16465_1234567/20181122/"
//#define TEST_RAW_FILE_NAME	   "053802_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2C/adis16465_3181207/20181228/"   
//#define TEST_RAW_FILE_NAME	   "091135_raw.txt"            

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2DF/adis16465_3666668/20190219/"
//#define TEST_RAW_FILE_NAME	   "051711_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2DF/adis16465_3666670/20190222/"
//#define TEST_RAW_FILE_NAME	   "072737_raw.txt"
//#define TEST_RAW_FILE_NAME	   "084313_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2DF/20190222cgi-h����/71/"
//#define TEST_RAW_FILE_NAME	   "070413_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2DF/adis16465_3666670/20190223/"
//#define TEST_RAW_FILE_NAME	   "020843_raw.txt"
//#define TEST_RAW_FILE_NAME	   "060932_raw.txt"
//#define TEST_RAW_FILE_NAME	   "073643_raw.txt"
//#define TEST_RAW_FILE_NAME	   "081502_raw_Bw20Hz.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2DF/adis16465_3666670/20190223/����/"
//#define TEST_RAW_FILE_NAME	   "062828_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2DF/adis16465_3666669/20190308/"
//#define TEST_RAW_FILE_NAME	   "011031_raw.txt"
//#define TEST_RAW_FILE_NAME	   "053357_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2DF/adis16465_3666669/20190311/"
//#define TEST_RAW_FILE_NAME	   "064256_raw.txt"
//#define TEST_RAW_FILE_NAME	   "072718_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2DF/baidu_20190311/"
//#define TEST_RAW_FILE_NAME	   "035329_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2DF/adis16465_3666670/20190318/"
//#define TEST_RAW_FILE_NAME	   "015827_raw.txt"
//#define TEST_RAW_FILE_NAME	   "025256_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2DF/adis16465_3666667/20190318/"
//#define TEST_RAW_FILE_NAME	   "021320_raw.txt"
//#define TEST_RAW_FILE_NAME	   "025257_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"P2DF/ǧѰ_20190322/20190322/"
//#define TEST_RAW_FILE_NAME	   "031544_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"CGI-610/4.15ͬ�ô�ѧ-��ɨ��/3666672/����̼�/"
//#define TEST_RAW_FILE_NAME	   "042907_raw - 2.txt"
//#define TEST_RAW_FILE_NAME	   "042907_raw - 1.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"CGI-610/4.15ͬ�ô�ѧ-��ɨ��/3666672/��̼�/"
//#define TEST_RAW_FILE_NAME	   "055605_raw.txt"
//#define TEST_RAW_FILE_NAME	   "064616_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"CGI-610/4.26/74_odo/"
//#define TEST_RAW_FILE_NAME	   "114904_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"CGI-610/CGI-610ǧѰ����/3666675/"  /*IMU �쳣*/
//#define TEST_RAW_FILE_NAME	   "022636_raw_short.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"CGI-610/��̼Ʋ���/20190512_ODO/"
//#define TEST_RAW_FILE_NAME	   "020336_raw.txt"

//#define TEST_RAW_FILE_PATH	 WORK_PATH"CGI-610/��̼Ʋ���/20190508/SN74_ODO/"
//#define TEST_RAW_FILE_NAME	   "035940_raw.txt"

//#define WORK_PATH  "D:/���ݴ���/"
//#define TEST_RAW_FILE_PATH	 WORK_PATH"��ͨ�ͳ�-����/3666692/20190513/"
//#define TEST_RAW_FILE_NAME	   "030254_raw.txt"
//#define TEST_RAW_FILE_NAME	   "071024_raw.txt"                        /*��̼ƣ�δ�ɼ�����Ч��λ��Ϣ*/
//#define TEST_RAW_FILE_NAME	   "122115_raw.txt"                        /*��̼ƣ�δ�ɼ�����Ч��λ��Ϣ*/

//#define WORK_PATH  "C:/Users/huace/Desktop/NX200-gilc/"
//#define TEST_RAW_FILE_PATH	 WORK_PATH"5.25/610/"
//#define TEST_RAW_FILE_NAME	   "075429_raw.txt"/*�������ȼ�����Ż�+ʵʱ�ں�+�ر�wifi ����*/

#define WORK_PATH  "C:/Users/huace/Desktop/NX200-gilc/"
#define TEST_RAW_FILE_PATH	 WORK_PATH"���˴�/"
#define TEST_RAW_FILE_NAME	   "ship.txt"/*�������ȼ�����Ż�+ʵʱ�ں�+�ر�wifi ����*/


//#define TEST_RAW_FILE_PATH	 WORK_PATH"5-15/91�궨��/"     /*�쳣���ݱ궨����*/
//#define TEST_RAW_FILE_NAME	 "095755_raw.txt"

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

#define GILC_NMEA_OUT_PERIOD_MS    100     /*dsf90: ���10Hz*/
