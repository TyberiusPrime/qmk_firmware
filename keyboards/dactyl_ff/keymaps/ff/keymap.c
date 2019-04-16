#include "dactyl-manuform.h"
#include "print.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "split_util.h"
#include "rgblight.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN   1

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP_5x6(
  // left hand
   KC_ESC,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5, 
   KC_GRV,    RGB_TOG,    KC_W,    KC_E,   KC_R,   KC_T,
   KC_TAB,    KC_A,    KC_S,    KC_D,   RGB_TOG,   KC_C,
   KC_LSHIFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
                       KC_TAB,  KC_BSLS,
                               LT(_FN, KC_DEL), KC_LSFT, 
                               KC_SPC,   KC_LCTRL,
                               KC_ENTER, KC_LALT,
        // right hand
                     KC_6,    KC_K,   KC_8,    KC_X,    KC_SPACE,    KC_MINS,
                     KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_EQL,
                     KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
                     KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSHIFT,
                                      KC_LBRC, KC_RBRC,
        KC_SPC, LT(_FN, KC_BSPC), 
        CTL_T(KC_PGUP), KC_PGDN,
        KC_LALT, KC_LGUI),
[_FN] = KEYMAP_5x6(
  // left hand
   _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, 
   _______,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,
   _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDN,
   RESET,    _______,  _______,  _______,  _______,  _______,
                       _______,  _______, 
                               LT(_FN, KC_DEL), KC_LSFT, 
                               KC_SPC,   KC_LCTRL,
                               KC_ENTER, KC_LALT,
        // right hand
                     KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,  KC_F11,
                     KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   _______,  KC_F12,
                     KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______, _______,
                     KC_CALC,  KC_MAIL,  KC_MYCM,  KC_WHOM,  _______,   RESET,
                                         _______,  _______,
        KC_SPC, LT(_FN, KC_BSPC), 
        CTL_T(KC_PGUP), KC_PGDN,
        KC_LALT, KC_LGUI),
};



void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
        dprintf("matrix init\n");

    //set_unicode_input_mode(UC_LNX); // REPLACE UC_XXXX with the Unicode Input Mode for your OS. See table below.
    //rgblight_enable();
};


void keyboard_post_init_user(void) {
        dprintf("post init user \n");
      // Customise these values to desired behaviour
         debug_enable=true;
           debug_matrix=true;
             debug_keyboard=true;
      //         //debug_mouse=true;
      //
               }
unsigned int ii = 0;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
    dprintf("set led\n");
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(20,120,20);
      
    matrix_print();
    }
    return true;
}
