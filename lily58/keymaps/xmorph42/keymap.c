#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#ifdef RGB_MATRIX_ENABLE
#define _RGB_TOG RGB_TOG
#define _RGB_MOD RGB_MOD
//#define COLEMAK_ENABLE
//#define WORKMAN_ENABLE
#define BASE_LAYERS 4    // the first n layers are base layers
#else
#define _RGB_TOG XXXXXXX
#define _RGB_MOD XXXXXXX
#define COLEMAK_ENABLE
#define WORKMAN_ENABLE
#define BASE_LAYERS 6   // the first n layers are base layers
#endif

enum xmorph_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _DVORAK,
#ifdef COLEMAK_ENABLE
    _COLEMAK,
#endif
    _COLEMAK_DH,
#ifdef WORKMAN_ENABLE
    _WORKMAN,
#endif
    _MIRYOKU,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_DVORAK,
    KC_COLEMAK,
    KC_COLEMAK_DH,
#ifdef WORKMAN_ENABLE
    KC_WORKMAN,
#endif
    KC_MIRYOKU,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_CYCLE,       // Cycle layouts
};

// ---------------------------------------------------------------------------------------------
// TAP DANCE - when a key has different meanings when pressed once or twice
// ---------------------------------------------------------------------------------------------
#if 0  // checking if this collides with home-row mods
enum custom_tapdance {
    TD_PLAY,   // handled to control audio play keys
    TD_HOME,
};

tap_dance_action_t tap_dance_actions[] = {
    // ENUM                             SINGLE,  DOUBLE
    [TD_PLAY] = ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_MNXT),  // mute, next-track
    [TD_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),   // Pos1, Ebd
};

//define convenient aliases to simplify usage in key layouts
#define KC_TPLY TD(TD_PLAY)
#define KC_THME TD(TD_HOME)
#endif

// ---------------------------------------------------------------------------------------------
// ------ define dvorak shift keys -------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
// !!! TO WORK YOU NEED TO ADD THE FOLLOWING TO rules.mk
//     KEY_OVERRIDE_ENABLE = yes  # Allows e.g. custom shift keys (programmers dvorak).
//
#include "process_key_override.h"

const key_override_t dvp_shift_keys[] = {
   ko_make_with_layers(MOD_MASK_SHIFT, KC_DLR,  KC_TILD, 0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_HASH, KC_PERC, 0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_LBRC, KC_7,    0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_LCBR, KC_5,    0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_3,    0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_AMPR, KC_1,    0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_EQL,  KC_9,    0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_RPRN, KC_0,    0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_RCBR, KC_2,    0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_RBRC, KC_4,    0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_ASTR, KC_6,    0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_EXLM, KC_8,    0x02),
   // 2nd line
   ko_make_with_layers(MOD_MASK_SHIFT, KC_SCLN, KC_COLN, 0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_LT,   0x02),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT,  KC_GT,   0x02),
   // 3rd line
   ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_UNDS, 0x02),
   // 4th line
   ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, KC_DQT,  0x02),
   // Dvorak Shift of RAISE layer
   ko_make_with_layers(MOD_MASK_SHIFT, KC_HASH, KC_GRV,   0x04),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_QUES,  0x04),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_AT,   KC_CIRC,  0x04),
   ko_make_with_layers(MOD_MASK_SHIFT, KC_BSLS, KC_PIPE,  0x04),
};

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &dvp_shift_keys[0],
    &dvp_shift_keys[1],
    &dvp_shift_keys[2],
    &dvp_shift_keys[3],
    &dvp_shift_keys[4],
    &dvp_shift_keys[5],
    &dvp_shift_keys[6],
    &dvp_shift_keys[7],
    &dvp_shift_keys[8],
    &dvp_shift_keys[9],
    &dvp_shift_keys[10],
    &dvp_shift_keys[11],
    &dvp_shift_keys[12],
    &dvp_shift_keys[13],
    &dvp_shift_keys[14],
    &dvp_shift_keys[15],
    &dvp_shift_keys[16],
    &dvp_shift_keys[17],
    &dvp_shift_keys[18],
    &dvp_shift_keys[19],
    &dvp_shift_keys[20],
    NULL // Null terminate the array of overrides!
};

