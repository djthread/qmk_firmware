#include "dz60.h"
#include "djthread.h"

enum dz60_layers {
  _MAIN,
  _NAVIGATION,
  _ALTLAYER,
  _ARROWS,
  _ARROWS2,
  _FN1,
  _FN2,
  _SYS,
  _WEB,
  _WEB2,
  _CHOONS,
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
    KC_LCTL, KC_LALT, KC_LGUI,     KC_SPC, KC_SPC, LT(_ALTLAYER, KC_SPC),       KC_RGUI, MO(_FN1), MO(_SYS), MO(_FN2), KC_PGDN
    //KC_LCTL, KC_LALT, KC_LGUI,     LGUI_T(KC_SPC), KC_SPC, LT(_ALTLAYER, KC_SPC),       KC_RGUI, MO(_FN1), MO(_SYS), MO(_FN2), KC_PGDN
  ),

  [_NAVIGATION] = LAYOUT_thread(
    M_CMDBT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, M_CMD_W,
    M_CMDTAB, M_CMDBT, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN1, KC_MS_WH_UP, KC_PGUP, KC_HOME, KC_UP, KC_END, M_FOCUSVIEW, M_MTOGG, M_MNEXT, KC_DEL,
    _______, M_CMD_H, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, M_ZOOM, _______,
    _______, M_DESKTOP, M_EXPOSE, M_WLEFT, M_WRIGHT, M_WMAX, M_WNEXTMON, M_GOLEFT, M_GORIGHT, M_S_PGUP, M_S_PGDN, M_FWD, M_RSTEX,
    _______, _______, _______,     M_BUILDINST, _______, TO(_MAIN),         _______, _______, _______, _______, _______
  ),

  [_ALTLAYER] = LAYOUT_thread(
    M_DISMISSNOTI, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_F13, KC_HOME,
    M_CMDTAB, M_CMDBT, _______, _______, M_APPTERM, M_KEYBTERM, _______, _______, M_CHATTERM, _______, _______, M_MTOGG, M_MNEXT, KC_END,
    M_BARTENDERSHOW, M_TEAMS, KC_F12, M_OUTLOOK, M_WTL, M_WTR,  M_WTOP, M_WLEFT, M_WRIGHT, M_WMAX, M_WNEXTMON, M_NEWBROWSER,     KC_PGUP,
    _______, _______, _______, _______, M_WBL,  M_WBR,  M_WBOTTOM, _______, M_NEWNOTE, M_MTOGG, M_MNEXT,     KC_UP, KC_PGDN,
    _______, _______, _______,      _______, M_ZOOMQUARTER, _______,         M_SEARCHNOTES, M_NEWNOTE, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_ARROWS] = LAYOUT_thread(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_UP,     KC_TAB,
    _______, _______, _______,      _______, _______, TO(_MAIN),         _______, MO(_ARROWS2), KC_LEFT, KC_DOWN, KC_RIGHT
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
    _______, _______, _______, _______, M_WTL, M_WTR,  M_WTOP, _______, _______, _______, _______, M_NEWBROWSER,     KC_PGUP,
    _______, M_TTREE, M_TMSG, _______, M_WBL,  M_WBR,  M_WBOTTOM, M_SEARCHNOTES, M_NEWNOTE, M_MTOGG, M_MNEXT,     KC_UP, KC_PGDN,
    _______, _______, _______,      _______, _______, M_BACK,         M_FWD, _______, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_SYS] = LAYOUT_thread(
    BL_TOGG, BL_DEC,  BL_INC,  BL_BRTG, _______,TG(_DVORAK),_______, _______, _______, _______, _______, _______, KC_F17, KC_F19, M_LOCK,
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, M_BUILDINST,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC__MUTE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F15,     KC__VOLUP,
    _______, _______, _______,       _______, _______, _______,        _______, _______, _______, KC_F14, KC__VOLDOWN
  ),

  [_FN2] = LAYOUT_thread(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     TO(_NAVIGATION),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(_CHOONS),     KC_HOME,
    _______, _______, _______,      _______, _______, _______,         _______, TO(_WEB), TO(_ARROWS), _______, KC_END
  ),

  [_WEB] = LAYOUT_thread(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M_RBCKT2X,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_V,     M_BACK,
    _______, _______, _______,      _______, _______, TO(_MAIN),         _______, MO(_WEB2), KC_F, KC_C, KC_H
  ),

  [_WEB2] = LAYOUT_thread(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M_TABPREV, M_TABNEXT, M_CMD_W,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          M_CMD_T,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_HOME,     M_FWD,
    _______, _______, _______,      _______, _______, _______,         M_FOCUSVIEW, _______, M_TABPREV, KC_END, M_TABNEXT
  ),

  [_CHOONS] = LAYOUT_thread(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M_MNEXT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,     M_MTOGG,
    _______, _______, _______,      _______, _______, TO(_MAIN),         _______, _______, _______, KC_F8, M_MPREV
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
        SEND_STRING(SS_LCTRL(SS_LGUI(SS_LSFT("k"))));
        wait_ms(500);
        SEND_STRING(SS_LCTRL(SS_LGUI("m")));
        wait_ms(300);
        SEND_STRING(";pddr e1z mavd h/60ZhckjodahZhyf" SS_TAP(X_ENTER));
        reset_keyboard();
        return false;
    }
  }

  return true;
}
