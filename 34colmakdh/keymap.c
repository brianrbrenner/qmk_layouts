#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keys {
  POINTER = SAFE_RANGE,
  ARROWOP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOT,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  XXXXXXX, LALT_T(KC_A),  LGUI_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,      KC_M,    RCTL_T(KC_N),  RSFT_T(KC_E),  RGUI_T(KC_I), LALT_T(KC_O), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,  KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        XXXXXXX,   KC_TAB,  LT(MO(1), KC_SPC),          KC_BSPC,   MO(2),  XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX,  KC_ESC,  KC_SCLN, KC_COLN,  XXXXXXX, XXXXXXX,                   KC_DOWN, KC_RIGHT, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_CIRC, XXXXXXX, KC_BSLS, POINTER, ARROWOP,                      KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_LEFT, KC_DLR, XXXXXXX, //end of line in vim and begin
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,                  KC_UP,  KC_LEFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______,  KC_SPC,     KC_ENT,   XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, KC_1,   KC_2,  KC_3,    KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,    KC_9,   KC_0,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_DLR, KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,                        KC_PIPE, KC_MINUS, KC_EQL,  KC_UNDS, KC_ASTR,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_GRAVE,                    KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_SPC,     KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,                          KC_F6,    KC_F7,    KC_F8,  KC_F9,   KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F11, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, XXXXXXX,  KC_SPC,     KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )

};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

void oled_render_B_logo(void) {
  static const char PROGMEM B_logo[] = { 
      // logo is 32x32
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xe0, 0xa0, 0xb0, 0xb0, 0x18, 0x18, 0x0c, 0x00, 0x00, 0x00, 0xff, 0x21, 0x21, 
	0x21, 0x31, 0x7e, 0xc0, 0x00, 0x00, 0x0c, 0x18, 0x18, 0x30, 0x30, 0xe0, 0xe0, 0x40, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x08, 
	0x08, 0x08, 0x04, 0x07, 0x00, 0x00, 0x04, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  oled_write_raw_P(B_logo, sizeof(B_logo));
}

void oled_render_rust_logo(void) {
 static const char PROGMEM rust_logo[] = {
	0x00, 0x00, 0x80, 0x80, 0xb0, 0xf0, 0xf0, 0xfc, 0xfc, 0x7e, 0x7e, 0x3e, 0x3f, 0x1f, 0x3e, 0x7f, 
	0x7f, 0x3e, 0x1f, 0x1f, 0x3c, 0x3e, 0x7e, 0xf8, 0xfc, 0xf8, 0xf0, 0xf0, 0x80, 0x80, 0x00, 0x00, 
	0xb0, 0xf6, 0xfe, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xef, 
	0xef, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x39, 0x3f, 0x7f, 0xef, 0xff, 0xff, 0xfe, 0xb0, 
	0x0d, 0x6f, 0x7f, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7b, 0x7b, 
	0x7b, 0x03, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x0d, 
	0x00, 0x00, 0x01, 0x01, 0x0d, 0x0f, 0x0f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7e, 0xfc, 0xf8, 0x78, 0xf8, 
	0xf8, 0x78, 0xf8, 0xfc, 0x3c, 0x7f, 0x7f, 0x1f, 0x3f, 0x1f, 0x0f, 0x0f, 0x01, 0x01, 0x00, 0x00
    };
    oled_write_raw_P(rust_logo, sizeof(rust_logo));
}

#define L_BASE 0
#define L_LOWER 1
#define L_RAISE 2
#define L_BOTH 3

#    define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case L_BASE:
            oled_write_P(PSTR("QRTY"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("LOW"), false);
            break;
        case L_RAISE:
            oled_write_P(PSTR("HIGH"), false);
            break;
        case L_BOTH:
            oled_write_P(PSTR("BOTH"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S"), led_state.scroll_lock);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_B_and_rust(void) {
    oled_render_B_logo();
    oled_set_cursor(0, 6);
    oled_render_rust_logo();
}

#ifdef WPM_ENABLE
static void print_logo_narrow(void) {
    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(1, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);
}
#endif

void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show modifier status
    render_mod_status(get_mods());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    render_keylogger_status();
    print_logo_narrow();
}

bool oled_task_user(void) {
  //update_log();
  if (is_keyboard_master()) {
    render_B_and_rust();
  } else {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode);
    }
    switch (keycode) {
    case POINTER:
        if (record->event.pressed) {
            SEND_STRING("->");
        }
        break;
    case ARROWOP:
        if (record->event.pressed) {
            SEND_STRING("=>");
        }
        break;
    case L_LOWER:
      if (record->event.pressed) {
        layer_on(L_LOWER);
        update_tri_layer(L_LOWER, L_RAISE, L_BOTH);
      } else {
        layer_off(L_LOWER);
        update_tri_layer(L_LOWER, L_RAISE, L_BOTH);
      }
      return false;
    case L_RAISE:
      if (record->event.pressed) {
        layer_on(L_RAISE);
        update_tri_layer(L_LOWER, L_RAISE, L_BOTH);
      } else {
        layer_off(L_RAISE);
        update_tri_layer(L_LOWER, L_RAISE, L_BOTH);
      }
      return false; 
    }
    return true;   

}
#endif // OLED_ENABLE
