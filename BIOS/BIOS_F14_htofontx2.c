#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "BIOS_F14.h"

// BUILD:
//  gcc -Wall -I /usr/lib/gcc/x86_64-linux-gnu/11/include/ BIOS_F14_htofontx2.c -o BIOS_F14_htofontx2

/*************************************************************************************************/

#define FONTNAME "BIOS_F14"
#define NCHARS (256)

/*************************************************************************************************/

uint8_t bitmap[NCHARS * 14];

int main()
{
    // Prepare bitmaps & blocks
    FILE *fontx = fopen("BIOS_F14.fnt", "wb");

    // FONTX2 HEADER
    // cf. http://elm-chan.org/docs/dosv/fontx_e.html
    //                11111111
    //      012345678901234567
    //      FONTX2BIOS_F14____
    //      headerfontnamewhtb
    uint8_t header[17];
    header[0] = 'F';
    header[1] = 'O';
    header[2] = 'N';
    header[3] = 'T';
    header[4] = 'X';
    header[5] = '2';
    header[6] = 'B';
    header[7] = 'I';
    header[8] = 'O';
    header[9] = 'S';
    header[10] = '_';
    header[11] = 'F';
    header[12] = '1';
    header[13] = '4';
    header[14] = 8u;      // Font width WF (dots)
    header[15] = 14u;      // Font height HF (dots)
    header[16] = 0u;      // Type ANK (single byte)
    fwrite(&header, sizeof(header), 1, fontx);

    // FONTX2 BITMAP
    fwrite(&BIOS_F14, sizeof(BIOS_F14), 1, fontx);

    fclose(fontx);
    return 0;
}

/* EOF */

