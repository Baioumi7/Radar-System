################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../EXTI_program.c \
../GIE_program.c \
../MAP_program.c \
../SvM_program.c \
../TIMER_program.c \
../UART_program.c \
../Ultrasonic_program.c \
../main.c 

OBJS += \
./DIO_program.o \
./EXTI_program.o \
./GIE_program.o \
./MAP_program.o \
./SvM_program.o \
./TIMER_program.o \
./UART_program.o \
./Ultrasonic_program.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./EXTI_program.d \
./GIE_program.d \
./MAP_program.d \
./SvM_program.d \
./TIMER_program.d \
./UART_program.d \
./Ultrasonic_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


