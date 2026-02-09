// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum banzai_layers {
  _BASE,
  _RAISE,
  _LOWER,
  _THIRD,
  _CODE,
  _CRAISE,
  _CLOWER,
  _FOURTH
};

enum banzai_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  CLOWER,
  CRAISE,
  LIGHT
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * https://docs.qmk.fm/keycodes_basic
     * https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_swedish.h
     * https://docs.splitkb.com/product-guides/liatris/onboard-rgb
     * Check out contra for good info on PDF / DF
     */

    /*
     *                             [ _BASE ]
     * ┌───┐                                                      ┌───┐
     * │Esc│                                                      │Ent│
     * ├───┼───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┼───┤
     * │Tab│ Q │ W │ E │ R │ T │              │ Y │ U │ I │ O │ P │ Å │
     * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
     * │Lsh│ A │ S │ D │ F │ G │              │ H │ J │ K │ L │ Ö │ Ä │
     * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
     * │Lct│ Z │ X │ C │ V │ B │              │ N │ M │ , │ . │ - │ ' │
     * └───┴───┴───┴───┼───┼───┼─────┐  ┌─────┼───┼───┼───┴───┴───┴───┘
     *                 │Alt│Gui│Raise│  │Space│Low│*1*│ *1* => DF(_CODE)
     *                 └───┴───┴─────┘  └─────┴───┴───┘
     */

    [_BASE] = LAYOUT(
        KC_ESC,                                                                                                                                                     KC_ENT,
        KC_TAB,     SE_Q,       SE_W,       SE_E,       SE_R,       SE_T,                               SE_Y,       SE_U,       SE_I,       SE_O,       SE_P,       SE_ARNG,
        KC_LSFT,    SE_A,       SE_S,       SE_D,       SE_F,       SE_G,                               SE_H,       SE_J,       SE_K,       SE_L,       SE_ODIA,    SE_ADIA,
        KC_LCTL,    SE_Z,       SE_X,       SE_C,       SE_V,       SE_B,                               SE_N,       SE_M,       SE_COMM,    SE_DOT,     SE_MINS,    SE_QUOT,
                                                        KC_LALT,    KC_LGUI,    RAISE,      KC_SPC,     LOWER,      DF(_CODE)
    ),

    /*
    *                             [ _RAISE ]
    * ┌───┐                                                      ┌───┐
    * │Esc│                                                      │Bks│
    * ├───┼───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┼───┤
    * │ § │ 1 │ 2 │ 3 │ 4 │ 5 │              │ 6 │ 7 │ 8 │ 9 │ 0 │ + │
    * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
    * │Lsh│ < │   │   │   │   │              │Lef│Dwn│Up │Rgh│ ¨ │ ´ │
    * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
    * │Lct│   │   │   │   │   │              │   │   │   │   │   │   │
    * └───┴───┴───┴───┼───┼───┼─────┐  ┌─────┼───┼───┼───┴───┴───┴───┘
    *                 │Alt│Gui│Raise│  │Space│Low│   │
    *                 └───┴───┴─────┘  └─────┴───┴───┘
    */

    [_RAISE] = LAYOUT(
        _______,                                                                                                                                                    KC_BSPC,
        SE_SECT,    SE_1,       SE_2,       SE_3,       SE_4,       SE_5,                               SE_6,       SE_7,       SE_8,       SE_9,       SE_0,       SE_PLUS,
        _______,    SE_LABK,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   SE_DIAE,    SE_ACUT,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                        _______,    _______,    _______,    _______,    _______,    XXXXXXX
    ),

    /*
     *                             [ _LOWER ]
     * ┌───┐                                                      ┌───┐
     * │Esc│                                                      │Del│
     * ├───┼───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┼───┤
     * │   │ F1│ F2│ F3│ F4│ F5│              │ F6│ F7│ F8│ F9│F10│F11│
     * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
     * │Lsh│   │Pre│Pla│For│   │              │Lef│Dwn│Up │Rgh│   │F12│
     * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
     * │Lct│   │   │Sto│   │Prt│              │VoU│VoD│VoM│   │   │Rct│
     * └───┴───┴───┴───┼───┼───┼─────┐  ┌─────┼───┼───┼───┴───┴───┴───┘
     *                 │Alt│Gui│Raise│  │Space│Low│   │
     *                 └───┴───┴─────┘  └─────┴───┴───┘
     */
    [_LOWER] = LAYOUT(
        _______,                                                                                                                                                    KC_DEL,
        XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
        _______,    XXXXXXX,    KC_MPRV,    KC_MPLY,    KC_MNXT,    XXXXXXX,                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   XXXXXXX,    KC_F12,
        _______,    XXXXXXX,    XXXXXXX,    KC_MSTP,    XXXXXXX,    XXXXXXX,                            KC_VOLD,    KC_VOLU,    KC_MUTE,    XXXXXXX,    XXXXXXX,    KC_RCTL,
                                                        _______,    _______,    _______,    _______,    _______,    XXXXXXX
    ),

    /*
     *                            [ _THIRD ]
     * ┌───┐                                                      ┌───┐
     * │Esc│                                                      │RCL│
     * ├───┼───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┼───┤
     * │   │   │ @ │ £ │ $ │ € │              │   │ { │ [ │ ] │ } │ \ │
     * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
     * │CAP│ | │   │   │   │   │              │Hom│PgD│PgU│End│ ~ │   │
     * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
     * │Lct│   │   │   │   │   │              │   │   │   │   │ScL│NuL│
     * └───┴───┴───┴───┼───┼───┼─────┐  ┌─────┼───┼───┼───┴───┴───┴───┘
     *                 │Alt│Gui│Raise│  │Space│Low│   │
     *                 └───┴───┴─────┘  └─────┴───┴───┘
     */

    [_THIRD] = LAYOUT(
        _______,                                                                                                                                                    MS_BTN2,
        XXXXXXX,    XXXXXXX,    SE_AT,      SE_PND,     SE_DLR,     SE_EURO,                            XXXXXXX,    SE_LCBR,    SE_LBRC,    SE_RBRC,    SE_RCBR,    SE_BSLS,
        KC_CAPS,    SE_PIPE,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     SE_TILD,    XXXXXXX,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_SCRL,    KC_NUM,
                                                        _______,    _______,    _______,    _______,    _______,    LIGHT
    ),

    /*
     *                             [ _CODE ]
     * ┌───┐                                                      ┌───┐
     * │Esc│                                                      │Ent│
     * ├───┼───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┼───┤
     * │Tab│ Q │ W │ E │ R │ T │              │ Y │ U │ I │ O │ P │ Å │
     * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
     * │Lsh│ A │ S │ D │ F │ G │              │ H │ J │ K │ L │ Ö │ Ä │
     * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
     * │Lct│ Z │ X │ C │ V │ B │              │ N │ M │ , │ . │ - │ ' │
     * └───┴───┴───┴───┼───┼───┼─────┐  ┌─────┼───┼───┼───┴───┴───┴───┘
     *                 │Alt│Gui│PRais│  │Space│PLo│*2*│ *2* => DF(_BASE)
     *                 └───┴───┴─────┘  └─────┴───┴───┘
     */

    [_CODE] = LAYOUT(
        KC_ESC,                                                                                                                                                     KC_ENT,
        KC_TAB,     SE_Q,       SE_W,       SE_E,       SE_R,       SE_T,                               SE_Y,       SE_U,       SE_I,       SE_O,       SE_P,       SE_ARNG,
        KC_LSFT,    SE_A,       SE_S,       SE_D,       SE_F,       SE_G,                               SE_H,       SE_J,       SE_K,       SE_L,       SE_ODIA,    SE_ADIA,
        KC_LCTL,    SE_Z,       SE_X,       SE_C,       SE_V,       SE_B,                               SE_N,       SE_M,       SE_COMM,    SE_DOT,     SE_MINS,    SE_QUOT,
                                                        KC_LALT,    KC_LGUI,    CRAISE,     KC_SPC,     CLOWER,     DF(_BASE)
    ),

    /*
    *                             [ _CRAISE ]
    * ┌───┐                                                      ┌───┐
    * │Esc│                                                      │Bks│
    * ├───┼───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┼───┤
    * │ § │ 1 │ 2 │ 3 │ 4 │ 5 │              │ 6 │ 7 │ 8 │ 9 │ 0 │ + │
    * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
    * │Lsh│ < │   │   │   │   │              │Lef│Dwn│Up │Rgh│ ¨ │ ´ │
    * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
    * │Lct│   │   │   │   │   │              │   │   │   │   │   │   │
    * └───┴───┴───┴───┼───┼───┼─────┐  ┌─────┼───┼───┼───┴───┴───┴───┘
    *                 │Alt│Gui│Raise│  │Space│Low│   │
    *                 └───┴───┴─────┘  └─────┴───┴───┘
    */

    [_CRAISE] = LAYOUT(
        _______,                                                                                                                                                    KC_BSPC,
        SE_SECT,    SE_1,       SE_2,       SE_3,       SE_4,       SE_5,                               SE_6,       SE_7,       SE_8,       SE_9,       SE_0,       SE_PLUS,
        _______,    SE_LABK,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   SE_DIAE,    SE_ACUT,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                        _______,    _______,    _______,    _______,    _______,    XXXXXXX
    ),

    /*
     *                             [ _CLOWER ]
     * ┌───┐                                                      ┌───┐
     * │Esc│                                                      │Del│
     * ├───┼───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┼───┤
     * │   │ F1│ F2│ F3│ F4│ F5│              │ F6│ F7│ F8│ F9│F10│F11│
     * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
     * │Lsh│   │Pre│Pla│For│   │              │Lef│Dwn│Up │Rgh│   │F12│
     * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
     * │Lct│   │   │Sto│   │Prt│              │VoU│VoD│VoM│   │   │Rct│
     * └───┴───┴───┴───┼───┼───┼─────┐  ┌─────┼───┼───┼───┴───┴───┴───┘
     *                 │Alt│Gui│Raise│  │Space│Low│   │
     *                 └───┴───┴─────┘  └─────┴───┴───┘
     */
    [_CLOWER] = LAYOUT(
        _______,                                                                                                                                                    KC_DEL,
        XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
        _______,    XXXXXXX,    KC_MPRV,    KC_MPLY,    KC_MNXT,    XXXXXXX,                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   XXXXXXX,    KC_F12,
        _______,    XXXXXXX,    XXXXXXX,    KC_MSTP,    XXXXXXX,    XXXXXXX,                            KC_VOLD,    KC_VOLU,    KC_MUTE,    XXXXXXX,    XXXXXXX,    KC_RCTL,
                                                        _______,    _______,    _______,    _______,    _______,    XXXXXXX
    ),

    /*
    *                             [ _FOURTH ]
    * ┌───┐                                                      ┌───┐
    * │Esc│                                                      │Del│
    * ├───┼───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┼───┤
    * │CAP│   │ @ │ : │ $ │ ( │              │ ) │ = │ * │ ~ │PgU│ \ │
    * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
    * │Lsh│ £ │   │ / │ < │ { │              │ } │ > │ # │   │PgD│   │
    * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
    * │Lct│ € │   │Hom│ ' │ [ │              │ ] │ | │End│   │   │Rct│
    * └───┴───┴───┴───┼───┼───┼─────┐  ┌─────┼───┼───┼───┴───┴───┴───┘
    *                 │Alt│Gui│Raise│  │Space│Low│   │
    *                 └───┴───┴─────┘  └─────┴───┴───┘
    */

    [_FOURTH] = LAYOUT(
        _______,                                                                                                                                                    MS_BTN2,
        KC_CAPS,    XXXXXXX,    SE_AT,      SE_COLN,    SE_DLR,     SE_LPRN,                            SE_RPRN,    SE_EQL,     SE_ASTR,    SE_TILD,    KC_PGUP,    SE_BSLS,
        _______,    SE_PND,     XXXXXXX,    SE_SLSH,    SE_LABK,    SE_LCBR,                            SE_RCBR,    SE_RABK,    SE_HASH,    XXXXXXX,    KC_PGDN,    XXXXXXX,
        _______,    SE_EURO,    XXXXXXX,    KC_HOME,    SE_QUOT,    SE_LBRC,                            SE_RBRC,    SE_PIPE,    KC_END,     XXXXXXX,    XXXXXXX,    KC_RCTL,
                                                        _______,    _______,    _______,    _______,    _______,    LIGHT
    )

};



