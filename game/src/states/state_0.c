#include "state_0.h"

#include "../entities/player/scr_player.h"
#include "../entities/enemy/ent_enemy.h"

#include "memory_sections.h"
#include "text_renderer.h"

#include "data/space.h"
#include "data/ds_font.h"
#include "data/spritesheet_player_and_ammo.h"
#include "data/spritesheet_enemy.h"

#include "engine/video/backgrounds.h"
#include "engine/video/palettes.h"
#include "engine/video/sprites.h"
#include "engine/animation/animations.h"
#include "engine/entity/entities.h"
#include "engine/input/input.h"

STATES_TABLE State LEVEL_STATE = {
    .init_callback = state_0_init,
    .update_callback = state_0_update,
    .draw_callback = state_0_draw
};

const uint16_t FNT_PALL[] = 
{
    RGB15(0, 0, 0),
    RGB15(31, 40, 40)
};

uint16_t _last_spawn_time;

void _start_enemy_spawn_timer()
{
    _last_spawn_time = 0;

    REG_TM2_VAL = 0;
    REG_TM2_CNT = TIMER_SPEED_1024 | TIMER_ENABLE;
}

void _check_enemy_spawn_timer()
{
    uint16_t now = REG_TM2_VAL;

    if(now < _last_spawn_time)
    {
        _last_spawn_time = 0;
    }

    if ((now - _last_spawn_time) > ENEMY_SPAWN_TIMER_INTERVAL)
    { 
        entities_create_entity(&ENEMY_ENTITY, &(Vec2_uint16){((REG_VCOUNT * 123123) + 123) & 0x7fff, 0});
        _last_spawn_time = now;
    }
}

void state_0_init()
{
    REG_DISPCNT = 0;
    bg_init(0, 0, 24, 3, false);

    //pal_load_sprite_data(spritesheetPal, spritesheetPalLen >> 1, 0);
    pal_load_sprite_data_slot(PLAYER_PALETTE_SLOT, spritesheet_player_and_ammoPal, spritesheet_player_and_ammoPalLen  >> 1);
    pal_load_sprite_data_slot(ENEMY_PALETTE_SLOT, spritesheet_enemyPal, spritesheet_enemyPalLen  >> 1);
    pal_load_bg_data(spacePal, 16, 0);
    pal_load_bg_data_slot(15, FNT_PALL, 2);
    
    bg_load_tiles(spaceTiles, 0, sizeof(spaceTiles) >> 1);
    spr_load_sprite_data(PLAYER_TILES_OFFSET, spritesheet_player_and_ammoTiles, spritesheet_player_and_ammoTilesLen >> 1);
    spr_load_sprite_data(ENEMY_TILES_OFFSET << 5, spritesheet_enemyTiles, spritesheet_enemyTilesLen >> 1);
    
    bg_load_map(spaceMap, 24, spaceMapLen >> 1);

    text_init(2, 1, 25, 15);
    text_load_font(ds_fontTiles, ds_fontTilesLen >> 1);
    
    _start_enemy_spawn_timer();

    entities_init();

    RuntimeEntity* e = entities_create_entity(&PLAYER_ENTITY, &(Vec2_uint16){0, 0});
}
void state_0_update()
{
    entities_check_collisions();
    entities_update(); 
    anims_update();

    _check_enemy_spawn_timer();
}
void state_0_draw()
{
    input_update();
    entties_draw();
    anims_draw();
    spr_dma_sprite_oam();
}