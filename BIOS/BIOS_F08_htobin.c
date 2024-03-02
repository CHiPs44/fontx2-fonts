#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "BIOS_F08.h"

// BUILD:
//  gcc -Wall -I /usr/lib/gcc/x86_64-linux-gnu/11/include/ BIOS_F08_htobin.c -o BIOS_F08_htobin

int main()
{
    FILE *fontbin = fopen("BIOS_F08.bin", "wb");
    fwrite(&BIOS_F08, sizeof(BIOS_F08), 1, fontbin);
    fclose(fontbin);
    return 0;
}

/* EOF */

