#include QMK_KEYBOARD_H


#define _MAIN 0
#define _SYMBOLS 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  MAIN = SAFE_RANGE,
  SYMBOLS,
  NAV,
  ADJUST,
};

// Tap Dance keycodes
enum td_keycodes {
    LCTL_UNDO, // `LCTL` when held, `UNDO` when tapped
    LALT_CUT, // `LALT` when held, `CUT` when tapped
    LGUI_COPY, // `LGUI` when held, `COPY` when tapped
    LSFT_PSTE // `LSFT` when held, `PSTE` when tapped
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void lctl_undo_finished(qk_tap_dance_state_t *state, void *user_data);
void lctl_undo_reset(qk_tap_dance_state_t *state, void *user_data);
void lalt_cut_finished(qk_tap_dance_state_t *state, void *user_data);
void lalt_cut_reset(qk_tap_dance_state_t *state, void *user_data);
void lgui_copy_finished(qk_tap_dance_state_t *state, void *user_data);
void lgui_copy_reset(qk_tap_dance_state_t *state, void *user_data);
void lsft_pste_finished(qk_tap_dance_state_t *state, void *user_data);
void lsft_pste_reset(qk_tap_dance_state_t *state, void *user_data);

enum combos {
  LRSFT_CAPLOCKS,
};

const uint16_t PROGMEM lrsft_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [LRSFT_CAPLOCKS] = COMBO(lrsft_combo, KC_LCAP),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌────────┬    ────────┬        ────────┬        ────────┬        ────────┬        ────────┐                                     ┌────────┬────────┬        ────────┬        ────────┬        ────────┬        ────────┐
     KC_NO,       KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,                                         KC_NO,   KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,
  //├────────┼    ────────┼        ────────┼        ────────┼        ────────┼        ────────┤                                     ├────────┼────────┼        ────────┼        ────────┼        ────────┼        ────────┤
     KC_NO,       KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,                                          KC_Y,    KC_U,            KC_I,            KC_O,            KC_P,            KC_NO,
  //├────────┼    ────────┼        ────────┼        ────────┼        ────────┼        ────────┤                                     ├────────┼────────┼        ────────┼        ────────┼        ────────┼        ────────┤
     KC_NO,       LCTL_T(KC_A),    LALT_T(KC_S),    LGUI_T(KC_D),    LSFT_T(KC_F),    KC_G,                                          KC_H,    RSFT_T(KC_J),    RGUI_T(KC_K),    RALT_T(KC_L),    RCTL_T(KC_SCLN), KC_NO,
  //├────────┼    ────────┼        ────────┼        ────────┼        ────────┼        ────────┼────────┐                   ┌────────┼────────┼────────┼        ────────┼        ────────┼        ────────┼        ────────┤
     KC_NO,       KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,    KC_NO,                       KC_NO,   KC_N,    KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_NO,
  //└────────┴    ────────┴        ────────┴        ───┬────┴        ───┬────┴        ───┬────┴───┬────┘                   └───┬────┴───┬────┴───┬────┴        ───┬────┴        ────────┴        ────────┴        ────────┘
                                                                         TT(_NAV),  KC_BSPC, KC_ENT,                            KC_SPC,  TT(_SYMBOLS),KC_ESC
                                                                     // └────────┴────────┴────────┘                           └────────┴────────┴────────┘
  ),

  [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬     ────────┬     ────────┬     ────────┬     ────────┐                          ┌────────┬────────┬     ────────┬     ────────┬       ────────┬     ────────┐
     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                              KC_NO,   KC_NO,        KC_NO,        KC_NO,          KC_NO,        KC_NO,
  //├────────┼────────┼     ────────┼     ────────┼     ────────┼     ────────┤                          ├────────┼────────┼     ────────┼     ────────┼       ────────┼     ────────┤
     KC_NO,   KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,                            KC_CIRC, KC_AMPR,      KC_ASTR,      KC_LPRN,        KC_RPRN,      KC_NO,
  //├────────┼────────┼     ────────┼     ────────┼     ────────┼     ────────┤                          ├────────┼────────┼     ────────┼     ────────┼       ────────┼     ────────┤
     KC_NO,   LCTL_T(KC_1), LALT_T(KC_2), LGUI_T(KC_3), LSFT_T(KC_4), KC_5,                               KC_6,    RSFT_T(KC_7), RGUI_T(KC_8), RALT_T(KC_9),   RCTL_T(KC_0), KC_NO,
  //├────────┼────────┼     ────────┼     ────────┼     ────────┼     ────────┼────────┐        ┌────────┼────────┼────────┼     ────────┼     ────────┼       ────────┼     ────────┤
     KC_NO,   KC_TAB,       KC_GRV,       KC_LBRC,      KC_RBRC,      KC_BSLS, _______,          _______, KC_QUOT, KC_MINS,      _______,      _______,        _______,      KC_NO,
  //└────────┴────────┴     ────────┴     ───┬────┴     ───┬────┴     ───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴     ───┬────┴     ────────┴       ────────┴     ────────┘
                                                        _______, _______, _______,                    _______,  _______, _______
                                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬      ────────┬     ────────┬      ────────┬      ────────┐                          ┌────────┬────────┬        ────────┬        ────────┬       ────────┬        ────────┐
     KC_NO,   KC_NO,         KC_NO,        KC_NO,         KC_NO,         KC_NO,                              KC_NO,   KC_NO,           KC_NO,           KC_NO,          KC_NO,           KC_NO,
  //├────────┼────────┼      ────────┼     ────────┼      ────────┼      ────────┤                          ├────────┼────────┼        ────────┼        ────────┼       ────────┼        ────────┤
     KC_NO,   KC_F1,         KC_F2,        KC_F3,         KC_F4,         KC_F5,                              KC_F6,   KC_F7,           KC_F8,           KC_F9,          KC_F10,          KC_NO,
  //├────────┼────────┼      ────────┼     ────────┼      ────────┼      ────────┤                          ├────────┼────────┼        ────────┼        ────────┼       ────────┼        ────────┤
     KC_NO,   TD(LCTL_UNDO), TD(LALT_CUT), TD(LGUI_COPY), TD(LSFT_PSTE), KC_F11,                             KC_BTN1, RSFT_T(KC_LEFT), RGUI_T(KC_DOWN), RALT_T(KC_UP),  RCTL_T(KC_RGHT), KC_NO,
  //├────────┼────────┼      ────────┼     ────────┼      ────────┼      ────────┼────────┐        ┌────────┼────────┼────────┼        ────────┼        ────────┼       ────────┼        ────────┤
     KC_NO,   KC_END,        KC_HOME,      KC_INS,        KC_DEL,        KC_F12, _______,          _______,  KC_BTN3, KC_MS_L,         KC_MS_D,         KC_MS_U,        KC_MS_R,         KC_NO,
  //└────────┴────────┴      ────────┴     ───┬────┴      ───┬────┴      ───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴        ───┬────┴        ────────┴       ────────┴        ────────┘
                                                           _______, _______, _______,                    _______,  _______, _______
                                                       // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void lctl_undo_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(G(KC_Z));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(G(KC_Z));
            register_code16(G(KC_Z));
            break;
        default:
            break;
    }
}

