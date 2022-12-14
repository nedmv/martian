#include "layers.h" // layers enum

#define COMMA ,

#define COLOR_OFF {0 COMMA 0 COMMA 0}
#define _________ COLOR_OFF

#define COLOR_RED {0 COMMA 255 COMMA 255}
#define COLOR_GREEN {85 COMMA 255 COMMA 255}
#define COLOR_BLUE {170 COMMA 255 COMMA 255}

#define COLOR_DBLUE {146 COMMA 224 COMMA 255}
#define COLOR_YELLOW {33 COMMA 255 COMMA 255}
#define COLOR_ORANGE {14 COMMA 255 COMMA 255}
#define COLOR_PURPLE {243 COMMA 222 COMMA 234}

#define COLOR_KEEB {30 COMMA 96 COMMA 255}
#define COLOR_RU COLOR_BLUE
#define COLOR_PROG COLOR_GREEN
#define COLOR_MOUSE COLOR_YELLOW

#define LEDS_ML( \
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
{ \
    k00, k10, k20, k30, k40, \
    k01, k11, k21, k31, k41, \
    k02, k12, k22, k32, k42, \
    k03, k13, k23, k33, k43, \
    k04, k14, k24, k34, k44, \
    k05, k15, k25, k35, \
    k06, k16, k26, \
    k50, k51, k52, \
    k53, \
 \
    k66, k76, k86, k96, ka6, \
    k65, k75, k85, k95, ka5, \
    k64, k74, k84, k94, ka4, \
    k63, k73, k83, k93, ka3, \
    k62, k72, k82, k92, ka2, \
    k61, k71, k81, k91, \
    k60, k70, k80, \
    kb4, kb5, kb6, \
    kb3 \
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [L_RU] = LEDS_ML(
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,
        COLOR_RU,
        COLOR_RU,      COLOR_RU,      COLOR_RU,

        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
                       _________,     _________,     _________,     _________,     _________,     _________,
                                      _________,     _________,     _________,     _________,     _________,
        COLOR_RU,
        COLOR_RU,      COLOR_RU,      COLOR_RU
    ), 
    [L_MOVE] = LEDS_ML(
        _________,     COLOR_DBLUE,   COLOR_DBLUE,   COLOR_DBLUE,   COLOR_DBLUE,   COLOR_DBLUE,   _________,
        _________,     COLOR_YELLOW,  COLOR_YELLOW,  COLOR_YELLOW,  COLOR_YELLOW,  _________,     _________,
        _________,     COLOR_ORANGE,  COLOR_ORANGE,  COLOR_ORANGE,  COLOR_ORANGE,  _________,     _________,
        _________,     COLOR_PURPLE,  COLOR_PURPLE,  COLOR_PURPLE,  COLOR_PURPLE,  _________,
        _________,     _________,     _________,     _________,     _________,
        _________,
        _________,     _________,     _________,

        _________,     COLOR_DBLUE,   COLOR_DBLUE,   COLOR_DBLUE,   COLOR_DBLUE,   COLOR_DBLUE,   _________,
        COLOR_DBLUE,   _________,     COLOR_YELLOW,  COLOR_YELLOW,  COLOR_YELLOW,  COLOR_YELLOW,  _________,
        COLOR_DBLUE,   _________,     COLOR_ORANGE,  COLOR_ORANGE,  COLOR_ORANGE,  COLOR_ORANGE,  _________,
                       _________,     COLOR_PURPLE,  COLOR_PURPLE,  COLOR_PURPLE,  COLOR_PURPLE,  _________,
                                      _________,     _________,     _________,     _________,     _________,
        _________,
        _________,     _________,     _________
    ), 

    [L_PROG] = LEDS_ML(
        _________,     _________,     _________,     _________,     _________,     _________,     COLOR_RED,
        _________,     _________,     _________,     _________,     COLOR_YELLOW,  _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,
        COLOR_PROG,
        COLOR_PROG,    COLOR_PROG,    COLOR_PROG,

        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     COLOR_RED,     COLOR_GREEN,   COLOR_YELLOW,  COLOR_GREEN,   _________,
        _________,     _________,     COLOR_GREEN,   COLOR_GREEN,   COLOR_GREEN,   COLOR_GREEN,   _________,
                       _________,     COLOR_DBLUE,   COLOR_GREEN,   _________,     _________,     _________,
                                      _________,     _________,     _________,     _________,     _________,
        COLOR_PROG,
        COLOR_PROG,    COLOR_PROG,    COLOR_PROG
    ), 
    [L_KEEB] = LEDS_ML(
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,
        COLOR_YELLOW,
        COLOR_KEEB,    COLOR_KEEB,    COLOR_KEEB,

        _________,     _________,     _________,     _________,     _________,     _________,     COLOR_RED,
        _________,     _________,     COLOR_GREEN,   COLOR_BLUE,    _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
                       _________,     _________,     _________,     _________,     _________,     _________,
                                      _________,     _________,     _________,     _________,     _________,
        COLOR_KEEB,
        COLOR_KEEB,    COLOR_KEEB,    COLOR_KEEB
    ),
#ifdef MOUSE_LAYER
    [L_MOUSE] = LEDS_ML(
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     COLOR_DBLUE,   COLOR_YELLOW,  COLOR_YELLOW,  COLOR_DBLUE,   _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,
        COLOR_MOUSE,
        COLOR_MOUSE,   COLOR_MOUSE,   COLOR_MOUSE,

        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     COLOR_ORANGE,  COLOR_ORANGE,  COLOR_ORANGE,  COLOR_ORANGE,  _________,
                       _________,     _________,     _________,     _________,     _________,     _________,
                                      _________,     _________,     _________,     _________,     _________,
        COLOR_MOUSE,
        COLOR_MOUSE,   COLOR_MOUSE,   COLOR_MOUSE
    ),
#endif
#ifdef GAME_LAYER
    [L_GAME] = LEDS_ML(
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     COLOR_BLUE,    _________,     _________,     _________,     COLOR_YELLOW,
        _________,     COLOR_BLUE,    COLOR_BLUE,    COLOR_BLUE,    _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,
        COLOR_RED,
        COLOR_BLUE,    COLOR_GREEN,   COLOR_YELLOW,

        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
        _________,     _________,     _________,     _________,     _________,     _________,     _________,
                       _________,     _________,     _________,     _________,     _________,     _________,
                                      _________,     _________,     _________,     _________,     _________,
        _________,
        COLOR_BLUE,    COLOR_GREEN,   COLOR_YELLOW
    ),
#endif
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
  if (rgb_matrix_get_suspend_state() || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    //L_EN and L_EN_S intentionally have no designated cases here
    case L_RU:
    case L_RU_S:
      set_layer_color(L_RU);
      break;
    case L_MOVE:
      set_layer_color(L_MOVE);
      break;
    case L_PROG:
      set_layer_color(L_PROG);
      break;
    case L_KEEB:
      set_layer_color(L_KEEB);
      break;
#ifdef MOUSE_LAYER
    case L_MOUSE:
      set_layer_color(L_MOUSE);
      break;
#endif
#ifdef GAME_LAYER
    case L_GAME:
      set_layer_color(L_GAME);
      break;
#endif
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

// enum ledmap_colors {
//   COLOR_BLACK = COLOR_SAFE_RANGE, // ???????????? ????????
//   COLOR_ANYFN, // ???????? ?????? ????????????, ???????????????????? ?????????? ??????????????
//   COLOR_PINKY, // ?????? ???????????? ???????????????????? ????????????????
//   COLOR_ANNUL, // ????????????????????
//   COLOR_MIDDL, // ??????????????
//   COLOR_INDEX, // ????????????????????????
//   COLOR_THUMB, // ?????????????? ??????????????
// };

// const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL] = {
//   [0] = {  // zones
//       COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY,
//       COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY,
//       COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_THUMB,
//       COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_THUMB,
//       COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB,
//       COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
//       COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
//       COLOR_THUMB,
//       COLOR_THUMB, COLOR_THUMB, COLOR_THUMB, 

//       COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY,
//       COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY,
//       COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_THUMB,
//       COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_THUMB,
//       COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB,
//       COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
//       COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
//       COLOR_THUMB,
//       COLOR_THUMB, COLOR_THUMB, COLOR_THUMB
// }