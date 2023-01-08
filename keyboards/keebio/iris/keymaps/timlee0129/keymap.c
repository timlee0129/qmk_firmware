#include QMK_KEYBOARD_H


#define _MAIN 0
#define _SYMBOLS 1
#define _NAV 2
#define _SYMBOLS2 3

enum custom_keycodes {
  MAIN = SAFE_RANGE,
  SYMBOLS,
  NAV,
  SYMBOLS2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌────────┬    ────────┬        ────────┬        ────────┬        ────────┬        ────────┐                                     ┌────────┬────────┬        ────────┬        ────────┬        ────────┬        ────────┐
     KC_NO,       KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,                                         KC_NO,   KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,
  //├────────┼    ────────┼        ────────┼        ────────┼        ────────┼        ────────┤                                     ├────────┼────────┼        ────────┼        ────────┼        ────────┼        ────────┤
     KC_ESC,      KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,                                          KC_Y,    KC_U,            KC_I,            KC_O,            KC_P,            KC_MINS,
  //├────────┼    ────────┼        ────────┼        ────────┼        ────────┼        ────────┤                                     ├────────┼────────┼        ────────┼        ────────┼        ────────┼        ────────┤
     KC_TAB,      LALT_T(KC_A),    LCTL_T(KC_S),    LGUI_T(KC_D),    LSFT_T(KC_F),    KC_G,                                          KC_H,    RSFT_T(KC_J),    RGUI_T(KC_K),    RCTL_T(KC_L),    RALT_T(KC_SCLN), KC_QUOT,
  //├────────┼    ────────┼        ────────┼        ────────┼        ────────┼        ────────┼────────┐                   ┌────────┼────────┼────────┼        ────────┼        ────────┼        ────────┼        ────────┤
     KC_CAPS,     KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,    KC_NO,                       KC_NO,   KC_N,    KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_EQL,
  //└────────┴    ────────┴        ────────┴        ───┬────┴        ───┬────┴        ───┬────┴───┬────┘                   └───┬────┴───┬────┴───┬────┴        ───┬────┴        ────────┴        ────────┴        ────────┘
                                                                         TT(_NAV), KC_BSPC, KC_ENT,                            KC_SPC,  TT(_SYMBOLS),KC_DEL
                                                                     // └────────┴────────┴────────┘                           └────────┴────────┴────────┘
  ),

  [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬     ────────┬     ────────┬     ────────┬     ────────┐                          ┌────────┬────────┬     ────────┬     ────────┬       ────────┬     ────────┐
     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                              KC_NO,   KC_NO,        KC_NO,        KC_NO,          KC_NO,        KC_NO,
  //├────────┼────────┼     ────────┼     ────────┼     ────────┼     ────────┤                          ├────────┼────────┼     ────────┼     ────────┼       ────────┼     ────────┤
     _______, KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,                            KC_CIRC, KC_AMPR,      KC_ASTR,      KC_LPRN,        KC_RPRN,      _______,
  //├────────┼────────┼     ────────┼     ────────┼     ────────┼     ────────┤                          ├────────┼────────┼     ────────┼     ────────┼       ────────┼     ────────┤
     _______, LALT_T(KC_1), LCTL_T(KC_2), LGUI_T(KC_3), LSFT_T(KC_4), KC_5,                               KC_6,    RSFT_T(KC_7), RGUI_T(KC_8), RCTL_T(KC_9),   RALT_T(KC_0), _______,
  //├────────┼────────┼     ────────┼     ────────┼     ────────┼     ────────┼────────┐        ┌────────┼────────┼────────┼     ────────┼     ────────┼       ────────┼     ────────┤
     _______, KC_LCBR,      KC_RCBR,      KC_LBRC,      KC_RBRC,      KC_BSLS, _______,          _______, KC_LPRN, KC_RPRN,      _______,      _______,        _______,      _______,
  //└────────┴────────┴     ────────┴     ───┬────┴     ───┬────┴     ───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴     ───┬────┴     ────────┴       ────────┴     ────────┘
                                                        _______, _______, _______,                    _______,  _______, _______
                                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_GRV,                             KC_DEL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), KC_NO,   _______,          _______, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    _______,  MO(_SYMBOLS2), KC_BTN1
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOLS2] = LAYOUT(
  //┌────────┬────────┬     ────────┬     ────────┬     ────────┬     ────────┐                          ┌────────┬────────┬     ────────┬     ────────┬       ────────┬     ────────┐
     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                              KC_NO,   KC_NO,        KC_NO,        KC_NO,          KC_NO,        KC_NO,
  //├────────┼────────┼     ────────┼     ────────┼     ────────┼     ────────┤                          ├────────┼────────┼     ────────┼     ────────┼       ────────┼     ────────┤
     _______, KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,                            KC_CIRC, KC_AMPR,      KC_ASTR,      KC_LPRN,        KC_RPRN,      _______,
  //├────────┼────────┼     ────────┼     ────────┼     ────────┼     ────────┤                          ├────────┼────────┼     ────────┼     ────────┼       ────────┼     ────────┤
     _______, LALT_T(KC_1), LCTL_T(KC_2), LGUI_T(KC_3), LSFT_T(KC_4), KC_5,                               KC_6,    RSFT_T(KC_7), RGUI_T(KC_8), RCTL_T(KC_9),   RALT_T(KC_0), _______,
  //├────────┼────────┼     ────────┼     ────────┼     ────────┼     ────────┼────────┐        ┌────────┼────────┼────────┼     ────────┼     ────────┼       ────────┼     ────────┤
     _______, KC_LCBR,      KC_RCBR,      KC_LBRC,      KC_RBRC,      KC_BSLS, _______,          _______, KC_LPRN, KC_RPRN,      _______,      _______,        _______,      _______,
  //└────────┴────────┴     ────────┴     ───┬────┴     ───┬────┴     ───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴     ───┬────┴     ────────┴       ────────┴     ────────┘
                                                        _______, _______, _______,                    _______,  _______, _______
                                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
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
        update_tri_layer(_SYMBOLS, _NAV, _SYMBOLS2);
      } else {
        layer_off(_SYMBOLS);
        update_tri_layer(_SYMBOLS, _NAV, _SYMBOLS2);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
        update_tri_layer(_SYMBOLS, _NAV, _SYMBOLS2);
      } else {
        layer_off(_NAV);
        update_tri_layer(_SYMBOLS, _NAV, _SYMBOLS2);
      }
      return false;
      break;
    case SYMBOLS2:
      if (record->event.pressed) {
        layer_on(_SYMBOLS2);
      } else {
        layer_off(_SYMBOLS2);
      }
      return false;
      break;
  }
  return true;
}
