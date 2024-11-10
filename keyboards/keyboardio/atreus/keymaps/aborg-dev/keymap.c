// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _NUM,
    _NAV,
    _WM,
};

#define KC_LANG  LSFT(KC_RALT)

const uint16_t PROGMEM escape_combo[] = {CTL_T(KC_J), KC_K, COMBO_END};
combo_t key_combos[] = {
    COMBO(escape_combo, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,           KC_T,                                                     KC_Y,           KC_U,           KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    CTL_T(KC_F),    KC_G,                                                     KC_H,           CTL_T(KC_J),    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,           KC_B,              KC_GRV,             KC_BSLS,           KC_N,           KC_M,           KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC,  KC_TAB,  KC_LALT, KC_TAB,         LT(_NUM, KC_BSPC), LM(_WM, MOD_LGUI),  LT(_NAV, KC_ENT),  SFT_T(KC_SPC),  KC_LANG,        CW_TOGG, KC_QUOT, KC_ENT ),

  /*
   *  ^       @      #     $    %        ||       *     7     8     9    +
   *  !       {      [     (    _        ||       =     4     5     6    -
   *  &       }      ]     )    :        ||       0     1     2     3    "
   * lower    .      .     .   bksp  tab || ent space   .     .     .    .
   */
  [_NUM] = LAYOUT( /* [> NUM <] */
    KC_CIRC, KC_AT,   KC_HASH, KC_DLR,         KC_PERC,                   KC_ASTR, KC_7,           KC_8,    KC_9,    KC_PLUS,
    KC_EXLM, KC_LCBR, KC_LBRC, KC_LPRN,        KC_UNDS,                   KC_EQL,  CTL_T(KC_4),    KC_5,    KC_6,    KC_PMNS,
    KC_AMPR, KC_RCBR, KC_RBRC, KC_RPRN,        KC_COLN, _______, _______, KC_0,    KC_1,           KC_2,    KC_3,    KC_DQUO,
    _______, _______, _______, _______,        _______, _______, _______, _______, _______,        _______, _______, _______),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_NAV] = LAYOUT( /* [> NAV <] */
    KC_INS,  MS_WHLD, MS_UP,   MS_WHLU, KC_PGUP,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_F10  ,
    KC_DEL,  MS_LEFT, MS_DOWN, MS_RGHT, KC_PGDN,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F11  ,
    KC_NO,   KC_VOLU, _______, _______, _______,  _______, _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    _______, _______, _______, MS_BTN3, MS_BTN1, MS_BTN2, _______, _______,  _______, _______, _______, _______),
  /*
   *  q       .      .     .    t        ||        .    .     .     .    .
   *  1       2      3     4    5        ||        h    j     k     l    ;
   *  .       .      .     .    .        ||        .    .     .     .    .
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_WM] = LAYOUT( /* [> WM <] */
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};
