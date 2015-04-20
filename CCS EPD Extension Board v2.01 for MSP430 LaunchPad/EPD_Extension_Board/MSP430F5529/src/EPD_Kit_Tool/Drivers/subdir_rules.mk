################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/EPD_Kit_Tool/Drivers/EPD_LED.obj: ../src/EPD_Kit_Tool/Drivers/EPD_LED.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/cl430" -vmspx --abi=eabi --data_model=restricted --opt_for_speed=1 --include_path="/home/vagrant/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src/EPD_Kit_Tool/Drivers" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src/EPD_Kit_Tool" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src/Pervasive_Displays_small_EPD" -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="src/EPD_Kit_Tool/Drivers/EPD_LED.pp" --obj_directory="src/EPD_Kit_Tool/Drivers" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/EPD_Kit_Tool/Drivers/Uart_Driver.obj: ../src/EPD_Kit_Tool/Drivers/Uart_Driver.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/cl430" -vmspx --abi=eabi --data_model=restricted --opt_for_speed=1 --include_path="/home/vagrant/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src/EPD_Kit_Tool/Drivers" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src/EPD_Kit_Tool" --include_path="/home/vagrant/Desktop/dory/CCS EPD Extension Board v2.01 for MSP430 LaunchPad/EPD_Extension_Board/src/Pervasive_Displays_small_EPD" -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="src/EPD_Kit_Tool/Drivers/Uart_Driver.pp" --obj_directory="src/EPD_Kit_Tool/Drivers" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


