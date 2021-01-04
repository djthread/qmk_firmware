#include QMK_KEYBOARD_H
#include "djthread.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_thread(
    KC_A, KC_B, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, M_CMDTAB, _______, \
    KC_C, KC_D, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, _______, \
    KC_E, KC_F, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, \
    KC_G, KC_H, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN, \
    KC_I, KC_J, KC_LCTL, _______, MO(_FN2), KC_LALT, KC_LGUI, MO(_FN1),    KC_SPC, MO(_FN1), KC_RGUI, MO(_FN2), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT_thread(
    _______, _______, M_CMDBT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_BSPC, _______, \
    RGB_TOG, RGB_MOD, M_CMDTAB, M_CMDBT, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN1, KC_MS_WH_UP, KC_PGUP, KC_HOME, KC_UP, KC_END, M_FOCUSVIEW, M_MTOGG, M_MNEXT, KC_DEL, _______, \
    _______, _______, _______, M_CMD_H, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, M_ZOOM, _______, _______, \
    _______, _______, _______, M_DESKTOP, M_EXPOSE, M_WLEFT, M_WRIGHT, M_WMAX, M_WNEXTMON, M_GOLEFT, M_GORIGHT, M_S_PGUP, M_S_PGDN, M_FWD, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN2] = LAYOUT_thread(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END, \
    RESET, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
