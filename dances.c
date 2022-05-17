enum tap_dance_codes {
  D_SNAP, // [CUSTOM] Window snapshot on tap - Area snapshot on hold 
  D_EYO, // Russian "Е" on tap, russian "Ё" on hold
  D_EHYO, // Russian "Э" on tap, russian "Ё" on double tap
  D_SIGNS, // Russian "Ь" on tap, russian "Ъ" on double tap
  D_QUEUE, // [CUSTOM] Add song to the end of queue on tap - Add song to the beginning of queue on hold
  TAP_DANCE_RANGE,
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

static tap dance_state[TAP_DANCE_RANGE];

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // FIXME: not working properly?
    MORE_TAPS
};

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

void D_SNAP_finished(qk_tap_dance_state_t *state, void *user_data);
void D_SNAP_reset(qk_tap_dance_state_t *state, void *user_data);

void D_SNAP_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[D_SNAP].step = dance_step(state);
    switch (dance_state[D_SNAP].step) {
        case SINGLE_TAP: register_code16(KC_PSCREEN); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_PSCREEN)); break;
    }
}

void D_SNAP_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[D_SNAP].step) {
        case SINGLE_TAP: unregister_code16(KC_PSCREEN); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_PSCREEN)); break;
    }
    dance_state[D_SNAP].step = 0;
}

void D_EYO_finished(qk_tap_dance_state_t *state, void *user_data);
void D_EYO_reset(qk_tap_dance_state_t *state, void *user_data);

void D_EYO_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[D_EYO].step = dance_step(state);
    switch (dance_state[D_EYO].step) {
        case SINGLE_TAP: register_code(KC_T); break;
        case SINGLE_HOLD: register_code(KC_GRAVE); break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP: tap_code(KC_T); register_code(KC_T); break;
        case DOUBLE_HOLD: tap_code(KC_T); register_code(KC_GRAVE);
    }
}

void D_EYO_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[D_EYO].step) {
        case SINGLE_TAP: unregister_code(KC_T); break;
        case SINGLE_HOLD: unregister_code(KC_GRAVE); break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP: unregister_code(KC_T); break;
        case DOUBLE_HOLD: unregister_code(KC_GRAVE);
    }
    dance_state[D_EYO].step = 0;
}

void D_EHYO_finished(qk_tap_dance_state_t *state, void *user_data);
void D_EHYO_reset(qk_tap_dance_state_t *state, void *user_data);

void D_EHYO_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[D_EHYO].step = dance_step(state);
    switch (dance_state[D_EHYO].step) {
        case SINGLE_TAP: register_code(KC_QUOT); break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP: register_code(KC_GRAVE);
    }
}

void D_EHYO_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[D_EHYO].step) {
        case SINGLE_TAP: unregister_code(KC_QUOT); break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP: unregister_code(KC_GRAVE);
    }
    dance_state[D_EHYO].step = 0;
}



void D_SIGNS_finished(qk_tap_dance_state_t *state, void *user_data);
void D_SIGNS_reset(qk_tap_dance_state_t *state, void *user_data);

void D_SIGNS_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[D_SIGNS].step = dance_step(state);
    switch (dance_state[D_SIGNS].step) {
        case SINGLE_TAP: register_code(KC_M); break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP: register_code(KC_RBRACKET);
    }
}

void D_SIGNS_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[D_SIGNS].step) {
        case SINGLE_TAP: unregister_code(KC_M); break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP: unregister_code(KC_RBRACKET);
    }
    dance_state[D_SIGNS].step = 0;
}

void D_QUEUE_finished(qk_tap_dance_state_t *state, void *user_data);
void D_QUEUE_reset(qk_tap_dance_state_t *state, void *user_data);

void D_QUEUE_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[D_QUEUE].step = dance_step(state);
    switch (dance_state[D_QUEUE].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_D)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_D))); break;
    }
}

void D_QUEUE_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[D_QUEUE].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_D)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_D))); break;
    }
    dance_state[D_QUEUE].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[TAP_DANCE_RANGE] = {
        [D_SNAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, D_SNAP_finished, D_SNAP_reset),
        [D_EYO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, D_EYO_finished, D_EYO_reset),
        [D_EHYO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, D_EHYO_finished, D_EHYO_reset),
        [D_SIGNS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, D_SIGNS_finished, D_SIGNS_reset),
        [D_QUEUE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, D_QUEUE_finished, D_QUEUE_reset),
};