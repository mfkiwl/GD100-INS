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
#define IMU_BW_HZ                 10
//��ǰѡ���˲������� 10hz  ��ѹVin_Boost 3.3V
/*--------------------------------IMU WALK-----------------------------*/
//murataģ��
//���ٶȼ�  SCC2230 ������Ӽ�+�������ݣ�
//***************����*****************//
//1��������������� 
//2������������  10Hz:0.12deg/s    60Hz:0.2deg/s
//3�����ٶȼ��������
//4�����ٶȼ��ٶ�����  10Hz:5mg    60Hz:7mg
#define VEL_WALK (5000)   //��Ҫ����
#define ACC_STD_X (0.001)     //g


#define GYRO_STD_Z (0.12)    //deg/s
//������    SCR2100���������ݣ�
//***************����*****************//
//1������������� 0.23deg/sqrt(hr)
//2��������ƫ�ȶ���  1deg/hr
//3�����������������ܶ�  0.005 ��deg/s��/sqrt(Hz) 
//4���˲������� 
#define GYRO_WALK (0.23/50)     //deg/sqrt(hr)
#define GYRO_STD_X (0.005*sqrt(IMU_BW_HZ))   //deg/s
#define GYRO_STD_Y (0.005*sqrt(IMU_BW_HZ))   //deg/s


#define ACC_STD_Y ACC_STD_X
#define ACC_STD_Z ACC_STD_X

/*--------------------------------IMU AXIS-----------------------------*/
#define CFG_GYRO_X_SCALE  (1)
#define CFG_GYRO_Y_SCALE  (-1)
#define CFG_GYRO_Z_SCALE (1)
#define CFG_ACC_X_SCALE   (1)
#define CFG_ACC_Y_SCALE   (-1)
#define CFG_ACC_Z_SCALE  (1)

#define CFG_GYRO_X_ROW 2
#define CFG_GYRO_Y_ROW 1
#define CFG_GYRO_Z_ROW 3
#define CFG_ACC_X_ROW 4
#define CFG_ACC_Y_ROW 5
#define CFG_ACC_Z_ROW 6

#endif
/*--------------------------------LEVER(m)-----------------------------*/
#define CFG_ARM_ANT_X    1.0
#define CFG_ARM_ANT_Y    0.0
#define CFG_ARM_ANT_Z    0.0
//#define WORK_PATH  "G:/test/"
//#define TEST_RAW_FILE_PATH	 WORK_PATH
//#define TEST_RAW_FILE_NAME	   "100401_raw.txt"

#define WORK_PATH  "G:/CGI310/CGI310��������/"
#define TEST_RAW_FILE_PATH	 WORK_PATH
#define TEST_RAW_FILE_NAME	   "ym.txt"
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
//#define CFG_GNSSVEL_MODE  GILC_GNSSVEL_MODE__SPEED_HEADING
#define GILC_NMEA_OUT_PERIOD_MS   100     /*dsf90: ���10Hz*/