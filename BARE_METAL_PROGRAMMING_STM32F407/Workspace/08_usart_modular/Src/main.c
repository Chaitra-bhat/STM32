#include<uart.h>



int main()
{

	uart_TX_init();

	while(1)
	{
		printf("Hello Chaitra, How are you\n\r");
	}
	return 0;
}

