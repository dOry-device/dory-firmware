
/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.platforms.msp430 package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


-l"/home/vagrant/dory-firmware/TIRTOStest/Debug/configPkg/package/cfg/empty_min_pe430X.oe430X"
-l"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/packages/ti/drivers/lib/drivers_MSP430F5529.ae430X"
-l"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/sysbios/fatfs/lib/release/ti.sysbios.fatfs.ae430X"
-l"/home/vagrant/dory-firmware/TIRTOStest/src/sysbios/sysbios.ae430X"
-l"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/catalog/msp430/init/lib/ti.catalog.msp430.init.ae430X"
-l"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/msp430/rts430/lib/ti.targets.msp430.rts430.ae430X"
-l"/home/vagrant/ccs/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/msp430/rts430/lib/boot.ae430X"

--retain="*(xdc.meta)"
--retain="*(xdc.noload)"


/* Elf symbols */
--symbol_map __TI_STACK_BASE=_stack
--symbol_map __TI_STACK_SIZE=_STACK_SIZE
--symbol_map __TI_STATIC_BASE=__bss__
--symbol_map __c_int00=_c_int00
--symbol_map __TI_cleanup_ptr=_cleanup_ptr
--symbol_map __TI_dtors_ptr=_dtors_ptr


--args 0x0
-heap  0x0
-stack 0x400

/*
 * Linker command file contributions from all loaded packages:
 */

/* Content from xdc.services.global (null): */

/* Content from xdc (null): */

/* Content from xdc.corevers (null): */

/* Content from xdc.shelf (null): */

/* Content from xdc.services.spec (null): */

/* Content from xdc.services.intern.xsr (null): */

/* Content from xdc.services.intern.gen (null): */

/* Content from xdc.services.intern.cmd (null): */

/* Content from xdc.bld (null): */

/* Content from ti.targets (null): */

/* Content from ti.targets.msp430.elf (null): */

/* Content from xdc.rov (null): */

/* Content from xdc.runtime (null): */

/* Content from xdc.services.getset (null): */

/* Content from ti.targets.msp430.rts430 (ti/targets/msp430/rts430/link.xdt): */

/* Definitions for ti.targets.msp430.rts430/boot.o* references:             */
/*     - ti_targets_msp430_rts430_noexit__I */
/*           defined in case main() returns in noexit variants              */
/*           of _c_int00.  Even in this case, we should call xdc.runtime    */
/*           exit processing; noexit only means that the RTS library's exit */
/*           handling is unnecessary.                                       */
--symbol_map ti_targets_msp430_rts430_noexit__I=xdc_runtime_System_exit__E

/* Content from ti.sysbios.interfaces (null): */

/* Content from ti.sysbios.family (null): */

/* Content from ti.sysbios.rts (ti/sysbios/rts/linkcmd.xdt): */

/* Content from xdc.runtime.knl (null): */

/* Content from xdc.platform (null): */

/* Content from ti.catalog.msp430 (null): */

/* Content from ti.catalog (null): */

/* Content from ti.catalog.msp430.init (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.catalog.msp430.peripherals.interrupt (null): */

/* Content from ti.catalog.msp430.peripherals.special_function (null): */

/* Content from ti.catalog.msp430.peripherals.timer (null): */

/* Content from ti.catalog.msp430.peripherals.watchdog (null): */

/* Content from ti.catalog.msp430.peripherals.clock (null): */

/* Content from ti.platforms.msp430 (null): */

/* Content from ti.sysbios (null): */

/* Content from ti.sysbios.fatfs (null): */

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sysbios.family.msp430 (null): */

/* Content from ti.drivers (null): */

/* Content from ti.tirtos (null): */

/* Content from ti.sysbios.gates (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sysbios.utils (null): */

/* Content from configPkg (null): */

/* Content from xdc.services.io (null): */

/* Content from ti.drivers.ports (null): */



/*
 * symbolic aliases for static instance objects
 */
xdc_runtime_Startup__EXECFXN__C = 1;
xdc_runtime_Startup__RESETFXN__C = 1;


SECTIONS
{



    xdc.meta: type = COPY
    xdc.noload: type = COPY
}

