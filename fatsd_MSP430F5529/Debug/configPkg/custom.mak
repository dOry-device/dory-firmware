## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e430X linker.cmd package/cfg/fatsd_msp430_pe430X.oe430X

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/fatsd_msp430_pe430X.xdl
	$(SED) 's"^\"\(package/cfg/fatsd_msp430_pe430Xcfg.cmd\)\"$""\"/home/vagrant/dory-firmware/fatsd_MSP430F5529/Debug/configPkg/\1\""' package/cfg/fatsd_msp430_pe430X.xdl > $@
	-$(SETDATE) -r:max package/cfg/fatsd_msp430_pe430X.h compiler.opt compiler.opt.defs
