#if !defined(SPRITES_H)
#define SPRITES_H

#include "dsgbalib/gba.h"
#include "engine/math/vectors.h"

void spr_init();
void spr_clear_sprite(OAMSprite* sprite);

OAMSprite* spr_init_sprite(uint8_t tile_id, uint8_t palette_id, Vec2_uint8* pos, uint8_t size);

void spr_load_sprite_data(uint16_t* sprites, uint16_t size);

OAMSprite* spr_get_sprite(uint8_t id);

void spr_update_sprite_tile(OAMSprite* sprite, uint8_t tile_idx);
void spr_update_sprite_palette(OAMSprite* sprite, uint8_t palette_idx);
void spr_update_sprite_position(OAMSprite* sprite, Vec2_uint8* pos);

void spr_flip_h(OAMSprite* sprite, bool flip);
void spr_flip_v(OAMSprite* sprite, bool flip);

void spr_dma_sprite_oam();

#endif // SPRITES_H
