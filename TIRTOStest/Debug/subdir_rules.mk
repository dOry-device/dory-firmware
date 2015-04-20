################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
MSP_EXP430F5529LP.obj: ../MSP_EXP430F5529LP.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/vagrant/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include" --include_path="/home/vagrant/ti/tirtos_msp43x_2_12_00_24/products/MSPWare_2_00_00_40a/driverlib/MSP430F5xx_6xx" --advice:power=all -g --define=__MSP430F5529__ --define=MSP430WARE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="MSP_EXP430F5529LP.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

doryI2C.obj: ../doryI2C.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/vagrant/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include" --include_path="/home/vagrant/ti/tirtos_msp43x_2_12_00_24/products/MSPWare_2_00_00_40a/driverlib/MSP430F5xx_6xx" --advice:power=all -g --define=__MSP430F5529__ --define=MSP430WARE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="doryI2C.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

empty_min.obj: ../empty_min.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/vagrant/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include" --include_path="/home/vagrant/ti/tirtos_msp43x_2_12_00_24/products/MSPWare_2_00_00_40a/driverlib/MSP430F5xx_6xx" --advice:power=all -g --define=__MSP430F5529__ --define=MSP430WARE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="empty_min.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: ../empty_min.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/home/vagrant/ti/xdctools_3_31_00_24_core/xs" --xdcpath="/home/vagrant/ti/tirtos_msp43x_2_12_00_24/packages;/home/vagrant/ti/tirtos_msp43x_2_12_00_24/products/bios_6_41_03_51/packages;/home/vagrant/ti/tirtos_msp43x_2_12_00_24/products/uia_2_00_02_39/packages;/home/vagrant/ti/ccsv6/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.msp430.elf.MSP430X -p ti.platforms.msp430:MSP430F5529 -r release -c "/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3" --compileOptions "-vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path=\"/home/vagrant/ti/ccsv6/ccs_base/msp430/include\" --include_path=\"/home/vagrant/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include\" --include_path=\"/home/vagrant/ti/tirtos_msp43x_2_12_00_24/products/MSPWare_2_00_00_40a/driverlib/MSP430F5xx_6xx\" --advice:power=all -g --define=__MSP430F5529__ --define=MSP430WARE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal  " "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: | configPkg/linker.cmd
configPkg/: | configPkg/linker.cmd


