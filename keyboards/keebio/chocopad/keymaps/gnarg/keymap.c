#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1
#define _FN2 2

enum custom_keycodes {
  _AM_FUL = SAFE_RANGE,
  _AM_TAL,
  _AM_EVA,
  _AM_SHR,
  _AM_EXP,
  _AM_MAIN,
  _AM_SWCC,
  _AM_SWCL,
  _AM_SWSC,
  _AM_BSP
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case _AM_FUL:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_RALT("d")));
    }
    break;
  case _AM_TAL:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_RALT("a")));
    }
    break;
  case _AM_EVA:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_RALT("z")));
    }
    break;
  case _AM_SHR:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_RALT("h")));
    }
    break;
  case _AM_EXP:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_RALT("l")));
    }
    break;
  case _AM_MAIN:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_RALT(SS_TAP(X_ENTER))));
    }
    break;
  case _AM_SWCC:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL(SS_LSFT(SS_RALT("j"))));
    }
    break;
  case _AM_SWCL:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL(SS_LSFT(SS_RALT("k"))));
    }
    break;
  case _AM_SWSC:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL(SS_LSFT(SS_RALT("l"))));
    }
    break;
  case _AM_BSP:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL(SS_LSFT(SS_RALT("g"))));
    }
    break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
                             KC_MPLY,  KC_MNXT,  KC_VOLU,  KC_VOLD, \
                             _AM_FUL,  _AM_TAL,  _AM_BSP,  _AM_EVA, \
                             MO(_FN2), _AM_SWCL, _AM_SHR,  _AM_SWSC, \
                             MO(_FN1), _AM_SWCC, _AM_EXP,  _AM_MAIN  \
                             ),
  [_FN1] = LAYOUT_ortho_4x4(
                             KC_PGUP,  KC_HOME,  KC_UP,    KC_END , \
                             KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT, \
                             _______,  KC_VOLU,  KC_MPLY,  KC_MPRV, \
                             _______,  KC_VOLD,  KC_MUTE,  KC_MNXT  \
                             ),
  [_FN2] = LAYOUT_ortho_4x4(
                            KC_ESC,   KC_P7,    KC_P8,    KC_P9,  \
                            KC_TAB,   KC_P4,    KC_P5,    KC_P6,  \
                            KC_ENT,   KC_P1,    KC_P2,    KC_P3,  \
                            _______,  KC_P0,    KC_P0,    KC_DOT  \
  )

};
