#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile that supports host machie and MSP432
#
# Use: make [TARGET] [PLATFORM=HOST|MSP432]
#
# Build Targets:
#      %.i - preprocessor output
#      %.asm - assembly output of c-program or final output
#      %.o - object file of a .c
#      compile-all - compiles all .o without linking
#      build - compiles all .o, links them and pruduces a final output
#      clean - deletes all generated files
#
# Platform Overrides:
#      PLATFORM=HOST   - native gcc
#      PLATFORM=MSP432 - cross compiler arm-none-eabi-gcc
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST

TARGET = c1final

ifeq ($(PLATFORM),MSP432)
    # Architectures Specific Flags
    LINKER_FILE = msp432p401r.lds
    CPU = cortex-m4
    ARCH = armv7e-m
    SPECS = nosys.specs
    ARCHFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) \
                  -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)

    # Compiler Flags and Defines
    CC = arm-none-eabi-gcc
    LD = arm-none-eabi-ld
    LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
    CPPFLAGS = -DMSP432 $(INCLUDES)

else
    # Compiler Flags and Defines
    CC      = gcc
    LD      = ld
    LDFLAGS  = -Wl,-Map=$(TARGET).map
    CPPFLAGS = -DHOST $(INCLUDES)

endif

# Compile time switches
CPPFLAGS += -DCOURSE1 -DVERBOSE

CFLAGS = -Wall -Werror -g -O0 -std=c99 $(ARCHFLAGS) #applies for both platforms

ifeq ($(PLATFORM),MSP432) #ignores some warnings from interrupts_msp432p401r_gcc.c
  CFLAGS += -Wno-error=attributes
endif

OBJS = $(SOURCES:.c=.o)
DEPS = $(OBJS:.o=.d)

# RULES
# =================

# Preprocessor output
%.i: %.c
	$(CC) -E $(CPPFLAGS) $(CFLAGS) $< -o $@

# Assembly output of a .c
%.asm: %.c
	$(CC) -S $(CPPFLAGS) $(CFLAGS) $< -o $@

# Assembly of an output file
%.asm: %.out
	objdump -d $< > $@

# Object file + dependencies
%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -MD -MP $< -o $@

# compile all
.PHONY: compile-all
compile-all: $(OBJS)

# build
.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@
	size $@

# clean
.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(SOURCES:.c=.i) $(SOURCES:.c=.asm) \
	      $(TARGET).out $(TARGET).map $(TARGET).asm

-include $(DEPS)

