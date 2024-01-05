/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

/* Regarding https://precondition.github.io/home-row-mods#tapping-force-hold:
 * Prevent normal rollover on alphas from accidentally triggering mods.
 *
 * Since 2023-02-26 QMK replaced TAPPING_FORCE_HOLD with defining QUICK_TAP_TERM to 0
 *
 * If QUICK_TAP_TERM is set to 0, no key is generated when holding the "mod keys".
 * When using home-row mods this unfortunately mean, that the vim movements jkl will no longer 
 * work :(
 *
 * Not defining QUICK_TAP_TERM results that one need to tap the key twice to get them repeated.
 *
 * Otherwise setting it to 0 will force me to use vi movement alternatives
 */
//#define QUICK_TAP_TERM 0

// Configure the global tapping term (default: 200ms)
// 2023-03-07:PBU:TAPPING_TERM=100 is too short for homerow mods to work for me
#define TAPPING_TERM 170

// more granular control as I have problems with shift hold mod on ESC
#define TAPPING_TERM_PER_KEY

// "Caps Words" feature (https://github.com/qmk/qmk_firmware/blob/master/docs/feature_caps_word.md)
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// 2024-01-05 I have problems with LT(LOWER,ESC) and deflault mode (even with tapping-term 130)
// so I want to test this one: but currently only for this specific key
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#undef RGBLED_NUM
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

// Underglow
/*
#undef RGBLED_NUM
#define RGBLED_NUM 14    // Number of LEDs
#define RGBLIGHT_SLEEP
*/