layer_state_t layer_state_set_user(layer_state_t state) {
    switch (biton32(state)) {
    case _CODE:
      //rgblight_enable_noeeprom();
      rgblight_mode_noeeprom(RGB_MODE_RAINBOW);
      break;
    default:
      rgblight_mode_noeeprom(RGB_MODE_PLAIN);
      //rgblight_disable_noeeprom();
      break;
    }
  return state;
}

void housekeeping_task_user(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _BASE:
            // Default layer
            rgblight_setrgb_at(RGB_BLACK, 0);
            rgblight_setrgb_at(RGB_BLACK, 1);
            break;
        case _RAISE:
            rgblight_setrgb_at(0x05, 0, 0, 0);
            rgblight_setrgb_at(0x05, 0, 0, 1);
            break;
        case _LOWER:
            rgblight_setrgb_at(0, 0, 0x05, 0);
            rgblight_setrgb_at(0, 0, 0x05, 1);
            break;
        case _THIRD:
            rgblight_setrgb_at(0x05, 0, 0x05, 0);
            rgblight_setrgb_at(0x05, 0, 0x05, 1);
            break;
        case _CODE:
            // Default layer
//            rgblight_setrgb_at(0, 0x05, 0, 0);
  //          rgblight_setrgb_at(0, 0x05, 0, 1);
   //         rgblight_mode_noeeprom(RGB_MODE_RAINBOW);
            break;
        case _CRAISE:
            rgblight_setrgb_at(0x05, 0x05, 0, 0);
            rgblight_setrgb_at(0x05, 0x05, 0, 1);
            break;
        case _CLOWER:
            rgblight_setrgb_at(0, 0x05, 0x05, 0);
            rgblight_setrgb_at(0, 0x05, 0x05, 1);
            break;
        case _FOURTH:
            rgblight_setrgb_at(0x05, 0x05, 0x05, 0);
            rgblight_setrgb_at(0x05, 0x05, 0x05, 1);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _THIRD);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _THIRD);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _THIRD);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _THIRD);
      }
      return false;
      break;
    case CLOWER:
      if (record->event.pressed) {
        layer_on(_CLOWER);
        update_tri_layer(_CLOWER, _CRAISE, _FOURTH);
      } else {
        layer_off(_CLOWER);
        update_tri_layer(_CLOWER, _CRAISE, _FOURTH);
      }
      return false;
      break;
    case CRAISE:
      if (record->event.pressed) {
        layer_on(_CRAISE);
        update_tri_layer(_CLOWER, _CRAISE, _FOURTH);
      } else {
        layer_off(_CRAISE);
        update_tri_layer(_CLOWER, _CRAISE, _FOURTH);
      }
      return false;
      break;
  }
  return true;
}
