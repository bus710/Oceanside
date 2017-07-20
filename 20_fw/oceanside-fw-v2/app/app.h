#ifndef APP_H_
#define APP_H_

#define MCU_ID					"STM32F446Rx"
#define KN_VER					"1706"

#define PRJ_ID					"OCEANSIDE"
#define PRJ_VER				"1"
#define HW_VER					"0003"
#define FW_VER					"0002"
#define PT_VER					"0001"


extern mutex_t mtx_uart_tx;
extern mutex_t mtx_uart_rx;
extern char global_char;

void app_init(void);

#endif
