#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_russian.h"

#define CASH(KC)  LALT(LCTL(LSFT(KC))) // CASH does not work as expected
#define KC_LSWAP KC_CAPSLOCK //TODO: add ability to change hotkey

#define LAYOUT_ML( \
    k00, k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35,      \
    k40, k41, k42, k43, k44,           \
    k53, \
    k50, k51, k52, \
    \
    k60, k61, k62, k63, k64, k65, k66, \
    k70, k71, k72, k73, k74, k75, k76, \
    k80, k81, k82, k83, k84, k85, k86, \
    k91, k92, k93, k94, k95, k96, \
    ka2, ka3, ka4, ka5, ka6, \
    kb3,\
    kb4, kb5, kb6 \
) \
LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
)


enum layers {
  // Language layers MUST be 0 and 1
  L_EN = 0, // Base English layer, based on QWERTY
  L_RU = 1, // Base Russian layer, based on ЙЦУКЕН

  L_MOVE = 2, // Movement layer (arrows, mouse, F1-F12)
  L_PROG = 3, // Program layer (Meh hotkeys, media)
  L_KEEB = 4, // Keyboard layer (lighting, sound, reset)
};

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  GONKI, // Start next race on klavogonki.ru
  TO_RU, //Invert state of russian layer and toggle layout.
  L_ESCAPE, // TO layer 1, if it's active. Else TO layer 0.
  RU_LBRACKET, // LBRACKET for Russian layer.
  RU_RBRACKET, // RBRACKET for Russian layer.
  RU_GRAVE, // GRAVE for Russian layer.
  RU_HASH, // # for Russian layer.
  LOCK, // Lock screen and move to layer 0.
};

