#include "sweet16.h"

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
  M_TABNEXT,
  M_EMAIL,
  M_HELP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_4x4(
        M_WLEFT, M_WRIGHT,  M_WMAX,    M_WNEXTMON,
        M_WTL,   M_WTR,     M_EMAIL,   M_HELP,
        M_WBL,   M_WBR,     M_MTOGG,   M_MNEXT,
        M_ZOOM,  M_TABPREV, M_TABNEXT, KC_EQL
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_EMAIL:
            if (record->event.pressed) {
                SEND_STRING("adambellinson@quickeloans.com");
            }
            return false;
        case M_HELP:
            if (record->event.pressed) {
                SEND_STRING("http://shorty/areyouserious");
            }
            return false;
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
    return true;
}

/*
void led_set_user(uint8_t usb_led) {

  // Map RXLED to USB_LED_NUM_LOCK
	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		DDRB |= (1 << 0); PORTB &= ~(1 << 0);
	} else {
		DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
	}

  // Map TXLED to USB_LED_CAPS_LOCK
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRD |= (1 << 5); PORTD &= ~(1 << 5);
	} else {
		DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
	}
}
*/
