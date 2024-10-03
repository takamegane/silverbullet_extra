#include QMK_KEYBOARD_H

enum my_keycode{
  NORMAL = QK_KB_0,
  ACCEL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_MUTE,        KC_MUTE,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_LGUI, KC_BSPC, KC_LGUI, KC_BSPC, KC_SPC,                             KC_BSPC, KC_SPC,   KC_SPC,  KC_ENT, KC_RALT
    ),
    [1] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_MUTE,        KC_MUTE,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_LGUI, KC_BSPC, KC_LGUI, KC_BSPC, KC_SPC,                             KC_BSPC, KC_SPC,   KC_SPC,  KC_ENT, KC_RALT
    ),
    [2] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_MUTE,        KC_MUTE,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_LGUI, KC_BSPC, KC_LGUI, KC_BSPC, KC_SPC,                             KC_BSPC, KC_SPC,   KC_SPC,  KC_ENT, KC_RALT
    ),
    [3] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_MUTE,        KC_MUTE,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_LGUI, KC_BSPC, KC_LGUI, KC_BSPC, KC_SPC,                             KC_BSPC, KC_SPC,   KC_SPC,  KC_ENT, KC_RALT
    )
};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_C, KC_D),
            ENCODER_CCW_CW(KC_C, KC_D), 
            ENCODER_CCW_CW(KC_E, KC_F), 
            ENCODER_CCW_CW(KC_G, KC_H), 
            ENCODER_CCW_CW(KC_I, KC_J),
            ENCODER_CCW_CW(KC_G, KC_H) },
    [1] = { ENCODER_CCW_CW(KC_C, KC_D),
            ENCODER_CCW_CW(KC_C, KC_D), 
            ENCODER_CCW_CW(KC_E, KC_F), 
            ENCODER_CCW_CW(KC_G, KC_H), 
            ENCODER_CCW_CW(KC_I, KC_J),
            ENCODER_CCW_CW(KC_G, KC_H) },
    [2] = { ENCODER_CCW_CW(KC_C, KC_D),
            ENCODER_CCW_CW(KC_C, KC_D), 
            ENCODER_CCW_CW(KC_E, KC_F), 
            ENCODER_CCW_CW(KC_G, KC_H), 
            ENCODER_CCW_CW(KC_I, KC_J),
            ENCODER_CCW_CW(KC_G, KC_H) },
    [3] = { ENCODER_CCW_CW(KC_C, KC_D),
            ENCODER_CCW_CW(KC_C, KC_D), 
            ENCODER_CCW_CW(KC_E, KC_F), 
            ENCODER_CCW_CW(KC_G, KC_H), 
            ENCODER_CCW_CW(KC_I, KC_J),
            ENCODER_CCW_CW(KC_G, KC_H) },
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NORMAL:
      pimoroni_trackball_set_cpi(128*125); //Default Speed
      break;
    case ACCEL:                                      
      pimoroni_trackball_set_cpi(3*128*125); // x3 Speed
      break;
  }
  return true;
}

// Default Accellaration Mode
void pointing_device_init_kb(void) {
    //uint8_t addr=0x14;
    uint8_t addr=0x0a<<1;
    //uint8_t data[]={0x90, 0x00};    // AZ1UBALL normal speed mode
    uint8_t data[]={0x91, 0x00};      // AZ1UBALL accellaration mode
    uint16_t timeout=100;             // in milli-seconds
    i2c_status_t status;
    status  = i2c_transmit (addr, data, 2, timeout);
    if (status != 0) {
        return;
    }   
}

void keyboard_post_init_user(void) {
    pointing_device_set_cpi_on_side(true,500); //Set cpi on left side to a low value for slower scrolling.
    pointing_device_set_cpi_on_side(false, 8000); //Set cpi on right side to a reasonable value for mousing.
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}