enum tap_dance_codes {
  D_SNAP, // [CUSTOM] Window snapshot - Area snapshot - ___ - ___ 
  D_EYO, // Russian "Е" - Russian "Ё" - ___ - ___
  D_SIGNS, // Russian "Ь" - Russian "Ъ" - ___ - ___
  D_QUEUE, // [CUSTOM] Add song to the end of queue - Add song to the beginning of queue - ___ - ___
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_EN] = LAYOUT_ML(
    KC_ESCAPE,   KC_1,           KC_2,        KC_3,          KC_4,           KC_5,      KC_EQUAL,
    OSL(L_PROG), KC_Q,           KC_W,        KC_E,          KC_R,           KC_T,      KC_LBRACKET,
    TO_RU,       KC_A,           KC_S,        KC_D,          KC_F,           KC_G,      KC_RBRACKET,
    XXXXXXX,     KC_Z,           KC_X,        KC_C,          KC_V,           KC_B,
    KC_GRAVE,    TD(D_SNAP),     KC_LGUI,     KC_LALT,       KC_LCTRL,
    TO_RU,
    KC_SPACE,    KC_BSPACE,      KC_DELETE,
    
    XXXXXXX,     KC_6,           KC_7,        KC_8,          KC_9,           KC_0,      KC_MINUS,
    KC_DOT,      KC_Y,           KC_U,        KC_I,          KC_O,           KC_P,      XXXXXXX,
    KC_COMMA,    KC_H,           KC_J,        KC_K,          KC_L,           KC_SCOLON, KC_QUOTE,
    KC_N,        KC_M,           KC_COMMA,    KC_DOT,        KC_SLASH,       GONKI,
    TT(L_MOVE),  TT(L_PROG),     TT(L_KEEB),  KC_BSLASH,     XXXXXXX,
    XXXXXXX,
    KC_TAB,      KC_ENTER,       KC_LSHIFT
  ),
  [L_RU] = LAYOUT_ML(
    _______,      _______,       _______,     RU_HASH,          _______,        _______,    _______,
    _______,      RU_SHTI,       RU_TSE,      RU_U,          RU_KA,          TD(D_EYO),  RU_LBRACKET,
    _______,      RU_EF,         RU_YERU,     RU_VE,         RU_A,           RU_PE,      RU_RBRACKET,
    _______,      RU_YA,         RU_CHE,      RU_ES,         RU_EM,          RU_I,
    RU_GRAVE,     _______,       _______,     _______,       _______,       
    _______,                                                                                                               
    _______,      _______,       _______,
    
    _______,      _______,       _______,     _______,       _______,        _______,    RU_MINS,
    RU_DOT,       RU_EN,         RU_GHE,      RU_SHA,        RU_SHCH,        RU_ZE,      RU_HA,
    LSFT(RU_DOT), RU_ER,         RU_O,        RU_EL,         RU_DE,          RU_ZHE,     RU_E,                
    RU_TE,        TD(D_SIGNS),   RU_BE,       RU_YU,         RU_DOT,         GONKI,
    _______,      _______,       _______,     _______,       _______,
    _______,
    _______,      _______,       _______
  ),
  [L_MOVE] = LAYOUT_ML(
    L_ESCAPE,     KC_F1,         KC_F2,       KC_F3,         KC_F4,          KC_F5,      _______,
    _______,      _______,       _______,     _______,       _______,        _______,    _______,
    _______,      KC_MS_LEFT,    KC_MS_UP,    KC_MS_DOWN,    KC_MS_RIGHT,    _______,    _______,
    _______,      _______,       _______,     _______,       _______,        _______,
    _______,      TD(D_SNAP),    KC_LGUI,     KC_LALT,       KC_LCTRL,
    _______,
    KC_MS_BTN1,   KC_MS_BTN2,    KC_MS_BTN3,

    KC_F11,       KC_F6,         KC_F7,       KC_F8,         KC_F9,          KC_F10,     KC_F12,
    _______,      _______,       KC_HOME,     KC_PGUP,       KC_PGDOWN,      KC_END,     _______, 
    _______,      _______,       KC_LEFT,     KC_UP,         KC_DOWN,        KC_RIGHT,   _______,   
    _______,      LCTL(KC_LEFT), LCTL(KC_UP), LCTL(KC_DOWN), LCTL(KC_RIGHT), _______,              
    _______,      _______,       _______,     _______,       LOCK,  
    _______,
    KC_TAB,       KC_ENTER,      KC_LSHIFT
  ),
  [L_PROG] = LAYOUT_ML(
    L_ESCAPE,     _______,       _______,     _______,       _______,        _______,    _______,
    _______,      LALT(KC_F4),   CASH(KC_W),  CASH(KC_E),    LALT(KC_TAB),   CASH(KC_T), _______,
    _______,      CASH(KC_A),    CASH(KC_S),  CASH(KC_D),    CASH(KC_F),     CASH(KC_G), _______,
    _______,      CASH(KC_Z),    CASH(KC_X),  CASH(KC_C),    CASH(KC_V),     CASH(KC_B),
    _______,      TD(D_SNAP),    KC_LGUI,     KC_LALT,       KC_LCTRL,
    _______,        
    KC_SPACE,     KC_BSPACE,     KC_DELETE,

    _______,      _______,       _______,     _______,       _______,        _______,    _______, 
    _______,    TD(D_QUEUE), KC_AUDIO_MUTE, KC_AUDIO_VOL_UP, CASH(KC_O),     _______,    _______, 
    _______,  KC_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,_______, _______, 
    KC_DOWN,      CASH(KC_M),    KC_AUDIO_VOL_DOWN,_______,  _______,        _______, 
    _______,      _______,       _______,     _______,       LOCK,
    _______,
    KC_TAB,       KC_ENTER,      KC_LSHIFT
  ),
  [L_KEEB] = LAYOUT_ML(
    L_ESCAPE,     _______,       _______,     _______,       _______,        _______,    LED_LEVEL,
    _______,      _______, TOGGLE_LAYER_COLOR,_______,       RGB_SLD,        _______,    _______,
    KC_LSWAP,     RGB_HUI,       RGB_SAI,     RGB_VAI,       RGB_TOG,        RGB_SPI,    _______,
    _______,      RGB_HUD,       RGB_SAD,     RGB_VAD,       _______,        RGB_SPD,
    _______,      TD(D_SNAP),    KC_LGUI,     KC_LALT,       KC_LCTRL,       
    _______,
    KC_SPACE,     KC_BSPACE,     KC_DELETE,

    _______,      _______,       _______,     _______,       _______,        _______,    RESET,  
    _______,      _______,       _______,     _______,       _______,        _______,    _______, 
    _______,      _______,       AU_TOG,      _______,       _______,        _______,    _______, 
    MU_MOD,       MU_TOG,        _______,     _______,       _______,        _______,
    _______,      _______,       _______,     _______,       LOCK,
    _______,
    KC_TAB,       KC_ENTER,      KC_LSHIFT
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

void press_inverted(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    //TODO: how to process oneshot mods?
    uint8_t mods = get_mods();
    clear_mods();
    tap_code(KC_LSWAP);
    set_mods(mods);
    tap_code(keycode);
    mods = get_mods();
    clear_mods();
    tap_code(KC_LSWAP);
    set_mods(mods);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TO_RU:
    if (record->event.pressed) {
        clear_keyboard();
        tap_code(KC_LSWAP);
        layer_invert(L_RU);
    }
    break;  
    case GONKI:
    if (record->event.pressed) {
      //Delay is needed for page loading.
      SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)) SS_DELAY(1000) SS_LCTL(SS_TAP(X_ENTER)));
    }
    break;
    case L_ESCAPE:
    if (record->event.pressed) {
      layer_move(IS_LAYER_ON(L_RU)?L_RU:L_EN);
    }
    break;
    case RU_LBRACKET:
    press_inverted(KC_LBRACKET, record);
    break;
    case RU_RBRACKET:
    press_inverted(KC_RBRACKET, record);
    break;
    case RU_GRAVE:
    press_inverted(KC_GRAVE, record);
    break;
    case RU_HASH:
    if (get_mods() | MOD_MASK_SHIFT) {
      press_inverted(KC_3, record);
    } else {
      if (record->event.pressed) {
        tap_code(KC_3);
      }
    }
    break;
    case LOCK:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_L)));
      if(IS_LAYER_ON(L_RU)) {
        tap_code(KC_LSWAP);
      }
      layer_move(L_EN);
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

