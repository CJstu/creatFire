//
// Created by 25230 on 24-8-21.
//

#include "Bsp_fire.h"
#include "tim.h"


//占空比一般为60%
void Bsp_fire_ON(uint8_t fire_duty) {
    __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,fire_duty);//6放电时间
    // HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);//点火
}


//TODO 因硬件问题，必须持续打开光耦，否则会让点火线圈持续通电，导致线圈烧坏。
//TODO 如果需要关闭点火，请使用Bsp_fire_OFF函数，不可直接关闭光耦。修改硬件电路之后，可以将注释打开。
void Bsp_fire_OFF(void) {
    __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,100);
    // HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);//熄灭
}



