#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#define MASTER_RIGHT  // My left side provides unsufficient power :(

// Disabled to save space
#define NO_ACTION_ONESHOT  // 332
#define NO_ACTION_MACRO    // 0
#define NO_ACTION_FUNCTION // 0
#define DISABLE_LEADER     // 0     PBU; need to check This . has some similarities to vim

#define SOFLE

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

