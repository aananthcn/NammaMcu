# 
# Created on Thu Dec 23 2022 12:23:34 PM
# 
# The MIT License (MIT)
# Copyright (c) 2022 Aananth C N
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software
# and associated documentation files (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all copies or substantial
# portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
# COMPILER=arm-none-eabi-
CC=${COMPILER}gcc
LD=${COMPILER}ld
AS=${COMPILER}as
AR=${COMPILER}ar
RANLIB=${COMPILER}ranlib
OBJCOPY=${COMPILER}objcopy


include c_l_flags.mk # include the hand-modified local file
include ${ROOT_DIR}/path_defs.mk


INCDIRS  := -I ${MCU_PATH}/src/bsp/startup \
	    -I ${MCU_PATH}/src/bsp/startup/${BOARD_NAME} \
	    -I ${MCU_PATH}/api \
	    -I ${MCU_PATH}/src/common/api \
	    -I ${MCU_PATH}/src/bsp/startup/lib/include \
	    -I ${MCU_PATH}/src \
 	    -I ${MCU_PATH}/src/common \
 	    -I ${MCU_PATH}/src/common/api \
 	    -I ${MCU_PATH}/src/common/src \
	    -I ${MCU_STARTUP_PATH} \
	    -I ${OS_PATH}/include \
	    -I ${OS_BUILDER_PATH}/src
	    

LDFLAGS  := -nostdlib -g -relocatable
CFLAGS   := -Werror ${INCDIRS} -fPIC -g
ASFLAGS  := ${INCDIRS} -g 
TARGET 	 := libMcu_Startup.la
# include c_l_flags.mk to add more definitions specific to micro-controller
include ${ROOT_DIR}/c_l_flags.mk

$(info  )
$(info compiling ${BOARD_NAME} board specific files)


MCU_STARTUP_OBJS := \
	${MCU_STARTUP_PATH}/boot_stage2.o \
	${MCU_STARTUP_PATH}/board.o \
	${MCU_STARTUP_PATH}/vector_handlers.o \
	${MCU_STARTUP_PATH}/vectors.o \
	${MCU_STARTUP_PATH}/interrupt.o \
	${MCU_STARTUP_PATH}/startup.o \
	${MCU_STARTUP_PATH}/bootrom.o 


ARCH_OBJS	:= \
	${MCU_PATH}/src/bsp/arch/arm/cortex-m0/lowlevel.o \
	${MCU_PATH}/src/bsp/arch/arm/cortex-m0/interrupt.o


all: $(TARGET)

LIB_OBJS := $(MCU_STARTUP_OBJS) $(ARCH_OBJS)

$(TARGET): $(LIB_OBJS)
	$(LD) ${LDFLAGS} -o $@ $^

clean:
	$(RM) $(LIB_OBJS) $(TARGET)
 