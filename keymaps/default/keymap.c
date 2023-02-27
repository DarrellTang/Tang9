/*
Copyright 2022 Joe Scotto

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
    SELECT_SPEAKERS = SAFE_RANGE,
    SELECT_HEADPHONES,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SELECT_SPEAKERS:
        if (record->event.pressed) {
            // when keycode SELECT_SPEAKERS is pressed
            SEND_STRING(
              SS_LCTL(
                SS_LSFT(
                  SS_LALT("s")
                )
              )
            );
        }
        break;
    case SELECT_HEADPHONES:
        if (record->event.pressed) {
            // when keycode SELECT_HEADPHONES is pressed
            SEND_STRING(
              SS_LCTL(
                SS_LSFT(
                  SS_LALT("h")
                )
              )
            );
        }
        break;
    }
    return true;
};

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x3(
        SELECT_SPEAKERS, SELECT_HEADPHONES, KC_MUTE, 
        KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_4,
        KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK
    )
};
