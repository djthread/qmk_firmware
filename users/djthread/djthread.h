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
  M_TMSG,
  M_TTREE,
  M_SEARCHNOTES,
  M_NEWNOTE,
  NEW_SAFE_RANGE  // use "NEW_SAFE_RANGE" for keymap specific codes
};

#endif
