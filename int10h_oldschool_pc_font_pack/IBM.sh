#!/usr/bin/env bash

SRC_DIR="oldschool_pc_font_pack_v2.2/ttf - Px (pixel outline)/"
SRC_IBM="PxPlus_IBM_*.ttf"

FONTS=$(find "$SRC_DIR" -name "$SRC_IBM" -print0 | \
    xargs -0 -i basename "{}" | \
    egrep -v "\-2x|\-2y" | \
    sort)

printf "%-30s %-20s %s\n" "Font" "Full" "Fontx"
printf "%-30s %-20s %s\n" "----" "----" "-----"
for FONT in $FONTS; do
    # Strip out PxPlus_IBM_ and .ttf extension
    FULL=$(echo -n "${FONT}" | sed "s/PxPlus_IBM_//g" | sed "s/\.ttf//g")
    # Reduce/expand to 8 chars for FONTX name
    FONTX=$(echo -n "${FULL}        " | sed "s/_/ /")
    FONTX=${FONTX:0:8}
    # echo -e "$FONT\t$FULL\t|$FONTX|"
    printf "%-30s %-20s |%s|\n" "$FONT" "$FULL" "$FONTX"
done

# EOF
