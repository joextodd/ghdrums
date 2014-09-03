#include "stm32f4xx_conf.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "timer.h"
#include "utl.h"

static volatile uint32_t ms_count = 0;

/* 
 * SYSCLK = 16MHz
 * TIM2CLK = 16MHz / 16 = 1MHz
 */
extern void 
timer_init(void) 
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    TIM2->PSC = 0x000F;             /* 16 prescalar */
    TIM2->ARR = 0x03E8;             /* count to 1000 */
    TIM2->DIER |= TIM_DIER_UIE;     /* enable update interrupt */
    TIM2->CR1 |= TIM_CR1_ARPE       /* autoreload on */
        | (TIM_CR1_CEN);            /* counter enabled */
    TIM2->EGR = 1;                  /* trigger update event */

    utl_enable_irq(TIM2_IRQn);
}

extern uint32_t 
timer_get(void)
{
    return (ms_count * 1000UL) + TIM2->CNT;
}

extern void 
timer_delay(uint32_t time) {
    uint32_t start;
    uint32_t timer;
    uint32_t end;

    start = timer_get();
    end = start + time;

    while (timer < end) {
        timer = timer_get();
    }
}

void TIM2_IRQHandler(void) 
{
    uint32_t sr;
    sr = TIM2->SR;

    if (sr & TIM_SR_UIF) {
        ms_count++;
    }
    TIM2->SR &= ~TIM_SR_UIF;
}