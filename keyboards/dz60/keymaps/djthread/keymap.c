#include "dz60.h"
#include "djthread.h"

enum dz60_layers {
  _MAIN,
  _NAVIGATION,
  _ARROWS,
  _ARROWS2,
  _FN1,
  _FN2,
  _SYS,
  _WEB,
  _DVORAK
};

enum dz60_keycodes {
  M_BUILDINST = NEW_SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT_thread(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,KC_EQL, KC_BSLS, M_CMDTAB,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,KC_RBRC,KC_BSPC,
    LT(_NAVIGATION, KC_ESC),KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,KC_QUOT, LT(_NAVIGATION, KC_ENT),
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_PGUP,
    KC_LCTL, KC_LALT, KC_LGUI,     LGUI_T(KC_SPC), KC_SPC, KC_SPC,       KC_RGUI, MO(_FN1), MO(_SYS), MO(_FN2), KC_PGDN
  ),

  [_NAVIGATION] = LAYOUT_thread(
    M_CMD_W, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, M_CMD_H,
    M_CMDTAB, M_CMDBT, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN1, KC_MS_WH_UP, KC_PGUP, KC_HOME, KC_UP, KC_END, M_FOCUSVIEW, M_MTOGG, M_MNEXT, KC_DEL,
    _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, M_ZOOM,
    _______, M_DESKTOP, M_EXPOSE, M_WLEFT, M_WRIGHT, M_WMAX, M_WNEXTMON, M_GOLEFT, M_GORIGHT, M_S_PGUP, M_S_PGDN, M_FWD, M_RSTEX,
    _______, _______, _______,     _______, _______, _______,     TO(_MAIN), M_BACK, _______, M_FWD, _______
  ),

  [_ARROWS] = LAYOUT_thread(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP,     KC_UP,     KC_PGDN,
    _______, _______, _______,      _______, _______, _______,         TO(_MAIN), MO(_ARROWS2), KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_ARROWS2] = LAYOUT_thread(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_PGUP,     _______,
    _______, _______, _______,      _______, _______, _______,                 _______, _______, KC_HOME, KC_PGDN, KC_END
  ),

  [_FN1] = LAYOUT_thread(
    M_DISMISSNOTI, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______, KC_HOME,
    _______, _______, _______, M_CHATTERM, M_APPTERM, M_KEYBTERM, _______, _______, _______, _______, _______, M_MTOGG, M_MNEXT, KC_END,
    _______, _______, M_TEAMS, M_OUTLOOK, M_WTL, M_WTR,  M_WTOP, _______, _______, _______, M_NEWBROWSER, _______,     KC_PGUP,
    _______, M_TTREE, M_TMSG, _______, M_WBL,  M_WBR,  M_WBOTTOM, M_SEARCHNOTES, M_NEWNOTE, M_MTOGG, M_MNEXT,     KC_UP, KC_PGDN,
    _______, _______, _______,      _______, _______, _______,         _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_FN2] = LAYOUT_thread(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     TO(_NAVIGATION),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_HOME,
    _______, _______, _______,      _______, _______, _______,         _______, TO(_WEB), TO(_ARROWS), _______, KC_END
  ),

  [_SYS] = LAYOUT_thread(
    BL_TOGG, BL_DEC,  BL_INC,  BL_BRTG, _______,TG(_DVORAK),_______, _______, _______, _______, _______, _______, KC_F17, KC_F19, M_LOCK,
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, M_BUILDINST,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC__MUTE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F15,     KC__VOLUP,
    _______, _______, _______,       _______, _______, _______,        _______, _______, _______, KC_F14, KC__VOLDOWN
  ),

  [_WEB] = LAYOUT_thread(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M_LBCKT2X, M_RBCKT2X,              KC_F,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,     KC_V,     KC_END,
    _______, _______, _______,      _______, _______, _______,         TO(_MAIN), _______, KC_F, KC_C, KC_H
  ),

  [_DVORAK] = LAYOUT_thread(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______,
    _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  _______,
    _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, _______,
    _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______, _______,
    _______, _______, _______,      _______, _______,  _______,       _______, _______, _______, _______, _______
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
