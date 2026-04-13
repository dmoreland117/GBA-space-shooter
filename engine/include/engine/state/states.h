#if !defined(STATES_H)
#define STATES_H

#include "state.h"

void set_current_state(State* state);

void states_loop();
void states_break_loop();

#endif // STATES_H
