# Info

This repository contains my keymap for [ZSA Moonlander](https://www.zsa.io/moonlander/) ergonomic keyboard. The keymap is based on QWERTY layout for English language and ЙЦУКЕН layout for Russian language with some modifications. It is inspired by [Optozorax's keymap](https://github.com/optozorax/moonlander) and relies on his [lang_shift](https://github.com/klavarog/lang_shift) module.

# Usage
1. Install QMK CLI using [this guide](https://docs.qmk.fm/#/newbs_getting_started?id=set-up-your-environment).
2. Run QMK setup to install firmware.
```
qmk setup zsa/qmk_firmware -b firmware21
```
3. Clone this repo. 
```
git clone --recurse-submodules https://github.com/nedmv/martian
```
4. Place repo inside firmware folder (or make a soft link).
```
ln -s <repo-location> <qmk-location>/keyboards/moonlander/keymaps/martian
```
5. Compile and flash firmware.
```
qmk compile -kb moonlander -km martian
qmk flash -kb moonlander -km martian
```
This can also be done by using `make.sh` and `flash.sh` scripts.