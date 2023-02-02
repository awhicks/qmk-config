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
    _RAISE,
    _UTIL,
    _MOUSE
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define UTIL   MO(_UTIL)
#define MOUSE  MO(_MOUSE)

// Shortcut to make keymap more readable
#define KC_C_ESC   LCTL_T(KC_ESC)
#define SC_LSBRO   LSFT_T(KC_LCBR)
#define SC_LSBRCO  LSFT_T(KC_LBRC)

// Tap Dance declarations
enum {
    G_Z,
    G_X,
    G_C,
    G_V,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_C_ESC, KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    SC_LSPO,  TD(G_Z),     TD(G_X),  TD(G_C),  TD(G_V),   KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
                                            KC_LGUI,   LOWER,    KC_SPC,   RAISE,    MOUSE
  ),

  [_LOWER] = LAYOUT(
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_PIPE,   KC_RCBR,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______, _______,
    SC_LSBRCO,KC_LCTL,  KC_LALT,  KC_ESC,   KC_CAPS,   KC_TILD,            KC_HOME,  KC_END,   _______,  _______,  _______,  _______,
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),

  [_RAISE] = LAYOUT(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_BSLS,   KC_RBRC,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
    SC_LSBRO, G(KC_Z),  G(KC_X),  G(KC_C),  G(KC_V),   KC_GRV,             KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),

  [_UTIL] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______, _______,   _______,
    _______,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______, _______,   _______,
    _______,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______, _______,   _______,
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),

  [_MOUSE] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,   _______,            KC_WH_U,  KC_BTN1,  KC_MS_U,  KC_BTN2, KC_WH_L,   _______,
    _______,  _______,  _______,  _______,  _______,   _______,            KC_WH_U,  KC_MS_L,  KC_MS_D,  KC_MS_R, KC_WH_R,   _______,
    _______,  _______,  _______,  _______,  _______,   _______,            KC_BTN3,  _______,  _______,  _______, _______,   _______,
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _UTIL);
}

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    qk_tap_dance_action_t *action;

    switch (keycode) {
        case TD(G_Z):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(G_X):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(G_C):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(G_V):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}

void tap_dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

qk_tap_dance_action_t tap_dance_actions[] = {
    [G_Z] = ACTION_TAP_DANCE_TAP_HOLD(KC_Z, G(KC_Z)),
    [G_X] = ACTION_TAP_DANCE_TAP_HOLD(KC_X, G(KC_X)),
    [G_C] = ACTION_TAP_DANCE_TAP_HOLD(KC_C, G(KC_C)),
    [G_V] = ACTION_TAP_DANCE_TAP_HOLD(KC_V, G(KC_V)),
};
