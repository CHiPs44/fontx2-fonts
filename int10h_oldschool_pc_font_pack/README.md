# The Ultimate Oldschool PC Font Pack (v2.2)

## Download and extract ZIP archive

From VileR, cf. <https://int10h.org/oldschool-pc-fonts/>: "__Free to use under the CC BY-SA 4.0 license__"

Go to <https://int10h.org/oldschool-pc-fonts/download/> and download <https://int10h.org/oldschool-pc-fonts/download/oldschool_pc_font_pack_v2.2_FULL.zip>.

Unzip it in this folder, under `oldschool_pc_font_pack_v2.2`:

```bash
mkdir oldschool_pc_font_pack_v2.2
cd oldschool_pc_font_pack_v2.2
unzip ~/Downloads/oldschool_pc_font_pack_v2.2_FULL.zip
cd ..
```

NB: we'll use the TTF files only, feel free to download <https://int10h.org/oldschool-pc-fonts/download/oldschool_pc_font_pack_v2.2_linux.zip>.

## Tools

### Conversion to BDF

Install `otf2bdf`, for Ubuntu/Debian:

```bash
apt install otf2bdf
```

### Conversion to FONTX2

Download __Bits'N'Picas__ from <https://github.com/kreativekorp/bitsnpicas/blob/master/downloads/BitsNPicas.jar>.

Install Java:

```bash
apt install openjdk-11-jre-headless
```

## Example conversion => FAIL

```bash
TTF=./oldschool_pc_font_pack_v2.2/ttf\ -\ Px\ \(pixel\ outline\)/PxPlus_IBM_BIOS.ttf
BDF=bdf/PxPlus_IBM_BIOS.bdf
otf2bdf "$TTF" > "$BDF"
java -jar ~/BitsNPica.jar convertbitmap -f fontx2 -ee "UTF16-LE" "$BDF"
```

KO: font is ugly / not in 8x8...

cf. <https://gist.github.com/Earnestly/6bc5bad7666f7bf8816d054b7b76112e>?

Using FontForge to convert pcf/bdf to otb, could change to otb to bdf?
