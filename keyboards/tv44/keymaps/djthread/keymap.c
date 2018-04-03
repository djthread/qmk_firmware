#include "tv44.h"
#include "djthread.h"

enum custom_keycodes2 {
  M_BUILDINST = NEW_SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*  0: MAIN LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |  Tab    |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Bksp   |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * | L1/Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  L1/'  |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |   Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sft/Ent|
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |  Ctrl  |  Alt  |  Lower |  L2/Ent   |   Space     |  Cmd   |  L4  |  L3   |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    LT(1, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(1, KC_QUOT),
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SFT_T(KC_ENT),
    KC_LCTL, KC_LALT, KC_LGUI, LT(2, KC_ENT), KC_SPC, KC_RGUI, MO(4), MO(3)),

  /*  1: NUMBERS LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |   `    |   1  |   2  |   3  |   4  |   5  |   6  |   7  |  UP  |   9  |   0  |          |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |        |   \  |   '  |   [  |   ]  |   -  |   =  | LEFT | DOWN |RIGHT |   8  |          |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |           |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |       |       |        |           |             |        |      |       |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_UP, KC_9, KC_0, KC_TRNS,
    KC_TRNS, KC_BSLS, KC_QUOT, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL, KC_LEFT, KC_DOWN, KC_RGHT, KC_8, KC_TRNS,
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /*  2: SHIFTED LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |   ~    |   !  |   @  |   #  |   $  |   %  |   ^  |   &  | PGUP |   (  |   )  |  DELETE  |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |        |   |  |   "  |   {  |   }  |   _  |   +  | HOME | PGDN |  END |   *  |          |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * | ZOOM      |DESKT |EXPOSE| WLEFT|WRIGHT| WMAX|WNXMON|      |      |      |       |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |         |        |       |           |                |          |           |          |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_PGUP, KC_LPRN, KC_RPRN, KC_DEL,
    KC_TRNS, KC_PIPE, KC_DQUO, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_HOME, KC_PGDN, KC_END, KC_ASTR, KC_TRNS,
    M_ZOOM, M_DESKTOP, M_EXPOSE, M_WLEFT, M_WRIGHT, M_WNEXTMON, KC_TRNS, KC_TRNS, KC_TRNS, BL_BRTG, BL_STEP, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /*  3: BONUS LAYER
   * ,---------+------+-----+------+------+------+------+------+------+------+------+---------.
   * | CMD-`   |      |MBTN2 | MUP  | MBTN1 |MWHUP |      |      | WTL  | WTR |                |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |TODVORAK |MBTN3 |MLEFT |MDOWN |MRIGHT|MWHDN |      |       |      | WBL  | WBR  |BUILDINST|
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |           |      |      |      |      |      |      |      |      |      |      |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |  TABPREV   |TABNEXT|M_MPREV|  M_MTOGG    |    M_MNEXT   | BRIGH- | BRIGH+  |            |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP(
    M_CMDBT, KC_TRNS, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN1, KC_MS_WH_UP, KC_TRNS, KC_TRNS, KC_TRNS, M_WTL, M_WTR, KC_TRNS,
    TO(5), KC_MS_BTN3, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, M_WBL, M_WBR, M_BUILDINST,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    M_TABPREV, M_TABNEXT, M_MPREV, M_MTOGG, M_MNEXT, KC_F14, KC_F15, KC_TRNS),

  /*  4: MACRO LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |         |     |      |      |       |      |      |      |      |      |      |         |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |         |      |       |     |      |      |      |      |      |      |      |         |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |           |      |      |      |      |      |      |      |      |      |      | RSTEX |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |   BACK     |  FWD   |       |             |              |  Vol-  |         |  Vol+     |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_RSTEX,
    M_BACK, M_FWD, KC_TRNS, KC_TRNS, KC_TRNS, KC__VOLDOWN, KC_TRNS, KC__VOLUP),



  /*  5: DVORAK
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |   Tab   |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  Bksp   |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |  L6/Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  L6/-  |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * | Shift     |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Sft/Ent|
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * | Ctrl | Alt  | Gui  |  Space    |    Space     |   Gui   |  L9   |   L8    |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP(
    KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC,
    LT(6, KC_ESC), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, LT(6, KC_MINS),
    KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, SFT_T(KC_ENT),
    KC_LCTRL, KC_LALT, KC_LGUI, LT(7, KC_ENT), KC_SPC, KC_RGUI, MO(9), MO(8)),

  /*  6: DVORAK NUMBERS LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |   `    |   1  |   2  |   3  |   4  |   5  |   6  |   7  |  UP  |   9  |   0  |          |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |        |   \  |   -  |   /  |   =  |   -  |   =  | LEFT | DOWN |RIGHT |   8  |          |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |           |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |      |       |        |           |             |        |      |       |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_UP, KC_9, KC_0, KC_TRNS,
    KC_TRNS, KC_BSLS, KC_MINS, KC_SLSH, KC_EQL, KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_RGHT, KC_8, KC_TRNS,
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /*  7: DVORAK SHIFTED LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |   ~    |   !  |   @  |   #  |   $  |   %  |   ^  |   &  | PGUP |   (  |   )  |          |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |        |   |  |   _  |   ?  |   +  |   {  |   }  | HOME | PGDN |  END  |   *  |          |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * | ZOOM      |DESKT |EXPOSE| WLEFT|WRIGHT| WMAX|WNXMON|      |      |      |       |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |        |       |        |           |             |        |      |       |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_PGUP, KC_LPRN, KC_RPRN, KC_TRNS,
    KC_TRNS, KC_PIPE, KC_UNDS, KC_QUES, KC_PLUS, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT, KC_ASTR, KC_TRNS,
    M_ZOOM, M_DESKTOP, M_EXPOSE, M_WLEFT, M_WRIGHT, M_WNEXTMON, KC_TRNS, KC_TRNS, KC_TRNS, BL_BRTG, BL_STEP, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /*  8: DVORAK BONUS LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * | CMD-`   |     | MBTN2| MUP  | MBTN1 |MWHUP |      |      |      |      |LEDST | DELETE  |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * | TOQWERTY |MBTN3 | MLEFT |MDOWN|MRIGHT|MWHDN |      |      |      |      |BREATH|        |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |           |      |      |      |      |      |      |      |      |      |      |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |        |       |       |          |              |        |      |       |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP(
    M_CMDBT, KC_TRNS, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN1, KC_MS_WH_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_STEP, KC_DEL,
    TO(0), KC_MS_BTN3, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_BRTG, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /*  9: DVORAK MACRO LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |         |     |      |      |       |      |      |      |      |      |      |         |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |         |      |       |     |      |      |      |      |      |      |      |         |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |           |      |      |      |      |      |      |      |      |      |      |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |   BACK     |  FWD   |       |             |              |        |  RSTEX  |           |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    M_BACK, M_FWD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_RSTEX),

};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case M_BUILDINST:
        SEND_STRING("mavd k.44ZhckjodahZhyf" SS_TAP(X_ENTER));
        reset_keyboard();
        return false;
    }
  }

  return true;
}
