/*=================================================================================*/
/*  Author      : Ahmed bayoumii                   Embedded SW Engineer           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bayoumii77/             */
/*  Git account : https://github.com/Baioumi7				               */
/*  mail        : ahmedbayoumii2024@gmil.com                                         */
/*=================================================================================*/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*Options:		
			1- LOW_LEVEL
			2- ON_CHANGE
			3- FALLING_EDGE	
			4- RISING_EDGE				
								*/		
#define INT0_SENSE			ON_CHANGE
#define INT1_SENSE			ON_CHANGE
#define INT2_SENSE			RISING_EDGE

/*Options:
			1- ENABLED
			2- DISABLED
								*/
#define INT0_INITIAL_STATE	ENABLED
#define INT1_INITIAL_STATE	ENABLED
#define INT2_INITIAL_STATE	DISABLED


#endif
