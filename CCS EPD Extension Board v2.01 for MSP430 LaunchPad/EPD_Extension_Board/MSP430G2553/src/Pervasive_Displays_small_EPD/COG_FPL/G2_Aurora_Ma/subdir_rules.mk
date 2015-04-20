################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Ma/EPD_G2_Aurora_Ma.obj: ../src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Ma/EPD_G2_Aurora_Ma.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/cl430" -vmsp --abi=eabi -Ooff --opt_for_speed=1 --use_hw_mpy=none --include_path="/home/vagrant/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src/EPD_Kit_Tool/Drivers" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src/EPD_Kit_Tool" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src/Pervasive_Displays_small_EPD" -g --define=__MSP430G2553__ --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Ma/EPD_G2_Aurora_Ma.pp" --obj_directory="src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Ma" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