// ---------------------------------------------------------------------------------------------

#if 0
enum Q_GASC {
   GUI_A = LGUI_T(KC_A),
   ALT_S = LALT_T(KC_S),
   SFT_D = LSFT_T(KC_D),
   CTL_F = LCTL_T(KC_F),
   CTL_J = RCTL_T(KC_J),
   SFT_K = RSFT_T(KC_K),
   ALT_L = LALT_T(KC_L),
   GUI_SCLN = RGUI_T(KC_SCLN)
};
#else
enum Q_GACS{
   GUI_A = LGUI_T(KC_A),
   ALT_S = LALT_T(KC_S),
   CTL_D = LCTL_T(KC_D),
   SFT_F = LSFT_T(KC_F),
   SFT_J = RSFT_T(KC_J),
   CTL_K = RCTL_T(KC_K),
   ALT_L = LALT_T(KC_L),
   GUI_SCLN = RGUI_T(KC_SCLN)
};
#endif

#if 0
// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)
#endif


// Left-hand colemak home row mods
#define C_GUI_A LGUI_T(KC_A)
#define C_ALT_R LALT_T(KC_R)
#define C_SFT_S LSFT_T(KC_S)
#define C_CTL_T LCTL_T(KC_T)

// Right-hand colemak home row mods
#define C_CTL_N RCTL_T(KC_N)
#define C_SFT_E RSFT_T(KC_E)
#define C_ALT_I LALT_T(KC_I)
#define C_GUI_O RGUI_T(KC_O)

// Left-hand original miryoku home row mods
#define M_GUI_A LGUI_T(KC_A)
#define M_ALT_R LALT_T(KC_R)
#define M_CTL_S LCTL_T(KC_S)
#define M_SFT_T LSFT_T(KC_T)

// Right-hand original miryoku home row mods
#define M_SFT_N RSFT_T(KC_N)
#define M_CTL_E RCTL_T(KC_E)
#define M_ALT_I RALT_T(KC_I)
#define M_GUI_O RGUI_T(KC_O)

