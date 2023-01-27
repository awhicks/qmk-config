/* Copyright 2020 gtips
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
#include "g/keymap_combo.h"

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

// Shortcut to make keymap more readable
#define KC_C_ESC   LCTL_T(KC_ESC)
#define SC_LSBRO   LSFT_T(KC_LCBR)
#define SC_LSBRCO  LSFT_T(KC_LBRC)

// Tap Dance declarations
// enum {
    // TD_ESC_CAPS,
// };

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    // [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

// Add tap dance item to your keymap in place of a keycode
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     // ...
//     TD(TD_ESC_CAPS)
//     // ...
// };


// tap dance declarations
// enum {
//     _TD_TAB_ESC = 0,
//     _TD_BSPC_WDEL,
//     _TD_SFT_CAPS,
//     _TD_SPC_ENT,
//     _TD_N_NTILDE,
//     _TD_CTRL_LANG,
// };

// #define TD_TAB_ESC TD(_TD_TAB_ESC)
// #define TD_BSPC_WDEL TD(_TD_BSPC_WDEL)
// #define TD_SFT_CAPS TD(_TD_SFT_CAPS)
// #define TD_SPC_ENT TD(_TD_SPC_ENT)
// #define TD_N_NTILDE TD(_TD_N_NTILDE)
// #define TD_CTRL_LANG TD(_TD_CTRL_LANG)

// Add tap dance item to your keymap in place of a keycode
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // ...
    // TD(TD_ESC_CAPS)
    // ...
// };

// void dance_egg(qk_tap_dance_state_t *state, void *user_data) {
//     if (state->count >= 100) {
//         SEND_STRING("Safety dance!");
//         reset_tap_dance(state);
//     }
// }

// qk_tap_dance_action_t tap_dance_actions[] = {
//     [CT_EGG] = ACTION_TAP_DANCE_FN(dance_egg),
// };

// Tap Dance Definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     [_TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
//     [_TD_BSPC_WDEL] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, LALT(KC_BSPC)),
//     [_TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
//     [_TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
//     [_TD_CTRL_LANG] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LCTL(LSFT(KC_SPACE))),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_C_ESC, KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    SC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
                                            KC_LGUI,   LOWER,    KC_SPC,   RAISE,    KC_LGUI
  ),

  [_LOWER] = LAYOUT(
    _______,  KC_EXLM,  KC_AT,    KC_HASH, KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_UNDS,  KC_PLUS,  KC_LCBR, KC_PIPE,   KC_RCBR,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______, _______,
    SC_LSBRCO,KC_LCTL,  KC_LALT,  KC_ESC,  KC_CAPS,   KC_TILD,            KC_HOME,  KC_END,   _______,  _______,  _______,  _______,
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),

  [_RAISE] = LAYOUT(
    _______,  KC_1,     KC_2,     KC_3,    KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC, KC_BSLS,   KC_RBRC,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
    SC_LSBRO, G(KC_Z),  G(KC_X),  G(KC_C), G(KC_V),   KC_GRV,             KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),

};
