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
    //[_BASE] = LAYOUT_ortho_4x4(
    [_BASE] = LAYOUT_ortho_90deg_left_4x4(
        M_WLEFT,     M_WRIGHT,    M_WMAX,      M_WNEXTMON,
        M_TABPREV,   M_TABNEXT,   M_BROWSERREFRESH, M_RSTEX,
        KC_F1,       M_APPTERM,   KC_F2,       KC_F3,
        M_CMDTAB,    M_CMDBT,     MO(_ALT_2),  MO(_ALT_1)
    ),

    [_ALT_1] = LAYOUT_ortho_90deg_left_4x4(
        TO(_PER_NAV),TO(_PER_WINDOW),TO(_PER_SYS),TO(_PER_WORK),
        M_BACK,      M_FWD,       M_ZOOM,      M_BUILDINST,
        M_TEAMS,     M_OUTLOOK,   M_SIFT,      M_MPREV,
        M_DESKTOP,   M_EXPOSE,    KC_NO,       KC_NO
    ),

    [_ALT_2] = LAYOUT_ortho_90deg_left_4x4(
        M_BROWSERVIEW,KC_F2,      KC_NO,     KC_NO,
        M_NEWBROWSER,M_KEYBTERM,  KC_F7,     KC_F8,
        M_CMD_H,     M_CMD_W,     M_MTOGG,   M_MNEXT,
        TO(_BASE),   TO(_PER_NAV),KC_NO,     TO(_ALT_2)
    ),

    [_PER_NAV] = LAYOUT_ortho_90deg_left_4x4(
        KC_HOME,     KC_UP,       KC_END,      KC_PGUP,
        KC_LEFT,     KC_DOWN,     KC_RGHT,     KC_PGDN,
        M_GOLEFT,    M_GORIGHT,   M_CMD_H,     M_CMD_W,
        TO(_BASE),   MO(_PER_NAV_ALT),MO(_ALT_2),MO(_ALT_1)
    ),

    [_PER_NAV_ALT] = LAYOUT_ortho_90deg_left_4x4(
        KC_NO,        KC_NO,       KC_NO,       KC_NO,
        KC_NO,        KC_NO,       KC_NO,       KC_NO,
        KC_NO,        KC_NO,       KC_NO,       M_CMD_Q,
        TO(_BASE),    KC_NO,       KC_NO,       KC_NO
    ),

    [_PER_WINDOW] = LAYOUT_ortho_90deg_left_4x4(
        KC_NO,       KC_NO,       M_WIN_SHRINK_W,  M_WIN_GROW_W,
        KC_NO,       KC_NO,       KC_NO,       KC_NO,
        KC_NO,       KC_NO,       KC_NO,       KC_NO,
        TO(_BASE),   KC_NO,       KC_NO,       KC_NO
    ),

    [_PER_SYS] = LAYOUT_ortho_90deg_left_4x4(
        KC_F15,      KC__VOLUP,   KC_NO,       M_DISMISSNOTI,
        KC_F14,      KC__VOLDOWN, KC_NO,       KC_NO,
        KC_NO,       KC_NO,       KC_NO,       KC_NO,
        TO(_BASE),   KC_NO,       KC_NO,       KC_NO
    ),

    [_PER_WORK] = LAYOUT_ortho_90deg_left_4x4(
        M_TEAMS,     M_TMSG,      M_TTREE,     KC_NO,
        M_OUTLOOK,   M_SIFT,      KC_NO,       KC_NO,
        M_CALENDAR,  KC_NO,       KC_NO,       KC_NO,
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

};

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
