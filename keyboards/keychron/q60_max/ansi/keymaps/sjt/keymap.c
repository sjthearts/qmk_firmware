/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    WIN_BASE,
    FN,
    L3,
    L4,
    L5
};
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_60(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,            KC_BSPC,
        KC_LCTL, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                      KC_ENT,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, MO(FN),
                           KC_LOPTN, KC_LCMMD,                           KC_SPC,                             KC_RCMMD, MO(L3)),

    [WIN_BASE] = LAYOUT_ansi_60(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,            KC_DEL,
        KC_LCTL, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                      KC_ENT,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, MO(FN),
                           KC_LWIN,  KC_LALT,                            KC_SPC,                             KC_RALT,  KC_RWIN),

    [FN] = LAYOUT_ansi_60(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    KC_INS,  KC_DEL,
        KC_CAPS, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,    _______,            _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,                      _______,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, BAT_LVL, NK_TOGG, _______, KC_END,  KC_PGDN, KC_DOWN,             _______, _______,
                           _______,  _______,                            _______,                            _______,  _______),

    [L3] = LAYOUT_ansi_60(
        KC_MUTE, KC_VOLD,  KC_VOLU,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   KC_LPAD, KC_MCTL,
        _______, _______,  KC_UP,    _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______,  _______,            _______,
        _______, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______,                      _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
                           _______,  _______,                            _______,                            _______,  _______),

    [L4] = LAYOUT_ansi_60(
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______, _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,                      _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
                           _______,  _______,                            _______,                            _______,  _______),

    [L5] = LAYOUT_ansi_60(
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______, _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,                      _______,
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

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

// a LED group (ie. "arrows", "volume")
typedef struct {
    uint8_t num;      // num leds in group
    uint8_t leds[8];  // group max sz 8
    rgb_led_t color;  // color of group
} led_group_t;

const led_group_t led_list_arrows        = {4, {17,30,31,32}, {RGB_RED}};
const led_group_t led_list_mouse_arrows  = {4, {20,33,34,35}, {RGB_BLUE}};
const led_group_t led_list_mouse_buttons = {2, {19,21},       {RGB_YELLOW}};
const led_group_t led_list_vol           = {3, {0, 1, 2},     {RGB_GREEN}};
const led_group_t led_list_mac           = {2, {13, 14},      {RGB_CYAN}};

led_group_t led_groups[] = {
    led_list_arrows,
    led_list_mouse_arrows,
    led_list_mouse_buttons,
    led_list_vol,
    led_list_mac};
uint8_t num_groups = 5;

bool rgb_matrix_indicators_user(void) {
    uint8_t layer, i, j;

    // color groups
    if ((layer = get_highest_layer(layer_state)) == L3) {
        for (i=0; i<MATRIX_ROWS; ++i) {
            for (j=0; j<MATRIX_COLS; ++j) {
                rgb_matrix_set_color(g_led_config.matrix_co[i][j], RGB_BLACK);
            }
        }
        for (i = 0; i < num_groups; i++) {
            for (j = 0; j < led_groups[i].num; j++) {

                rgb_matrix_set_color(led_groups[i].leds[j],
                                     led_groups[i].color.r,
                                     led_groups[i].color.g,
                                     led_groups[i].color.b);
            }
        }
    }
    return false;
}

