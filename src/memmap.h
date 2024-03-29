#ifndef __E820MAP_H
#define __E820MAP_H

#include "types.h" // u64

#define E820_RAM          1
#define E820_RESERVED     2
#define E820_ACPI         3
#define E820_NVS          4
#define E820_UNUSABLE     5
#define E820_HOLE         ((u32)-1) // Useful for removing entries

struct e820entry {
    u64 start;
    u64 size;
    u32 type;
};

void add_e820(u64 start, u64 size, u32 type);
void memmap_finalize(void);

// A typical OS page size
#define PAGE_SIZE 4096
//Used by Virtio and Xen
#define PAGE_SHIFT 12

// e820 map storage (defined in system.c)
extern struct e820entry e820_list[];
extern int e820_count;

// Space for exported bios tables (defined in misc.c)
extern char BiosTableSpace[];

#endif // e820map.h
