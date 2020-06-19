#define __IO volatile

typedef unsigned int uint32_t;
typedef signed int int32_t;

typedef struct
{
    __IO uint32_t CR;
    __IO uint32_t PLLCFGR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t AHB1RSTR;
    __IO uint32_t AHB2RSTR;
    __IO uint32_t AHB3RSTR;
    uint32_t      RESERVED0;
    __IO uint32_t APB1RSTR;
    __IO uint32_t APB2RSTR;
    uint32_t      RESERVED1[2];
    __IO uint32_t AHB1ENR;
    __IO uint32_t AHB2ENR;
    __IO uint32_t AHB3ENR;
    uint32_t      RESERVED2;
    __IO uint32_t APB1ENR;
    __IO uint32_t APB2ENR;
    uint32_t      RESERVED3[2];
    __IO uint32_t AHB1LPENR;
    __IO uint32_t AHB2LPENR;
    __IO uint32_t AHB3LPENR;
    uint32_t      RESERVED4;
    __IO uint32_t APB1LPENR;
    __IO uint32_t APB2LPENR;
    uint32_t      RESERVED5[2];
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
    uint32_t      RESERVED6[2];
    __IO uint32_t SSCGR;
    __IO uint32_t PLLI2SCFGR;
    __IO uint32_t PLLSAICFGR;
    __IO uint32_t DCKCFGR;
    __IO uint32_t CKGATENR;
    __IO uint32_t DCKCFGR2;
} RCC_TypeDef;

typedef struct
{
    __IO uint32_t MODER;
    __IO uint32_t OTYPER;
    __IO uint32_t OSPEEDR;
    __IO uint32_t PUPDR;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t LCKR;
    __IO uint32_t AFR[2];
} GPIO_TypeDef;

// Peripheral base address in the alias region
#define PERIPH_BASE 0x40000000U

#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000U)

#define RCC_BASE (AHB1PERIPH_BASE + 0x3800U)
#define GPIOA_BASE (AHB1PERIPH_BASE + 0x0000U)
#define GPIOC_BASE (AHB1PERIPH_BASE + 0x0800U)

#define RCC ((RCC_TypeDef *) RCC_BASE)
#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOC ((GPIO_TypeDef *) GPIOC_BASE)

#define USER    1

#define LED_NUM (1)

const unsigned long led_mask[] = {1ul << 5};

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
}