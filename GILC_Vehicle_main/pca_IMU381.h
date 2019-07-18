#pragma once
#pragma once
/*
* TestFileConfig.h
*
*  Created on: May 15, 2018
*      Author: dsf
*/

#ifndef _GILC_IMU_CONFIG_H_
#define _GILC_IMU_CONFIG_H_
#define IMU_T  0.01
#include <math.h>

/*-------------------------------IMU BW(Hz)-----------------------------*/
#define IMU_BW_HZ                 5
#define IMU_381_200				0 
#define IMU_381_400				0 
/*--------------------------------IMU WALK-----------------------------*/
/*TUpdate(,1)*/
/******随机游走******/
#define GYRO_WALK (0.3*0.05)			 //0.015deg/s/sqrt(hr)     2019-6-10
#define VEL_WALK (5000)						 //deg/sqrt(hr) bias instability  6 deg/hr
/*--------------------------------IMU STD-----------------------------*/
#define GYRO_STD_X 0.011*sqrt(IMU_BW_HZ)   //deg/s    0.06975deg/s
#define ACC_STD_X 0.00015*sqrt(IMU_BW_HZ) //g   0.001581g


//#define GYRO_WALK (0.3*0.05)			 //0.015deg/s/sqrt(hr)
//#define VEL_WALK (5000)						 //deg/sqrt(hr) bias instability  6 deg/hr
///*--------------------------------IMU STD-----------------------------*/
//#define GYRO_STD_X 0.06975*0.5   //deg/s    0.035deg/s
//#define GYRO_STD_Y 0.06975*0.5   //deg/s    0.035deg/s
//#define GYRO_STD_Z 0.06975*2   //deg/s    0.139deg/s
//#define ACC_STD_X 0.001581*1.5 //g   0.001581g
//#define ACC_STD_Y 0.001581*1.5 //g   0.001581g
//#define ACC_STD_Z 0.001581 //g   0.001581g

//#define GYRO_STD_X (0.03*sqrt(IMU_BW_HZ))   //deg/s    0.1897deg/s
//#define ACC_STD_X (0.0005*sqrt(IMU_BW_HZ))  //g   0.0032g
//#define GYRO_STD_X (0.031*sqrt(IMU_BW_HZ))   //deg/s
//#define ACC_STD_X (0.000035*sqrt(IMU_BW_HZ))  //g
#if IMU_381_200 
/*****************************IMU381-200************************/
/******零偏不稳定性******/
#define GYRO_WALK (6/sqrt(3600))           //0.1deg/s/sqrt(hr) bias instability  6 deg/hr
#define VEL_WALK (20)	
/********************随机游走计算噪声std************************/
#define GYRO_STD_X (0.3/sqrt(3600))/sqrt(IMU_T)   //0.3deg/sqrt(hr)  0.05deg/s
#define ACC_STD_X (0.005*2/sqrt(3600))/sqrt(IMU_T)  //0.005g/sqrt(hr) 0.00083g
#endif

#if IMU_381_400
/*****************************IMU381-400************************/
/******零偏不稳定性******/
//#define GYRO_WALK (6*0.5/sqrt(3600))           //0.1deg/s/sqrt(hr) bias instability  6 deg/hr
//#define VEL_WALK (20)
/********************随机游走计算噪声std************************/
#define GYRO_STD_X (0.3/sqrt(3600))/sqrt(IMU_T)   //0.3deg/sqrt(hr)  0.05deg/s
#define ACC_STD_X (0.005/sqrt(3600))/sqrt(IMU_T)  //0.005g/sqrt(hr) 0.0083g
#endif


#define GYRO_STD_Y GYRO_STD_X
#define GYRO_STD_Z GYRO_STD_X

#define ACC_STD_Y ACC_STD_X
#define ACC_STD_Z ACC_STD_X

/*--------------------------------IMU AXIS-----------------------------*/
#define CFG_GYRO_X_SCALE  (1)
#define CFG_GYRO_Y_SCALE  (1)
#define CFG_GYRO_Z_SCALE (1)
#define CFG_ACC_X_SCALE   (1)
#define CFG_ACC_Y_SCALE   (1)
#define CFG_ACC_Z_SCALE  (1)

#define CFG_GYRO_X_ROW 1
#define CFG_GYRO_Y_ROW 2
#define CFG_GYRO_Z_ROW 3
#define CFG_ACC_X_ROW 4
#define CFG_ACC_Y_ROW 5
#define CFG_ACC_Z_ROW 6

#endif
/*--------------------------------LEVER(m)-----------------------------*/
#define CFG_ARM_ANT_X    1.0
#define CFG_ARM_ANT_Y    0.0
#define CFG_ARM_ANT_Z    0.0
//#define WORK_PATH  "G:/5.29粗对准数据/-90/"
//#define TEST_RAW_FILE_PATH	 WORK_PATH
//#define TEST_RAW_FILE_NAME	   "024624_raw.txt"

#define WORK_PATH  "E:/P2项目/CGI310/CGI310测试数据/"
#define TEST_RAW_FILE_PATH	 WORK_PATH
#define TEST_RAW_FILE_NAME	   "test1.txt"
/*--------------------------------TEST_OUT/TMP_FILE_PATH-----------------------------*/
#define TEST_OUT_FILE_PATH    TEST_RAW_FILE_PATH"OUT/"
#define TEST_TMP_FILE_PATH    "D:/TMP/"

/*--------------------------------TEST_RST_FILE_NAME----------------------------*/
#define TEST_RST_FILE_NAME     "gilc_vehicle_rst.nmea"

/*--------------------------------RAW CFG-----------------------------*/
#define CFG_POS_STD_USE 1
#define CFG_VEL_STD_USE 1
//#define CFG_GNSSPOS_MODE GILC_GNSSPOS_MODE__LLA_RAD
#define CFG_GNSSPOS_MODE  GILC_GNSSPOS_MODE__LLA_DEG
//#define CFG_GNSSVEL_MODE GILC_GNSSVEL_MODE__ECEF
#define CFG_GNSSVEL_MODE GILC_GNSSVEL_MODE__SPEED_HEADING

#define GILC_NMEA_OUT_PERIOD_MS    100     /*dsf90: 输出10Hz*/