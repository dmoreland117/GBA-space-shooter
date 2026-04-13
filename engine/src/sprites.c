#include "engine/video/sprites.h"

OAMSprite _shadow_oam[MAX_OAM_OBJ];

void spr_init()
{
}

OAMSprite* spr_init_sprite(uint8_t tile_id, uint8_t palette_id, Vec2_uint8* pos, uint8_t size)
{
    for (uint8_t i = 0; i < MAX_OAM_OBJ; i++)
    {
        OAMSprite* s = &_shadow_oam[i];
        if ((s->attr2 & 0x00FF)) continue;
        
        s->attr0 = pos->y;
        s->attr1 = pos->x | OAM_ATTR1_SIZE(size);
        s->attr2 = tile_id | OAM_ATTR2_PALETTE(palette_id);
    
        return s;
    }

    return nullptr;
}

void spr_clear_sprite(OAMSprite* sprite)
{
    sprite->attr0 = 0;
    sprite->attr1 = 0;
    sprite->attr2 = 0;
    sprite->attr3 = 0;
}
void spr_load_sprite_data(uint16_t *sprites, uint16_t size)
{
    DMA3CPY(sprites, SPRITES, size);
}
OAMSprite *spr_get_sprite(uint8_t id)
{
    return &_shadow_oam[id];
}
void spr_update_sprite_tile(OAMSprite* sprite, uint8_t tile_id)
{
    sprite->attr2 &= 0xFF00;
    sprite->attr2 |= tile_id;
}
void spr_update_sprite_position(OAMSprite* sprite, Vec2_uint8* pos)
{
    sprite->attr0 &= 0xFF00;
    sprite->attr1 &= 0xFF00;

    sprite->attr0 |= pos->y;
    sprite->attr1 |= pos->x;
}
void spr_flip_h(OAMSprite* sprite, bool flip)
{
    if (flip)
    {
        sprite->attr1 |= OAM_ATTR1_H_FLIP;
    } else {
        sprite->attr1 &= ~OAM_ATTR1_H_FLIP;
    }
}
void spr_flip_v(OAMSprite* sprite, bool flip)
{
    if (flip)
    {
        sprite->attr1 |= OAM_ATTR1_V_FLIP;
    } else {
        sprite->attr1 &= ~OAM_ATTR1_V_FLIP;
    }
}
void spr_dma_sprite_oam()
{
    DMA3CPY(_shadow_oam, OAM, sizeof(_shadow_oam) >> 1);
}
