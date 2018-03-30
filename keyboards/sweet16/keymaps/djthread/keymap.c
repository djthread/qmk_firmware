#include "sweet16.h"
#include "djthread.h"

// enum custom_keycodes {
//   M_SOMETHING = NEW_SAFE_RANGE,
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // 0: Base
    LAYOUT_ortho_4x4(
        M_WLEFT,     M_WRIGHT,    M_WMAX,      M_WNEXTMON,
        KC_TRNS,     KC_TRNS,     M_ZOOM,      M_RSTEX,
        M_MTOGG,     M_BACK,      M_FWD,       M_MNEXT,
        MO(2),       M_TABPREV,   M_TABNEXT,   MO(1)
    ),

    // 1: Alt
    LAYOUT_ortho_4x4(
        TO(3),       KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     RESET,
        M_WTL,       M_WTR,       KC_TRNS,     M_MPREV,
        M_WBL,       M_WBR,       KC_TRNS,     KC_TRNS
    ),

    // 2: Alt 2
    LAYOUT_ortho_4x4(
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS
    ),

    // 3: Nav
    LAYOUT_ortho_4x4(
        KC_TRNS,      KC_PGUP,     KC_UP,       KC_PGDN,
        KC_TRNS,      KC_LEFT,     KC_DOWN,     KC_RGHT,
        KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS,
        MO(4),        KC_TRNS,     KC_TRNS,     TO(0)
    ),

    // 4: Nav Alt
    LAYOUT_ortho_4x4(
        KC_TRNS,      KC_HOME,     KC_UP,       KC_END,
        KC_TRNS,      KC_LEFT,     KC_DOWN,     KC_RGHT,
        KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS
    )

};
