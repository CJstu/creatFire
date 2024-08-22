//
// Created by 25230 on 24-8-21.
//
#include "Bsp_usart.h"
#include "usart.h"

/* USER CODE BEGIN 0 */
uint8_t cmd = 0;


//串口接收中断回调函数
//A1 点火
//A2 关闭
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART1){
        if(cmd == 0xA1){
            HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_SET);
            Bsp_fire_ON(50);
            HAL_UART_Transmit(&huart1, "OPEN!\r\n", sizeof("OPEN!\r\n"),10000);
        }
        if(cmd == 0xA2){
            Bsp_fire_OFF();
            HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_RESET);
            HAL_UART_Transmit(&huart1, "CLOSE!\r\n", sizeof("CLOSE!\r\n"),10000);
        }
        HAL_UART_Receive_IT(&huart1, &cmd, 1);
    }
}

/* USER CODE END 0 */