// ---------------------------------------------------------------------------------------------


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | - _  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |      |   GUI|   ALT|   SFT|   CTL|      |       |    |       |      |   CTL|   SFT|   ALT|   GUI|      |   
 * |------+------+------+------+------+------|  LGUI |    | RGUI  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `---------------------------'           '------''---------------------'
 */
[_QWERTY] = LAYOUT(
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5,                           KC_6      , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T,                           KC_Y      , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
  KC_ESC , GUI_A  , ALT_S  , CTL_D  , SFT_F  , KC_G,                           KC_H      , SFT_J  , CTL_K  , ALT_L  , GUI_SCLN, KC_QUOT,
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B,       KC_LGUI,   KC_RGUI, KC_N      , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                             KC_LALT, KC_LCTL, MO(_LOWER), KC_ENT ,   KC_SPC , MO(_RAISE), KC_RCTL, KC_RALT
),

/*
 * DVORAK
 * ,-----------------------------------------.                     ,----------------------------------------.
 * | $ ~  |  # % |  [ 7 | { 5  | } 3  |  ( 1 |                    |  = 9 |  * 0 |  ) 2 |  + 4 |  ] 6 |  ! 8 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  ; : |  , < |  . > |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  - _ |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|  ' " |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_DVORAK] = LAYOUT(
  KC_DLR , KC_HASH, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,                        KC_EQL    , KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM,
  KC_TAB , KC_SCLN, KC_COMM, KC_DOT , KC_P   , KC_Y,                           KC_F      , KC_G   , KC_C   , KC_R   , KC_L   , KC_BSPC,
  KC_ESC , KC_A   , KC_O   , KC_E   , KC_U   , KC_I,                           KC_D      , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS,
  KC_LSFT, KC_QUOT, KC_Q   , KC_J   , KC_K   , KC_X,       KC_LGUI,   KC_RGUI, KC_B      , KC_M   , KC_W   , KC_V   , KC_Z   , KC_RSFT,
                             KC_LALT, KC_LCTL, MO(_LOWER), KC_ENT ,   KC_SPC , MO(_RAISE), KC_RCTL, KC_RALT
),

/*
 * COLEMAK-VANILLA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ` ~ |  1 ! |  2 @ |  3 # |  4 $ |  5 % |                    |  6 ^ |  7 & |  8 * |  9 ( |  0 ) | ` ~  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |  ; : | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  | ' "  |
 * |      |   GUI|   ALT|   SFT|   CTL|      |       |    |       |      |   CTL|   SFT|   ALT|   GUI|      |   
 * |------+------+------+------+------+------|  LGUI |    | RGUI  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |  , < |  . > |  / ? |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `---------------------------'           '------''---------------------'
 */
#ifdef COLEMAK_ENABLE
[_COLEMAK] = LAYOUT(
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5      ,                     KC_6,       KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
  KC_TAB,  KC_Q   , KC_W   , KC_F   , KC_P   , KC_G      ,                     KC_J,       KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSPC,
  KC_ESC , C_GUI_A, C_ALT_R, C_SFT_S, C_CTL_T, KC_D      ,                     KC_H,       C_CTL_N, C_SFT_E, C_ALT_I, C_GUI_O, KC_QUOT,
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B      , KC_LGUI,   KC_RGUI, KC_K,       KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                             KC_LALT, KC_LCTL, MO(_LOWER), KC_ENT,    KC_SPC,  MO(_RAISE), KC_RCTL, KC_RALT
),
#endif

/*
 * COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ` ~ |  1 ! |  2 @ |  3 # |  4 $ |  5 % |                    |  6 ^ |  7 & |  8 * |  9 ( |  0 ) | ` ~  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |  ; : | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  | ' "  |
 * |      |   GUI|   ALT|   SFT|   CTL|      |       |    |       |      |   CTL|   SFT|   ALT|   GUI|      |   
 * |------+------+------+------+------+------|  LGUI |    | RGUI  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |  , < |  . > |  / ? |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `---------------------------'           '------''---------------------'
 */
[_COLEMAK_DH] = LAYOUT(
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5      ,                     KC_6,       KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
  KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B      ,                     KC_J,       KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSPC,
  KC_ESC , C_GUI_A, C_ALT_R, C_SFT_S, C_CTL_T, KC_G      ,                     KC_M,       C_CTL_N, C_SFT_E, C_ALT_I, C_GUI_O, KC_QUOT,
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V      , KC_LGUI,   KC_RGUI, KC_K,       KC_H   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                             KC_LALT, KC_LCTL, MO(_LOWER), KC_ENT,    KC_SPC,  MO(_RAISE), KC_RCTL, KC_RALT
),
/*
 * WORKMAN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Prnt |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |                    |   J  |   F  |   U  |   P  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   H  |   T  |   G  |-------.    ,-------|   Y  |   N  |   E  |   O  |   I  |  '   |
 * |------+------+------+------+------+------|       |    | MUTE  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   M  |   C  |   V  |-------|    |-------|   K  |   L  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `---------------------------'           '------''---------------------`
 */
#ifdef WORKMAN_ENABLE
[_WORKMAN] = LAYOUT(
  KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,     KC_7,     KC_8,    KC_9,   KC_0,    KC_PSCR,
  KC_TAB,  KC_Q,   KC_D,    KC_R,    KC_W,    KC_B,                            KC_J,     KC_F,     KC_U,    KC_P,   KC_SCLN, KC_BSPC,
  KC_ESC,  KC_A,   KC_S,    KC_H,    KC_T,    KC_G,                            KC_Y,     KC_N,     KC_E,    KC_O,   KC_I,    KC_QUOT,
  KC_LSFT, KC_Z,   KC_X,    KC_M,    KC_C,    KC_V,     KC_LGUI,      KC_RGUI, KC_K,     KC_L,     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                            KC_LALT, KC_LCTL, MO(_LOWER), KC_ENT,       KC_SPC, MO(_RAISE), KC_RCTL, KC_RALT
),
#endif

/*
 * My modified Miryoku
 * Miryoku (https://github.com/manna-harbour/miryoku/) is an ergonomic, minimal, orthogonal,
 * and universal keyboard layout.
 *
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |  ' " |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |      |
 * |      |   GUI|   ALT|   CTL|   SFT|      |       |    |       |      |   SFT|   CTL|   ALT|   GUI|      |   
 * |------+------+------+------+------+------| LGUI  |    | RGUI  |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |  , < |  . > |  / ? |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `---------------------------'           '------''---------------------'
 */
