#ifndef __SENSIML_SENSOR_CONFIG_H__
#define __SENSIML_SENSOR_CONFIG_H__

#include <stdint.h>
#include "dcl_commands.h"
#include "sensor_config.h"


#define SML_DEVICE_COMMAND_NUM_MSGS 4

const struct sensor_config_msg recognition_config[] = {
	SENSOR_CONFIG_CLEAR_MSG(),
	SENSOR_CONFIG_IMU_MSG(SENSOR_ENG_VALUE_ACCEL,104,0xc8),
	SENSOR_CONFIG_IMU_MSG(SENSOR_ENG_VALUE_GYRO,104,0),
	SENSOR_CONFIG_DONE_MSG()
};

#endif //__SENSIML_SENSOR_CONFIG_H__