################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/image_data.obj: ../src/image_data.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/vagrant/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src/Pervasive_Displays_small_EPD" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src/EPD_Kit_Tool" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src/EPD_Kit_Tool/Drivers" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Mb" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src/Pervasive_Displays_small_EPD/COG_FPL" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src" --include_path="/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="src/image_data.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/main.obj: ../src/main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/vagrant/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src/Pervasive_Displays_small_EPD" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src/EPD_Kit_Tool" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src/EPD_Kit_Tool/Drivers" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src/Pervasive_Displays_small_EPD/COG_FPL/G2_Aurora_Mb" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src/Pervasive_Displays_small_EPD/COG_FPL" --include_path="/home/vagrant/dory-firmware/DisplayTestNew/src" --include_path="/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="src/main.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


