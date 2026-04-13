    .section .text
    .global _start
    .global sqrt
    .arm

/* GBA ROM entry */
_start:
    b start                @ branch over header

.fill 192, 1, 0x00    

start:

    /* Disable interrupts */
    mov r0,#0
    ldr r1,=0x04000208
    str r0,[r1]

    /* Set stack pointer */
    ldr sp,=0x03007F00

    /* Call main */
    ldr r0,=main
    bx r0

hang:
    b hang



