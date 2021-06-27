//Where is the LED connected
//Pin
//Port


//General peripheral addresses
#define PERIPH_BASE			0x4000 0000U
#define AHB1_PERIPH_OFFST	0x0002 0000U
#define AHB1_PERIPH_BASE	(*(volatile unsigned int*)(PERIPH_BASE + AHB1_PERIPH_OFFST))

//offset address
#define GPIOA_OFFST			(0x0000U)

//gpio peripherals
#define GPIOA				0x40020000U
#define GPIOB				0x40020400U
#define GPIOC				0x40020800U
#define GPIOD				0x40020C00U

//other peripherals
#define RCC_BASE				0x40023800U

//ahb1 peripheral rcc address
#define AHB1ENR_OFFST			0x30U
#define RCC_AHB1ENR				(*(volatile unsigned int*)(RCC_BASE + AHB1ENR_OFFST))

#define RCC_GPIOA_EN			(1U<<0)
#define RCC_GPIOB_EN			(1U<<1)
#define RCC_GPIOC_EN			(1U<<2)
#define RCC_GPIOD_EN			(1U<<3)

#define GPIOA_MODER				(*(volatile unsigned int*)(GPIOA + 0x0U))
#define GPIOB_MODER				(*(volatile unsigned int*)(GPIOB + 0x0U))
#define GPIOC_MODER				(*(volatile unsigned int*)(GPIOC + 0x0U))
#define GPIOD_MODER				(*(volatile unsigned int*)(GPIOD + 0x0U))

#define ODR_OFFST				0x14U
#define GPIOD_ODR				(*(volatile unsigned int*)(GPIOD + ODR_OFFST))

#define PIN12					(1U<<12)
#define GREEN_LED_PIN			PIN12



int main()
{
	//Enable clock for GPIOD
	RCC_AHB1ENR |= (RCC_GPIOD_EN);

	//Set PD12 as output pin
	GPIOD_MODER |= (1U<<24);
	GPIOD_MODER &= ~(1U<25);

	while(1)
	{
		//set PD12 high
		GPIOD_ODR |= GREEN_LED_PIN;

		//toggling the PD12 to low
		//GPIOD_ODR ^= GREEN_LED_PIN;

		//a delay to notice the toggling
		for(int count = 0; count<1000000;count++);
	}
	return 0;
}
