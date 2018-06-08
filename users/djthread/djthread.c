#include "djthread.h"
#include "quantum.h"
#include "action.h"
#include "version.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void chrome(void) {
  SEND_STRING(SS_LGUI(SS_LALT(SS_LSFT(SS_LCTRL("n")))));
  wait_ms(200);
}

void opera(void) {
  SEND_STRING(SS_LGUI(SS_LALT(SS_LSFT(SS_LCTRL("o")))));
  wait_ms(200);
}

void alfred(void) {
  SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
  wait_ms(150);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  /*
  // Check for shift letter (ty planck/bbaserdem)
  bool is_capital = ( keyboard_report->mods &
      (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)) ) ^
      ( keyboard_report->mods & MOD_BIT(KC_CAPS) );
      */

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
    case M_WTOP: // window to top half of screen
      SEND_STRING(SS_LSFT(SS_LGUI(SS_LALT("m")))); return false;
    case M_WBOTTOM:
      SEND_STRING(SS_LSFT(SS_LGUI(SS_LALT("n")))); return false;
    case M_MPREV:
      SEND_STRING(SS_LSFT(SS_LGUI(SS_LALT("2")))); return false;
    case M_MTOGG:
      SEND_STRING(SS_LGUI(SS_LALT("1"))); return false;
      /* SEND_STRING(SS_TAP(X_F15)); return false; */
    case M_MNEXT:
      SEND_STRING(SS_LGUI(SS_LALT("2"))); return false;
    case M_RPI:
      alfred(); SEND_STRING("Eorg" SS_TAP(X_ENTER)); return false;
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
      SEND_STRING(SS_LCTRL(SS_LGUI("k")));  // show/hide iterm
      SEND_STRING(SS_LCTRL(SS_LGUI(SS_LSFT("a"))));  // switch to "app" iterm
      wait_ms(250);
      SEND_STRING(SS_LCTRL("\\")      // ctrl-\ kills erlang
        SS_TAP(X_UP) SS_TAP(X_ENTER)  // recall + execute last command
        SS_LGUI(SS_TAP(X_TAB)));      // switch back to previous app
      return false;
    case M_LOCK:
      SEND_STRING(SS_LCTRL("`"));
      return false;
    case M_ZULIP:
      SEND_STRING(SS_LCTRL(SS_LALT("/")));
      return false;
    case M_OUTLOOK:
      chrome();
      wait_ms(200);
      SEND_STRING(SS_LGUI("2"));
      return false;
    case M_SIFT:
      opera();
      SEND_STRING(SS_LGUI("k"));
      wait_ms(200);
      SEND_STRING(";gyk[" SS_TAP(X_ENTER));
      return false;
    case M_TEAMS:
      chrome();
      wait_ms(200);
      SEND_STRING(SS_LGUI("1"));
      return false;
    case M_TMSG:
      chrome();
      wait_ms(200);
      SEND_STRING(SS_LGUI("1"));
      wait_ms(100);
      SEND_STRING(SS_TAP(X_ESCAPE));
      wait_ms(100);
      SEND_STRING(SS_LALT("l"));
      return false;
    case M_TTREE:
      chrome();
      wait_ms(200);
      SEND_STRING(SS_LGUI("1"));
      wait_ms(100);
      SEND_STRING(SS_TAP(X_ESCAPE));
      wait_ms(100);
      SEND_STRING(SS_LALT("d"));
      wait_ms(100);
      SEND_STRING(".dlkfod kod");
      wait_ms(400);
      SEND_STRING(SS_TAP(X_DOWN) SS_TAP(X_ENTER));
      return false;
    case M_SEARCHNOTES:
      SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT(SS_TAP(X_HOME)))));
      return false;
    case M_NEWNOTE:
      SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT(SS_TAP(X_END)))));
      return false;
    case M_FOCUSVIEW: // focuses opera viewport
      SEND_STRING(SS_LGUI(SS_LALT("p")));
      return false;
    case M_ACTIVITYMON: // focuses opera viewport
      alfred();
      SEND_STRING("aikg.gk" SS_TAP(X_ENTER));
      return false;
    case M_S_PGUP:
      SEND_STRING(SS_LSFT(SS_TAP(X_PGUP))); return false;
    case M_S_PGDN:
      SEND_STRING(SS_LSFT(SS_TAP(X_PGDOWN))); return false;
    case M_CMD_W:
      SEND_STRING(SS_LGUI(",")); return false;
    case M_CMD_H:
      SEND_STRING(SS_LGUI("j")); return false;
    case M_CMD_T:
      SEND_STRING(SS_LGUI("k")); return false;
    case M_CMD_Q:
      SEND_STRING(SS_LGUI("x")); return false;
    case M_COPY:
      SEND_STRING(SS_LGUI("i")); return false;
    case M_PASTE:
      SEND_STRING(SS_LGUI(".")); return false;
    case M_CMDTAB:
      SEND_STRING(SS_LGUI(SS_TAP(X_TAB))); return false;
    case M_APPTERM:  // switch to "app" iterm
      SEND_STRING(SS_LCTRL(SS_LGUI(SS_LSFT("a")))); return false;
    case M_CHATTERM:  // switch to "chat" iterm
      SEND_STRING(SS_LCTRL(SS_LGUI(SS_LSFT("i")))); return false;
    case M_KEYBTERM:  // switch to "keyboard editing" iterm
      SEND_STRING(SS_LCTRL(SS_LGUI(SS_LSFT("v")))); return false;
    case M_CALENDAR:  // switch to calendar
      SEND_STRING(SS_LCTRL(SS_LALT("q"))); return false;
    case M_GHEGIST:  // run alfred workflow to put clipboard in gist and get url
      SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT(SS_LSFT("u"))))); return false;
    case M_GOLEFT:
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_MINUS)))); return false;
    case M_GORIGHT:
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_EQUAL)))); return false;
    case M_NEWBROWSER:
      opera(); SEND_STRING(SS_LGUI("k")); return false;
    case M_BROWSERVIEW:
      opera(); SEND_STRING(SS_LGUI(SS_LALT("p"))); return false;
    case M_BROWSERREFRESH:
      opera(); SEND_STRING(SS_LGUI("o"));
      SEND_STRING(SS_LGUI(SS_TAP(X_TAB))); return false;
    case M_CHROME:
      SEND_STRING(SS_LCTRL(SS_LALT("n"))); return false;
    case M_WIN_SHRINK_W:
      SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT(SS_LSFT(SS_TAP(X_KP_1)))))); return false;
    case M_WIN_GROW_W:
      SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT(SS_LSFT(SS_TAP(X_KP_2)))))); return false;
    case M_LBCKT2X: SEND_STRING("--"); return false;
    case M_RBCKT2X: SEND_STRING("=="); return false;
    case M_BARTENDERSHOW: SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT(SS_LGUI(SS_TAP(X_HOME)))))); return false;
  }

  return process_record_keymap(keycode, record);
}
