################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../event.cpp \
../eventprocessor.cpp \
../loggingserver.cpp \
../main.cpp \
../producer.cpp \
../random.cpp \
../runnable.cpp \
../stacktracer.cpp \
../subscriber.cpp 

OBJS += \
./event.o \
./eventprocessor.o \
./loggingserver.o \
./main.o \
./producer.o \
./random.o \
./runnable.o \
./stacktracer.o \
./subscriber.o 

CPP_DEPS += \
./event.d \
./eventprocessor.d \
./loggingserver.d \
./main.d \
./producer.d \
./random.d \
./runnable.d \
./stacktracer.d \
./subscriber.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


