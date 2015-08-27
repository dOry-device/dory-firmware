# invoke SourceDir generated makefile for gpiointerrupt_msp430f5529.pe430X
gpiointerrupt_msp430f5529.pe430X: .libraries,gpiointerrupt_msp430f5529.pe430X
.libraries,gpiointerrupt_msp430f5529.pe430X: package/cfg/gpiointerrupt_msp430f5529_pe430X.xdl
	$(MAKE) -f /home/vagrant/dory-firmware/gpiointerrupt_MSP430F5529/src/makefile.libs

clean::
	$(MAKE) -f /home/vagrant/dory-firmware/gpiointerrupt_MSP430F5529/src/makefile.libs clean

