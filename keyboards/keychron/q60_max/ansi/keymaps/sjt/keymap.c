/* Copyright 2024 @ sjt */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    FN,
    L2
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_60(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,            KC_BSPC,
        KC_LCTL, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                      KC_ENT,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, MO(FN),
                           KC_LOPTN, KC_LCMMD,                           KC_SPC,                             KC_RCMMD, MO(L2)),

    [FN] = LAYOUT_ansi_60(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    KC_INS,  EE_CLR,
        KC_CAPS, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,    _______,            KC_DEL,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,                      _______,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, BAT_LVL, NK_TOGG, _______, KC_END,  KC_PGDN, KC_DOWN,             _______, _______,
                           _______,  _______,                            _______,                            _______,  _______),

    [L2] = LAYOUT_ansi_60(
        KC_MUTE, KC_VOLD,  KC_VOLU,  KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______,  _______,   KC_LPAD, KC_MCTL,
        _______, _______,  KC_UP,    _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______,  _______,            _______,
        _______, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______,                      _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
                           _______,  _______,                            _______,                            _______,  _______)
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

/*mouse jiggler **************************************************************/

bool jiggle_enabled = false;
bool jiggle_direction = false;
uint16_t jiggle_freq = 55000; // 55 seconds
uint16_t jiggle_timer = 0;

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        jiggle_enabled = active;
    }
    return true;
}

void housekeeping_task_user(void) {
    static uint16_t count = 0;

    if (jiggle_timer == 0) jiggle_timer = timer_read();

    if (jiggle_enabled && (++count == 15000)) {
        count = 0;
        if (timer_elapsed(jiggle_timer) > jiggle_freq) {
            jiggle_timer = timer_read();
            if (jiggle_direction) {
                tap_code(KC_MS_LEFT);
            } else {
                tap_code(KC_MS_RIGHT);
            }
            jiggle_direction = !jiggle_direction;
        }
    }
}

/*Layer lights****************************************************************/

// a LED group (ie. "arrows", "volume")
typedef struct {
    uint8_t num;       // num leds in group
    uint8_t leds[16];  // group max sz 16
    rgb_led_t color;   // color of group
} led_group_t;

// group definitions FN
const led_group_t led_list_fn        = {12, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, {RGB_RED}};
const led_group_t led_list_insdel    = {2,  {13, 28},                                {RGB_GREEN}};
const led_group_t led_list_arrows_fn = {4,  {26, 39, 40, 52},                        {RGB_YELLOW}};
const led_group_t led_list_page      = {7,  {23, 24, 25, 37, 38, 50, 51},            {RGB_MAGENTA}};
const led_group_t led_list_rgb       = {9,  {29, 30, 31, 32, 33, 43, 44, 45, 46},    {RGB_GREEN}};
const led_group_t led_list_batnk     = {2,  {47, 48},                                {RGB_CYAN}};
const led_group_t led_list_bluetooth = {4,  {16, 17, 18, 19},                        {RGB_BLUE}};
const led_group_t led_list_eeprom    = {1,  {14},                                    {RGB_WHITE}};

led_group_t led_groups_fn[] = { led_list_fn, led_list_insdel,
                                led_list_arrows_fn, led_list_page,
                                led_list_rgb, led_list_batnk,
                                led_list_bluetooth, led_list_eeprom };

// group definitions L2
const led_group_t led_list_arrows_l2     = {4, {17, 30, 31, 32}, {RGB_RED}};
const led_group_t led_list_mouse_arrows  = {4, {20, 33, 34, 35}, {RGB_BLUE}};
const led_group_t led_list_mouse_buttons = {2, {19, 21},         {RGB_YELLOW}};
const led_group_t led_list_vol           = {3, {0, 1, 2},        {RGB_GREEN}};
const led_group_t led_list_mac           = {2, {13, 14},         {RGB_CYAN}};
const led_group_t led_list_media         = {3, {3, 4, 5},        {RGB_MAGENTA}};

led_group_t led_groups_l2[] = { led_list_arrows_l2, led_list_mouse_arrows, 
                                led_list_mouse_buttons, led_list_vol,
                                led_list_mac, led_list_media };

// mouse jiggler handled separately in FN layer
const led_group_t led_list_msjig_on  = {1,  {0}, {RGB_GREEN}};
const led_group_t led_list_msjig_off = {1,  {0}, {RGB_RED}};

void paint_group(led_group_t group) {
    for (uint8_t j = 0; j < group.num; j++) {
        rgb_matrix_set_color(group.leds[j],
                             group.color.g,
                             group.color.r,
                             group.color.b);
    }
}

void paint_layer(led_group_t *groups, uint8_t num_groups) {
    uint8_t i,j;

    // black it out
    for (i=0; i<MATRIX_ROWS; ++i) {
        for (j=0; j<MATRIX_COLS; ++j) {
            rgb_matrix_set_color(g_led_config.matrix_co[i][j], RGB_BLACK);
        }
    }

    // apply color to groups
    for (i = 0; i < num_groups; i++) {
        paint_group(groups[i]);
    }
}

bool rgb_matrix_indicators_user(void) {

    switch (get_highest_layer(layer_state)) {
    case FN:
        paint_layer(led_groups_fn, ARRAY_SIZE(led_groups_fn));

        if (jiggle_enabled) {
            paint_group(led_list_msjig_on);
        }
        else {
            paint_group(led_list_msjig_off);
        }

        break;
    case L2:
        paint_layer(led_groups_l2, ARRAY_SIZE(led_groups_l2));
        break;
    default:
        break;
    }

    // return true to call rgb_matrix_indicators_keychron()
    return true;
}

