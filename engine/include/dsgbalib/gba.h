#if !defined(GBA_H)
#define GBA_H

/*
    --- LOW LEVEL ---
*/
#include "hw/gba_display.h"
#include "hw/gba_backgrounds.h"
#include "hw/gba_palettes.h"
#include "hw/gba_dma.h"
#include "hw/gba_oam.h"
#include "hw/gba_inputs.h"
#include "hw/gba_timers.h"

#include "hw/video/gba_dma_copy.h"
#include "hw/video/gba_sprite.h"

#define IWRAM_DATA __attribute__((section(".iwram_data")))
#define IWRAM_BSS __attribute__((section(".iwram_bss")))

#define EWRAM_DATA __attribute__((section(".ewram_data")))
#define EWRAM_BSS __attribute__((section(".ewram_bss")))



#endif // GBA_H
