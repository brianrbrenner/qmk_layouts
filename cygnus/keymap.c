#include QMK_KEYBOARD_H

enum custom_keys {
    POINTER,
    ARROWOP
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

[0] = LAYOUT(
 _______, KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,           KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, _______,
 _______, LALT_T(KC_A),  LGUI_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,      KC_M,    RCTL_T(KC_N),  RSFT_T(KC_E),  RGUI_T(KC_I), LALT_T(KC_O), _______,
 _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,  KC_COMM,  KC_DOT, KC_SLSH, _______,
                KC_CAPS,   KC_TAB,  LT(MO(1), KC_SPC),       KC_BSPC,   MO(2),  KC_TRNS
),

[1] = LAYOUT(
 _______, KC_ESC,  KC_COLN, KC_SCLN,  KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, _______,
 _______, KC_CIRC, KC_TRNS, KC_BSLS, POINTER, ARROWOP,                    KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT, KC_DLR, _______,
 _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, _______,
                        KC_TRNS, KC_TRNS, KC_SPC,                           KC_ENT,  KC_TRNS,  KC_TRNS
),


[2] = LAYOUT(
_______, KC_1,   KC_2,  KC_3,    KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,    KC_9,   KC_0, _______,
_______, KC_DLR, KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,                       KC_PIPE, KC_MINUS, KC_EQL,  KC_UNDS, KC_ASTR, _______,
_______, KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_GRAVE,                   KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,
                 KC_TRNS, KC_TRNS, KC_SPC,                      KC_ENT,  KC_TRNS,  KC_TRNS
)

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
