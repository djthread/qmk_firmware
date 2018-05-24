#include "dz60.h"
#include "djthread.h"

enum dz60_layers {
  _MAIN,
  _NAVIGATION,
  _ARROWS,
  _FN1,
  _FN2,
  _SYS,
  _WEB,
};

enum dz60_keycodes {
  M_BUILDINST = NEW_SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
  [_MAIN] = LAYOUT_thread(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,KC_EQL, KC_BSLS, M_BUILDINST,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,KC_RBRC,KC_BSPC,
        LT(_NAVIGATION, KC_ESC),KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,KC_QUOT, LT(_NAVIGATION, KC_ENT),
        KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_1, KC_2, KC_3,
        KC_1, KC_1, KC_1,  KC_1, KC_1, KC_1,  KC_1, KC_1, KC_1,KC_1,KC_1
  ),
  */

  [_MAIN] = LAYOUT_thread(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,KC_EQL, KC_BSLS, M_CMDTAB,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,KC_RBRC,KC_BSPC,
        LT(_NAVIGATION, KC_ESC),KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,KC_QUOT, LT(_NAVIGATION, KC_ENT),
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_PGUP,
        KC_LCTL, KC_LALT, KC_LGUI,     LGUI_T(KC_SPC), KC_SPC, KC_SPC,       KC_RGUI, MO(_FN1), MO(_SYS), MO(_FN2), KC_PGDN
  ),

  [_NAVIGATION] = LAYOUT_thread(
        M_CMD_W, KC_F1, KC_F2, KC_F3, M_CHATTERM, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, M_APPTERM, KC_F12, _______, M_CMD_H,
        M_CMDTAB, M_CMDBT, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN1, KC_MS_WH_UP, KC_PGUP, KC_HOME, KC_UP, KC_END, M_FOCUSVIEW, M_MTOGG, M_MNEXT, KC_DEL,
        _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, M_ZOOM,
        _______, M_DESKTOP, M_EXPOSE, M_WLEFT, M_WRIGHT, M_WMAX, M_WNEXTMON, M_GOLEFT, M_GORIGHT, M_S_PGUP, M_S_PGDN, M_FWD, M_RSTEX,
        _______, _______, _______,     _______, _______, M_BACK,     M_FWD, TO(_MAIN), _______, _______, _______
  ),

  [_ARROWS] = LAYOUT_thread(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_UP,     KC_PGDN,
        _______, _______, _______,      _______, _______, _______,         _______, TO(_MAIN), KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_FN1] = LAYOUT_thread(
        M_DISMISSNOTI, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______, _______,
        _______, _______, _______, _______, _______, M_KEYBTERM, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, M_TEAMS, M_OUTLOOK, M_WTL, M_WTR,  M_WTOP, _______, _______, _______, M_NEWBROWSER, _______,     _______,
        _______, M_TTREE, M_TMSG, _______, M_WBL,  M_WBR,  M_WBOTTOM, M_SEARCHNOTES, M_NEWNOTE, M_MTOGG, M_MNEXT,     KC__VOLUP, _______,
        _______, _______, _______,      _______, _______, _______,         _______, _______, KC_F14, KC__VOLDOWN, KC_F15
  ),

  [_FN2] = LAYOUT_thread(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     TO(_NAVIGATION),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_HOME,
        _______, _______, _______,      _______, _______, _______,         TO(_WEB), _______, TO(_ARROWS), _______, KC_END
  ),

  [_SYS] = LAYOUT_thread(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F17, KC_F19, M_LOCK,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, M_BUILDINST,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,
        _______, _______, _______,       _______, _______, _______,        _______, _______, _______, _______, _______
  ),

  [_WEB] = LAYOUT_thread(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M_LBCKT2X, M_RBCKT2X,              KC_F,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_V,     KC_H,
        _______, _______, _______,      _______, _______, _______,         _______, TO(_MAIN), KC_LEFT, KC_C, KC_RIGHT
  )
};


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case M_BUILDINST:
        SEND_STRING(";pddr e1z mavd h/60ZhckjodahZhyf" SS_TAP(X_ENTER));
        reset_keyboard();
        return false;
    }
  }

  return true;
}
