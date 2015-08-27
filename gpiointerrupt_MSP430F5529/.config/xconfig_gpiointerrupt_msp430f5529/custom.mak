## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e430X linker.cmd package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/gpiointerrupt_msp430f5529_pe430X.xdl
	$(SED) 's"^\"\(package/cfg/gpiointerrupt_msp430f5529_pe430Xcfg.cmd\)\"$""\"/home/vagrant/dory-firmware/gpiointerrupt_MSP430F5529/.config/xconfig_gpiointerrupt_msp430f5529/\1\""' package/cfg/gpiointerrupt_msp430f5529_pe430X.xdl > $@
	-$(SETDATE) -r:max package/cfg/gpiointerrupt_msp430f5529_pe430X.h compiler.opt compiler.opt.defs
