#include "text_renderer.h"

#include "engine/video/backgrounds.h"

#include "dsgbalib/gba.h"

EWRAM_BSS uint8_t _charbase;
EWRAM_BSS uint8_t _mapbase;
EWRAM_BSS uint8_t _palette;

void text_init(uint8_t bg, uint8_t charbase, uint8_t mapbase, uint8_t palette)
{
    bg_init(bg, charbase, mapbase, 0, false);
    _charbase = charbase;
    _mapbase = mapbase;
    _palette = palette;
}
void text_load_font(uint16_t *fnt, uint16_t size_words)
{
    uint16_t* charbase = CHAR_BASE_BLOCK(_charbase);
    DMA3CPY(fnt, charbase, size_words);
}

void draw_string(Vec2_uint8 *pos, char * string)
{
    uint16_t map_idx = pos->x + (pos->y * 32);
    uint16_t offset = 0;

    uint16_t* mapbase = SCREEN_BASE_BLOCK(_mapbase);

    char c = string[offset];
    while (c)
    {
        uint16_t attr = (c - ASCII_OFFSET) | MAP_ATTRIB_PALETTE(_palette);
        mapbase[offset + map_idx] = attr;
        offset++;
        c = string[offset];
    }
    

}

void int_to_string(uint32_t value, char *buffer)
{
    int divisors[] = {10000, 1000, 100, 10, 1};
    int started = 0;

    if (value == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        int divisor = divisors[i];
        int digit = 0;

        while (value >= divisor)
        {
            value -= divisor;
            digit++;
        }

        if (digit > 0 || started)
        {
            *buffer++ = '0' + digit;
            started = 1;
        }
    }

    *buffer = '\0';
}
