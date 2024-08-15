/* SPDX-License-Identifier: MIT */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "BIOS_F08.h"

int main()
{
    FILE *fontbin = fopen("BIOS_F08.bin", "wb");
    fwrite(&BIOS_F08, sizeof(BIOS_F08), 1, fontbin);
    fclose(fontbin);
    return 0;
}

/* EOF */

