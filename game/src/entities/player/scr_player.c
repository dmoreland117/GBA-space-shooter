#include "scr_player.h"
#include "../bullet/ent_bullet.h"

#include "player_anims.h"

#include "text_renderer.h"
#include "save_manager.h"

#include "engine/input/input.h"
#include "engine/animation/animations.h"
#include "engine/entity/entities.h"

EWRAM_BSS char _score_str_buffer[8];
EWRAM_BSS char _high_score_str_buffer[8];

EWRAM_BSS uint8_t _selected_bullet;

void player_init(RuntimeEntity* this)
{
    entities_set_flags(
        this, 
        RT_ENTITY_FLAG_DRAW | 
        RT_ENTITY_FLAG_PROCESS_PHYSICS | 
        RT_ENTITY_FLAG_PROCESS_UPDATE | 
        RT_ENTITY_FLAG_DRAW | 
        RT_ENTITY_FLAG_COLLISION
    );

    this->screen_position.y = TO_FIX(150 - PLAYER_SIZE_Y);
    this->screen_position.x = TO_FIX((240 >> 1) - PLAYER_SIZE_X);
    
    Vec2_uint8 sp;
    sp.x = FROM_FIX(this->screen_position.x);
    sp.y = FROM_FIX(this->screen_position.y);
    
    this->oam_attribs = spr_init_sprite(1, 0, &sp, OAM_SPR_SIZE_16x16);
    
    PlayerVars* pv = (PlayerVars*)this->data;
    pv->health = 100;
    pv->score = 0;

    _selected_bullet = 0;
    
    SaveData* sd = load_save();

    int_to_string(sd->high_score, _high_score_str_buffer);
    draw_string(&(Vec2_uint8){32 - 7, 2}, _high_score_str_buffer);

    draw_string(&(Vec2_uint8){30 - 8, 20 - 2}, BULLET_NAMES[_selected_bullet]);
    draw_string(&(Vec2_uint8){1 - 8, 20 - 2}, BULLET_NAMES[_selected_bullet]);
}

void player_destroy(RuntimeEntity *this)
{

}

void player_update(RuntimeEntity* this)
{
    bool moving = false;
    
    // --- INPUT ---
    if (input_is_key_pressed(KEY_RIGHT))
    {
        moving = true;
        this->velocity.x += PLAYER_ACCELERATION;
    }

    if (input_is_key_pressed(KEY_LEFT))
    {
        moving = true;
        this->velocity.x -= PLAYER_ACCELERATION;
    }
    if (input_is_key_just_pressed(KEY_B))
    {
        _selected_bullet++;

        if (_selected_bullet >= 3)
        {
            _selected_bullet = 0;
        }

        draw_string(&(Vec2_uint8){30 - 12, 20 - 2}, "         ");
        draw_string(&(Vec2_uint8){30 - 8, 20 - 2}, BULLET_NAMES[_selected_bullet]);
    }
    if (input_is_key_just_pressed(KEY_A))
    {
        Vec2_uint16 p;
        p.x = FROM_FIX(this->screen_position.x);
        p.y = FROM_FIX(this->screen_position.y);
        
        entities_create_entity(BULLET_ENTITIES[_selected_bullet], &p);
    }
    
    // --- FRICTION ---
    if (!moving)
    {
        if (this->velocity.x > 0)
        {
            this->velocity.x -= PLAYER_ACCELERATION;
            if (this->velocity.x < 0)
                this->velocity.x = 0;
        }
        else if (this->velocity.x < 0)
        {
            this->velocity.x += PLAYER_ACCELERATION;
            if (this->velocity.x > 0)
                this->velocity.x = 0;
        }
    }

    // --- CLAMP ---
    if (this->velocity.x > PLAYER_MAX_SPEED)
        this->velocity.x = PLAYER_MAX_SPEED;

    if (this->velocity.x < -PLAYER_MAX_SPEED)
        this->velocity.x = -PLAYER_MAX_SPEED;
    
    if (FROM_FIX(this->screen_position.x) < PLAYER_MIN_X)
    {
        this->screen_position.x = TO_FIX(PLAYER_MIN_X);
        this->velocity.x = 0;
    }

    if (FROM_FIX(this->screen_position.x) > PLAYER_MAX_X)
    {
        this->screen_position.x = TO_FIX(PLAYER_MAX_X);
        this->velocity.x = 0;
    }

    PlayerVars* pv = (PlayerVars*)this->data;
    int_to_string(pv->score, _score_str_buffer);

    draw_string(&(Vec2_uint8){32 - 7, 1}, _score_str_buffer);
}
void player_collide(RuntimeEntity* this, RuntimeEntity* e1)
{
    if (e1->id == ENEMY_ID)
    {
        PlayerVars* pv = (PlayerVars*)this->data;
        SaveData sd = {
            .high_score = pv->score
        };

        save(&sd);

        entities_free_entity(this);
    }
}

ENTITY_VTABLE(
    SCR_PLAYER_VTABLE,
    player_init,
    player_update,
    0x00,
    player_collide,
    player_destroy
)
ENTITY_DATA(
    PLAYER_ID, PLAYER_ENTITY, SCR_PLAYER_VTABLE,
    PLAYER_SIZE_X, PLAYER_SIZE_Y,
    0
)