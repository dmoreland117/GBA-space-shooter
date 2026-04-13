#include "engine/video/palettes.h"
#include "dsgbalib/gba.h"

void pal_load_bg_data(uint16_t *colors, uint16_t count, uint8_t offset)
{
    DMA3CPY(colors, &BG_PALETTE[offset], count);
}
void pal_load_bg_data_slot(uint8_t slot, uint16_t *colors, uint16_t count)
{
    uint16_t* p = &BG_PALETTE[slot * 16];
    DMA3CPY(colors, p, count);
}
void pal_load_sprite_data(uint16_t *colors, uint16_t count, uint8_t offset)
{
    DMA3CPY(colors, &SPRITE_PALETTE[offset], count);
}

void pal_load_sprite_data_slot(uint8_t slot, uint16_t *colors, uint16_t count)
{
    DMA3CPY(colors, &SPRITE_PALETTE[slot * 16], count);
}
void pal_set_bg_color(uint8_t color_id, uint16_t color)
{
    BG_PALETTE[color_id] = color;
}

void pal_set_sprite_color(uint8_t color_id, uint16_t color)
{
    SPRITE_PALETTE[color_id] = color;
}
