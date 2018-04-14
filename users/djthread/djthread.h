#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

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
  M_WTOP,
  M_WBOTTOM,
  M_MPREV,
  M_MTOGG,
  M_MNEXT,
  M_TABPREV,
  M_TABNEXT,
  M_BACK,
  M_FWD,
  M_RSTEX,
  M_DISMISSNOTI,
  M_LOCK,
  M_OUTLOOK,
  M_TEAMS,
  M_TMSG,
  M_TTREE,
  M_SEARCHNOTES,
  M_NEWNOTE,
  M_FOCUSVIEW,
  M_S_PGUP,
  M_S_PGDN,
  M_CMD_W,
  M_CMD_H,
  M_CMD_TAB,
  M_APPTERM,
  M_GOLEFT,
  M_GORIGHT,
  NEW_SAFE_RANGE  // use "NEW_SAFE_RANGE" for keymap specific codes
};

#endif
