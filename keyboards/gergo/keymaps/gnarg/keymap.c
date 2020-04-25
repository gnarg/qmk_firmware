/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define _BASE 0 // default layer
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

// Blank template at the bottom

enum customKeycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  _AM_FUL,
  _AM_TAL,
  _AM_SHR,
  _AM_EXP,
  _AM_MAIN,
  _AM_SWCC,
  _AM_SWCL,
  _AM_SWSC,
  _DSK_RT,
  _DSK_LT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |    ESC |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * | Shift  |   A  |   S  |   D  |   F  |   G  |  [   |           |  ]   |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | Ctrl   |   Z  |   X  |   C  |   V  |   B  |  {   |           |  }   |   N  |   M  | ,  < | . >  | /  ? |  Shift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                .-------.   .-----.
 *                    | LGUI     |   | Lower |                                | Raise |   | Alt |
 *                    '----------'   '-------'                                `-------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        |  (    |                      |  Del  |
 *                                 ,------|-------|                      |-------|------.
 *                                 |      |       |                      |       |      |
 *                                 | Ctrl/|  Tab  |                      | BckSp |Space |
 *                                 | Ent  |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[_BASE] = LAYOUT_gergo(
    KC_ESC,   KC_Q,  KC_W,   KC_E,  KC_R, KC_T,                                          KC_Y,  KC_U, KC_I,    KC_O,   KC_P,    KC_BSLS,
    KC_LSFT,  KC_A,  KC_S,   KC_D,  KC_F, KC_G, KC_LBRC,                       KC_RBRC,  KC_H,  KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LCTRL, KC_Z,  KC_X,   KC_C,  KC_V, KC_B, KC_LCBR, KC_LPRN,     KC_DEL,  KC_RCBR,  KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                     KC_LGUI, LOWER, MT(MOD_RCTL, KC_ENT), KC_TAB,    KC_BSPC, KC_SPC,   RAISE, KC_RALT
    ),
/* Keymap 2: Lower layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |   `    |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      | LEFT | RIGHT| UP   |  [   |      |           |      |   ]  |  6   |  5   |  4   |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | _FUL   | _SWCL| _EXP | _SWSC| DOWN |  {   |      |           |      |   }  |  1   |  2   |  3   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |  0  |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|-------.
 *                                 |      |       |                     |       |       |
 *                                 |      |       |                     |_DSK_LT|_DSK_RT|
 *                                 |      |       |                     |       |       |
 *                                 `--------------'                     `---------------'
 */
[_LOWER] = LAYOUT_gergo(
    KC_GRAVE, KC_1, 	  KC_2,    KC_3,     KC_4,    KC_5,                                            KC_6,    KC_7,  KC_8,  KC_9,  KC_0,    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_LEFT, KC_RGHT,  KC_UP,   KC_LBRC, KC_TRNS,                       KC_TRNS, KC_RBRC, KC_P4, KC_P5, KC_P6, KC_TRNS, KC_TRNS,
    _AM_FUL,  _AM_SWCL, _AM_EXP, _AM_SWSC, KC_DOWN, KC_LCBR, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_RCBR, KC_P1, KC_P2, KC_P3, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     _DSK_LT, _DSK_RT, KC_TRNS, KC_P0
    ),
/* Keymap 3: Raise layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |   ~    |  !   |  @   |  #   |  $   |  %   |                         |   ^  |  &   |  *   |  (   |  )   |  \ |   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        | MPRV | MNXT | VOLU | PGUP |  -   |      |           |      |   =  | HOME |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | MUTE   |      | MPLY | VOLD | PGDN |  _   |      |           |      |   +  | END  | _MAIN| _SHR | _SWCC| _TAL   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[_RAISE] = LAYOUT_gergo(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                            KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN,  KC_PIPE,
    KC_TRNS, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_MINS, KC_TRNS,                          KC_TRNS, KC_EQL,  KC_HOME, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_MUTE, KC_TRNS, KC_MPLY, KC_VOLD, KC_PGDN, KC_UNDS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_PLUS, KC_END,  _AM_MAIN, _AM_SHR, _AM_SWCC, _AM_TAL,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case BASE:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_BASE);
    }
    return false;
    break;
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
  case _DSK_RT:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_RIGHT))));
    }
    break;
  case _DSK_LT:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_LEFT))));
    }
    break;
  }
  return true;
}

