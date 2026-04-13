DEVKITARM = /opt/devkitpro/devkitARM/bin/


LibName = game

Sources = src
Data 	= data

OutPutDir = build
DataOutputDir = src/data

Includes = include

WarnLevel = -Wall
OptimizationLevel = 

# Compiler and flags
CC = $(DEVKITARM)arm-none-eabi-gcc
AS = $(DEVKITARM)arm-none-eabi-as
AR = $(DEVKITARM)arm-none-eabi-ar
OBJCOPY = $(DEVKITARM)arm-none-eabi-objcopy
GBAFIX 	= /opt/devkitpro/tools/bin/gbafix
GRIT 	= /opt/devkitpro/tools/bin/grit
MKDIR 	= mkdir -p

ARCH = -mthumb -mthumb-interwork -mcpu=arm7tdmi -mtune=arm7tdmi

INCLUDES = $(foreach inc,$(Includes), -I $(inc))

CFLAGS 	=  $(ARCH) -g $(WarnLevel) $(OptimizationLevel) $(INCLUDES) 
LDFLAGS =  $(ARCH) -T gba.ld -nostartfiles -nostdlib

TARGET 	 = $(OutPutDir)/lib$(LibName)
LIB_PATH = $(TARGET).a

CFILES 	:= $(foreach dir,$(Sources),$(wildcard $(dir)/*.c))
SFILES 	:= $(foreach dir,$(Sources),$(wildcard $(dir)/*.s))
OSRCS 	:= $(CFILES:.c=.o) $(SFILES:.s=.o)

OFILES = $(foreach ofile,$(OSRCS), $(OutPutDir)/$(notdir $(ofile)))

VPATH = $(Sources) $(Data)


# Build target
all: $(OutPutDir) $(LIB_PATH)

$(OutPutDir):
	@echo "Creating Build Dir: " $@
	@ $(MKDIR) $@

$(LIB_PATH): $(OFILES)
	@echo "Linking " $@
	@ $(AR) rcs $@ $^

$(OutPutDir)/%.o: %.c
	@echo "Compilling " $<
	@ $(CC) $(CFLAGS) -o $(OutPutDir)/$(notdir $@) -c $<

$(OutPutDir)/%.o: %.s
	@echo "Compilling " $<
	@ $(CC) $(CFLAGS) -o $(OutPutDir)/$(notdir $@) -c $<

clean:
	@echo "Cleaning..."

.PHONY: all clean assets