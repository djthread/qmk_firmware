#include "djthread.h"
#include "quantum.h"
#include "action.h"
#include "version.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
    case M_CMDBT:
      SEND_STRING(SS_LGUI("`")); return false;
    case M_ZOOM:
      SEND_STRING(SS_LCTRL("z")); return false;
    case M_EXPOSE:
      SEND_STRING(SS_LCTRL(SS_LALT("s"))); return false;
    case M_DESKTOP:
      SEND_STRING(SS_LCTRL(SS_LALT("a"))); return false;
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
    case M_BACK:
      SEND_STRING(SS_LGUI(SS_TAP(X_LEFT))); return false;
    case M_FWD:
      SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT))); return false;
    case M_DISMISSNOTI:
      SEND_STRING(SS_LCTRL(SS_LALT(SS_LGUI(SS_LSFT("h"))))); return false;
    case M_RSTEX:  // restart elixir
      SEND_STRING(SS_LCTRL(SS_LALT("k")));  // switch to iterm
      _delay_ms(250);
      SEND_STRING(SS_LCTRL("\\")      // ctrl-\ kills erlang
        SS_TAP(X_UP) SS_TAP(X_ENTER)  // recall + execute last command
        SS_LGUI(SS_TAP(X_TAB)));      // switch back to previous app
      return false;
    case M_LOCK:
      SEND_STRING(SS_LCTRL("`"));
      return false;
    case M_TTREE:
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
      _delay_ms(200);
      SEND_STRING("kdam;" SS_TAP(X_ENTER));
      _delay_ms(1000);
      SEND_STRING(
        SS_TAP(X_TAB)
        SS_TAP(X_TAB)
        SS_TAP(X_TAB)
        SS_LALT("3")
      );
      _delay_ms(1000);
      SEND_STRING(SS_LALT("d"));  // search
      _delay_ms(1000);
      SEND_STRING(".dlkfod kod");
      _delay_ms(400);
      SEND_STRING(
        SS_TAP(X_DOWN)
        SS_TAP(X_ENTER)
        SS_TAP(X_TAB)
        "i");
      return false;
    case M_TMSG:
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
      _delay_ms(200);
      SEND_STRING("kdam;" SS_TAP(X_ENTER));
      _delay_ms(100);
      SEND_STRING(
        SS_TAP(X_TAB)
        SS_TAP(X_TAB)
        SS_TAP(X_TAB)
        SS_LALT("l")
      );
      return false;
    case M_SEARCHNOTES:
      SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT(SS_TAP(X_HOME)))));
      return false;
    case M_NEWNOTE:
      SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT(SS_TAP(X_END)))));
      return false;
  }

  return process_record_keymap(keycode, record);
}