void lctl_undo_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(G(KC_Z));
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(G(KC_Z));
            break;
        default:
            break;
    }
}

void lalt_cut_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(G(KC_X));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(G(KC_X));
            register_code16(G(KC_X));
            break;
        default:
            break;
    }
}

void lalt_cut_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(G(KC_X));
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(G(KC_X));
            break;
        default:
            break;
    }
}

void lgui_copy_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(G(KC_C));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LGUI)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(G(KC_C));
            register_code16(G(KC_C));
            break;
        default:
            break;
    }
}

void lgui_copy_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(G(KC_C));
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LGUI)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(G(KC_C));
            break;
        default:
            break;
    }
}

void lsft_pste_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(G(KC_V));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(G(KC_V));
            register_code16(G(KC_V));
            break;
        default:
            break;
    }
}

void lsft_pste_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(G(KC_V));
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(G(KC_V));
            break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [LCTL_UNDO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lctl_undo_finished, lctl_undo_reset),
    [LALT_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lalt_cut_finished, lalt_cut_reset),
    [LGUI_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lgui_copy_finished, lgui_copy_reset),
    [LSFT_PSTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsft_pste_finished, lsft_pste_reset)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MAIN);
      }
      return false;
      break;
    case SYMBOLS:
      if (record->event.pressed) {
        layer_on(_SYMBOLS);
        update_tri_layer(_SYMBOLS, _NAV, _ADJUST);
      } else {
        layer_off(_SYMBOLS);
        update_tri_layer(_SYMBOLS, _NAV, _ADJUST);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
        update_tri_layer(_SYMBOLS, _NAV, _ADJUST);
      } else {
        layer_off(_NAV);
        update_tri_layer(_SYMBOLS, _NAV, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
