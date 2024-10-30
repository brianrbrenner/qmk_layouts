/* Copyright 2022 James White <jamesmnw@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keys {
    _CMAK = SAFE_RANGE,
    _CSTM,
    _SYM,
    POINTER,
    ARROWOP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * COLEMAK_DH
 * ,---------------------------------.     ,----------------------------------.
 * |  Q  |   W  |   F  |   P  |   B  |     |   J  |   L  |   U  |   Y  |   "  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  A  |   R  |   S  |   T  |   G  |     |   M  |   N  |   E  |   I  |   O  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |  Z  |   X  |   C  |   V  |   V  |     |   K  |   H  |   ,  |   .  |   /  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              | CAPS | Tab | Spc  |      | Bspc  | MO2  | ____ |
 *              `--------------------'     `--------------------'
 */

[_CMAK] = LAYOUT_split_3x5_3(
KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,           KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
  LALT_T(KC_A),  LGUI_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,      KC_M,    RCTL_T(KC_N),  RSFT_T(KC_E),  RGUI_T(KC_I), LALT_T(KC_O),
KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,  KC_COMM,  KC_DOT, KC_SLSH,
   KC_CAPS,   KC_TAB,  LT(MO(1), KC_SPC),          KC_BSPC,   MO(2),  KC_TRNS
),

[_CSTM] = LAYOUT_split_3x5_3(
KC_ESC,  KC_COLN, KC_SCLN,  KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_CIRC, KC_TRNS, KC_BSLS, POINTER, ARROWOP,                    KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT, KC_DLR,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_SPC,                      KC_ENT,  KC_TRNS,  KC_TRNS
),


[_SYM] = LAYOUT_split_3x5_3(
KC_1,   KC_2,  KC_3,    KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,    KC_9,   KC_0,
KC_DLR, KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,                       KC_PIPE, KC_MINUS, KC_EQL,  KC_UNDS, KC_ASTR,
KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_GRAVE,                   KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC,
                 KC_TRNS, KC_TRNS, KC_SPC,                      KC_ENT,  KC_TRNS,  KC_TRNS
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case POINTER:
      if (record->event.pressed) {
            SEND_STRING("->");
      }
      return false; // Skip all further processing of this key
    case ARROWOP:
        if (record->event.pressed) {
            SEND_STRING("=>");
        }
      return false; // Let QMK send the enter press/release events
    default:
      return true; // Process all other keycodes normally
  }
}
