#if !defined(GBA_DISPLAY_H)
#define GBA_DISPLAY_H

#include "../types.h"

#define GBA_DISPLAY_REG_BASE 0x04000000


#define REG_DISPCNT     *(volatile uint16_t*)GBA_DISPLAY_REG_BASE

enum DISPCNT_MODES {
    MODE0 = 0,
    MODE1,
    MODE2,
    MODE3,
    MODE4,
    MODE5,
    MODE6
};

enum DISPCNT_BG_ENABLE {
    BG0_ENABLE          = (1 << 8),
    BG1_ENABLE          = (1 << 9),
    BG2_ENABLE          = (1 << 10),
    BG3_ENABLE          = (1 << 11),
};

enum DISPCNT_OBJ {
    SPRITES_LINEAR_ARRAY  = (1 << 6),
    DISPLAY_SPRITES       = (1 << 12)
};

#define BLANK_DISPLAY     (1 << 7)
#define ENABLE_OBJS       (1 << 12)


#define REG_DISPSTAT    *(volatile uint16_t*)GBA_DISPLAY_REG_BASE + 0x4

enum DISPSTAT_FLAGS {
    V_REFRESH_STATUS = (1 << 0),
    H_REFRESH_STATUS = (1 << 1),

};


#define REG_VCOUNT *((volatile uint16_t*)0x04000006)


#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 160

#endif // GBA_DISPLAY_H
