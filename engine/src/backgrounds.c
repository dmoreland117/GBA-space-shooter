#include "engine/video/backgrounds.h"
#include "dsgbalib/gba.h"


void bg_init(uint8_t bg, uint8_t charblock, uint8_t screenblock, uint8_t priority, bool mode256)
{
    priority &= 0x3; // clamp to 3

    REG_DISPCNT |= (BG0_ENABLE << bg);
    volatile uint16_t* bg_ptr = &REG_BG0CNT;
    bg_ptr[bg] = priority | CHAR_BASE(charblock) | SCREEN_BASE(screenblock);
}

void bg_deinit(uint8_t bg)
{
}

void bg_load_tiles(const uint16_t *tiles, uint8_t charblock, uint32_t size_words)
{
    uint16_t* charbase = CHAR_BASE_BLOCK(charblock);

    DMA3CPY(tiles, charbase, size_words);
}

void bg_load_map(const uint16_t *map, uint8_t screenblock, uint32_t size_words)
{
    uint16_t* mapbase = SCREEN_BASE_BLOCK(screenblock);

    DMA3CPY(map, mapbase, size_words);
}

void bg_set_scroll(uint8_t bg, uint16_t x, uint16_t y)
{
}

void bg_set_tile(uint8_t screenblock, Vec2_uint8 pos, uint16_t tile_id, uint8_t palette, uint8_t flags)
{
}

uint16_t bg_get_tile(uint8_t screenblock, Vec2_uint8 pos)
{
    return 0;
}

uint16_t bg_get_attr(uint8_t screenblock, Vec2_uint8 pos)
{
    return 0;
}

void bg_set_attr(uint8_t screenblock, Vec2_uint8 pos, uint16_t attr)
{
}
