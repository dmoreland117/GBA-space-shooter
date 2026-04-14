#if !defined(SAVE_MANAGER_H)
#define SAVE_MANAGER_H

#include "dsgbalib/types.h"

#define SAVE_START 0x0E000000

typedef struct 
{
    uint16_t high_score;
} SaveData;

#define SAVE_DATA ((SaveData*) SAVE_START)

#endif // SAVE_MANAGER_H
