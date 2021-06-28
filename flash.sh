#!/bin/bash

FLASHER="$HOME/apps/wally-cli"
QMK="$HOME/git/zsa_qmk"
KEYBOARD="moonlander"
LAYOUT="martian"
LAYOUT_BINARY="${KEYBOARD}_$LAYOUT.bin"
LAST_FLASH="${PWD}/flashing.log"
ALL_FLASHES="${PWD}/flashing.info"

HASH=$(git log -n1 --pretty=format:'%h')
cd "$QMK" || { echo "CD to ${QMK} failed."; exit 1; }
make -j16 $KEYBOARD:$LAYOUT | tee "$LAST_FLASH" && "$FLASHER" "$QMK/$LAYOUT_BINARY" | tee -a "$LAST_FLASH" || { echo "Failed to flash layout."; exit 1; }

BINARY_SIZE=$(du -b "$LAYOUT_BINARY" | sed 's/\t.*$//')
echo "$(date +"%F %T"): Flashed version $HASH ($BINARY_SIZE bytes)." >> "$ALL_FLASHES"