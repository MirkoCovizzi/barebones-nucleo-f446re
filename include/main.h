#define __IO volatile             /*!< Defines 'read / write' permissions */

typedef unsigned int uint32_t;
typedef signed int int32_t;

typedef struct
{
    __IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
    __IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
    __IO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
    __IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
    __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
    __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
    __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
    uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
    __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
    __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
    uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
    __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
    __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
    __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
    uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
    __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
    __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
    uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
    __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
    __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
    __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
    uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
    __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
    __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
    uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
    __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
    __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
    uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
    __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
    __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
    __IO uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
    __IO uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
    __IO uint32_t CKGATENR;      /*!< RCC Clocks Gated ENable Register,                            Address offset: 0x90 */
    __IO uint32_t DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x94 */
} RCC_TypeDef;

typedef struct
{
    __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
    __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
    __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
    __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
    __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
    __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
    __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

#define PERIPH_BASE 0x40000000U // Peripheral base address in the alias region

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
