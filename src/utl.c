/*******************************************************************************
 * @file    utl.c
 * @author  Joe Todd
 * @version
 * @date    January 2014
 * @brief   Theremin
 *
  ******************************************************************************/


/* Includes -------------------------------------------------------------------*/
#include "utl.h"

/**
 * Enable an interrupt.
 */
extern void
utl_enable_irq(IRQn_Type irq)
{
    NVIC->ISER[0] = 1 << (irq & 0x1F);
}

/**
 * Disable an interrupt.
 */
extern void
utl_disable_irq(IRQn_Type irq)
{
    NVIC->ICER[0] = 1 << (irq & 0x1F);
}