/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "whitefox.h"
#include "djthread.h"

enum custom_keycodes2 {
  M_BUILDINST = NEW_SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * | ` |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|   |   |
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|Zoo|
     * |---------------------------------------------------------------|
     * |L1/Esc|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|L1/Enter|PgU|
     * |---------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgD|
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Space         |Gui |L2  |  |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    KEYMAP_TRUEFOX( \
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSLS,KC_TRNS, KC_TRNS, \
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSPC,     M_ZOOM, \
    LT(1, KC_ESC),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,LT(1, KC_ENT),      KC_PGUP, \
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP,  KC_PGDN, \
        KC_LCTL,KC_LALT,KC_LGUI,               KC_SPC,           KC_RGUI,MO(2),                              KC_LEFT,KC_DOWN,KC_RGHT \
    ),

    /* Layer 1
     * ,---------------------------------------------------------------.
     * |ClN| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |Br-|Br+|
     * |---------------------------------------------------------------|
     * |     |   |Bn2|MUp|Bn1|MWU|PgU|Hom| Up|End|FoV|   |   |  Del|Mut|
     * |---------------------------------------------------------------|
     * |      |Bn3|MLe|MDn|MRi|MWD|PgD|Lef|Dow|Rig|MuT|MuN|        |VoU|
     * |---------------------------------------------------------------|
     * |        |Des|Exp|WLe|WRi|WMx|WNM|   |   |   |   |      |PgU|VoD|
     * |---------------------------------------------------------------|
     * |TPre|TNex|    |                       |    |    |  |Hom|PgD|End|
     * `---------------------------------------------------------------'
     */
    KEYMAP_TRUEFOX( \
        M_DISMISSNOTI,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS,KC_F14,KC_F15,\
        KC_TRNS,KC_TRNS,KC_MS_BTN2,KC_MS_UP,KC_MS_BTN1,KC_MS_WH_UP,KC_PGUP,KC_HOME,KC_UP,KC_END,M_FOCUSVIEW,KC_TRNS,KC_TRNS,KC_DEL,     KC_MUTE,\
        KC_TRNS,KC_MS_BTN3,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_WH_DOWN,KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,M_MTOGG,M_MNEXT,KC_TRNS,     KC_VOLU,\
        KC_TRNS,M_DESKTOP,M_EXPOSE,M_WLEFT,M_WRIGHT,M_WMAX,M_WNEXTMON,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_PGUP,KC_VOLD,\
        M_TABPREV,M_TABNEXT,KC_TRNS,               KC_TRNS,          KC_TRNS,KC_TRNS,     KC_HOME,KC_PGDN,KC_END  \
    ),

    /* Layer 2
     * ,---------------------------------------------------------------.
     * |Res|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |WTL|WTR|     |   |
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |WBL|WBR|        |   |
     * |---------------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |Sea|New| Lock |   |   |
     * |---------------------------------------------------------------|
     * |    |    |    |          Back         | Fwd|    |  |   |   |   |
     * `---------------------------------------------------------------'
     */
    KEYMAP_TRUEFOX( \
        RESET,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,M_WTL,M_WTR,KC_TRNS,     KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,M_WBL,M_WBR,KC_TRNS,     KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,M_SEARCHNOTES,M_NEWNOTE,M_LOCK,     KC_TRNS,KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,               M_BACK,          M_FWD,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS  \
    ),
};

/*
const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
};
*/

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case M_BUILDINST:
        SEND_STRING("mavd ,jgkdysbZhckjodahZhyf'fkgp" SS_TAP(X_ENTER));
        reset_keyboard();
        return false;
    }
  }

  return true;
}
