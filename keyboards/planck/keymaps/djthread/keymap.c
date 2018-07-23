/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"
#include "djthread.h"

enum planck_layers {
  _BASE,
  _ALT,
  _NUMBERS_ENTER,
  _T_L1, _T_L1_ALT,
  _T_L2,
  _T_L3,
  _T_L4, _T_L4_ALT,
  _T_L5, _T_L6, _T_L7, _T_L8,
};

enum planck_keycodes {
  M_BUILDINST = NEW_SAFE_RANGE,
  M_RPI_PLANCK,
  M_1_ENT, M_2_ENT, M_3_ENT, M_4_ENT, M_5_ENT,
  M_6_ENT, M_7_ENT, M_8_ENT, M_9_ENT, M_0_ENT,
  T_L1, T_L2, T_L3, T_L4, T_L5, T_L6, T_L7, T_L8
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    Applications     ____    ____   Work
    Window Mgt       Mouse   ____   System
    */
  [_BASE] = LAYOUT_planck_grid_90deg_right(
    T_L1, T_L2, T_L3, T_L4, T_L5, M_LOCK, M_BUILDINST, T_L8,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
/**/M_DESKTOP, M_EXPOSE, M_BARTENDERSHOW, M_CMD_H,
    M_KEYBTERM, M_ZOOM, M_MTOGG, M_MNEXT,
    M_TABPREV,   M_TABNEXT,   KC_UP,       KC_NO,
    KC_NO,       KC_LEFT,     KC_DOWN,     KC_RIGHT,
    KC_PGUP,     KC_PGDN,     M_COPY,      M_PASTE,
    M_CMDTAB,    M_CMDBT,     KC_NO,       MO(_ALT)
  ),

  [_ALT] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
/**/KC_TRNS, KC_TRNS, KC_NO,       KC_NO,
    KC_TRNS, KC_TRNS, M_RPI_PLANCK, KC_TRNS,
    KC_NO,       KC_NO,       M_CMD_Q,     M_CMD_W,
    M_BACK,      M_FWD,       KC_NO,       KC_NO,
    KC_HOME,     KC_END,      KC_NO,       KC_NO,
    KC_NO,       KC_NO,       KC_NO,       KC_TRNS
  ),

  // Applications
  [_T_L1] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_F1,       KC_F2,       KC_F3,     KC_F4,
    KC_F5,       KC_F6,       KC_F7,     KC_F8,
    KC_F10,      KC_TRNS,     KC_TRNS,   KC_TRNS,
    M_APPTERM,   M_CHATTERM,  KC_NO, MO(_T_L1_ALT),
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // Applications ALT
  [_T_L1_ALT] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    M_CHROME,    KC_F2,   KC_F3,     KC_F4,
    KC_F5,       KC_F6,       KC_F7,     KC_F8,
    KC_F10,      KC_TRNS,     KC_TRNS,   KC_TRNS,
    KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // Mouse
  [_T_L2] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_MS_BTN2,  KC_MS_UP,    KC_MS_BTN1,  KC_MS_WH_UP,
    KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT, KC_MS_WH_DOWN,
    KC_NO,       KC_NO,       KC_NO,       KC_NO,
    KC_NO,       KC_NO,       KC_NO,       KC_NO,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_T_L3] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // Work
  [_T_L4] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    M_TEAMS,     M_TMSG,      M_TTREE,     KC_NO,
    M_OUTLOOK,   KC_NO,       M_BROWSERREFRESH, M_RSTEX,
    M_ZULIP,  M_SIFT,      KC_F1,       M_APPTERM,
    M_CALENDAR,     M_CIRCLECI,  M_HAL9000,   KC_NO,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_T_L4_ALT)
  ),

  // Work ALT
  [_T_L4_ALT] = LAYOUT_planck_grid_90deg_right(
    _______, _______, _______, _______, _______, _______, _______, _______,
    _______,     _______,      _______,     _______,
    _______,   _______,       _______, _______,
    _______,  _______,      _______,       _______,
    _______,     _______,       _______,       _______,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_T_L4_ALT)
  ),

  // Window Management
  [_T_L5] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_NO,       KC_NO,       M_WIN_SHRINK_W,  M_WIN_GROW_W,
    KC_NO,       KC_NO,       KC_NO,       KC_NO,
    M_WTL,       M_WTR,       M_WTOP,       KC_NO,
    M_WBL,       M_WBR,       M_WBOTTOM,    KC_NO,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_T_L6] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_T_L7] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // System
  [_T_L8] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_F15,      KC__VOLUP,   KC_NO,       M_DISMISSNOTI,
    KC_F14,      KC__VOLDOWN, KC_NO,       KC_NO,
    KC_NO,       KC_NO,       KC_NO,       KC_NO,
    KC_NO,       KC_NO,       M_ACTIVITYMON, M_BUILDINST,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NUMBERS_ENTER] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    M_1_ENT,       M_2_ENT,       M_3_ENT,       M_4_ENT,
    M_5_ENT,      M_6_ENT,       M_7_ENT,       M_8_ENT,
    M_9_ENT,     M_0_ENT,      KC_NO,       KC_NO,
    KC_NO,       KC_NO,       KC_NO,       KC_NO
  ),

};

