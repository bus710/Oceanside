#ifndef APP_H_
#define APP_H_


/*
 Here is the entire map of main information.

 There are 3 different data type:
 - SYSTEM INFORMATION provides constant data to present the board's information.
 - APPLICATION INFORMATION stores variables to keep current application's information.
 - DATA STREAM stores real time data from sensors and motors.

 DATA STREAM should be updated once every second.
 However, SYSTEM INFORMATION only needs to be updated when the high level software is initialized.
 Also, APPLICATION INFORMATION needs to be exchanged when the high level software requires it.
 */


// Address definition for System Information.
// Up to 10 addresses can be defined here.
// The address range is 118~127 so that MCU_ID will be 118.
// Each one has 16 bytes space so that the max length should be up to 16.

#define SYS_INFO_BASE_ADDR	118
#define SYS_INFO_END_ADDR	SYS_INFO_BASE_ADDR + 9

static const char sys_info[10][16] = { "F446Rx", "1706", "OCEANSIDE", "0001",
		"0001", "0001", "0001", "0000", "0000", "0000"
};

enum system_info_order {
	mcu_id,
	kernel_info,
	proj_name,
	proj_ver,
	hw_ver,
	fw_ver,
	protocol_ver,
	reserved_system_1,
	reserved_system_2,
	reserved_system_3
};


// Address definition for Application Information.
// Up to 18 addresses can be defined here.
// The address range is 100~117.
// Each one has 16 bytes space so that the max length should be up to 16.

#define APP_INFO_BASE_ADDR	100
#define APP_INFO_END_ADDR	APP_INFO_BASE_ADDR + 17

enum app_info_order {
	app_config,
	uart_config,
	rs485_config,
	i2c_config,
	spi_config,
	gpio_config_0,
	gpio_config_1,
	gpio_config_2,
	gpio_config_3,
	can_config_0,
	can_config_1,
	can_config_2,
	can_config_3,
	motor_config_0,
	motor_config_1,
	motor_config_2,
	motor_config_3,
	reserved_app_0
};


// Address definition for Data Stream.
// Up to 100 addresses can be defined here.
// The address range is 0~99.
// Each one has 16 bytes space so that the max length should be up to 16.

#define DATA_STREAM_BASE_ADDR 	0
#define DATA_STREAM_END_ADDR		DATA_STREAM_BASE_ADDR + 99

void app_init(void);

#endif

