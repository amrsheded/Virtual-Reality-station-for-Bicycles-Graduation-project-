################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_MotorDriver.c \
../DIO.c \
../EXT_INT.c \
../UART_Driver.c \
../UART_service.c \
../VR.c \
../main.c 

OBJS += \
./DC_MotorDriver.o \
./DIO.o \
./EXT_INT.o \
./UART_Driver.o \
./UART_service.o \
./VR.o \
./main.o 

C_DEPS += \
./DC_MotorDriver.d \
./DIO.d \
./EXT_INT.d \
./UART_Driver.d \
./UART_service.d \
./VR.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


