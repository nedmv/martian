#include QMK_KEYBOARD_H
#include "version.h"
#include "layers.h"
// #include "keymap_russian.h"
#include "dances.c"
#include "lighting.c"

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

enum custom_keycodes {
  RGB_SLD = CUSTOM_SAFE_RANGE,
  GONKI, // Start next race on klavogonki.ru
  TO_RU, //Invert state of russian layer and toggle layout.
  L_ESCAPE, // TO L_RU, if it's active. Else TO L_EN.
  LOCK, // Lock screen and move to layer 0.
  COPY_URL, // Copy current browser URL to clipboard.

  CUSTOM_KEYCODES_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE CUSTOM_KEYCODES_SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_EN] = LAYOUT_ML(
    KC_ESCAPE,   AG_1,           AG_2,        AG_3,          AG_4,           AG_5,      AG_EQL,
    OSL(L_PROG), EN_Q,           EN_W,        EN_E,          EN_R,           EN_T,      EN_LBRC,
    AG_CMSP,     EN_A,           EN_S,        EN_D,          EN_F,           EN_G,      EN_RBRC,
    TT(L_MOUSE), EN_Z,           EN_X,        EN_C,          EN_V,           EN_B,
    LA_CHNG,     AG_COMM,        WIN_0,       ALT_0,         CTRL_0,
    SFT_N,
    KC_SPACE,    KC_BSPACE,      KC_DELETE,
    
    EN_GRV,      AG_6,           AG_7,        AG_8,          AG_9,           AG_0,      AG_MINS,
    EN_LPRN,     EN_Y,           EN_U,        EN_I,          EN_O,           EN_P,      XXXXXXX,
    EN_RPRN,     EN_H,           EN_J,        EN_K,          EN_L,           XXXXXXX,   XXXXXXX,
                 EN_N,           EN_M,        EN_QUOT,       XXXXXXX,        AG_DOT,    AG_SLSH,
                                 TT(L_MOVE),  TT(L_PROG),    TT(L_KEEB),     EN_PIPE,   GONKI,
    S(KC_TAB),
    KC_TAB,      KC_ENTER,       SFT_N
  ),
  [L_EN_S] = LAYOUT_ML(
    _______,     AG_EXCL,        AG_DQUO,     EN_HASH,       EN_DLR,         AG_PERC,   AG_PLUS,
    _______,     EN_S_Q,         EN_S_W,      EN_S_E,        EN_S_R,         EN_S_T,    EN_LCBR,
    AG_SCLN,     EN_S_A,         EN_S_S,      EN_S_D,        EN_S_F,         EN_S_G,    EN_RCBR,
    _______,     EN_S_Z,         EN_S_X,      EN_S_C,        EN_S_V,         EN_S_B,
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
    _______,     RU_JA,          RU_CH,       RU_S,          RU_M,           RU_I,
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
    _______,     RU_S_JA,        RU_S_CH,     RU_S_S,        RU_S_M,         RU_S_I,
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
    L_ESCAPE,     KC_F1,         KC_F2,       KC_F3,         KC_F4,          KC_F5,      XXXXXXX,
    _______,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,
    XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,
    _______,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,
    XXXXXXX,      XXXXXXX,       _______,     _______,       _______,
    _______,
    _______,      _______,       _______,

    KC_F11,       KC_F6,         KC_F7,       KC_F8,         KC_F9,          KC_F10,     KC_F12,
    XXXXXXX,      XXXXXXX,       KC_HOME,     KC_PGUP,       KC_PGDOWN,      KC_END,     XXXXXXX, 
    XXXXXXX,      XXXXXXX,       KC_LEFT,     KC_UP,         KC_DOWN,        KC_RIGHT,   XXXXXXX,   
                  XXXXXXX,    LCTL(KC_LEFT), LCTL(KC_UP), LCTL(KC_DOWN), LCTL(KC_RIGHT), XXXXXXX,              
                                 _______,      _______,       _______,       XXXXXXX,    LOCK,  
    TD(D_SNAP),
    _______,      _______,       _______
  ),
  [L_PROG] = LAYOUT_ML(
    L_ESCAPE,     XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,
    _______,      LALT(KC_F4),   CASH(KC_W),  CASH(KC_E),    LALT(KC_TAB),   CASH(KC_T), COPY_URL,
    XXXXXXX,      CASH(KC_A),    CASH(KC_S),  CASH(KC_D),    CASH(KC_F),     CASH(KC_G), XXXXXXX,
    _______,      CASH(KC_Z),    CASH(KC_X),  CASH(KC_C),    CASH(KC_V),     CASH(KC_B),
    XXXXXXX,      XXXXXXX,       _______,     _______,       _______,
    _______,        
    _______,      _______,       _______,

    XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX, 
    XXXXXXX,    TD(D_QUEUE), KC_AUDIO_MUTE, KC_AUDIO_VOL_UP, CASH(KC_O),     XXXXXXX,    XXXXXXX, 
    XXXXXXX,  KC_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,XXXXXXX, XXXXXXX, 
                  KC_DOWN,      CASH(KC_M),KC_AUDIO_VOL_DOWN,XXXXXXX,        XXXXXXX,    XXXXXXX, 
                                _______,      _______,       _______,        XXXXXXX,    LOCK,
    _______,
    _______,      _______,       _______
  ),
  [L_KEEB] = LAYOUT_ML(
    L_ESCAPE,     XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    LED_LEVEL,
    _______,      XXXXXXX, TOGGLE_LAYER_COLOR,XXXXXXX,       RGB_MOD,        XXXXXXX,    XXXXXXX,
    XXXXXXX,      RGB_HUI,       RGB_SAI,     RGB_VAI,       RGB_SLD,        RGB_SPI,    XXXXXXX,
    _______,      RGB_HUD,       RGB_SAD,     RGB_VAD,       RGB_TOG,        RGB_SPD,
    LA_SYNC,      XXXXXXX,       _______,     _______,       _______,       
    _______,
    _______,      _______,       _______,

    XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    RESET,  
    XXXXXXX,      XXXXXXX,       LA_CAPS,     LA_ALSH,       LA_CTSH,        LA_WISP,    XXXXXXX, 
    XXXXXXX,      XXXXXXX,       AU_TOG,      XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX, 
                  MU_MOD,        MU_TOG,      XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,
                                 _______,     _______,       _______,        XXXXXXX,    LOCK,
    _______,
    _______,      _______,       _______
  ),
  [L_MOUSE] = LAYOUT_ML(
    L_ESCAPE,     XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,
    _______,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,
    XXXXXXX,      KC_MS_BTN2, KC_MS_WH_DOWN,  KC_MS_WH_UP,   KC_MS_BTN1,     XXXXXXX,    XXXXXXX,
    _______,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,
    XXXXXXX,      XXXXXXX,       _______,     _______,       _______,       
    _______,
    _______,      _______,       _______,

    XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,  
    XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX, 
    XXXXXXX,      XXXXXXX,       KC_MS_LEFT,  KC_MS_UP,      KC_MS_DOWN,     KC_MS_RIGHT,XXXXXXX, 
                  XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,
                                 _______,     _______,       _______,        XXXXXXX,    XXXXXXX,
    _______,
    _______,      _______,       _______
  ),
  // [L_STUB] = LAYOUT_ML(
  //   L_ESCAPE,     XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,
  //   XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,
  //   _______,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,
  //   XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,
  //   _______,      XXXXXXX,       _______,     _______,       _______,       
  //   _______,
  //   _______,      _______,       _______,

  //   XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,  
  //   XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX, 
  //   XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX, 
  //                 XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,
  //                                _______,     _______,       _______,        XXXXXXX,    _______,
  //   _______,
  //   _______,      _______,       _______
  // ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
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
    return false;
    case L_ESCAPE:
    if (record->event.pressed) {
      layer_move(IS_LAYER_ON(L_RU)?L_RU:L_EN);
    }
    return false;
    case LOCK:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_L)));
      if(IS_LAYER_ON(L_RU)) {
        keyrecord_t record;
        record.event.pressed = true;
        lang_shift_process_record(LA_CHNG, &record);
      }
      layer_move(L_EN);
    }
    return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
    return false;
    case COPY_URL:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        tap_code(KC_L);
        tap_code(KC_C);
        unregister_code(KC_LCTRL);
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