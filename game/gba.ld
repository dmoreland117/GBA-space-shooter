ENTRY(_start)

MEMORY
{
    ROM  : ORIGIN = 0x08000000, LENGTH = 32M
    IWRAM : ORIGIN = 0x03000000, LENGTH = 32K
    EWRAM : ORIGIN = 0x02000000, LENGTH = 256K
}

SECTIONS
{
    . = 0x08000000;

    .text :
    {
        KEEP(*build/crt0.o(.text*))
        *(.text*)
    } > ROM

    .rodata :
    {
        *(.rodata*)
    } > ROM

    .entities_table :
    {
        __entities_table_start = .;
        KEEP(*(.entities_table))
        __entities_table_end = .;
    } > ROM
    .states_table :
    {
        __states_table_start = .;
        KEEP(*(.states_table))
        __states_table_end = .;
    } > ROM

    /* ---------- EWRAM ---------- */

    .ewram_data :
    {
        *(.ewram_data*)
    } > EWRAM

    .ewram_bss (NOLOAD) :
    {
        *(.ewram_bss*)
    } > EWRAM

    /* ---------- IWRAM ---------- */

    .iwram_data :
    {
        *(.iwram_data*)
    } > IWRAM

    .iwram_bss (NOLOAD) :
    {
        *(.iwram_bss*)
    } > IWRAM

    /* ---------- DEFAULT ---------- */

    .data :
    {
        *(.data*)
    } > IWRAM

    .bss (NOLOAD) :
    {
        *(.bss*)
        *(COMMON)
    } > IWRAM
}