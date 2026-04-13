#if !defined(TYPES_H)
#define TYPES_H

typedef signed char int8_t;
typedef unsigned char uint8_t;

#define INT8_MAX 0xFF

// Define 16-bit types
typedef signed short int16_t;
typedef unsigned short uint16_t;

#define INT16_MAX 0xFFFF


// Define 32-bit types
// Use 'long' if 'int' is 16-bit, use 'int' if 'int' is 32-bit for optimization
// The below uses 'long' as a general example for older/smaller systems
typedef signed long int32_t;
typedef unsigned long uint32_t;

#define INT32_MAX 0xFFFFFFFF

#define bool uint8_t
#define true 0x1
#define false 0x0

#define nullptr 0x00000000

#endif // TYPES_H
