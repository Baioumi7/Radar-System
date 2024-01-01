/*=================================================================================*/
/*  Author      : Ahmed bayoumii                   Embedded SW Engineer           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bayoumii77/             */
/*  Git account : https://github.com/Baioumi7				               */
/*  mail        : ahmedbayoumii2024@gmil.com                                         */
/*=================================================================================*/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Reg,bit) 		 Reg|=(1<<bit)
#define CLR_BIT(Reg,bit) 		 Reg=(Reg&(~(1<<bit)))
#define TOOGLE_BIT(Reg,bit)	     Reg^=(1<<bit)
#define GET_BIT(Reg,bit) 		((Reg>>bit)&1)
#define BIT_IS_SET(Reg,bit) (Reg & (1<<bit))
#define BIT_IS_CLEAR(Reg,bit) (!(Reg & (1<<bit)))

#endif /* BIT_MATH_H_ */
