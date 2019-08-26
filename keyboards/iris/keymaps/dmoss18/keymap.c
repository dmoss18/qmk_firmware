#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

// *** Custom combos *** //
// ********************* //
// Cmd+tab
#define KC_ATBR LGUI(KC_TAB)
// Cmd+Shft+Tab
#define KC_ATBL LGUI(S(KC_TAB))
// Cmd+`
#define KC_ATDR LGUI(KC_GRV)
// Cmd+Shft+`
#define KC_ATDL LGUI(S(KC_GRV))
// Ctrl+Tab
#define KC_CTBR LCTL(KC_TAB)
// Ctrl+Shft+Tab
#define KC_CTBL LCTL(S(KC_TAB))
// Ctrl+`
#define KC_CTDR LCTL(KC_GRV)
// Ctrl+Shft+`
#define KC_CTDL LCTL(S(KC_GRV))
// Cmd+Alt(Option)+Backslash
#define KC_1PAS LGUI(LALT(KC_BSLS))
// Ctrl+a (home)
#define KC_MHOM LCTL(KC_A)
// Ctrl+e (end)
#define KC_MEND LCTL(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,LCTL,     LCTL, N  , M  ,COMM,DOT ,SLSH,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LOWR,ENT ,         SPC ,RASE,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,MINS,EQL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , 1  , 2  ,MEND , 4  , 5  ,               6  ,    ,    ,    ,LBRC,RBRC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     DEL ,MHOM,LEFT, UP ,RGHT,    ,               GRV ,MINS,UNDS,PLUS,EQL ,PIPE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,    ,    ,DOWN,    ,LCBR,LPRN,     RPRN,RCBR,    ,DOWN,    ,    ,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,ATDR ,PGUP,               CIRC,AMPR,ASTR,LPRN,RPRN,1PAS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,CTDR,CTBR,MUTE,               EQL ,LEFT, UP ,RGHT,    ,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,MRWD,MFFD,VOLD,VOLU,MPLY,MUTE,         ,    ,    ,DOWN,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RTOG,RMOD,RHUI,RSAI,RVAI,    ,                   ,    ,    ,    ,    ,1PAS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,DBUG,RHUD,RSAD,RVAD,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BL_S,RST ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
