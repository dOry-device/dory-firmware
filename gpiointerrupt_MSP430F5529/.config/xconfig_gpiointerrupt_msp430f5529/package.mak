#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
MK_NOGENDEPS := $(filter clean,$(MAKECMDGOALS))
override PKGDIR = xconfig_gpiointerrupt_msp430f5529
XDCINCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(XPKGPATH))))
XDCCFGDIR = package/cfg/

#
# The following dependencies ensure package.mak is rebuilt
# in the event that some included BOM script changes.
#
ifneq (clean,$(MAKECMDGOALS))
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/utils.js:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/utils.js
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/xdc.tci:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/xdc.tci
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/template.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/template.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/om2.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/om2.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/xmlgen.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/xmlgen.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/xmlgen2.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/xmlgen2.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/Warnings.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/Warnings.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/IPackage.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/IPackage.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/package.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/package.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/services/global/Clock.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/services/global/Clock.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/services/global/Trace.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/services/global/Trace.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/bld.js:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/bld.js
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/BuildEnvironment.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/BuildEnvironment.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/PackageContents.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/PackageContents.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/_gen.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/_gen.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Library.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Library.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Executable.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Executable.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Repository.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Repository.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Configuration.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Configuration.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Script.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Script.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Manifest.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Manifest.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Utils.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/Utils.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/ITarget.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/ITarget.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/ITarget2.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/ITarget2.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/ITarget3.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/ITarget3.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/ITargetFilter.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/ITargetFilter.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/package.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/bld/package.xs
package.mak: config.bld
/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/ITarget.xs:
package.mak: /home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/ITarget.xs
/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/C28_large.xs:
package.mak: /home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/C28_large.xs
/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/C28_float.xs:
package.mak: /home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/C28_float.xs
/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/package.xs:
package.mak: /home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/package.xs
/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/msp430/elf/MSP430.xs:
package.mak: /home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/msp430/elf/MSP430.xs
/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/msp430/elf/MSP430X.xs:
package.mak: /home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/msp430/elf/MSP430X.xs
/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/msp430/elf/MSP430X_small.xs:
package.mak: /home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/msp430/elf/MSP430X_small.xs
/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/msp430/elf/package.xs:
package.mak: /home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/msp430/elf/package.xs
package.mak: package.bld
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/tools/configuro/template/compiler.opt.xdt:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/tools/configuro/template/compiler.opt.xdt
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/services/io/File.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/services/io/File.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/services/io/package.xs:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/services/io/package.xs
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/tools/configuro/template/compiler.defs.xdt:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/tools/configuro/template/compiler.defs.xdt
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/tools/configuro/template/custom.mak.exe.xdt:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/tools/configuro/template/custom.mak.exe.xdt
/home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/tools/configuro/template/package.xs.xdt:
package.mak: /home/vagrant/ccs/xdctools_3_31_00_24_core/packages/xdc/tools/configuro/template/package.xs.xdt
endif

ti.targets.msp430.elf.MSP430X.rootDir ?= /home/vagrant/ccs/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3
ti.targets.msp430.elf.packageBase ?= /home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/msp430/elf/
.PRECIOUS: $(XDCCFGDIR)/%.oe430X
.PHONY: all,e430X .dlls,e430X .executables,e430X test,e430X
all,e430X: .executables,e430X
.executables,e430X: .libraries,e430X
.executables,e430X: .dlls,e430X
.dlls,e430X: .libraries,e430X
.libraries,e430X: .interfaces
	@$(RM) $@
	@$(TOUCH) "$@"

.help::
	@$(ECHO) xdc test,e430X
	@$(ECHO) xdc .executables,e430X
	@$(ECHO) xdc .libraries,e430X
	@$(ECHO) xdc .dlls,e430X


all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.inc package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.inc package/%_xconfig_gpiointerrupt_msp430f5529.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package xconfig_gpiointerrupt_msp430f5529" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

.dlls,e430X .dlls: gpiointerrupt_msp430f5529.pe430X

-include package/cfg/gpiointerrupt_msp430f5529_pe430X.mak
-include package/cfg/gpiointerrupt_msp430f5529_pe430X.cfg.mak
ifeq (,$(MK_NOGENDEPS))
-include package/cfg/gpiointerrupt_msp430f5529_pe430X.dep
endif
gpiointerrupt_msp430f5529.pe430X: package/cfg/gpiointerrupt_msp430f5529_pe430X.xdl
	@


ifeq (,$(wildcard .libraries,e430X))
gpiointerrupt_msp430f5529.pe430X package/cfg/gpiointerrupt_msp430f5529_pe430X.c: .libraries,e430X
endif

package/cfg/gpiointerrupt_msp430f5529_pe430X.c package/cfg/gpiointerrupt_msp430f5529_pe430X.h package/cfg/gpiointerrupt_msp430f5529_pe430X.xdl: override _PROG_NAME := gpiointerrupt_msp430f5529.xe430X
package/cfg/gpiointerrupt_msp430f5529_pe430X.c: package/cfg/gpiointerrupt_msp430f5529_pe430X.cfg
package/cfg/gpiointerrupt_msp430f5529_pe430X.xdc.inc: package/cfg/gpiointerrupt_msp430f5529_pe430X.xdl
package/cfg/gpiointerrupt_msp430f5529_pe430X.xdl package/cfg/gpiointerrupt_msp430f5529_pe430X.c: .interfaces

