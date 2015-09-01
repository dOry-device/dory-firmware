# invoke SourceDir generated makefile for fatsd_msp430.pe430X
fatsd_msp430.pe430X: .libraries,fatsd_msp430.pe430X
.libraries,fatsd_msp430.pe430X: package/cfg/fatsd_msp430_pe430X.xdl
	$(MAKE) -f /home/vagrant/dory-firmware/fatsd_MSP430F5529/src/makefile.libs

clean::
	$(MAKE) -f /home/vagrant/dory-firmware/fatsd_MSP430F5529/src/makefile.libs clean

