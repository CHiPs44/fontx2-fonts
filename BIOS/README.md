# BIOS 8x8 CP437 from IBM VGA BIOS

I  had to rebuild `BIOS.F08` from `BIOS_F08.h` as I lost the original file I converted with `xxd`.

Then `md5sum` and Google told me that `36addababf8830d29e7502e7a4d4d9f8` is for original IBM VGA 8x8 font with code page 437, thanks to
<https://github.com/spacerace/romfont/blob/master/MD5SUMS.md#8x8-fonts-full-256-items-charset>.

Most sources say this file is Public Domain.

Binary file is at <https://github.com/spacerace/romfont/blob/master/font-bin/IBM_VGA_8x8.bin>, you can download it with:

```bash
wget https://github.com/spacerace/romfont/raw/master/font-bin/IBM_VGA_8x8.bin
mv IBM_VGA_8x8.bin BIOS_F08.bin
```

```bash
xxd -i -c 8 BIOS_F08.bin > BIOS_F08_xxd.h
sed s/BIOS_F08_bin/BIOS_F08/g BIOS_F08_xxd.h > BIOS_F08_xxd2.h
```

