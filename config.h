/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 300000

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"WW3gz/x3w53"
#define RGB_MATRIX_STARTUP_SPD 60

#define LANG_CHANGE_DEFAULT LANG_CHANGE_CAPS

#define COMPOSE_KEY KC_PAUSE

// #define MOUSE_LAYER
// #define GAME_LAYER