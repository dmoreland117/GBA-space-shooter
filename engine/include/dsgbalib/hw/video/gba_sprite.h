#if !defined(GBA_SPRITE_H)
#define GBA_SPRITE_H

#include "../../types.h"

typedef struct
{
    uint16_t attr0;
    uint16_t attr1;
    uint16_t attr2;
    uint16_t attr3;
} OAMSprite;

#define OAM_ATTR0_ROT_SCALE_ENABLE   (1 << 8),
#define OAM_ATTR0_OVERFLOW_ENABLE    (1 << 9), // i think this is right
#define OAM_ATTR0_MOSAIC_ENABLE      (1 << 12),
#define OAM_ATTR0_256_COLOR          (1 << 13),

enum OAMSpriteModes {
    OAM_ATTR0_MODE_NORMAL,
    OAM_ATTR0_MODE_SIMI_TRANSEPARENT,
    OAM_ATTR0_MODE_WINDOW,
};

#define OAM_ATTR0_MODE(mode) (mode) << 10

#define OAM_ATTR1_H_FLIP (1 << 12)
#define OAM_ATTR1_V_FLIP (1 << 13)

#define OAM_ATTR0_SIZE(s) (((s) >> 2) << 14)
#define OAM_ATTR1_SIZE(s) ((s) << 14)

enum SpriteSizes 
{
    OAM_SPR_SIZE_8x8,
    OAM_SPR_SIZE_16x16,
    OAM_SPR_SIZE_32x32,
    OAM_SPR_SIZE_64x64,
    OAM_SPR_SIZE_16x8,
    OAM_SPR_SIZE_32x8,
    OAM_SPR_SIZE_32x16,
    OAM_SPR_SIZE_64x32,
    OAM_SPR_SIZE_8x16,
    OAM_SPR_SIZE_8x32,
    OAM_SPR_SIZE_16x32,
    OAM_SPR_SIZE_32x64  ,
};

#define OAM_ATTR2_PRIORITY(p) (p) << 10
#define OAM_ATTR2_PALETTE(p) (p) << 12



#endif // GBA_SPRITE_H
