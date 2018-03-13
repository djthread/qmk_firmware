#include "tv44.h"

enum custom_keycodes {
  M_ZOOM = SAFE_RANGE,
  M_CMDBT,
  M_EXPOSE,
  M_DESKTOP,
  M_WMAX,
  M_WNEXTMON,
  M_WLEFT,
  M_WRIGHT,
  M_WTL,
  M_WTR,
  M_WBL,
  M_WBR,
  M_MPREV,
  M_MTOGG,
  M_MNEXT,
  M_TABPREV,
  M_TABNEXT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*  0: MAIN LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |  Tab    |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Bksp   |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * | L1/Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  L1/'  |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |   Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |  L3  |  Ctrl  |  Alt  |  Lower |  L2/Ent   |   Space     |  Cmd   | Alt  | Ctl  |  L3   |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP_ARROW_COMMAND(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    LT(1, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(1, KC_QUOT),
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, //SFT_T(KC_ENT),
    /* KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SFT_T(KC_ENT), */
    MO(3), KC_LCTL, KC_LALT, KC_LGUI, LT(2, KC_ENT), KC_SPC, KC_RGUI, KC_RALT, KC_RCTL, MO(3)),

  /*  1: NUMBERS LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |   `    |   1  |   2  |   3  |   4  |   5  |   6  |   7  |  UP  |   9  |   0  |          |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |        |   \  |   '  |   [  |   ]  |   -  |   =  | LEFT | DOWN |RIGHT |   8  |          |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |           |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |      |        |       |        |           |             |        |      |      |       |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP_ARROW_COMMAND(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_UP, KC_9, KC_0, KC_TRNS,
    KC_TRNS, KC_BSLS, KC_QUOT, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL, KC_LEFT, KC_DOWN, KC_RGHT, KC_8, KC_TRNS,
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /*  2: SHIFTED LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |   ~    |   !  |   @  |   #  |   $  |   %  |   ^  |   &  | PGUP |   (  |   )  |          |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |        |   |  |   "  |   {  |   }  |   _  |   +  | HOME | PGDN |  END |   *  |          |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |           |      |      |      |      |      |      |      |      |      |      |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |      |        |       |        |           |             |        |      |      |       |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP_ARROW_COMMAND(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_PGUP, KC_LPRN, KC_RPRN, KC_TRNS,
    KC_TRNS, KC_PIPE, KC_DQUO, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_HOME, KC_PGDN, KC_END, KC_ASTR, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /*  3: BONUS LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * | CMD-`   |WMAX |WNXMON|      |       |      |      |      |      |      |LEDST | DELETE  |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * | RESET   | EXPOS| DESKT| WTL  | WTR  |      |      |      |      |      |BREATH|TODVORAK |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * | ZOOM      |WLEFT |WRIGHT| WBL  | WBR  |      |      |      |      |      |      |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |      | TABPREV|TABNEXT|M_MPREV| M_MTOGG  |    M_MNEXT   |        |      |      |       |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP_ARROW_COMMAND(
    M_CMDBT, M_WMAX, M_WNEXTMON, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_STEP, KC_DEL,
    RESET, M_EXPOSE, M_DESKTOP, M_WTL, M_WTR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_BRTG, TO(4),
    M_ZOOM, M_WLEFT, M_WRIGHT, M_WBL, M_WBR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, M_TABPREV, M_TABNEXT, M_MPREV, M_MTOGG, M_MNEXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),



  /*  4: DVORAK
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |   Tab   |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  Bksp   |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * | Ctrl/Esc |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |   -    |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * | Shift     |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Sft/Ent|
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |  L7 | Ctrl | Alt  | Gui  |  Space    |    Space     |   Gui   | Alt  | Ctrl  | L7  |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP_ARROW_COMMAND(
    KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC,
    LT(5, KC_ESC), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, LT(5, KC_MINS),
    KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, SFT_T(KC_ENT),
    MO(7), KC_LCTRL, KC_LALT, KC_LGUI, MO(6), KC_SPC, KC_RGUI, KC_RALT, KC_RCTL, MO(7)),

  /*  5: DVORAK NUMBERS LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |   `    |   1  |   2  |   3  |   4  |   5  |   6  |   7  |  UP  |   9  |   0  |          |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |        |   \  |   -  |   /  |   =  |   -  |   =  | LEFT | DOWN |RIGHT |   8  |          |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |           |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |      |        |       |        |           |             |        |      |      |       |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP_ARROW_COMMAND(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_UP, KC_9, KC_0, KC_TRNS,
    KC_TRNS, KC_BSLS, KC_MINS, KC_SLSH, KC_EQL, KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_RGHT, KC_8, KC_TRNS,
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /*  6: DVORAK SHIFTED LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * |   ~    |   !  |   @  |   #  |   $  |   %  |   ^  |   &  | PGUP |   (  |   )  |          |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |        |   |  |   _  |   ?  |   +  |   {  |   }  | HOME | PGDN |  END  |   *  |          |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |           |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |      |        |       |        |           |             |        |      |      |       |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP_ARROW_COMMAND(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_PGUP, KC_LPRN, KC_RPRN, KC_TRNS,
    KC_TRNS, KC_PIPE, KC_UNDS, KC_QUES, KC_PLUS, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT, KC_ASTR, KC_TRNS,
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /*  7: BONUS LAYER
   *
   * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
   * | CMD-`   |     |      |      |       |      |      |      |      |      |LEDST | DELETE  |
   * |---------`------`------`------`------`------`------`------`------`------`------`---------|
   * |         |      |      |      |      |      |      |      |      |      |BREATH| TOQWERTY |
   * |----------`------`------`------`------`------`------`------`------`------`------`--------|
   * |           |      |      |      |      |      |      |      |      |      |      |       |
   * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
   * |      |        |       |       |          |              |        |      |      |       |
   *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------' */
  KEYMAP_ARROW_COMMAND(
    M_CMDBT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_STEP, KC_DEL,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_BRTG, TO(0),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M_CMDBT:
        SEND_STRING(SS_LGUI("`")); return false;
      case M_ZOOM:
        SEND_STRING(SS_LCTRL("z")); return false;
      case M_EXPOSE:
        SEND_STRING(SS_LCTRL(SS_LALT("a"))); return false;
      case M_DESKTOP:
        SEND_STRING(SS_LCTRL(SS_LALT("s"))); return false;
      case M_WMAX:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_UP)))); return false;
      case M_WNEXTMON:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT("=")))); return false;
      case M_WLEFT:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_LEFT)))); return false;
      case M_WRIGHT:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_RIGHT)))); return false;
      case M_WTL:
        SEND_STRING(SS_LSFT(SS_LGUI(SS_LALT("y")))); return false;
      case M_WTR:
        SEND_STRING(SS_LSFT(SS_LGUI(SS_LALT("u")))); return false;
      case M_WBL:
        SEND_STRING(SS_LSFT(SS_LGUI(SS_LALT("h")))); return false;
      case M_WBR:
        SEND_STRING(SS_LSFT(SS_LGUI(SS_LALT("j")))); return false;
      case M_MPREV:
        SEND_STRING(SS_LSFT(SS_LGUI(SS_LALT("2")))); return false;
      case M_MNEXT:
        SEND_STRING(SS_TAP(X_F16)); return false;
      case M_MTOGG:
        SEND_STRING(SS_TAP(X_F15)); return false;
      case M_TABPREV:
        SEND_STRING(SS_TAP(X_KP_1)); return false;
      case M_TABNEXT:
        SEND_STRING(SS_TAP(X_KP_2)); return false;
    }
  }

  return true;
}