[_MIRYOKU] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   ,                     XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B      ,                     KC_J,       KC_L   , KC_U   , KC_Y   , KC_SCLN, XXXXXXX,
  KC_ESC,  M_GUI_A, M_ALT_R, M_CTL_S, M_SFT_T, KC_G      ,                     KC_M,       M_SFT_N, M_CTL_E, M_ALT_I, M_GUI_O, XXXXXXX,
  XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V      , KC_LGUI,   KC_RGUI, KC_K,       KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
                             KC_LALT, KC_LCTL, MO(_LOWER), KC_SPC,    KC_ENT,  MO(_RAISE), KC_RCTL, KC_RALT
),

/* lower
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  LGUI |    | RGUI  |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   ``----------------------------------'           '------''---------------------'
 */
[_LOWER] = LAYOUT(
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 ,
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12 ,
  _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, KC_EQL , KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,    _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                             _______, _______, _______, _______,    _______, _______, _______, _______
),

/* RAISE
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |Cycle | MPrv | Play | MNxt | Vol- | Vol+ |                    |      |      |      | PrtSc| SclL | Paus |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      |      |                    |      | PWrd |      | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LAt  | LCtl |LShift|      | Caps |-------.    ,-------| Left | Down |  Up  | Right|  Del | PgUp |
 * |------+------+------+------+------+------|  LGUI |    | RGUI  |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | Home |      | End |      | PgDn |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `---------------------------'           '------''---------------------'
 */
