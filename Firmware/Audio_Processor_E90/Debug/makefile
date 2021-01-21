################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Audio_Processor_E90.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Audio_Processor_E90.list \

OBJCOPY_BIN += \
Audio_Processor_E90.bin \


# All Target
all: Audio_Processor_E90.elf secondary-outputs

# Tool invocations
Audio_Processor_E90.elf: $(OBJS) $(USER_OBJS) /Users/skylercornell/Projects/E90/Firmware/Audio_Processor_E90/STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "Audio_Processor_E90.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/Users/skylercornell/Projects/E90/Firmware/Audio_Processor_E90/STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Audio_Processor_E90.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Audio_Processor_E90.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Audio_Processor_E90.list"
	@echo 'Finished building: $@'
	@echo ' '

Audio_Processor_E90.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Audio_Processor_E90.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
