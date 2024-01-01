/*=================================================================================*/
/*  Author      : Ahmed bayoumii                   Embedded SW Engineer           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bayoumii77/             */
/*  Git account : https://github.com/Baioumi7				               */
/*  mail        : ahmedbayoumii2024@gmil.com                                         */
/*=================================================================================*/
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Ultrasonic_config.h"
#include "Ultrasonic_interface.h"

#include "EXTI_interface.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "UART_interface.h"

u8 sensor_working=0;
u8 rising_edge=0;
u32 timer_counter=0;
u32 distance;



void Ultrasonic_voidInit(void)
{

	TIMER0_voidInit();

	DIO_u8SetPinDirection(ECHO_PORT,ECHO_PIN,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(ECHO_PORT,ECHO_PIN,DIO_u8PIN_HIGH);

	DIO_u8SetPinDirection(TRIGER_PORT,TRIGER_PIN,DIO_u8PIN_OUTPUT);

	EXTI_voidInt1Init();

}


void Ultra_voidTriger(void)
{
	if(!sensor_working){

		DIO_u8SetPinValue(TRIGER_PORT,TRIGER_PIN,DIO_u8PIN_HIGH);
		_delay_us(15);
		DIO_u8SetPinValue(TRIGER_PORT,TRIGER_PIN,DIO_u8PIN_LOW);
		sensor_working=1;
		UART_voidSendDecimalNumber(distance);

	}

}


void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(sensor_working==1)
	{
		if(rising_edge==0)
		{
			TCNT0=0x00;
			rising_edge=1;
			timer_counter=0;
		}
		else{
			distance=(timer_counter*256+TCNT0)/466;

			_delay_ms(40);
			TCNT0 = 0x00;
			sensor_working=0;
			timer_counter=0;
			rising_edge=0;
		}
	}
}
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	timer_counter++;
	if(timer_counter >550){

		sensor_working=0;
		rising_edge=0;
		timer_counter=0;
	}
}

