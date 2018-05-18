#ifndef PLANCK_H
#define PLANCK_H

#include "quantum.h"

#define LAYOUT_planck_mit( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
	k30, k31, k32, k33, k34,    k35,   k37, k38, k39, k3a, k3b \
) \
{ \
	{ k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b }, \
	{ k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b }, \
	{ k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b }, \
	{ k30, k31, k32, k33, k34, k35, k35, k37, k38, k39, k3a, k3b } \
}

#define LAYOUT_planck_grid( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
	k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
{ \
	{ k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b }, \
	{ k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b }, \
	{ k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b }, \
	{ k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b } \
}

#define LAYOUT_planck_grid_90deg_right( \
  k30, k20, k10, k00, \
  k31, k21, k11, k01, \
  k32, k22, k12, k02, \
  k33, k23, k13, k03, \
  k34, k24, k14, k04, \
  k35, k25, k15, k05, \
  k36, k26, k16, k06, \
  k37, k27, k17, k07, \
  k38, k28, k18, k08, \
  k39, k29, k19, k09, \
  k3a, k2a, k1a, k0a, \
  k3b, k2b, k1b, k0b \
) \
{ \
  { k30, k20, k10, k00 }, \
  { k31, k21, k11, k01 }, \
  { k32, k22, k12, k02 }, \
  { k33, k23, k13, k03 }, \
  { k34, k24, k14, k04 }, \
  { k35, k25, k15, k05 }, \
  { k36, k26, k16, k06 }, \
  { k37, k27, k17, k07 }, \
  { k38, k28, k18, k08 }, \
  { k39, k29, k19, k09 }, \
  { k3a, k2a, k1a, k0a }, \
  { k3b, k2b, k1b, k0b } \
}


/*
#define LAYOUT_planck_grid_90deg_right( \
	k0b, k1b, k2b, k3b, \
  k0a, k1a, k2a, k3a, \
  k09, k19, k29, k39, \
  k08, k18, k28, k38, \
  k07, k17, k27, k37, \
  k06, k16, k26, k36, \
  k05, k15, k25, k35, \
  k04, k14, k24, k34, \
  k03, k13, k23, k33, \
  k02, k12, k22, k32, \
  k01, k11, k21, k31, \
  k00, k10, k20, k30 \
) \
{ \
	{ k0b, k1b, k2b, k3b }, \
  { k0a, k1a, k2a, k3a }, \
  { k09, k19, k29, k39 }, \
  { k08, k18, k28, k38 }, \
  { k07, k17, k27, k37 }, \
  { k06, k16, k26, k36 }, \
  { k05, k15, k25, k35 }, \
  { k04, k14, k24, k34 }, \
  { k03, k13, k23, k33 }, \
  { k02, k12, k22, k32 }, \
  { k01, k11, k21, k31 }, \
  { k00, k10, k20, k30 } \
}
*/

// Used to create a keymap using only KC_ prefixed keys
#define KC_KEYMAP( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
	k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
	) \
	LAYOUT_planck_grid( \
		KC_##k00, KC_##k01, KC_##k02, KC_##k03, KC_##k04, KC_##k05, KC_##k06, KC_##k07, KC_##k08, KC_##k09, KC_##k0a, KC_##k0b, \
		KC_##k10, KC_##k11, KC_##k12, KC_##k13, KC_##k14, KC_##k15, KC_##k16, KC_##k17, KC_##k18, KC_##k19, KC_##k1a, KC_##k1b, \
		KC_##k20, KC_##k21, KC_##k22, KC_##k23, KC_##k24, KC_##k25, KC_##k26, KC_##k27, KC_##k28, KC_##k29, KC_##k2a, KC_##k2b, \
		KC_##k30, KC_##k31, KC_##k32, KC_##k33, KC_##k34, KC_##k35, KC_##k36, KC_##k37, KC_##k38, KC_##k39, KC_##k3a, KC_##k3b \
    )

#define KEYMAP LAYOUT_planck_grid
#define LAYOUT_ortho_4x12 LAYOUT_planck_grid
#define KC_LAYOUT_ortho_4x12 KC_KEYMAP

#endif
