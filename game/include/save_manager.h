#if !defined(SAVE_MANAGER_H)
#define SAVE_MANAGER_H

#include "dsgbalib/types.h"

#define SAVE_START 0x0E000000

#define SRAM ((volatile uint8_t*) SAVE_START)

typedef struct 
{
    uint16_t high_score;
} SaveData;

SaveData current_data;

static inline void save(SaveData* data)
{
    uint8_t* src = (uint8_t*)data;

    for (uint16_t i = 0; i < sizeof(SaveData); i++)
    {
        SRAM[i] = src[i];
    }
}

static inline SaveData* load_save()
{
    uint8_t* dst = (uint8_t*)&current_data;

    for (uint16_t i = 0; i < sizeof(SaveData); i++)
    {
        dst[i] = SRAM[i];
    }

    return &current_data;
}

#endif // SAVE_MANAGER_H
