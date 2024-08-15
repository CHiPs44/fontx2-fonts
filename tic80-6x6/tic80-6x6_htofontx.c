#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint8_t font[2048] = {
#include "font.inl"
};

// uint8_t altfont[] = {
// #include "altfont.inl"
// };

#define FONTNAME "tic80-6x6"
#define NCHARS (256)

/*************************************************************************************************/

// typedef struct _block {
//   uint16_t first_char;
//   uint16_t last_char;
// } block_t;

// uint8_t bitmap[NCHARS * 8];
// uint16_t offset = 0;
// block_t blocks[256];
// uint8_t nblocks = 0;

// void append_block(uint16_t first_char, uint16_t last_char, uint8_t *source) {
//   printf("Block #%02d: %05d %04x-%04x (%03d) %p\n", nblocks, offset,
//   first_char,
//          last_char, last_char - first_char + 1, source);
//   for (uint16_t i = 0; i <= last_char - first_char; i += 1) {
//     for (uint8_t j = 0; j < 8; j += 1) {
//       // cf. https://github.com/dhepper/font8x8/blob/master/README#L17
//       // The least significant bit of each byte corresponds to the first
//       pixel
//       // in a row.
//       // Seems it's the same with TIC-80 fonts...
//       uint8_t byte1 = source[i * 8 + j];
//       uint8_t byte2 = 0;
//       uint8_t mask1 = 0b00000001;
//       uint8_t mask2 = 0b10000000;
//       for (uint8_t k = 0; k < 8; k += 1) {
//         uint8_t bit = byte1 & mask1 ? 1 : 0;
//         if (bit) {
//           byte2 |= mask2;
//         }
//         mask1 *= 2;
//         mask2 /= 2;
//       }
//       bitmap[offset++] = byte2;
//       bitmap[offset++] = byte1;
//     }
//   }
//   printf("offset=%d nchars*8=%d sizeof=%ld\n", offset, NCHARS * 8,
//          sizeof(bitmap));
//   blocks[nblocks].first_char = first_char;
//   blocks[nblocks].last_char = last_char;
//   nblocks += 1;
// }

int main()
{
    //   // Prepare bitmaps & blocks
    //   append_block(0x0000u, 0x007fu, (uint8_t *)&font);
    //   append_block(0x0080u, 0x00ffu, (uint8_t *)&altfont);

    FILE *fontx = fopen("tic80-6x6.fnt", "wb");

    // FONTX2 HEADER
    // cf. http://elm-chan.org/docs/dosv/fontx_e.html
    //                11111111
    //      012345678901234567
    //      FONTX2FONT8x8 ____
    //      headerfontnamewhtb
    // uint8_t header[18];
    uint8_t header[17];
    header[0] = 'F';
    header[1] = 'O';
    header[2] = 'N';
    header[3] = 'T';
    header[4] = 'X';
    header[5] = '2';
    header[6] = 'T';
    header[7] = 'I';
    header[8] = 'C';
    header[9] = '8';
    header[10] = '0';
    header[11] = '6';
    header[12] = 'X';
    header[13] = '6';
    // header[14] = 6u; // Font width WF (dots)
    // header[15] = 6u; // Font height HF (dots)
    header[14] = 8u; // Font width WF (dots)
    header[15] = 8u; // Font height HF (dots)
    header[16] = 0u; // Type ANK (single byte)
    //   header[16] = 1u; // Type ISO10646 / Unicode (??? Code flag (1:Shift JIS)
    //   ???)
    header[16] = 0u; // Type ANK (single byte)
    //   header[17] = nblocks; // Number of code blocks NB
    //   printf("%d/%d %p %ld\n", nblocks, header[17], &header, sizeof(header));
    fwrite(&header, sizeof(header), 1, fontx);

    //   // FONTX2 BLOCKS
    //   // /!\ little endian
    //   // fwrite(&blocks, sizeof(block_t), nblocks, fontx);
    //   for (uint8_t block = 0; block < nblocks; block += 1) {
    //     uint8_t first_char_lo = blocks[block].first_char & 0xff;
    //     uint8_t first_char_hi = blocks[block].first_char >> 8;
    //     uint8_t last_char_lo = blocks[block].last_char & 0xff;
    //     uint8_t last_char_hi = blocks[block].last_char >> 8;
    //     printf("%02d/%02d: %02x %02x %02x %02x\n", block, nblocks,
    //     first_char_lo,
    //            first_char_hi, last_char_lo, last_char_hi);
    //     fwrite(&first_char_lo, sizeof(first_char_lo), 1, fontx);
    //     fwrite(&first_char_hi, sizeof(first_char_hi), 1, fontx);
    //     fwrite(&last_char_lo, sizeof(last_char_lo), 1, fontx);
    //     fwrite(&last_char_hi, sizeof(last_char_hi), 1, fontx);
    //   }

    //   // FONTX2 BITMAP
    //   fwrite(&bitmap, sizeof(bitmap), 1, fontx);
    printf("sizeof(font)=%ld\n", sizeof(font));
    for (int i = 0; i < sizeof(font); i++)
    {
        uint8_t src = font[i];
        uint8_t dst = 0;
        if (src & 0b10000000u)
            dst |= 0b00000001u;
        if (src & 0b01000000u)
            dst |= 0b00000010u;
        if (src & 0b00100000u)
            dst |= 0b00000100u;
        if (src & 0b00010000u)
            dst |= 0b00001000u;
        if (src & 0b00001000u)
            dst |= 0b00010000u;
        if (src & 0b00000100u)
            dst |= 0b00100000u;
        if (src & 0b00000010u)
            dst |= 0b01000000u;
        if (src & 0b00000001u)
            dst |= 0b10000000u;
        font[i] = dst;
    }
    fwrite(&font, sizeof(font), 1, fontx);

    fclose(fontx);
    return 0;
}

/* EOF */
