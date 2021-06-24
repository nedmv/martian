#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

#define CASH(KC)  LALT(LCTL(LSFT(KC)))

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0, // Start next game on klavogonki.ru
};


enum tap_dance_codes {
  DANCE_0, // [CUSTOM] Window snapshot - Area snapshot - ___ - ___ 
  DANCE_1, // Russian "Е" - Russian "Ё" - ___ - ___
  DANCE_2, // Russian "Ь" - Russian "Ъ" - ___ - ___
  DANCE_3, // [CUSTOM] Add song to the end of queue - Add song to the beginning of queue - ___ - ___
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                                       KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    OSL(3),         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRACKET,                                    KC_DOT,         KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    TG(1),          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_RBRACKET,                                                                    KC_COMMA,       KC_H,           KC_J,           KC_K,           KC_L,           LT(3,KC_SCOLON),LGUI_T(KC_QUOTE),
    KC_CAPSLOCK,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),ST_MACRO_0,     
    KC_GRAVE,       TD(DANCE_0),    KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_TRANSPARENT,                                                                                                 TO(1),          TT(2),          TT(3),          TT(4),          KC_BSLASH,      LGUI(KC_L),     
    KC_SPACE,       KC_BSPACE,      KC_DELETE,                      KC_TAB,         KC_ENTER,       KC_LSHIFT
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                                       KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           RU_MINS,        
    OSL(3),         RU_SHTI,        RU_TSE,         RU_U,           RU_KA,          TD(DANCE_1),    KC_LBRACKET,                                    RU_DOT,         RU_EN,          RU_GHE,         RU_SHA,         RU_SHCH,        RU_ZE,          RU_HA,          
    KC_TRANSPARENT, RU_EF,          RU_YERU,        RU_VE,          RU_A,           RU_PE,          KC_RBRACKET,                                                                    LSFT(RU_DOT),   RU_ER,          RU_O,           RU_EL,          RU_DE,          RU_ZHE,         RU_E,           
    KC_CAPSLOCK,    RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                           RU_TE,          TD(DANCE_2),    RU_BE,          RU_YU,          RU_DOT,         ST_MACRO_0,     
    KC_TRANSPARENT, TD(DANCE_0),    KC_LGUI,        KC_LALT,        KC_LCTRL,       TO(0),                                                                                                          KC_TRANSPARENT, TT(2),          TT(3),          TT(4),          KC_BSLASH,      LGUI(KC_L),    
    KC_SPACE,       KC_BSPACE,      KC_DELETE,                      KC_TAB,         KC_ENTER,       KC_LSHIFT
  ),
  [2] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_UP,       KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(KC_LEFT),  LCTL(KC_UP),    LCTL(KC_DOWN),  LCTL(KC_DOWN),  KC_TRANSPARENT, 
    KC_TRANSPARENT, TD(DANCE_0),    KC_LGUI,        KC_LALT,        KC_LCTRL,       TO(0),                                                                                                          TO(1),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_L),     
    KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_BTN3,                     KC_TAB,         KC_ENTER,       KC_LSHIFT
  ),
  [3] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LALT(KC_F4),    CASH(KC_W),CASH(KC_E),LALT(KC_TAB),   CASH(KC_T),KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_3),    KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,CASH(KC_O),KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, CASH(KC_A), CASH(KC_S),CASH(KC_D),CASH(KC_F),KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_UP,          KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, CASH(KC_Z),CASH(KC_X),CASH(KC_C),CASH(KC_V),KC_TRANSPARENT,                                                      KC_DOWN,        CASH(KC_M), KC_AUDIO_VOL_DOWN,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, TD(DANCE_0),    KC_LGUI,        KC_LALT,        KC_LCTRL,       TO(0),                                                                                                          TO(1),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_L),     
    KC_SPACE,       KC_BSPACE,      KC_DELETE,                      KC_TAB,         KC_ENTER,       KC_LSHIFT
  ),
  [4] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MOON_LED_LEVEL,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,          
    KC_TRANSPARENT, KC_TRANSPARENT, TOGGLE_LAYER_COLOR,KC_TRANSPARENT, RGB_SLD,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, WEBUSB_PAIR,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_HUI,        RGB_SAI,        RGB_VAI,        RGB_TOG,        RGB_SPI,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_HUD,        RGB_SAD,        RGB_VAD,        KC_TRANSPARENT, RGB_SPD,                                        MU_MOD,         MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, TD(DANCE_0),    KC_LGUI,        KC_LALT,        KC_LCTRL,       TO(0),                                                                                                          TO(1),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_L),     
    KC_SPACE,       KC_BSPACE,      KC_DELETE,                      KC_TAB,         KC_ENTER,       KC_LSHIFT
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {33,255,255}, {14,255,255}, {243,222,234}, {0,0,0}, {146,224,255}, {33,255,255}, {14,255,255}, {243,222,234}, {0,0,0}, {146,224,255}, {33,255,255}, {14,255,255}, {243,222,234}, {0,0,0}, {146,224,255}, {33,255,255}, {14,255,255}, {243,222,234}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,183,238}, {85,203,158}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {14,255,255}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {14,255,255}, {14,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {20,177,225}, {0,0,0}, {0,0,0}, {30,96,255}, {30,96,255}, {30,96,255}, {30,96,255}, {20,177,225}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {195,61,255}, {195,61,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {195,61,255}, {0,0,0}, {0,0,0}, {0,0,0}, {30,96,255}, {30,96,255}, {30,96,255}, {30,96,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)) SS_DELAY(1000) SS_LCTL(SS_TAP(X_ENTER)));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[8];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PSCREEN);
        tap_code16(KC_PSCREEN);
        tap_code16(KC_PSCREEN);
    }
    if(state->count > 3) {
        tap_code16(KC_PSCREEN);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_PSCREEN); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_PSCREEN)); break;
        case DOUBLE_TAP: register_code16(KC_PSCREEN); register_code16(KC_PSCREEN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PSCREEN); register_code16(KC_PSCREEN);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_PSCREEN); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_PSCREEN)); break;
        case DOUBLE_TAP: unregister_code16(KC_PSCREEN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PSCREEN); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RU_IE);
        tap_code16(RU_IE);
        tap_code16(RU_IE);
    }
    if(state->count > 3) {
        tap_code16(RU_IE);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(RU_IE); break;
        case SINGLE_HOLD: register_code16(RU_YO); break;
        case DOUBLE_TAP: register_code16(RU_IE); register_code16(RU_IE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RU_IE); register_code16(RU_IE);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(RU_IE); break;
        case SINGLE_HOLD: unregister_code16(RU_YO); break;
        case DOUBLE_TAP: unregister_code16(RU_IE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RU_IE); break;
    }
    dance_state[1].step = 0;
}
void on_DANCE_2(qk_tap_dance_state_t *state, void *user_data);
void DANCE_2_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_DANCE_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RU_SOFT);
        tap_code16(RU_SOFT);
        tap_code16(RU_SOFT);
    }
    if(state->count > 3) {
        tap_code16(RU_SOFT);
    }
}

void DANCE_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(RU_SOFT); break;
        case SINGLE_HOLD: register_code16(RU_HARD); break;
        case DOUBLE_TAP: register_code16(RU_SOFT); register_code16(RU_SOFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RU_SOFT); register_code16(RU_SOFT);
    }
}

void DANCE_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(RU_SOFT); break;
        case SINGLE_HOLD: unregister_code16(RU_HARD); break;
        case DOUBLE_TAP: unregister_code16(RU_SOFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RU_SOFT); break;
    }
    dance_state[3].step = 0;
}

void on_DANCE_3(qk_tap_dance_state_t *state, void *user_data);
void DANCE_3_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_DANCE_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_D));
        tap_code16(LCTL(KC_D));
        tap_code16(LCTL(KC_D));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_D));
    }
}

void DANCE_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_D)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_D))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_D)); register_code16(LCTL(KC_D)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_D)); register_code16(LCTL(KC_D));
    }
}

void DANCE_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_D)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_D))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_D)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_D)); break;
    }
    dance_state[6].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_2, DANCE_2_finished, DANCE_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_3, DANCE_3_finished, DANCE_3_reset),
};
