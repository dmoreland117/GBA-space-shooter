#if !defined(GBA_PALETTES_H)
#define GBA_PALETTES_H

#include "../types.h"


#define BG_PALETTE ((volatile uint16_t*)0x05000000)
#define SPRITE_PALETTE ((volatile uint16_t*)0x05000200)

#define PALETTE_BANK(n) (n) * 16

/* GBA RGB format: 0BBBBBGGGGGRRRRR */
#define RGB15(r,g,b) ((r) | ((g)<<5) | ((b)<<10))

#endif // GBA_PALETTES_H
