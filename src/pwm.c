/*
 * pwm.c
 *
 *  Created on: 17 дек. 2020 г.
 *      Author: Tr
 */

#include "pwm.h"

void pwm_gpio_init() {
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER6_1;	//tim3_ch1
}


void pwm_init() {
	pwm_gpio_init();

	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	TIM3->ARR = 8096;
	TIM3->PSC = 6;

	TIM3->CCMR1 |= (TIM_CCMR1_OC1M & ~TIM_CCMR1_OC1M_0);
	TIM3->CCMR1 |= TIM_CCMR1_OC1PE;

	TIM3->CCER |= TIM_CCER_CC1E;	//enable output
	TIM3->CCER |= TIM_CCER_CC1P;	//inverse

	TIM3->CR1 |= TIM_CR1_CEN;
}

void pwm_set_val(uint8_t num_ch, uint16_t val) {
//	switch(num_ch)
//	{
//		case 1 :
			TIM3->CCR1 = val;
//		break;
//	}

}
