################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/vagrant/ccs/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3

ORDERED_OBJS += \
"./src/image_data.obj" \
"./src/main.obj" \
"./src/Pervasive_Displays_small_EPD/EPD_hardware_driver.obj" \
"./src/Pervasive_Displays_small_EPD/EPD_interface.obj" \
"./src/Pervasive_Displays_small_EPD/EPD_partial_interface.obj" \
"./src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Mb/EPD_G2_Aurora_Mb.obj" \
"./src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Ma/EPD_G2_Aurora_Ma.obj" \
"./src/Pervasive_Displays_small_EPD/COG_FPL/G1_Aurora_Mb/EPD_G1_Aurora_Mb.obj" \
"./src/EPD_Kit_Tool/Char.obj" \
"./src/EPD_Kit_Tool/EPD_Kit_Tool_Process.obj" \
"./src/EPD_Kit_Tool/Mem_Flash.obj" \
"./src/EPD_Kit_Tool/Uart_Controller.obj" \
"./src/EPD_Kit_Tool/Drivers/EPD_LED.obj" \
"./src/EPD_Kit_Tool/Drivers/Uart_Driver.obj" \
"../lnk_msp430f5529.cmd" \
$(GEN_CMDS__FLAG) \
-l"libmath.a" \
-l"libc.a" \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include src/subdir_vars.mk
-include src/Pervasive_Displays_small_EPD/subdir_vars.mk
-include src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Mb/subdir_vars.mk
-include src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Ma/subdir_vars.mk
-include src/Pervasive_Displays_small_EPD/COG_FPL/G1_Aurora_Mb/subdir_vars.mk
-include src/EPD_Kit_Tool/subdir_vars.mk
-include src/EPD_Kit_Tool/Drivers/subdir_vars.mk
-include subdir_rules.mk
-include src/subdir_rules.mk
-include src/Pervasive_Displays_small_EPD/subdir_rules.mk
-include src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Mb/subdir_rules.mk
-include src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Ma/subdir_rules.mk
-include src/Pervasive_Displays_small_EPD/COG_FPL/G1_Aurora_Mb/subdir_rules.mk
-include src/EPD_Kit_Tool/subdir_rules.mk
-include src/EPD_Kit_Tool/Drivers/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
DisplayTestNew.out \

EXE_OUTPUTS__QUOTED += \
"DisplayTestNew.out" \

BIN_OUTPUTS += \
DisplayTestNew.hex \

BIN_OUTPUTS__QUOTED += \
"DisplayTestNew.hex" \


# All Target
all: DisplayTestNew.out

# Tool invocations
DisplayTestNew.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"/home/vagrant/ccs/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=full -z -m"DisplayTestNew.map" --heap_size=600 --stack_size=160 --cinit_hold_wdt=on -i"/home/vagrant/ccs/ccsv6/ccs_base/msp430/include" -i"/home/vagrant/ccs/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/lib" -i"/home/vagrant/ccs/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include" -i"/home/vagrant/ccs/ccsv6/ccs_base/msp430/lib/5xx_6xx_FRxx" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="DisplayTestNew_linkInfo.xml" --use_hw_mpy=F5 --rom_model -o "DisplayTestNew.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

DisplayTestNew.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"/home/vagrant/ccs/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/hex430" --memwidth=8 --romwidth=8 -o "DisplayTestNew.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "src/image_data.pp" "src/main.pp" "src/Pervasive_Displays_small_EPD/EPD_hardware_driver.pp" "src/Pervasive_Displays_small_EPD/EPD_interface.pp" "src/Pervasive_Displays_small_EPD/EPD_partial_interface.pp" "src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Mb/EPD_G2_Aurora_Mb.pp" "src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Ma/EPD_G2_Aurora_Ma.pp" "src/Pervasive_Displays_small_EPD/COG_FPL/G1_Aurora_Mb/EPD_G1_Aurora_Mb.pp" "src/EPD_Kit_Tool/Char.pp" "src/EPD_Kit_Tool/EPD_Kit_Tool_Process.pp" "src/EPD_Kit_Tool/Mem_Flash.pp" "src/EPD_Kit_Tool/Uart_Controller.pp" "src/EPD_Kit_Tool/Drivers/EPD_LED.pp" "src/EPD_Kit_Tool/Drivers/Uart_Driver.pp" 
	-$(RM) "src/image_data.obj" "src/main.obj" "src/Pervasive_Displays_small_EPD/EPD_hardware_driver.obj" "src/Pervasive_Displays_small_EPD/EPD_interface.obj" "src/Pervasive_Displays_small_EPD/EPD_partial_interface.obj" "src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Mb/EPD_G2_Aurora_Mb.obj" "src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Ma/EPD_G2_Aurora_Ma.obj" "src/Pervasive_Displays_small_EPD/COG_FPL/G1_Aurora_Mb/EPD_G1_Aurora_Mb.obj" "src/EPD_Kit_Tool/Char.obj" "src/EPD_Kit_Tool/EPD_Kit_Tool_Process.obj" "src/EPD_Kit_Tool/Mem_Flash.obj" "src/EPD_Kit_Tool/Uart_Controller.obj" "src/EPD_Kit_Tool/Drivers/EPD_LED.obj" "src/EPD_Kit_Tool/Drivers/Uart_Driver.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

