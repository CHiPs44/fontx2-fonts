# IBM VGA BIOS (CP437) Fonts

## License

The files below should be in "Public Domain", as they come directly, indirectly or are related to:

- [Disclaimer](https://github.com/viler-int10h/vga-text-mode-fonts/blob/master/FONTS.TXT)
- [For 8x8 font](https://github.com/dhepper/font8x8/blob/master/README#L66)
- [Doubts?](https://github.com/spacerace/romfont/blob/master/README.md#comparing-fonts--observations)
- [Comment regarding "public domain"ness #1](https://github.com/spacerace/romfont/issues/1)

These are the 3 files:

- `IBM_VGA_8x8.bin`  or `BIOS.F08`, md5sum `36addababf8830d29e7502e7a4d4d9f8`
- `IBM_VGA_8x14.bin` or `BIOS.F14`, md5sum `8bcbaf14d1c2729dbbbd486d0929f98c`
- `IBM_VGA_8x16.bin` or `BIOS.F16`, md5sum `10c3d174722de153243d60a06d29865a`

The work I made to convert these to FONTX format is under MIT license.

## BIOS 8x8 CP437 from IBM VGA BIOS

Note:

- I had to rebuild `BIOS.F08` from `BIOS_F08.h` with `BIOS_F08_htobin.c` as I lost the source for the original file I converted with `xxd -i -c 16`...
- Then `md5sum` and a quick Google search told me that `36addababf8830d29e7502e7a4d4d9f8` is for original IBM VGA 8x8 font with code page 437, thanks to
<https://github.com/spacerace/romfont/blob/master/MD5SUMS.md#8x8-fonts-full-256-items-charset>.

In fact, i recall now my `BIOS.F08` came from <https://github.com/viler-int10h/vga-text-mode-fonts/>, specifically <https://github.com/viler-int10h/vga-text-mode-fonts/raw/master/FONTS/PC-IBM/BIOS.F08>.

Binary file from <https://github.com/spacerace/romfont/> site, specifically <https://github.com/spacerace/romfont/blob/master/font-bin/IBM_VGA_8x8.bin> is the same as Viler's one.

You can download and rename it with:

```bash
wget https://github.com/spacerace/romfont/raw/master/font-bin/IBM_VGA_8x8.bin
mv IBM_VGA_8x8.bin BIOS_F08.bin
```

To compare with the generated `BIOS_F08.h`,

```bash
xxd -i -c 8 BIOS_F08.bin > BIOS_F08_xxd.h
sed s/BIOS_F08_bin/BIOS_F08/g BIOS_F08_xxd.h > BIOS_F08_xxd2.h
diff -u BIOS_F08.h BIOS_F08_xxd2.h
```

## 8x14 conversion from binary to FONTX

```bash
wget https://github.com/spacerace/romfont/raw/master/font-bin/IBM_VGA_8x14.bin
cp -p IBM_VGA_8x14.bin BIOS_F14.bin
xxd -i -c 8 BIOS_F14.bin > BIOS_F14.h
sed s/BIOS_F14_bin/BIOS_F14/g BIOS_F14.h > BIOS_F14.h
gcc -Wall -I /usr/lib/gcc/x86_64-linux-gnu/11/include/ BIOS_F14_htofontx2.c -o BIOS_F14_htofontx2
./BIOS_F14_htofontx2
xxd -i -c 8 BIOS_F14.fnt > ../include/BIOS_F14.h
rm ./BIOS_F14_htofontx2
```

## 8x16 conversion from binary to FONTX

```bash
wget https://github.com/spacerace/romfont/raw/master/font-bin/IBM_VGA_8x16.bin
cp -p IBM_VGA_8x16.bin BIOS_F16.bin
xxd -i -c 8 BIOS_F16.bin > BIOS_F16.h
sed s/BIOS_F16_bin/BIOS_F16/g BIOS_F16.h > BIOS_F16.h
gcc -Wall -I /usr/lib/gcc/x86_64-linux-gnu/11/include/ BIOS_F16_htofontx2.c -o BIOS_F16_htofontx2
./BIOS_F16_htofontx2
xxd -i -c 8 BIOS_F16.fnt > ../include/BIOS_F16.h
./BIOS_F16_htofontx2
```
