#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/vagrant/ccs/tirtos_msp43x_2_12_01_33/packages;/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages;/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/uia_2_00_02_39/packages;/home/vagrant/ccs/ccsv6/ccs_base;/home/vagrant/dory-firmware/gpiointerrupt_MSP430F5529/.config
override XDCROOT = /home/vagrant/ccs/xdctools_3_31_00_24_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/vagrant/ccs/tirtos_msp43x_2_12_01_33/packages;/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages;/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/uia_2_00_02_39/packages;/home/vagrant/ccs/ccsv6/ccs_base;/home/vagrant/dory-firmware/gpiointerrupt_MSP430F5529/.config;/home/vagrant/ccs/xdctools_3_31_00_24_core/packages;..
HOSTOS = Linux
endif
