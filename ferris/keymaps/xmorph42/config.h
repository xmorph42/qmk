/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Pick good defaults for enabling homerow modifiers
#define TAPPING_TERM 170  //(150 too short?)

//PBU needed? #define TAPPING_FORCE_HOLD

// more granular control as I have problems with shift hold mod on ESC
#define TAPPING_TERM_PER_KEY

// "Caps Words" feature (https://github.com/qmk/qmk_firmware/blob/master/docs/feature_caps_word.md)
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// 2024-01-05 I have problems with LT(LOWER,ESC) and deflault mode (even with tapping-term 130)
// so I want to test this one: but currently only for this specific key
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Underglow configuration
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

