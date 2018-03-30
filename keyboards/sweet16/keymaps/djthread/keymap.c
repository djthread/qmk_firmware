#include "sweet16.h"
#include "djthread.h"

// enum custom_keycodes {
//   M_SOMETHING = NEW_SAFE_RANGE,
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_4x4(
        M_WLEFT,     M_WRIGHT,    M_WMAX,      M_WNEXTMON,
        KC_TRNS,     KC_TRNS,     M_ZOOM,      RESET,
        M_BACK,      M_FWD,       M_MTOGG,     M_MNEXT,
        M_TABPREV,   M_TABNEXT,   M_RSTEX,     MO(1)
    ),

    LAYOUT_ortho_4x4(
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        M_WTL,       M_WTR,       KC_TRNS,     M_MPREV,
        M_WBL,       M_WBR,       KC_TRNS,     KC_TRNS
    )
};

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
