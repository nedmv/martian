#include QMK_KEYBOARD_H
#include "version.h"
// #include "keymap_russian.h"
#include "dances.c"

#define CUSTOM_SAFE_RANGE ML_SAFE_RANGE
#include "lang_shift/include.h"

#define CASH(KC)  LALT(LCTL(LSFT(KC))) // MEH does not work as expected

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
  // Language layers for lang-shift must be in that order.
  L_EN = 0, // Base English layer, based on QWERTY
  L_EN_S, // Shifted English layer
  L_RU, // Base Russian layer, based on ЙЦУКЕН
  L_RU_S, // Shifted Russian layer.

  L_MOVE, // Movement layer (arrows, mouse, F1-F12)
  L_PROG, // Program layer (Meh hotkeys, media)
  L_KEEB, // Keyboard layer (lighting, sound, reset)
};

enum custom_keycodes {
  RGB_SLD = CUSTOM_SAFE_RANGE,
  GONKI, // Start next race on klavogonki.ru
  TO_RU, //Invert state of russian layer and toggle layout.
  L_ESCAPE, // TO L_RU, if it's active. Else TO L_EN.
  LOCK, // Lock screen and move to layer 0.

  CUSTOM_KEYCODES_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE CUSTOM_KEYCODES_SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_EN] = LAYOUT_ML(
    KC_ESCAPE,   AG_1,           AG_2,        AG_3,          AG_4,           AG_5,      AG_EQL,
    OSL(L_PROG), EN_Q,           EN_W,        EN_E,          EN_R,           EN_T,      EN_LBRC,
    AG_CMSP,     EN_A,           EN_S,        EN_D,          EN_F,           EN_G,      EN_RBRC,
    AG_SDOT,     EN_Z,           EN_X,        EN_C,          EN_V,           EN_B,
    LA_CHNG,     AG_COMM,        WIN_0,       ALT_0,         CTRL_0,
    SFT_N,
    KC_SPACE,    KC_BSPACE,      KC_DELETE,
    
    EN_GRV,      AG_6,           AG_7,        AG_8,          AG_9,           AG_0,      AG_MINS,
    EN_LPRN,     EN_Y,           EN_U,        EN_I,          EN_O,           EN_P,      XXXXXXX,
    EN_RPRN,     EN_H,           EN_J,        EN_K,          EN_L,           XXXXXXX,   XXXXXXX,
                 EN_N,           EN_M,        XXXXXXX,       XXXXXXX,        AG_DOT,    AG_SLSH,
                                 TT(L_MOVE),  TT(L_PROG),    TT(L_KEEB),     EN_PIPE,   GONKI,
    S(KC_TAB),
    KC_TAB,      KC_ENTER,       SFT_N
  ),
  [L_EN_S] = LAYOUT_ML(
    _______,     AG_EXCL,        AG_DQUO,     EN_HASH,       EN_DLR,         AG_PERC,   AG_PLUS,
    _______,     EN_S_Q,         EN_S_W,      EN_S_E,        EN_S_R,         EN_S_T,    EN_LCBR,
    AG_SCLN,     EN_S_A,         EN_S_S,      EN_S_D,        EN_S_F,         EN_S_G,    EN_RCBR,
    AG_3DOT,     EN_S_Z,         EN_S_X,      EN_S_C,        EN_S_V,         EN_S_B,
    _______,     _______,        _______,     _______,       _______,
    _______,
    _______,     _______,        _______,
    
    EN_TILD,     EN_CIRC,        AG_QUES,     AG_ASTR,       EN_AMPR,        EN_AT,     AG_UNDS,
    EN_LT,       EN_S_Y,         EN_S_U,      EN_S_I,        EN_S_O,         EN_S_P,    _______,
    EN_GT,       EN_S_H,         EN_S_J,      EN_S_K,        EN_S_L,         _______,   _______,
                 EN_S_N,         EN_S_M,      _______,       _______,        AG_COLN,   AG_BSLS,
                                 _______,     _______,       _______,        EN_QUOT,   _______,
    _______,
    _______,     _______,        _______
  ),
  [L_RU] = LAYOUT_ML(
    _______,     AG_1,           AG_2,        AG_3,          AG_4,           AG_5,      AG_EQL,
    _______,     RU_J,           RU_TS,       RU_U,          RU_K,           TD(D_EYO), EN_LBRC,
    AG_CMSP,     RU_F,           RU_Y,        RU_V,          RU_A,           RU_P,      EN_RBRC,
    AG_SDOT,     RU_JA,          RU_CH,       RU_S,          RU_M,           RU_I,
    _______,     _______,        _______,     _______,       _______,
    _______,
    _______,     _______,        _______,
    
    EN_GRV,      AG_6,           AG_7,        AG_8,          AG_9,           AG_0,      AG_MINS,
    EN_LPRN,     RU_N,           RU_G,        RU_SH,         RU_SC,          RU_Z,      RU_H,
    EN_RPRN,     RU_R,           RU_O,        RU_L,          RU_D,           RU_ZH,     RU_E,
                 RU_T,           TD(D_SIGNS), RU_B,          RU_JU,          AG_DOT,    AG_SLSH,
                                 _______,     _______,       _______,        EN_PIPE,   _______,
    _______,
    _______,     _______,        _______
  ),
  [L_RU_S] = LAYOUT_ML(
    _______,     AG_EXCL,        AG_DQUO,     EN_HASH,       EN_DLR,         AG_PERC,   AG_PLUS,
    _______,     RU_S_J,         RU_S_TS,     RU_S_U,        RU_S_K,         TD(D_EYO), EN_LCBR,
    AG_SCLN,     RU_S_F,         RU_S_Y,      RU_S_V,        RU_S_A,         RU_S_P,    EN_RCBR,
    AG_3DOT,     RU_S_JA,        RU_S_CH,     RU_S_S,        RU_S_M,         RU_S_I,
    _______,     _______,        _______,     _______,       _______,
    _______,
    _______,     _______,        _______,
    
    EN_TILD,     EN_CIRC,        AG_QUES,     AG_ASTR,       EN_AMPR,        EN_AT,     AG_UNDS,
    EN_LT,       RU_S_N,         RU_S_G,      RU_S_SH,       RU_S_SC,        RU_S_Z,    RU_S_H,
    EN_GT,       RU_S_R,         RU_S_O,      RU_S_L,        RU_S_D,         RU_S_ZH,   RU_S_E,
                 RU_S_T,         TD(D_SIGNS), RU_S_B,        RU_S_JU,        AG_COLN,   AG_BSLS,
                                 _______,     _______,       _______,        EN_QUOT,   _______,
    _______,
    _______,     _______,        _______
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
    TD(D_SNAP),
    KC_TAB,       KC_ENTER,      SFT_N
  ),
  [L_PROG] = LAYOUT_ML(
    L_ESCAPE,     _______,       _______,     _______,       _______,        _______,    _______,
    _______,      LALT(KC_F4),   CASH(KC_W),  CASH(KC_E),    LALT(KC_TAB),   CASH(KC_T), _______,
    _______,      CASH(KC_A),    CASH(KC_S),  CASH(KC_D),    CASH(KC_F),     CASH(KC_G), _______,
    _______,      CASH(KC_Z),    CASH(KC_X),  CASH(KC_C),    CASH(KC_V),     CASH(KC_B),
    _______,      TD(D_SNAP),    _______,     _______,       _______,
    _______,        
    KC_SPACE,     KC_BSPACE,     KC_DELETE,

    _______,      _______,       _______,     _______,       _______,        _______,    _______, 
    _______,    TD(D_QUEUE), KC_AUDIO_MUTE, KC_AUDIO_VOL_UP, CASH(KC_O),     _______,    _______, 
    _______,  KC_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,_______, _______, 
    KC_DOWN,      CASH(KC_M),    KC_AUDIO_VOL_DOWN,_______,  _______,        _______, 
    _______,      _______,       _______,     _______,       LOCK,
    _______,
    KC_TAB,       KC_ENTER,      SFT_N
  ),
  [L_KEEB] = LAYOUT_ML(
    L_ESCAPE,     _______,       _______,     _______,       _______,        _______,    LED_LEVEL,
    _______,      _______, TOGGLE_LAYER_COLOR,_______,       RGB_SLD,        _______,    _______,
    _______,      RGB_HUI,       RGB_SAI,     RGB_VAI,       RGB_TOG,        RGB_SPI,    _______,
    LA_SYNC,      RGB_HUD,       RGB_SAD,     RGB_VAD,       _______,        RGB_SPD,
    _______,      TD(D_SNAP),    _______,     _______,       _______,       
    _______,
    KC_SPACE,     KC_BSPACE,     KC_DELETE,

    _______,      _______,       _______,     _______,       _______,        _______,    RESET,  
    _______,      _______,       _______,     _______,       _______,        _______,    _______, 
    _______,      _______,       AU_TOG,      _______,       _______,        _______,    _______, 
    MU_MOD,       MU_TOG,        _______,     _______,       _______,        _______,
    _______,      _______,       _______,     _______,       LOCK,
    _______,
    KC_TAB,       KC_ENTER,      SFT_N
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
    case L_RU:
    case L_RU_S:
      set_layer_color(1);
      break;
    case L_MOVE:
      set_layer_color(2);
      break;
    case L_PROG:
      set_layer_color(3);
      break;
    case L_KEEB:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!lang_shift_process_record(keycode, record)) {
    return false;
  } 

  switch (keycode) {
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
    case LOCK:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_L)));
      if(IS_LAYER_ON(L_RU)) {
        tap_code16(LA_CHNG);
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

void user_timer(void) {
  lang_shift_user_timer();
}

void matrix_scan_user(void) {
  user_timer();
}