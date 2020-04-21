#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _EVE 0
#define _FN1 1
#define _FN2 2

enum custom_keycodes {
  EVE = SAFE_RANGE,
  _M_1,
  _M_2,
  _M_3,
  _M_4,
  _L_1,
  _L_2,
  _L_3,
  _L_4
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case _M_1:
    if (record->event.pressed) {
      // SEND_STRING(SS_LALT(SS_TAP(X_F1)));
      register_code(KC_LALT);
      _delay_ms(100);
      register_code(KC_F1);
    } else {
      unregister_code(KC_F1);
      unregister_code(KC_LALT);
    }
    break;
  case _M_2:
    if (record->event.pressed) {
      // SEND_STRING(SS_LALT(SS_TAP(X_F2)));
      register_code(KC_LALT);
      _delay_ms(100);
      register_code(KC_F2);
    } else {
      unregister_code(KC_F2);
      unregister_code(KC_LALT);
    }
    break;
  case _M_3:
    if (record->event.pressed) {
      // SEND_STRING(SS_LALT(SS_TAP(X_F3)));
      register_code(KC_LALT);
      _delay_ms(100);
      register_code(KC_F3);
    } else {
      unregister_code(KC_F3);
      unregister_code(KC_LALT);
    }
    break;
  case _M_4:
    if (record->event.pressed) {
      // SEND_STRING(SS_LALT(SS_TAP(X_F4)));
      register_code(KC_LALT);
      _delay_ms(100);
      register_code(KC_F4);
    } else {
      unregister_code(KC_F4);
      unregister_code(KC_LALT);
    }
    break;
  case _L_1:
    if (record->event.pressed) {
      // SEND_STRING(SS_LCTRL(SS_TAP(X_F1)));
      register_code(KC_LCTRL);
      _delay_ms(100);
      register_code(KC_F1);
    } else {
      unregister_code(KC_F1);
      unregister_code(KC_LCTRL);
    }
    break;
  case _L_2:
    if (record->event.pressed) {
      // SEND_STRING(SS_LCTRL(SS_TAP(X_F2)));
      register_code(KC_LCTRL);
      _delay_ms(100);
      register_code(KC_F2);
    } else {
      unregister_code(KC_F2);
      unregister_code(KC_LCTRL);
    }
    break;
  case _L_3:
    if (record->event.pressed) {
      // SEND_STRING(SS_LCTRL(SS_TAP(X_F3)));
      register_code(KC_LCTRL);
      _delay_ms(100);
      register_code(KC_F3);
    } else {
      unregister_code(KC_F3);
      unregister_code(KC_LCTRL);
    }
    break;
  case _L_4:
    if (record->event.pressed) {
      // SEND_STRING(SS_LCTRL(SS_TAP(X_F4)));
      register_code(KC_LCTRL);
      _delay_ms(100);
      register_code(KC_F4);
    } else {
      unregister_code(KC_F4);
      unregister_code(KC_LCTRL);
    }
    break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_EVE] = LAYOUT_ortho_4x4(
                            KC_F1,   KC_F2,   KC_F3,   KC_F4, \
                            _M_1,    _M_2,    _M_3,    _M_4, \
                            _L_1,    _L_2,    _L_3,    _L_4, \
                            KC_LCTL, _______, _______, KC_LSFT  \
  )

};
