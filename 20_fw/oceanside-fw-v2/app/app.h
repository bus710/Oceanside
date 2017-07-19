#ifndef APP_H_
#define APP_H_

#define MCU_ID					"STM32F446Rx"
#define KN_VER					"1706"

#define PRJ_ID					"OCEANSIDE"
#define PRJ_VER				"1"
#define HW_VER					"0003"
#define FW_VER					"0002"
#define PT_VER					"0001"


extern mutex_t mtx_app_uart;
extern char global_char;

extern char buffer[8];
extern msg_t queue[1];
extern mailbox_t mb_buffer;


#endif
