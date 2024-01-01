/*=================================================================================*/
/*  Author      : Ahmed bayoumii                   Embedded SW Engineer           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bayoumii77/             */
/*  Git account : https://github.com/Baioumi7				               */
/*  mail        : ahmedbayoumii2024@gmil.com                                         */
/*=================================================================================*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SvM_config.h"
#include "SvM_interface.h"
#include "SvM_private.h"

#include "MAP_interface.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "TIMER_register.h"

void SVM_voidServoInit(void)
{
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN4,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN5,DIO_u8PIN_OUTPUT);
	TIMER1_voidInit();
	ICR1 = 19999;
	//Timer1_voidSetICRValue(20000);
}
void SVM_voidSetAngle1(u8 Copy_u8SetAngle1)
{
	u16 Local_u16Value = Map(0,180,540,1540,Copy_u8SetAngle1);


	Timer1_voidSetChannelACompMatchValue(Local_u16Value);
}
void SVM_voidSetAngle2(u8 Copy_u8SetAngle2)
{
	u16 Local_u16Value = Map(0,180,540,1540,Copy_u8SetAngle2);

	OCR1B = Local_u16Value;
	//Timer1_voidSetChannelBCompMatchValue(Local_u16Value);
}


