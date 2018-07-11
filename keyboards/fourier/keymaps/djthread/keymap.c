#include "fourier.h"
#include "djthread.h"
//#include "action_layer.h"
//#include "eeconfig.h"

enum fourier_layers {
  _BASE,
  _NUMBERS,
  _SHIFTED,
  _NAVIGATION,
  _ARROWS,
  _ARROWS2,
  _FN,
  _SYS
};

enum fourier_keycodes {
  M_BUILDINST = NEW_SAFE_RANGE
};

extern keymap_config_t keymap_config;

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_ESCNUM LT(_NUMBERS, KC_ESC)
#define KC_QUOTNUM LT(_NUMBERS, KC_QUOT)
#define KC_ENTSHIFTED LT(_SHIFTED, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = MY_LAYOUT(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_BSPC,
    KC_ESCNUM, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOTNUM,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_ENTSHIFTED, KC_SPC, KC_RGUI, MO(_FN), MO(_SYS), MO(_NAVIGATION)
  ),

  [_NUMBERS] = MY_LAYOUT(
   KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_UP, KC_9, KC_0, M_CMD_H, _______,
   _______, KC_BSLS, M_CMDTAB, M_CMDBT, KC_RBRC, KC_MINS, KC_EQL, KC_LEFT, KC_DOWN, KC_RGHT, KC_8, _______,
   _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
   _______, _______, _______, M_TABPREV, M_TABNEXT, _______, _______, _______, _______
  ),

  [_SHIFTED] = MY_LAYOUT(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_PGUP, KC_LPRN, KC_RPRN, _______, KC_DEL,
    M_ZULIP, KC_PIPE, M_CMDTAB, M_CMDBT, KC_RCBR, KC_UNDS, KC_PLUS, KC_HOME, KC_PGDN, KC_END, KC_ASTR, M_FOCUSVIEW,
    TO(_NAVIGATION), M_DESKTOP, M_EXPOSE, M_WLEFT, M_WRIGHT, M_WMAX, M_WNEXTMON, M_GOLEFT, M_GORIGHT, M_S_PGUP, M_S_PGDN, TO(_NAVIGATION),
    _______, _______, _______, _______,  M_ZOOM   , M_APPTERM, M_CHROME, M_MTOGG, M_MNEXT
  ),

  [_NAVIGATION] = MY_LAYOUT(
   M_CMD_H, M_CMD_W, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN1, KC_MS_WH_UP, KC_PGUP, KC_HOME, KC_UP, KC_END, XXXXXXX, KC_HOME, KC_PGUP,
   TO(_BASE), KC_MS_BTN3, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_PGDN,
   _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
   M_KEYBTERM, _______, _______, M_TABPREV,  M_TABNEXT, M_BACK, M_FWD, _______, _______
  ),

  [_FN] = MY_LAYOUT(
    M_DISMISSNOTI, M_ACTIVITYMON, _______, _______, _______, M_KEYBTERM, _______, M_GHEGIST, _______, _______, KC_F17, KC_F19, M_LOCK,
    _______, _______, M_TEAMS, M_OUTLOOK, M_WTL, M_WTR, M_WTOP, _______, _______, _______, M_NEWBROWSER, M_BUILDINST,
    _______, M_TTREE, M_TMSG, _______, M_WBL, M_WBR, M_WBOTTOM, M_SEARCHNOTES, M_NEWNOTE, M_MTOGG, M_MNEXT, M_RSTEX,
    KC_F14, KC_F15, KC__MUTE, KC__VOLDOWN, KC__VOLUP, _______, _______, _______, _______
  ),

  [_SYS] = MY_LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, TO(_ARROWS), _______, _______
  ),

  [_ARROWS] = MY_LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP, KC_PGDN,
    _______, _______, _______, _______, TO(_BASE), MO(_ARROWS2), KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_ARROWS2] = MY_LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, _______, KC_END,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case M_BUILDINST:
        SEND_STRING(";pddr e1z mavd ysfogdoZhckjodahZa.ohfhd" SS_TAP(X_ENTER));
        reset_keyboard();
        return false;
    }
  }

  return true;
}
