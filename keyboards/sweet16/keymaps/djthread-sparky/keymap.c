#include "sweet16.h"
// #include "djthread.h"

enum sweet16_layers {
  _BASE,
  _ALT
};

/*
enum sweet16_keycodes {
  M_BUILDINST = NEW_SAFE_RANGE,
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_4x4(
        KC_NO, KC_NO, KC_NO, MO(_ALT),
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_8, KC_9, KC_RPRN, KC_EXLM,
        KC_AT, KC_HASH, KC_DLR, KC_PERC
    ),

    [_ALT] = LAYOUT_ortho_4x4(
        KC_0, KC_1, KC_2, KC_TRNS,
        KC_4, KC_5, KC_6, KC_7,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO
    )
};

/*
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case M_BUILDINST:
        SEND_STRING("mavd ;,ddk16ZhckjodahZa.ohfhd" SS_TAP(X_ENTER));
        _delay_ms(200);
        reset_keyboard();
        return false;
    }
  }

  return true;
}
*/
