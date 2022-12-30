#include QMK_KEYBOARD_H


#define _MAC 0
#define _MACNAV 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  MAC = SAFE_RANGE,
  MACNAV,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAC] = LAYOUT(
  //┌────────┬    ────────┬        ────────┬        ────────┬        ────────┬        ────────┐                          ┌────────┬────────┬        ────────┬        ────────┬        ────────┬        ────────┐
     KC_NO,       KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,                              KC_NO,   KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,
  //├────────┼    ────────┼        ────────┼        ────────┼        ────────┼        ────────┤                          ├────────┼────────┼        ────────┼        ────────┼        ────────┼        ────────┤
     KC_ESC,      KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,                               KC_Y,    KC_U,            KC_I,            KC_O,            KC_P,            KC_MINS,
  //├────────┼    ────────┼        ────────┼        ────────┼        ────────┼        ────────┤                          ├────────┼────────┼        ────────┼        ────────┼        ────────┼        ────────┤
     KC_TAB,      LCTL_T(KC_A),    LALT_T(KC_S),    LGUI_T(KC_D),    LSFT_T(KC_F),    KC_G,                               KC_H,    RSFT_T(KC_J),    RGUI_T(KC_K),    RALT_T(KC_L),    RCTL_T(KC_SCLN), KC_QUOT,
  //├────────┼    ────────┼        ────────┼        ────────┼        ────────┼        ────────┼────────┐        ┌────────┼────────┼────────┼        ────────┼        ────────┼        ────────┼        ────────┤
     KC_CAPS,     KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,    KC_NO,            KC_NO,   KC_N,    KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_EQL,
  //└────────┴    ────────┴        ────────┴        ───┬────┴        ───┬────┴        ───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴        ───┬────┴        ────────┴        ────────┴        ────────┘
                                                                         KC_DEL,  KC_BSPC, KC_ENT,                   KC_SPC,  TT(_MACNAV),KC_NO
                                                                     // └────────┴────────┴────────┘                └────────┴────────┴────────┘
  ),

  [_MACNAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_GRV,                             KC_LBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), KC_BSLS, _______,          _______, KC_RBRC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MAC);
      }
      return false;
      break;
    case MACNAV:
      if (record->event.pressed) {
        layer_on(_MACNAV);
        update_tri_layer(_MACNAV, _RAISE, _ADJUST);
      } else {
        layer_off(_MACNAV);
        update_tri_layer(_MACNAV, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_MACNAV, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_MACNAV, _RAISE, _ADJUST);
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
