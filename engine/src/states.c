#include "engine/state/states.h"

#include "dsgbalib/types.h"
#define GBA_HW_IMPL
#include "dsgbalib/gba.h"

bool   _is_running;
State* _current_state;

static inline void wait_vblank(void)
{
    volatile uint16_t* vcount = (volatile uint16_t*)0x04000006;

    // Wait until NOT in VBlank
    while (*vcount >= 160);

    // Wait until IN VBlank
    while (*vcount < 160);
}

void set_current_state(State *state) 
{
    _current_state->destroy_callback();
    _current_state = state;
    state->init_callback();
}
void states_loop()
{
    _is_running = true;

    while (_is_running)
    {
        if (!_current_state) continue;

        wait_vblank();

        _current_state->update_callback();
        _current_state->draw_callback();
    }
    

}
void states_break_loop()
{
    _is_running = false;
}