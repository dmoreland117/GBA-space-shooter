DEVKITARM = /opt/devkitpro/devkitARM/bin/


RomName = space_shooter

EntityDirs = src/entities/player \
			 src/entities/bullet \
			 src/entities/enemy \

Sources = src src/data src/states src/entities $(EntityDirs)
Data 	= data data/image

OutPutDir = build
DataOutputDir = src/data

Includes = include ../engine/include src

LibDirs = ../engine/build
LibFiles = game

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

INCLUDES =  $(foreach inc,$(Includes), -I $(inc))
LIB_DIRS =  $(foreach dir,$(LibDirs), -L $(dir))
LIB_FILES = $(foreach file,$(LibFiles), -l$(file))

CFLAGS 	=  $(ARCH) -g $(WarnLevel) $(OptimizationLevel) $(INCLUDES) 
LDFLAGS =  $(ARCH) -T gba.ld -nostartfiles -nostdlib -Wl,-Map=project.map

TARGET 	 = $(OutPutDir)/$(RomName)
ELF_PATH = $(TARGET).elf
ROM_PATH = $(TARGET).gba

CFILES 	:= $(foreach dir,$(Sources),$(wildcard $(dir)/*.c))
SFILES 	:= $(foreach dir,$(Sources),$(wildcard $(dir)/*.s))
OSRCS 	:= $(CFILES:.c=.o) $(SFILES:.s=.o)

OFILES = $(foreach ofile,$(OSRCS), $(OutPutDir)/$(notdir $(ofile)))

PNGFILES := $(foreach dir,$(Data),$(wildcard $(dir)/*.png))
PNGDATAFILES = $(foreach pngfile,$(PNGFILES), $(DataOutputDir)/$(notdir $(pngfile)))
PNGSFILES = $(PNGDATAFILES:.png=.s)

VPATH = $(Sources) $(Data)


# Build target
all: $(OutPutDir) $(ROM_PATH)

$(ROM_PATH): $(ELF_PATH)
	@echo "Finishing Rom..."
	$(OBJCOPY) -O binary $< $@
	$(GBAFIX) $@
	@echo "Finished Rom..."

$(OutPutDir):
	@echo "Creating Build Dir: " $@
	@ $(MKDIR) $@

$(ELF_PATH): $(OFILES)
	@echo "Linking " $@
	@ $(CC) $(LDFLAGS) $^ $(LIB_DIRS) $(LIB_FILES) -o $@ 

$(OutPutDir)/%.o: %.c
	@echo "Compilling " $<
	@ $(CC) $(CFLAGS) -o $(OutPutDir)/$(notdir $@) -c $<

$(OutPutDir)/%.o: %.s
	@echo "Compilling " $<
	@ $(CC) $(CFLAGS) -o $(OutPutDir)/$(notdir $@) -c $<

assets: $(PNGSFILES)
	@echo "Building assets"

game/src/data/%.s: %.png
	@echo "Building asset " $<
	@ $(GRIT) $< -o $@ -gu 16 -gB 4 -ft c

palette:
	@ $(GRIT) data/image/tileset_tropical.png -p -g! -gu 16 -gB 4 -ft c

engine:
	$(MAKE) -C engine

clean:
	@echo "Cleaning..."

.PHONY: all clean assets engine