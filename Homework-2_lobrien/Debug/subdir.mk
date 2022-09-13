################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main\ -\ Copy.cpp \
../main.cpp 

CPP_DEPS += \
./main\ -\ Copy.d \
./main.d 

OBJS += \
./main\ -\ Copy.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
main\ -\ Copy.o: ../main\ -\ Copy.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"main - Copy.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./main\ -\ Copy.d ./main\ -\ Copy.o ./main.d ./main.o

.PHONY: clean--2e-

