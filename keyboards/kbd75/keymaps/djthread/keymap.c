#include "kbd75.h"
#include "djthread.h"

enum kbd75_layers {
  _QWERTY,
  _NAVIGATION,
  _FUNCTION,
  _FUNCTION2
};

enum kbd75_keycodes {
  M_BUILDINST = NEW_SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = KEYMAP_ALL(
		M_CMD_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, M_APPTERM, KC_F12, M_CMD_W, M_CMD_H, KC_DEL,
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_NO, KC_HOME,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_END,
		LT(_NAVIGATION, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, LT(_NAVIGATION, KC_ENT), KC_PGUP,
		KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
		KC_LCTL, KC_LALT, KC_LGUI, KC_LGUI, KC_SPC, KC_SPC, KC_RGUI, MO(_FUNCTION2), MO(_FUNCTION), KC_LEFT, KC_DOWN, KC_RGHT),

	[_NAVIGATION] = KEYMAP_ALL(
		M_CMD_H, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO,
		M_CMD_W, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, M_APPTERM, KC_F12, KC_NO, KC_NO, KC_DEL,
		M_CMD_TAB, M_CMDBT, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN1, KC_MS_WH_UP, KC_PGUP, KC_HOME, KC_UP, KC_END, M_FOCUSVIEW, M_MTOGG, M_MNEXT, KC_TRNS, KC_TRNS,
		TO(_QWERTY), KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, M_ZOOM, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_NO, M_DESKTOP, M_EXPOSE, M_WLEFT, M_WRIGHT, M_WMAX, M_WNEXTMON, M_GOLEFT, M_GORIGHT, M_S_PGUP, M_S_PGDN, KC_TRNS, M_FWD, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, M_TABPREV, M_TABNEXT, M_BACK, M_FWD, KC_TRNS, KC_TRNS, M_TABPREV, M_BACK, M_TABNEXT),

	[_FUNCTION] = KEYMAP_ALL(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F17, KC_F19, M_LOCK,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, M_BUILDINST, KC__VOLUP,
		KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC__MUTE, KC__VOLDOWN,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_NAVIGATION), KC_F15,
		KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, BL_DEC, BL_TOGG, BL_INC, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_FWD, KC_F14,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_TABPREV, M_BACK, M_TABNEXT),

	[_FUNCTION2] = KEYMAP_ALL(
		M_DISMISSNOTI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, M_ACTIVITYMON, KC_TRNS, KC_TRNS, KC_TRNS, M_KEYBTERM, KC_TRNS, M_GHEGIST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, M_TEAMS, M_OUTLOOK, M_WTL, M_WTR, M_WTOP, KC_TRNS, KC_TRNS, KC_TRNS, M_NEWBROWSER, M_BROWSERREFRESH, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_NO, M_TTREE, M_TMSG, KC_TRNS, M_WBL, M_WBR, M_WBOTTOM, M_SEARCHNOTES, M_NEWNOTE, M_MTOGG, M_MNEXT, M_RSTEX, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case M_BUILDINST:
        SEND_STRING(";pddr e1z mavd vnh75ZhckjodahZhyf" SS_TAP(X_ENTER));
        reset_keyboard();
        return false;
    }
  }

  return true;
}
/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {


	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRB |= (1 << 2); PORTB &= ~(1 << 2);
	} else {
		DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
*/
