################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../basic_Menu.cpp \
../mainMenu.cpp \
../tutorial.cpp 

CPP_DEPS += \
./basic_Menu.d \
./mainMenu.d \
./tutorial.d 

OBJS += \
./basic_Menu.o \
./mainMenu.o \
./tutorial.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./basic_Menu.d ./basic_Menu.o ./mainMenu.d ./mainMenu.o ./tutorial.d ./tutorial.o

.PHONY: clean--2e-

