#if !defined(GBA_BACKGROUNDS_H)
#define GBA_BACKGROUNDS_H

#include "../types.h"


#define GBA_BG_REG_BASE 0x04000008

#define REG_BG0CNT    *((volatile uint16_t*)GBA_BG_REG_BASE)
#define REG_BG1CNT    *((volatile uint16_t*)GBA_BG_REG_BASE + 1)
#define REG_BG2CNT    *((volatile uint16_t*)GBA_BG_REG_BASE + 2)
#define REG_BG3CNT    *((volatile uint16_t*)GBA_BG_REG_BASE + 3)

#define REG_BG0_H_OFS    *((volatile uint16_t*)GBA_BG_REG_BASE + 4)
#define REG_BG0_V_OFS    *((volatile uint16_t*)GBA_BG_REG_BASE + 5)
#define REG_BG1_H_OFS    *((volatile uint16_t*)GBA_BG_REG_BASE + 6)
#define REG_BG1_V_OFS    *((volatile uint16_t*)GBA_BG_REG_BASE + 7)
#define REG_BG2_H_OFS    *((volatile uint16_t*)GBA_BG_REG_BASE + 8)
#define REG_BG2_V_OFS    *((volatile uint16_t*)GBA_BG_REG_BASE + 9)
#define REG_BG3_H_OFS    *((volatile uint16_t*)GBA_BG_REG_BASE + 10)
#define REG_BG3_V_OFS    *((volatile uint16_t*)GBA_BG_REG_BASE + 11)

// BG FLAGS
#define BG_16_COLOR (0 << 7)
#define BG_256_COLOR (1 << 7)

#define SCREEN_BASE(m)	((m) << 8)

#define MAP_ATTRIB_H_FLIP BIT(0xA)
#define MAP_ATTRIB_V_FLIP BIT(0xB)
#define MAP_ATTRIB_PALETTE(p) ((p) << 0xC)

#define	CHAR_BASE(m)		((m) << 2)

#define VRAM 0x06000000

#define SCREEN_BASE_BLOCK(n) ((uint16_t*)(VRAM + (n) * 0x800))
#define CHAR_BASE_BLOCK(m)	((void *)(VRAM + ((m) << 14)))


#endif // GBA_BACKGROUNDS_H
