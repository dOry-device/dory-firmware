################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../MSP_EXP430F5529LP.cmd 

CFG_SRCS += \
../empty_min.cfg 

C_SRCS += \
../MSP_EXP430F5529LP.c \
../doryGPIO.c \
../doryI2C.c \
../doryUART.c \
../empty_min.c 

OBJS += \
./MSP_EXP430F5529LP.obj \
./doryGPIO.obj \
./doryI2C.obj \
./doryUART.obj \
./empty_min.obj 

C_DEPS += \
./MSP_EXP430F5529LP.pp \
./doryGPIO.pp \
./doryI2C.pp \
./doryUART.pp \
./empty_min.pp 

GEN_MISC_DIRS += \
./configPkg/ 

GEN_CMDS += \
./configPkg/linker.cmd 

GEN_OPTS += \
./configPkg/compiler.opt 

GEN_FILES += \
./configPkg/linker.cmd \
./configPkg/compiler.opt 

GEN_FILES__QUOTED += \
"configPkg/linker.cmd" \
"configPkg/compiler.opt" 

GEN_MISC_DIRS__QUOTED += \
"configPkg/" 

C_DEPS__QUOTED += \
"MSP_EXP430F5529LP.pp" \
"doryGPIO.pp" \
"doryI2C.pp" \
"doryUART.pp" \
"empty_min.pp" 

OBJS__QUOTED += \
"MSP_EXP430F5529LP.obj" \
"doryGPIO.obj" \
"doryI2C.obj" \
"doryUART.obj" \
"empty_min.obj" 

C_SRCS__QUOTED += \
"../MSP_EXP430F5529LP.c" \
"../doryGPIO.c" \
"../doryI2C.c" \
"../doryUART.c" \
"../empty_min.c" 

GEN_CMDS__FLAG += \
-l"./configPkg/linker.cmd" 

GEN_OPTS__FLAG += \
--cmd_file="./configPkg/compiler.opt" 


