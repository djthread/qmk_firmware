#include "sweet16.h"
#include "djthread.h"

enum sweet16_layers {
  _BASE,
  _ALT_1,
  _ALT_2,
  _PER_NAV,  // PERSISTENT
  _PER_NAV_ALT,
  _PER_WINDOW,
  //_PER_MOUSE,
  _PER_SYS,
  _PER_WORK,
};

enum sweet16_keycodes {
  M_BUILDINST = NEW_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_4x4(
        M_WLEFT,     M_WRIGHT,    M_WMAX,      M_WNEXTMON,
        M_TABPREV,   M_TABNEXT,   M_ZOOM,      M_RSTEX,
        M_BACK,      M_FWD,       M_MTOGG,     M_MNEXT,
        M_CMD_TAB,   M_CMDBT,     MO(_ALT_2),  MO(_ALT_1)
    ),

    [_ALT_1] = LAYOUT_ortho_4x4(
        TO(_PER_NAV),TO(_PER_WINDOW),TO(_PER_SYS),OSL(_PER_WORK),
        M_WTL,       M_WTR,       M_WTOP,      M_BUILDINST,
        M_WBL,       M_WBR,       M_WBOTTOM,   M_MPREV,
        M_DESKTOP,   M_EXPOSE,    M_CMD_TAB,   KC_NO
    ),

    [_ALT_2] = LAYOUT_ortho_4x4(
        M_BROWSERVIEW,KC_F2,      KC_F3,     KC_F4,
        KC_F5,       KC_F6,       KC_F7,     KC_F8,
        M_CMD_H,     M_CMD_W,     M_NEWBROWSER,M_LOCK,
        TO(_BASE),   TO(_PER_NAV),KC_NO,     TO(_ALT_2)
    ),

    [_PER_NAV] = LAYOUT_ortho_4x4(
        KC_HOME,     KC_UP,       KC_END,      KC_PGUP,
        KC_LEFT,     KC_DOWN,     KC_RGHT,     KC_PGDN,
        M_GOLEFT,    M_GORIGHT,   M_CMD_H,     M_CMD_W,
        TO(_BASE),   MO(_PER_NAV_ALT),MO(_ALT_2),MO(_ALT_1)
    ),

    [_PER_NAV_ALT] = LAYOUT_ortho_4x4(
        KC_NO,        KC_NO,       KC_NO,       KC_NO,
        KC_NO,        KC_NO,       KC_NO,       KC_NO,
        KC_NO,        KC_NO,       KC_NO,       M_CMD_Q,
        TO(_BASE),    KC_NO,       KC_NO,       KC_NO
    ),

    [_PER_WINDOW] = LAYOUT_ortho_4x4(
        KC_MS_BTN2,  KC_MS_UP,    M_WIN_SHRINK_W,  M_WIN_GROW_W,
        KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT, KC_MS_WH_DOWN,
        KC_NO,       KC_NO,       KC_NO,       KC_NO,
        TO(_BASE),   KC_NO,       KC_NO,       KC_NO
    ),

    /*
    [_PER_MOUSE] = LAYOUT_ortho_4x4(
        KC_MS_BTN2,  KC_MS_UP,    KC_MS_BTN1,  KC_MS_WH_UP,
        KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT, KC_MS_WH_DOWN,
        KC_NO,       KC_NO,       KC_NO,       KC_NO,
        TO(_BASE),   KC_NO,       KC_NO,       KC_NO
    ),
    */

    [_PER_SYS] = LAYOUT_ortho_4x4(
        KC_F15,      KC__VOLUP,   KC_NO,       KC_NO,
        KC_F14,      KC__VOLDOWN, KC_NO,       KC_NO,
        KC_NO,       KC_NO,       KC_NO,       KC_NO,
        TO(_BASE),   KC_NO,       KC_NO,       KC_NO
    ),

    [_PER_WORK] = LAYOUT_ortho_4x4(
        M_TEAMS,     M_TTREE,     M_TMSG,      KC_NO,
        M_OUTLOOK,   M_SIFT,      KC_NO,       KC_NO,
        KC_A,        KC_B,        KC_C,        KC_NO,
        TO(_BASE),   KC_NO,       KC_NO,       KC_NO
    ),

};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case M_BUILDINST:
        SEND_STRING("mavd ;,ddk16ZhckjodahZa.ohfhd" SS_TAP(X_ENTER));
        _delay_ms(2000);
        reset_keyboard();
        return false;
    }
  }

  return true;
}
