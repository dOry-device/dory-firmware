#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.msp430.elf.MSP430X{1,0,4.4,3
#
ifeq (,$(MK_NOGENDEPS))
-include package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X.dep
package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X.dep: ;
endif

package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X: | .interfaces
package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X: package/cfg/gpiointerrupt_msp430f5529_pe430X.c package/cfg/gpiointerrupt_msp430f5529_pe430X.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle430X $< ...
	$(ti.targets.msp430.elf.MSP430X.rootDir)/bin/cl430 --abi=eabi -c  -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path=\"/home/vagrant/ccs/ccsv6/ccs_base/msp430/include\" --include_path=\"/home/vagrant/ccs/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include\" --include_path=\"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/driverlib/MSP430F5xx_6xx\" --include_path=\"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/grlib/grlib\" --advice:power=all -g --define=__MSP430F5529__ --define=MSP430WARE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal   -qq -pdsw225  -vmspx --near_data=none --code_model=large --data_model=restricted -eo.oe430X -ea.se430X  --embed_inline_assembly  -Dxdc_cfg__xheader__='"xconfig_gpiointerrupt_msp430f5529/package/cfg/gpiointerrupt_msp430f5529_pe430X.h"'  -Dxdc_target_name__=MSP430X -Dxdc_target_types__=ti/targets/msp430/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_4_3 -O2 -g --optimize_with_debug  $(XDCINCS) -I$(ti.targets.msp430.elf.MSP430X.rootDir)/include  -fs=./package/cfg -fr=./package/cfg -fc $<
	$(MKDEP) -a $@.dep -p package/cfg -s oe430X $< -C   -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path=\"/home/vagrant/ccs/ccsv6/ccs_base/msp430/include\" --include_path=\"/home/vagrant/ccs/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include\" --include_path=\"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/driverlib/MSP430F5xx_6xx\" --include_path=\"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/grlib/grlib\" --advice:power=all -g --define=__MSP430F5529__ --define=MSP430WARE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal   -qq -pdsw225  -vmspx --near_data=none --code_model=large --data_model=restricted -eo.oe430X -ea.se430X  --embed_inline_assembly  -Dxdc_cfg__xheader__='"xconfig_gpiointerrupt_msp430f5529/package/cfg/gpiointerrupt_msp430f5529_pe430X.h"'  -Dxdc_target_name__=MSP430X -Dxdc_target_types__=ti/targets/msp430/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_4_3 -O2 -g --optimize_with_debug  $(XDCINCS) -I$(ti.targets.msp430.elf.MSP430X.rootDir)/include  -fs=./package/cfg -fr=./package/cfg
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X: export C_DIR=
package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X: PATH:=$(ti.targets.msp430.elf.MSP430X.rootDir)/bin/:$(PATH)

package/cfg/gpiointerrupt_msp430f5529_pe430X.se430X: | .interfaces
package/cfg/gpiointerrupt_msp430f5529_pe430X.se430X: package/cfg/gpiointerrupt_msp430f5529_pe430X.c package/cfg/gpiointerrupt_msp430f5529_pe430X.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle430X -n $< ...
	$(ti.targets.msp430.elf.MSP430X.rootDir)/bin/cl430 --abi=eabi -c -n -s --symdebug:none -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path=\"/home/vagrant/ccs/ccsv6/ccs_base/msp430/include\" --include_path=\"/home/vagrant/ccs/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include\" --include_path=\"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/driverlib/MSP430F5xx_6xx\" --include_path=\"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/grlib/grlib\" --advice:power=all -g --define=__MSP430F5529__ --define=MSP430WARE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal   -qq -pdsw225  -vmspx --near_data=none --code_model=large --data_model=restricted -eo.oe430X -ea.se430X   -Dxdc_cfg__xheader__='"xconfig_gpiointerrupt_msp430f5529/package/cfg/gpiointerrupt_msp430f5529_pe430X.h"'  -Dxdc_target_name__=MSP430X -Dxdc_target_types__=ti/targets/msp430/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_4_3 -O2 -g --optimize_with_debug  $(XDCINCS) -I$(ti.targets.msp430.elf.MSP430X.rootDir)/include  -fs=./package/cfg -fr=./package/cfg -fc $<
	$(MKDEP) -a $@.dep -p package/cfg -s oe430X $< -C  -n -s --symdebug:none -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path=\"/home/vagrant/ccs/ccsv6/ccs_base/msp430/include\" --include_path=\"/home/vagrant/ccs/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include\" --include_path=\"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/driverlib/MSP430F5xx_6xx\" --include_path=\"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/grlib/grlib\" --advice:power=all -g --define=__MSP430F5529__ --define=MSP430WARE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal   -qq -pdsw225  -vmspx --near_data=none --code_model=large --data_model=restricted -eo.oe430X -ea.se430X   -Dxdc_cfg__xheader__='"xconfig_gpiointerrupt_msp430f5529/package/cfg/gpiointerrupt_msp430f5529_pe430X.h"'  -Dxdc_target_name__=MSP430X -Dxdc_target_types__=ti/targets/msp430/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_4_3 -O2 -g --optimize_with_debug  $(XDCINCS) -I$(ti.targets.msp430.elf.MSP430X.rootDir)/include  -fs=./package/cfg -fr=./package/cfg
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/gpiointerrupt_msp430f5529_pe430X.se430X: export C_DIR=
package/cfg/gpiointerrupt_msp430f5529_pe430X.se430X: PATH:=$(ti.targets.msp430.elf.MSP430X.rootDir)/bin/:$(PATH)

clean,e430X ::
	-$(RM) package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X
	-$(RM) package/cfg/gpiointerrupt_msp430f5529_pe430X.se430X

gpiointerrupt_msp430f5529.pe430X: package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X package/cfg/gpiointerrupt_msp430f5529_pe430X.mak

clean::
	-$(RM) package/cfg/gpiointerrupt_msp430f5529_pe430X.mak
