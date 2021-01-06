/* Copyright 2015-2017 Jack Humbert
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
#include "song_list.h"
#include "muse.h"

enum sasha_layers
{
    _QWERTY,
    _LOWER,
    _RAISE,
    _BOTH,
};

enum sasha_keycodes
{
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    BOTH,
    BACKLIT,
    PARENS,
    NOCTURNE,
    SOVIET,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
/* 
 * Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Gui  | Brite| Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
    [_QWERTY] = LAYOUT_preonic_grid(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSHIFT,
        KC_LCTL, KC_LGUI, BACKLIT, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
        ),
/* 
 * Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |      |   _  |   +  |   [  |   ]  |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |   -  |   =  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Gui  | Brite| Alt  |Lower |    Space    |Raise | Home | PgDn | PgUp |  End |
 * `-----------------------------------------------------------------------------------'
 */
    [_LOWER] = LAYOUT_preonic_grid(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TAB,   _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_F12,
        KC_LCTL,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_ENTER,
        KC_LSHIFT, _______, _______, _______, _______, _______, _______, PARENS,  _______, _______, _______, KC_ENTER,
        KC_LCTL,  KC_LGUI, BACKLIT, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_HOME, KC_PGDN, KC_PGUP, KC_END
        ),

/* 
 * Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |      |      |      |      |      |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      | Left | Down |  Up  | Right|Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      | Br-  | Br+  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Gui  | Brite| Alt  |Lower |    Space    |Raise | Next | Vol- | Vol- | Play |
 * `-----------------------------------------------------------------------------------'
 */
    [_RAISE] = LAYOUT_preonic_grid(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
        KC_TAB,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_F12,
        KC_LCTL,  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ENTER,
        KC_LSHIFT, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU,  KC_ENTER,
        KC_LCTL,  KC_LGUI, BACKLIT, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_MNXT, KC_VOLD, KC_VOLU,  KC_MPLY
        ),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_BOTH] = LAYOUT_preonic_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
        _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, KC_DEL,
        _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______,
        _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  NOCTURNE, SOVIET,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
        ),
};

void update_led(void)
{
    bool enable = false;
    if((enable = IS_LAYER_ON(_BOTH)))
        rgblight_sethsv(0, 0, 255);
    else if((enable = IS_LAYER_ON(_RAISE)))
        rgblight_sethsv(15, 163, 214);
    else if((enable = IS_LAYER_ON(_LOWER)))
        rgblight_sethsv(205, 89, 148);
    else
        rgblight_disable();

    if(enable)
        rgblight_enable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch(keycode)
    {
    case QWERTY:
        if(record->event.pressed)
            set_single_persistent_default_layer(_QWERTY);
        return false;
    case LOWER:
        if(record->event.pressed)
        {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _BOTH);
        }
        else
        {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _BOTH);
        }
        update_led();
        return false;
    case RAISE:
        if(record->event.pressed)
        {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _BOTH);
        }
        else
        {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _BOTH);
        }
        update_led();
        return false;
    case PARENS:
        if(record->event.pressed)
            SEND_STRING("()" SS_TAP(X_LEFT));
        return true;
    case BACKLIT:
        if(record->event.pressed)
            register_code(KC_LGUI);
        else
            unregister_code(KC_LGUI);
        return false;
    case NOCTURNE:
    {
        float song[][2] = SONG(NOCTURNE_OP_9_NO_1);
        PLAY_SONG(song);
        return true;
    }
    case SOVIET:
    {
        float song[][2] = SONG(USSR_ANTHEM);
        PLAY_SONG(song);
        return true;
    }
    }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise)
{
    if(muse_mode)
    {
        if(IS_LAYER_ON(_RAISE))
        {
            if(clockwise)
                muse_offset++;
            else
                muse_offset--;
        }
        else
        {
            if(clockwise)
                muse_tempo++;
            else
                muse_tempo--;
        }
    }
    else if(clockwise)
    {
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
    }
    else
    {
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
    }
}

void dip_switch_update_user(uint8_t index, bool active)
{
    switch(index)
    {
    case 0:
        if(active)
            layer_on(_BOTH);
        else
            layer_off(_BOTH);
        break;
    case 1:
        if(active)
            muse_mode = true;
        else
            muse_mode = false;
        break;
    }
}

void matrix_scan_user(void)
{
#ifdef AUDIO_ENABLE
    if(muse_mode)
    {
        if(muse_counter == 0)
        {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if(muse_note != last_muse_note)
            {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
    else
    {
        if(muse_counter)
        {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) 
{
   switch (keycode)
   {
   case RAISE:
   case LOWER:
       return false;
   default:
       return true;
   }
}
