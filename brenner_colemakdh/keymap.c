#include QMK_KEYBOARD_H

/*
*   TODO: configure tri-state layer to add media controls / or use layer 1
*   TODO: add arrow macros
*/

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(KC_Q, KC_W, KC_F, KC_P, KC_B,      KC_J, KC_L, KC_U, KC_Y, KC_QUOT, 
                    LALT_T(KC_A), LGUI_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,       KC_M, RCTL_T(KC_N), RSFT_T(KC_E), RGUI_T(KC_I), RALT_T(KC_O),
                    KC_Z, KC_X, KC_C, KC_D, KC_V,      KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, 
                          KC_TAB, LT(MO(1),KC_SPC),         KC_BSPC, MO(2)),

[_LAYER1] = LAYOUT(KC_ESC, KC_COLN, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_CIRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DLR, 
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                        KC_TRNS, KC_TRNS,               KC_ENT, KC_TRNS),

[_LAYER2] = LAYOUT(KC_1, KC_2, KC_3, KC_4, KC_5,                  KC_6, KC_7, KC_8, KC_9, KC_0, 
                   KC_DLR, KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,      KC_PIPE, KC_MINS, KC_EQL, KC_UNDS, KC_ASTR,
                   KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_GRV,    KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, 
                                        KC_TRNS, KC_TRNS,             KC_ENT, KC_TRNS),

};
