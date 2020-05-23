/*
 * camera.c
 *
 *  Created on: Mar 7, 2020
 *      Author: Rushil Punchhi
 */

#include "camera.h"
#include "obc_i2c.h"
#include "obc_error.h"

#define CAMERA_DEV_ADDRESS 0x78
#define CAMERA_READ_ADDRESS 0x79

#define JPEG	1

#define OV5642_320x240 		0	//320x240
#define OV5642_640x480		1	//640x480
#define OV5642_1024x768		2	//1024x768
#define OV5642_1280x960 	3	//1280x960
#define OV5642_1600x1200	4	//1600x1200
#define OV5642_2048x1536	5	//2048x1536
#define OV5642_2592x1944	6	//2592x1944
#define OV5642_1920x1080    7	//1920x1080

i2c_err_t wr_8_8(uint8_t addr, uint8_t data) {
	uint8_t buf[2];
	buf[0] = addr;
	buf[1] = data;

	return i2c_write(CAMERA_DEV_ADDRESS, sizeof(buf), buf);
}

i2c_err_t wr_16_8(uint16_t addr, uint8_t data) {
	uint8_t buf[3];
	buf[0] = addr >> 8;
	buf[1] = addr & 0xFF;
	buf[2] = data;

	return i2c_write(CAMERA_DEV_ADDRESS, sizeof(buf), buf);
}

i2c_err_t wr_8_16(uint8_t addr, uint16_t data) {
	uint8_t buf[3];
	buf[0] = addr;
	buf[1] = data >> 8;
	buf[2] = data & 0xFF;

	return i2c_write(CAMERA_DEV_ADDRESS, sizeof(buf), buf);
}

i2c_err_t wr_16_16(uint16_t addr, uint16_t data){
	uint8_t buf[4];
	buf[0] = addr >> 8;
	buf[1] = addr & 0xFF;
	buf[2] = data >> 8;
	buf[3] = data & 0xFF;

	return i2c_write(CAMERA_DEV_ADDRESS, sizeof(buf), buf);
}

int setup_camera() {

	//set to JPEG and initialize camera
	//https://github.com/ArduCAM/Arduino/blob/master/ArduCAM/examples/mini/ArduCAM_Mini_5MP_Plus_LowPowerMode/ArduCAM_Mini_5MP_Plus_LowPowerMode.ino

	//set to lowest resolution
}


