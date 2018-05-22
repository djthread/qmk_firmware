#include "dz60.h"
#include "djthread.h"

enum dz60_layers {
  _QWERTY,
  _NAVIGATION,
  _FUNCTION2,
  _FUNCTION
};

enum dz60_keycodes {
  M_BUILDINST = NEW_SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* KEYMAP( */
	/* 	F(0), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,  */
	/* 	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,  */
	/* 	KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,  */
	/* 	KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO,  */
	/* 	KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, MO(2), KC_NO, MO(1), KC_RCTL), */
  [_QWERTY] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,KC_EQL, KC_BSLS, KC_SLSH,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,KC_RBRC,KC_BSPC,
        LT(_NAVIGATION, KC_ESC),KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,KC_QUOT, LT(_NAVIGATION, KC_ENT),
        KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH), KC_UP, M_BUILDINST, //MO(_FUNCTION2),
        KC_LCTL, KC_LALT, KC_LGUI,  KC_SPC, KC_SPC, KC_SPC,  KC_RGUI, MO(_FUNCTION), KC_LEFT,KC_DOWN,KC_RIGHT
  ),
  [_NAVIGATION] = LAYOUT(
        M_CMD_H, KC_F1, KC_F2, KC_F3, M_CHATTERM, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, M_APPTERM, KC_F12, _______, KC_NO,
        M_CMDTAB,M_CMDBT,KC_MS_BTN2,KC_MS_UP,KC_MS_BTN1,KC_MS_WH_UP,KC_PGUP,KC_HOME,KC_UP,KC_END,M_FOCUSVIEW,M_MTOGG,M_MNEXT,KC_DEL,
        _______,_______,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_WH_DOWN,KC_PGDN,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,M_ZOOM,
        _______,M_DESKTOP,M_EXPOSE,M_WLEFT,M_WRIGHT,M_WMAX,M_WNEXTMON,M_GOLEFT,M_GORIGHT,M_S_PGUP,M_S_PGDN,M_RSTEX, M_FWD, KC_NO,
        _______,_______,_______, _______, _______,         M_BACK,                M_FWD,M_TABPREV,M_TABNEXT,     M_TABPREV,M_BACK
  ),
  /*
  [_FUNCTION] = KEYMAP(
        M_DISMISSNOTI, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, M_LOCK,     KC_HOME,
        _______,_______,_______,_______,_______,M_KEYBTERM,_______,_______,_______,_______,_______,_______,_______,_______,     KC_END,
        _______,_______,M_TEAMS,M_OUTLOOK,M_WTL,M_WTR,  M_WTOP,_______,_______,_______,M_NEWBROWSER,_______,     TO(_NAVIGATION),
        _______,M_TTREE,M_TMSG, _______,M_WBL,  M_WBR,  M_WBOTTOM,M_SEARCHNOTES,M_NEWNOTE,M_MTOGG,M_MNEXT,_______,     KC__VOLUP,
        _______,_______,_______,                         _______,                _______,_______,_______,     KC_F14,KC__VOLDOWN,KC_F15
  ),
  [_FUNCTION2] = KEYMAP(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, KC_F17, KC_F19, M_LOCK,     KC_HOME,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,M_BUILDINST,     KC_END,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     TO(_NAVIGATION),
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
        _______,_______,_______,                         _______,                _______,_______,_______,     _______,_______,_______
  )


	KEYMAP(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_DEL,
		KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC, BL_TOGG, BL_INC, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, M(1), M(2), M(3), M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  */
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