[_RAISE] = LAYOUT(
  KC_CYCLE, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD , KC_VOLU,                     _______, _______ , _______, KC_PSCR,  KC_SCRL , KC_PAUS,
  _RGB_TOG, KC_INS , KC_PSCR, KC_APP , XXXXXXX , XXXXXXX,                     XXXXXXX, KC_PRVWD, XXXXXXX, KC_NXTWD, KC_DLINE, KC_BSPC,
  _RGB_MOD, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX , KC_CAPS,                     KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT , KC_DEL  , KC_PGUP,
  _______ , KC_UNDO, KC_CUT , KC_COPY, KC_PASTE, XXXXXXX, _______,   _______, XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND , _______ , KC_PGDN,
                              _______, _______ , _______, _______,   _______, _______, _______ , _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QWERTY|DVORAK|COLEMK|CLMKDH|MIRYOK|      |                    |      |MsBtn1|      |MsBtn2|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BOOT |      |      |      |      |      |-------.    ,-------|MsLeft| MsDn | MsUP |MsRght|      |      |
 * |------+------+------+------+------+------|  LGUI |    | RGUI  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `---------------------------'           '------''---------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_QWERTY, KC_DVORAK, KC_COLEMAK, KC_COLEMAK_DH, XXXXXXX,    XXXXXXX,                     XXXXXXX, KC_BTN1, XXXXXXX, KC_BTN2, XXXXXXX, XXXXXXX,
  QK_BOOT,   XXXXXXX,   XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                                    _______,       _______,    _______, _______,   _______, _______, _______, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

// Archspire Logo in 128x32 pixel. Convert to plain-bytes array (vertical, 1 bit) via image2cpp
// (https://javl.github.io/image2cpp/)
static void render_logo(void) {
   static const char PROGMEM raw_logo[] = {
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x20, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xbc, 0x1e, 0x1f, 0xff, 0xff, 0xff, 0x0d, 0xe0, 0x80,
      0x80, 0xe0, 0x78, 0x38, 0xfc, 0xfc, 0x0e, 0x02, 0x00, 0xf8, 0x8c, 0x80, 0x00, 0x80, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x80, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x80, 0x20, 0xc0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x80, 0x00, 0x80, 0x8c, 0xf8, 0xf0, 0xe0, 0x0e, 0xfc, 0xfc, 0x38, 0x78, 0xe0, 0x80,
      0x80, 0xc0, 0x0d, 0xff, 0xff, 0xff, 0x1f, 0x1e, 0xbc, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xa0,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x00, 0x00, 0x40, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x07, 0x3f, 0x03,
      0x00, 0xff, 0xff, 0xff, 0xff, 0x03, 0x03, 0x03, 0x01, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
      0xff, 0x0e, 0x06, 0x07, 0xff, 0xfd, 0x01, 0xf0, 0xf0, 0xf5, 0xfd, 0x3b, 0x0f, 0x3f, 0x1f, 0x3f,
      0x3f, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x1f, 0x5f, 0xc7, 0xf7, 0xfc, 0x7f, 0x0f, 0xb0, 0xb8, 0xb8,
      0xb8, 0xb8, 0xb0, 0x8f, 0x7f, 0xfc, 0xf7, 0xc7, 0x5f, 0x1f, 0x3f, 0x3f, 0xff, 0xf7, 0xef, 0x5f,
      0x3f, 0x3f, 0xff, 0xff, 0x3b, 0x3d, 0x3d, 0x73, 0x20, 0x00, 0xff, 0xff, 0x07, 0x06, 0x0e, 0xfe,
      0xff, 0xf3, 0x00, 0xff, 0xff, 0xff, 0x00, 0x01, 0x03, 0x03, 0x03, 0x83, 0x83, 0xe3, 0xf3, 0x03,
      0x03, 0x3f, 0x07, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x04, 0x08, 0x08, 0x18, 0x30, 0x30, 0x20, 0x68, 0x68, 0xe8,
      0xec, 0xef, 0xef, 0xff, 0xff, 0xf0, 0xc6, 0x88, 0x98, 0x98, 0x3f, 0x3f, 0x7f, 0xe0, 0x03, 0x07,
      0x0f, 0x7e, 0x00, 0x20, 0xff, 0xff, 0x00, 0x7f, 0x7f, 0x3f, 0xff, 0xe0, 0xc0, 0x80, 0x00, 0x00,
      0x00, 0x3f, 0xff, 0xff, 0x30, 0x30, 0x70, 0x60, 0xe0, 0xff, 0xff, 0x00, 0xe0, 0x03, 0x07, 0x0e,
      0x0e, 0x9c, 0xf8, 0xf1, 0x00, 0xff, 0xff, 0xc0, 0xc0, 0xe0, 0xe0, 0x70, 0x3f, 0x3f, 0x3f, 0x00,
      0x00, 0x00, 0xff, 0xff, 0xf0, 0xf8, 0x38, 0x70, 0x60, 0x00, 0xff, 0xff, 0x20, 0x00, 0x7c, 0x0f,
      0x07, 0x03, 0x00, 0xff, 0xff, 0xff, 0x80, 0x80, 0x80, 0xc0, 0xf0, 0xff, 0xff, 0xef, 0xef, 0xec,
      0xe8, 0x68, 0x68, 0x20, 0x30, 0x30, 0x18, 0x18, 0x08, 0x04, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x07, 0x07, 0x06, 0x0c, 0x18, 0x30, 0xc0,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x02, 0x02, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03,
      0x07, 0x06, 0x06, 0x06, 0x07, 0x07, 0x4e, 0xc0, 0xe0, 0xff, 0xff, 0x00, 0x00, 0x03, 0x0e, 0x3e,
      0x3e, 0x1f, 0x07, 0x01, 0x00, 0xff, 0xff, 0xe1, 0xc0, 0x4e, 0x0e, 0x06, 0x06, 0x06, 0x06, 0x07,
      0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x06, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x80, 0x20, 0x38, 0x0f, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   };
   oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt\n"), false);
            break;
        case _DVORAK:
            oled_write_ln_P(PSTR("Dvrk\n"), false);
            break;
#ifdef COLEMAK_ENABLE
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk\n"), false);
            break;
#endif
        case _COLEMAK_DH:
            oled_write_ln_P(PSTR("ClmkD"), false);
            break;
#ifdef WORKMAN_ENABLE
        case _WORKMAN:
            oled_write_ln_P(PSTR("Wrkmn"), false);
            break;
#endif
        case _MIRYOKU:
            oled_write_ln_P(PSTR("Mryok"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _DVORAK:
#ifdef COLEMAK_ENABLE
        case _COLEMAK:
#endif
        case _COLEMAK_DH:
#ifdef WORKMAN_ENABLE
        case _WORKMAN:
#endif
        case _MIRYOKU:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
#ifdef PBU_KEYLOG
        uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
             keycode,
             record->event.key.row,
             record->event.key.col,
             get_highest_layer(layer_state),
             record->event.pressed,
             get_mods(),
             get_oneshot_mods(),
             record->tap.count
             );
#endif
#endif
    switch (keycode) {
      case RCTL_T(KC_J):
        /*
         * PBU: Example adapted https://precondition.github.io/home-row-mods#rolled-modifiers-cancellation
         * This piece of code nullifies the effect of Right Shift when tapping
         * the RCTL_T(KC_J) key.
         * This helps rolling over RSFT_T(KC_K) and RCTL_T(KC_J) to obtain the intended "en" instead of "N".
         * Consequently, capital N can only be obtained by tapping RCTL_T(KC_N)
         * and holding LSFT_T(KC_S) (which is the left Shift mod tap).
         */
         /*
        Detect the tap.
        We're only interested in overriding the tap behaviour
        in a certain cicumstance. The hold behaviour can stay the same.
        */
         if (record->event.pressed && record->tap.count > 0) {
            // Detect right Shift
            if (get_mods() & MOD_BIT(KC_RSFT)) {
               // temporarily disable right Shift
               // so that we can send KC_E and KC_N
               // without Shift on.
               unregister_mods(MOD_BIT(KC_RSFT));
               tap_code(KC_K);
               tap_code(KC_J);
               // restore the mod state
               add_mods(MOD_BIT(KC_RSFT));
               // to prevent QMK from processing RCTL_T(KC_N) as usual in our special case
               return false;
            }
         }
         return true;
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
#ifdef COLEMAK_ENABLE
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
#endif
        case KC_COLEMAK_DH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_DH);
            }
            return false;
#ifdef WORKMAN_ENABLE
        case KC_WORKMAN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WORKMAN);
            }
            return false;
#endif
        case KC_MIRYOKU:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MIRYOKU);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_LEFT);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_LEFT);
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_RIGHT);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_RIGHT);
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                register_code(KC_HOME);
            } else {
                unregister_code(KC_HOME);
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                register_code(KC_END);
            } else {
                unregister_code(KC_END);
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case KC_CYCLE:
            if (record->event.pressed) {
               set_single_persistent_default_layer((1+get_highest_layer(default_layer_state)) % BASE_LAYERS);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif // ENCODER_ENABLE
