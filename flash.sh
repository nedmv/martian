#!/bin/bash
QMK_LOCATION="$HOME/qmk_firmware"
KEYBOARD="moonlander"
LAYOUT="martian"
LAYOUT_BINARY="${KEYBOARD}_$LAYOUT.bin"
LAST_FLASH="${PWD}/flashing.log"
ALL_FLASHES="${PWD}/flashing.info"

qmk flash -kb moonlander -km martian | tee "$LAST_FLASH" || { echo "Failed to flash firmware."; exit 1; }

HASH=$(git log -n1 --pretty=format:'%h')
BINARY_SIZE=$(du -b "$QMK_LOCATION/$LAYOUT_BINARY" | sed 's/\t.*$//')
echo "$(date +"%F %T"): Flashed version $HASH ($BINARY_SIZE bytes)." >> "$ALL_FLASHES"