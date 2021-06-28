#include<uart.h>
#include<adc.h>


uint32_t sensorValue;
int main()
{
	uart_TX_init();
	pa1_adc_init();
	start_conversion();

	while(1)
	{

		sensorValue = adc_read();
		printf("sensor value: %lu\n\r",sensorValue);
	}
	return 0;
}