void t_layers_off(void) {
  layer_off(_T_L1); layer_off(_T_L2); layer_off(_T_L3); layer_off(_T_L4);
  layer_off(_T_L5); layer_off(_T_L6); layer_off(_T_L7); layer_off(_T_L8);
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case T_L1: t_layers_off(); layer_on(_T_L1); return false;
      case T_L2: t_layers_off(); layer_on(_T_L2); return false;
      case T_L3: t_layers_off(); layer_on(_T_L3); return false;
      case T_L4: t_layers_off(); layer_on(_T_L4); return false;
      case T_L5: t_layers_off(); layer_on(_T_L5); return false;
      case T_L6: t_layers_off(); layer_on(_T_L6); return false;
      case T_L7: t_layers_off(); layer_on(_T_L7); return false;
      case T_L8: t_layers_off(); layer_on(_T_L8); return false;

      case M_1_ENT: SEND_STRING("1" SS_TAP(X_ENTER)); return false;
      case M_2_ENT: SEND_STRING("2" SS_TAP(X_ENTER)); return false;
      case M_3_ENT: SEND_STRING("3" SS_TAP(X_ENTER)); return false;
      case M_4_ENT: SEND_STRING("4" SS_TAP(X_ENTER)); return false;
      case M_5_ENT: SEND_STRING("5" SS_TAP(X_ENTER)); return false;
      case M_6_ENT: SEND_STRING("6" SS_TAP(X_ENTER)); return false;
      case M_7_ENT: SEND_STRING("7" SS_TAP(X_ENTER)); return false;
      case M_8_ENT: SEND_STRING("8" SS_TAP(X_ENTER)); return false;
      case M_9_ENT: SEND_STRING("9" SS_TAP(X_ENTER)); return false;
      case M_0_ENT: SEND_STRING("0" SS_TAP(X_ENTER)); return false;

      case M_RPI_PLANCK:
        SEND_STRING(SS_LCTRL(SS_LGUI(SS_LSFT("k"))));
        wait_ms(100);
        SEND_STRING(SS_LCTRL(SS_LGUI("o")));
        layer_on(_NUMBERS_ENTER);
        set_oneshot_layer(_NUMBERS_ENTER, ONESHOT_START);
        //clear_oneshot_layer_state(ONESHOT_PRESSED);
        //return false;
        break;

      case M_BUILDINST:
        SEND_STRING(SS_LCTRL(SS_LGUI(SS_LSFT("k"))));
        wait_ms(100);
        SEND_STRING(SS_LCTRL(SS_LGUI("m")));
        wait_ms(300);
        SEND_STRING(";pddr e2z mavd rpalivZhckjodahZhyf" SS_TAP(X_ENTER));
        reset_keyboard();
        return false;
    }
  } else {
    switch (keycode) {
      case M_RPI_PLANCK:
        clear_oneshot_layer_state(ONESHOT_PRESSED);
        //return false;
        break;
    }
  }

  return true;
}

void matrix_init_user(void) { // Runs boot tasks for keyboard
  layer_on(_T_L1);
};
