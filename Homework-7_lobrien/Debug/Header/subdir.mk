################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Header/FeetInches.cpp 

CPP_DEPS += \
./Header/FeetInches.d 

OBJS += \
./Header/FeetInches.o 


# Each subdirectory must supply rules for building sources it contributes
Header/%.o: ../Header/%.cpp Header/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Header

clean-Header:
	-$(RM) ./Header/FeetInches.d ./Header/FeetInches.o

.PHONY: clean-Header

