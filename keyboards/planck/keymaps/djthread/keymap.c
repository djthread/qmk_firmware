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
  _T_L1, _T_L1_ALT,
  _T_L2, _T_L3, _T_L4, _T_L5, _T_L6, _T_L7, _T_L8,
};

enum planck_keycodes {
  M_BUILDINST = NEW_SAFE_RANGE,
  T_L1, T_L2, T_L3, T_L4, T_L5, T_L6, T_L7, T_L8
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid_90deg_right(
    T_L1, T_L2, T_L3, T_L4, T_L5, T_L6, M_BUILDINST, T_L8,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
/**/M_DESKTOP, M_EXPOSE, M_CMD_W, M_CMD_H,
    KC_NO, M_ZOOM, M_MTOGG, M_MNEXT,
    M_WLEFT,     M_WRIGHT,    M_WMAX,      M_WNEXTMON,
    M_TABPREV,   M_TABNEXT,   M_BROWSERREFRESH, M_RSTEX,
    KC_PGUP,     KC_PGDN,     KC_NO,       KC_NO,
    M_CMDTAB,    M_CMDBT,     KC_NO,       MO(_ALT)
  ),

  [_ALT] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
/**/KC_TRNS, KC_TRNS, M_CMD_Q, KC_TRNS,
    KC_TRNS, KC_TRNS, M_RPI, KC_TRNS,
    KC_NO,       KC_NO,       KC_NO,       KC_NO,
    M_BACK,      M_FWD,       KC_NO,       M_BUILDINST,
    KC_HOME,     KC_END,      KC_NO,       KC_NO,
    KC_NO,       KC_NO,       KC_NO,       KC_TRNS
  ),

  // Applications
  [_T_L1] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_F1,       KC_F2,       KC_F3,     KC_F4,
    KC_F5,       KC_F6,       KC_F7,     KC_F8,
    KC_F10,      KC_TRNS,     KC_TRNS,   KC_TRNS,
    M_APPTERM,   M_CHATTERM,  M_KEYBTERM, MO(_T_L1_ALT),
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // Applications ALT
  [_T_L1_ALT] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    M_OPERA_SIDEBAR, KC_F2,   KC_F3,     KC_F4,
    KC_F5,       KC_F6,       KC_F7,     KC_F8,
    KC_F10,      KC_TRNS,     KC_TRNS,   KC_TRNS,
    KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_T_L2] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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
    M_OUTLOOK,   KC_NO,       KC_NO,       KC_NO,
    M_CALENDAR,  M_SIFT,      KC_NO,       KC_NO,
    TO(_BASE),   KC_NO,       KC_NO,       KC_NO,
/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // Window Management
  [_T_L5] = LAYOUT_planck_grid_90deg_right(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_NO,       KC_NO,       M_WIN_SHRINK_W,  M_WIN_GROW_W,
    KC_NO,       KC_NO,       KC_NO,       KC_NO,
    KC_NO,       KC_NO,       KC_NO,       KC_NO,
    TO(_BASE),   KC_NO,       KC_NO,       KC_NO,
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

      case M_BUILDINST:
        SEND_STRING("mavd rpalivZhckjodahZhyf" SS_TAP(X_ENTER));
        _delay_ms(200);
        reset_keyboard();
        return false;
    }
  }

  return true;
}

void matrix_init_user(void) { // Runs boot tasks for keyboard
  layer_on(_T_L1);
};
