#include "engine/video/backgrounds.h"
#include "engine/video/palettes.h"
#include "engine/video/sprites.h"
#include "states/state_0.h"
#include "engine/animation/animations.h"
#include "engine/entity/entities.h"
#include "engine/input/input.h"
#include "data/tileset.h"
#include "data/space.h"
#include "data/spritesheet.h"
#include "memory_sections.h"
#include "text_renderer.h"
#include "data/ds_font.h"

extern const EntityData PLAYER_ENTITY;
extern const EntityData ENEMY_ENTITY;

STATES_TABLE State START_STATE = {
    .init_callback = state_0_init,
    .update_callback = state_0_update,
    .draw_callback = state_0_draw
};

const uint16_t FNT_PAL[] = 
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
        entities_create_entity(&ENEMY_ENTITY, &(Vec2_uint16){REG_VCOUNT & 0xFF, 0});
        _last_spawn_time = now;
    }
}

void state_0_init()
{
    REG_DISPCNT = 0;
    bg_init(0, 0, 24, 3, false);

    pal_load_sprite_data(spritesheetPal, spritesheetPalLen >> 1, 0);
    pal_load_bg_data(spacePal, 16, 0);
    pal_load_bg_data_slot(15, FNT_PAL, 2);
    
    bg_load_tiles(spaceTiles, 0, sizeof(spaceTiles) >> 1);
    spr_load_sprite_data(spritesheetTiles, spritesheetTilesLen >> 1);
    
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