void on_D_SNAP(qk_tap_dance_state_t *state, void *user_data);
void D_SNAP_finished(qk_tap_dance_state_t *state, void *user_data);
void D_SNAP_reset(qk_tap_dance_state_t *state, void *user_data);

void on_D_SNAP(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PSCREEN);
        tap_code16(KC_PSCREEN);
        tap_code16(KC_PSCREEN);
    }
    if(state->count > 3) {
        tap_code16(KC_PSCREEN);
    }
}

void D_SNAP_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_PSCREEN); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_PSCREEN)); break;
        case DOUBLE_TAP: register_code16(KC_PSCREEN); register_code16(KC_PSCREEN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PSCREEN); register_code16(KC_PSCREEN);
    }
}

void D_SNAP_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_PSCREEN); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_PSCREEN)); break;
        case DOUBLE_TAP: unregister_code16(KC_PSCREEN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PSCREEN); break;
    }
    dance_state[0].step = 0;
}
void on_D_EYO(qk_tap_dance_state_t *state, void *user_data);
void D_EYO_finished(qk_tap_dance_state_t *state, void *user_data);
void D_EYO_reset(qk_tap_dance_state_t *state, void *user_data);

void on_D_EYO(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RU_IE);
        tap_code16(RU_IE);
        tap_code16(RU_IE);
    }
    if(state->count > 3) {
        tap_code16(RU_IE);
    }
}

void D_EYO_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(RU_IE); break;
        case SINGLE_HOLD: register_code16(RU_YO); break;
        case DOUBLE_TAP: register_code16(RU_IE); register_code16(RU_IE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RU_IE); register_code16(RU_IE);
    }
}

void D_EYO_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(RU_IE); break;
        case SINGLE_HOLD: unregister_code16(RU_YO); break;
        case DOUBLE_TAP: unregister_code16(RU_IE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RU_IE); break;
    }
    dance_state[1].step = 0;
}
void on_D_SIGNS(qk_tap_dance_state_t *state, void *user_data);
void D_SIGNS_finished(qk_tap_dance_state_t *state, void *user_data);
void D_SIGNS_reset(qk_tap_dance_state_t *state, void *user_data);

void on_D_SIGNS(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RU_SOFT);
        tap_code16(RU_SOFT);
        tap_code16(RU_SOFT);
    }
    if(state->count > 3) {
        tap_code16(RU_SOFT);
    }
}

void D_SIGNS_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(RU_SOFT); break;
        case SINGLE_HOLD: register_code16(RU_HARD); break;
        case DOUBLE_TAP: register_code16(RU_SOFT); register_code16(RU_SOFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RU_SOFT); register_code16(RU_SOFT);
    }
}

void D_SIGNS_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(RU_SOFT); break;
        case SINGLE_HOLD: unregister_code16(RU_HARD); break;
        case DOUBLE_TAP: unregister_code16(RU_SOFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RU_SOFT); break;
    }
    dance_state[3].step = 0;
}

void on_D_QUEUE(qk_tap_dance_state_t *state, void *user_data);
void D_QUEUE_finished(qk_tap_dance_state_t *state, void *user_data);
void D_QUEUE_reset(qk_tap_dance_state_t *state, void *user_data);

void on_D_QUEUE(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_D));
        tap_code16(LCTL(KC_D));
        tap_code16(LCTL(KC_D));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_D));
    }
}

void D_QUEUE_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_D)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_D))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_D)); register_code16(LCTL(KC_D)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_D)); register_code16(LCTL(KC_D));
    }
}

void D_QUEUE_reset(qk_tap_dance_state_t *state, void *user_data) {
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
        [D_SNAP] = ACTION_TAP_DANCE_FN_ADVANCED(on_D_SNAP, D_SNAP_finished, D_SNAP_reset),
        [D_EYO] = ACTION_TAP_DANCE_FN_ADVANCED(on_D_EYO, D_EYO_finished, D_EYO_reset),
        [D_SIGNS] = ACTION_TAP_DANCE_FN_ADVANCED(on_D_SIGNS, D_SIGNS_finished, D_SIGNS_reset),
        [D_QUEUE] = ACTION_TAP_DANCE_FN_ADVANCED(on_D_QUEUE, D_QUEUE_finished, D_QUEUE_reset),
};
