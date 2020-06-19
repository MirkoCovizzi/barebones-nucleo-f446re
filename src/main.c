#include "main.h"

int32_t LED_Initialize (void) {

    // Enable GPIOA clock
    RCC->AHB1ENR |=  (1ul << 0);

    // Configure LED (PA.5) pins as push-pull outputs, No pull-up, pull-down
    GPIOA->MODER   &= ~((3ul << 2*5));
    GPIOA->MODER   |=  ((1ul << 2*5));
    GPIOA->OTYPER  &= ~((1ul <<   5));
    GPIOA->OSPEEDR &= ~((3ul << 2*5));
    GPIOA->OSPEEDR |=  ((1ul << 2*5));
    GPIOA->PUPDR   &= ~((3ul << 2*5));
    return (0);
}

int32_t Buttons_Initialize (void) {
    // Enable GPIOC clock
    RCC->AHB1ENR |=  (1ul << 2);

    GPIOC->MODER   &= ~(3ul << 2*13);
    GPIOC->OSPEEDR &= ~(3ul << 2*13);
    GPIOC->OSPEEDR |=  (1ul << 2*13);
    GPIOC->PUPDR   &= ~(3ul << 2*13);
    return (0);
}

uint32_t Buttons_GetState (void) {

    uint32_t val = 0;

    if ((GPIOC->IDR & (1ul << 13)) == 0) {
        // USER button
        val |= USER;
    }

    return (val);
}

int32_t LED_On (uint32_t num) {
    int32_t retCode = 0;
    if (num < LED_NUM) {
        GPIOA->BSRR = (led_mask[num]);
    } else {
        retCode = -1;
    }
    return retCode;
}

int32_t LED_Off(uint32_t num) {
    int32_t retCode = 0;
    if (num < LED_NUM) {
        GPIOA->BSRR = (led_mask[num] << 16);
    } else {
        retCode = -1;
    }
    return retCode;
}

int main(void)
{
    LED_Initialize();
    Buttons_Initialize();

    uint32_t i;
    while (1) {
        if (Buttons_GetState() == 1) {
            LED_On(0);
            for (i = 0; i < 500000; i++);
            LED_Off(0);
            for (i = 0; i < 500000; i++);
        }
    }

    return 0;
}