clean:: clean,e430X
	-$(RM) package/cfg/gpiointerrupt_msp430f5529_pe430X.cfg
	-$(RM) package/cfg/gpiointerrupt_msp430f5529_pe430X.dep
	-$(RM) package/cfg/gpiointerrupt_msp430f5529_pe430X.c
	-$(RM) package/cfg/gpiointerrupt_msp430f5529_pe430X.xdc.inc

clean,e430X::
	-$(RM) gpiointerrupt_msp430f5529.pe430X
.executables,e430X .executables: gpiointerrupt_msp430f5529.xe430X

gpiointerrupt_msp430f5529.xe430X: |gpiointerrupt_msp430f5529.pe430X

-include package/cfg/gpiointerrupt_msp430f5529.xe430X.mak
gpiointerrupt_msp430f5529.xe430X: package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X 
	$(RM) $@
	@$(MSG) lnke430X $@ ...
	$(RM) $(XDCCFGDIR)/$@.map
	$(ti.targets.msp430.elf.MSP430X.rootDir)/bin/lnk430 -w -q -u _c_int00 -fs $(XDCCFGDIR)$(dir $@)  -q -o $@ package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X   package/cfg/gpiointerrupt_msp430f5529_pe430X.xdl  -c -m $(XDCCFGDIR)/$@.map -l $(ti.targets.msp430.elf.MSP430X.rootDir)/lib/libc.a
	
gpiointerrupt_msp430f5529.xe430X: export C_DIR=
gpiointerrupt_msp430f5529.xe430X: PATH:=$(ti.targets.msp430.elf.MSP430X.rootDir)/bin/:$(PATH)

gpiointerrupt_msp430f5529.test test,e430X test: gpiointerrupt_msp430f5529.xe430X.test

gpiointerrupt_msp430f5529.xe430X.test:: gpiointerrupt_msp430f5529.xe430X
ifeq (,$(_TESTLEVEL))
	@$(MAKE) -R -r --no-print-directory -f $(XDCROOT)/packages/xdc/bld/xdc.mak _TESTLEVEL=1 gpiointerrupt_msp430f5529.xe430X.test
else
	@$(MSG) running $<  ...
	$(call EXEC.gpiointerrupt_msp430f5529.xe430X, ) 
endif

clean,e430X::
	-$(RM) $(wildcard .tmp,gpiointerrupt_msp430f5529.xe430X,*)


clean:: clean,e430X

clean,e430X::
	-$(RM) gpiointerrupt_msp430f5529.xe430X
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@
gpiointerrupt_msp430f5529_pe430X.oe430X,copy : package/cfg/gpiointerrupt_msp430f5529_pe430X.oe430X
gpiointerrupt_msp430f5529_pe430X.se430X,copy : package/cfg/gpiointerrupt_msp430f5529_pe430X.se430X

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg $(XDCROOT)/packages/xdc/cfg/Main.xs | .interfaces
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,xconfig_gpiointerrupt_msp430f5529
ifeq (,$(MK_NOGENDEPS))
-include package/rel/xconfig_gpiointerrupt_msp430f5529.tar.dep
endif
package/rel/xconfig_gpiointerrupt_msp430f5529/xconfig_gpiointerrupt_msp430f5529/package/package.rel.xml: package/package.bld.xml
package/rel/xconfig_gpiointerrupt_msp430f5529/xconfig_gpiointerrupt_msp430f5529/package/package.rel.xml: package/build.cfg
package/rel/xconfig_gpiointerrupt_msp430f5529/xconfig_gpiointerrupt_msp430f5529/package/package.rel.xml: package/package.xdc.inc
package/rel/xconfig_gpiointerrupt_msp430f5529/xconfig_gpiointerrupt_msp430f5529/package/package.rel.xml: .force
	@$(MSG) generating external release references $@ ...
	$(XS) $(JSENV) -f $(XDCROOT)/packages/xdc/bld/rel.js $(MK_RELOPTS) . $@

xconfig_gpiointerrupt_msp430f5529.tar: package/rel/xconfig_gpiointerrupt_msp430f5529.xdc.inc package/rel/xconfig_gpiointerrupt_msp430f5529/xconfig_gpiointerrupt_msp430f5529/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELTAR,package/rel/xconfig_gpiointerrupt_msp430f5529.xdc.inc,package/rel/xconfig_gpiointerrupt_msp430f5529.tar.dep)


release release,xconfig_gpiointerrupt_msp430f5529: all xconfig_gpiointerrupt_msp430f5529.tar
clean:: .clean
	-$(RM) xconfig_gpiointerrupt_msp430f5529.tar
	-$(RM) package/rel/xconfig_gpiointerrupt_msp430f5529.xdc.inc
	-$(RM) package/rel/xconfig_gpiointerrupt_msp430f5529.tar.dep

clean:: .clean
	-$(RM) .libraries $(wildcard .libraries,*)
clean:: 
	-$(RM) .dlls $(wildcard .dlls,*)
#
# The following clean rule removes user specified
# generated files or directories.
#

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(wildcard package))
    $(shell $(MKDIR) package)
endif
ifeq (,$(wildcard package/cfg))
    $(shell $(MKDIR) package/cfg)
endif
ifeq (,$(wildcard package/lib))
    $(shell $(MKDIR) package/lib)
endif
ifeq (,$(wildcard package/rel))
    $(shell $(MKDIR) package/rel)
endif
ifeq (,$(wildcard package/internal))
    $(shell $(MKDIR) package/internal)
endif
endif
clean::
	-$(RMDIR) package

include custom.mak
