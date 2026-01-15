#include "uart_if.h"
#include <stdio.h>

extern UART_HandleTypeDef huart2;

void uart_send_class(int cls)
{
    char buf[32];
    int n = snprintf(buf, sizeof(buf), "ANOMALY:%d\r\n", cls);
    HAL_UART_Transmit(&huart2, (uint8_t*)buf, n, HAL_MAX_DELAY);
}
