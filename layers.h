#ifndef LAYERS_H
#define LAYERS_H

enum layers {
  // Language layers for lang-shift must be in that order.
  L_EN = 0, // Base English layer, based on QWERTY
  L_EN_S, // Shifted English layer
  L_RU, // Base Russian layer, based on ЙЦУКЕН
  L_RU_S, // Shifted Russian layer.

  L_MOVE, // Movement layer (arrows, mouse, F1-F12)
  L_PROG, // Program layer (Meh hotkeys, media)
  L_KEEB, // Keyboard layer (lighting, sound, reset)
};

#endif // LAYERS_H