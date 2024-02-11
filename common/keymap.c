#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#ifdef RGB_MATRIX_ENABLE
   #define _RGB_TOG RGB_TOG
   #define _RGB_MOD RGB_MOD
#else
   #define _RGB_TOG XXXXXXX
   #define _RGB_MOD XXXXXXX
#endif

// ------------------------------------------------------------------------------------------------
// My config
// ------------------------------------------------------------------------------------------------

/* 2023-12-26: hmmmm
 * - sometimes the hold mod Shift on Esc doesn't fire  :(
 * - the both-shift to enable CAPS WORD wasn't sometimes firing
 * - it is ??? maybe the general tap_term (170) was too long - so I now try term_per_key to reduce
 */
 #define USE_SFT_ESC_MOD        // Hold ESC -> LSHIFT   (otherwise hold ESC -> LOCALE layer)

/* 2023-12-26: I don't have problem with rollover and home-row mods (at least not with GACS)
#define USE_ROLLED_MOD_CANCEL  // Rolled modifiersecancellation
*/

// ------------------------------------------------------------------------------------------------

enum xmorph_layers {
    _COLEMAK_DH,
    _LOWER,
    _RAISE,
    _ADJUST,
    _LOC,     // locale layer (umlauts)
};

enum custom_keycodes {
    KC_COLEMAK_DH = SAFE_RANGE,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
};

// ---------------------------------------------------------------------------------------------
// TAP DANCE - when a key has different meanings when pressed once or twice
// ---------------------------------------------------------------------------------------------
#ifdef SOFLE  // checking if this collides with home-row mods (set in config.h)
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

// key or rotator for left and right: rotator
#define KR_LFT KC_MUTE
#define KR_RGT KC_THME
// Sofle has 2 additinal keys compared to lily
#define SOFLE_L  KC_LGUI
#define SOFLE_R  KC_RGUI
#else
// key or rotator for left and right: key
#define KR_LFT KC_LGUI
#define KR_RGT KC_RGUI
// Sofle has 2 additinal keys compared to lily
#define SOFLE_L
#define SOFLE_R
#endif

// Left-hand colemak home row mods
#define C_GUI_A LGUI_T(KC_A)
#define C_ALT_R LALT_T(KC_R)
#define C_CTL_S LCTL_T(KC_S)
#define C_SFT_T LSFT_T(KC_T)

// Right-hand colemak home row mods
#define C_SFT_N RSFT_T(KC_N)
#define C_CTL_E RCTL_T(KC_E)
#define C_ALT_I LALT_T(KC_I)
#define C_GUI_O RGUI_T(KC_O)

// ---------------------------------------------------------------------------------------------
#define UML_AE RALT(KC_Q)
#define UML_OE RALT(KC_P)
#define UML_UE RALT(KC_Y)
#define GER_SZ RALT(KC_S)
#define EU_EUR RALT(KC_5)
// ---------------------------------------------------------------------------------------------


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ` ~ |  1 ! |  2 @ |  3 # |  4 $ |  5 % |                    |  6 ^ |  7 & |  8 * |  9 ( |  0 ) | - _  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |  ; : | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   R  |   S  |   T  |   G  |                    |   M  |   N  |   E  |   I  |   O  | ' "  |
 * |Locale|   GUI|   ALT|   CTL|   SFT|      |                    |      |   SFT|   CTL|   ALT|   GUI|Locale|
 * |LShift|   GUI|   ALT|   CTL|   SFT|      |-------.    ,-------|      |   SFT|   CTL|   ALT|   GUI|Locale|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |       |    |       |   K  |   H  |  , < |  . > |  / ? |RShift|
 * |Locale|   Z  |   X  |   C  |   D  |   V  |-------.    .-------|   K  |   H  |  , < |  . > |  / ? |RShift|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |Enter |
 * `-----------------------------------------/--------,  ,--------\-----------------------------------------'
 *              |SOFLL| LAlt | LCTR |LOWER | /Enter  /    \ Space \ | RAISE | RCTR | RAlt | SOFLR |
 *              |     |      |      |ESC   |/       /      \      \ |       |      |      |       |
 *              `----------------------------------'       '--------------------------------------'
 */
[_COLEMAK_DH] = LAYOUT(
  KC_GRV       , KC_1   , KC_2   , KC_3   , KC_4   , KC_5      ,                    KC_6      , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
  KC_TAB       , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B      ,                    KC_J      , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSPC,
#ifdef USE_SFT_ESC_MOD
LSFT_T(KC_ESC) , C_GUI_A, C_ALT_R, C_CTL_S, C_SFT_T, KC_G      ,                    KC_M      , C_SFT_N, C_CTL_E, C_ALT_I, C_GUI_O, RSFT_T(KC_QUOT),
  MO(_LOC)     , KC_Z   , KC_X   , KC_C   , KC_D   , KC_V      , _______,  _______, KC_K      , KC_H   , KC_COMM, KC_DOT , KC_SLSH, LT(_LOC, KC_ENT),
#else
LT(_LOC,KC_ESC), C_GUI_A, C_ALT_R, C_CTL_S, C_SFT_T, KC_G      ,                    KC_M      , C_SFT_N, C_CTL_E, C_ALT_I, C_GUI_O, LT(_LOC,KC_QUOT),
  KC_LSFT      , KC_Z   , KC_X   , KC_C   , KC_D   , KC_V      , _______,  _______, KC_K      , KC_H   , KC_COMM, KC_DOT , KC_SLSH, RSFT_T(KC_ENT),
#endif
#ifdef SOFLE
                           SOFLE_L, KC_LALT, KC_LCTL, MO(_LOWER), KC_ENT ,  KC_SPC , MO(_RAISE), KC_RCTL, KC_RALT, SOFLE_R
#else
                                    KC_LALT, KC_LCTL, LT(_LOWER, KC_ESC), KC_ENT ,  KC_SPC , MO(_RAISE), KC_RCTL, KC_RALT
#endif
),

/* lower
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ~   |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *              |SOFLL| LAlt | LCTR |LOWER | /Enter  /     \ Space \ | RAISE | RCTR | RAlt | SOFLR |
 *              |     |      |      |      |/       /       \      \ |       |      |      |       |
 *              `----------------------------------'        '--------------------------------------'
 */
[_LOWER] = LAYOUT(
  _______ , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 ,
  _______ , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12 ,
  KC_TILDE, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  KC_LSFT , KC_EQL , KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,    _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_RSFT,
#ifdef SOFLE
                    SOFLE_L, _______, _______, _______, _______,    _______, _______, _______, _______, SOFLE_R
#else
                             _______, _______, _______, _______,    _______, _______, _______, _______
#endif
),

/* RAISE
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |RGBtog| MPrv | Play | MNxt | Vol- | Vol+ |                    |      |      |      | PrtSc| SclL | Paus |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBmod| Ins  | Pscr | Menu |      |      |                    |      | PWrd |      | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |(Shft)| LGUI | LALT | LCTL |LSFT  | Caps |-------.    ,-------| Left | Down |  Up  | Right|  Del | PgUp |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | Home |      | End  |      | PgDn |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *              |SOFLL| LAlt | LCTR |LOWER | /Enter  /     \ Space \ | RAISE | RCTR | RAlt | SOFLR |
 *              |     |      |      |      |/       /       \      \ |       |      |      |       |
 *              `----------------------------------'        '--------------------------------------'
 */
[_RAISE] = LAYOUT(
  _RGB_TOG, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD , KC_VOLU,                     _______, _______ , _______, KC_PSCR,  KC_SCRL , KC_PAUS,
  _RGB_MOD, KC_INS , KC_PSCR, KC_APP , _______ , _______,                     _______, KC_PRVWD, _______, KC_NXTWD, KC_DLINE, KC_BSPC,
  _______ , KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT , KC_CAPS,                     KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT , KC_DEL  , KC_PGUP,
  _______ , KC_UNDO, KC_CUT , KC_COPY, KC_PASTE, _______, _______,   _______, _______, KC_LSTRT, _______, KC_LEND , _______ , KC_PGDN,
#ifdef SOFLE
                    SOFLE_L, _______, _______, _______, _______,    _______, _______, _______, _______, SOFLE_R
#else
                             _______, _______, _______, _______,    _______, _______, _______, _______
#endif
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | BOOT |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |MsBtnL|MsBtnM|MsBtnR|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|MsLeft| MsDn | MsUP |MsRght|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *              |SOFLL| LAlt | LCTR |LOWER | /Enter  /     \ Space \ | RAISE | RCTR | RAlt | SOFLR |
 *              |     |      |      |      |/       /       \      \ |       |      |      |       |
 *              `----------------------------------'        '--------------------------------------'
 */
[_ADJUST] = LAYOUT(
  QK_BOOT,   _______,   _______,    _______,       _______,    _______,                     _______, _______, _______, _______, _______, _______,
  _______,   _______,   _______,    _______,       _______,    _______,                     _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
  _______,   _______,   _______,    _______,       _______,    _______,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
  _______,   _______,   _______,    _______,       _______,    _______, _______,   _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
#ifdef SOFLE
                    SOFLE_L, _______, _______, _______, _______,    _______, _______, _______, _______, SOFLE_R
#else
                             _______, _______, _______, _______,    _______, _______, _______, _______
#endif
),

/* LOC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      | ü Ü  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | ä Ä  |      |  ß   |      |      |-------,    ,-------|      |      |  €   | RALT | ö Ö  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *              |SOFLL| LAlt | LCTR |LOWER | /Enter  /     \ Space \ | RAISE | RCTR | RAlt | SOFLR |
 *              |     |      |      |      |/       /       \      \ |       |      |      |       |
 *              `----------------------------------'        '--------------------------------------'
 */
[_LOC] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     _______, _______, UML_UE , _______, _______, _______,
  _______, UML_AE , _______, GER_SZ , _______, _______,                     _______, _______, EU_EUR , KC_RALT,   UML_OE , _______,
  _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
#ifdef SOFLE
                    SOFLE_L, _______, _______, _______, _______,    _______, _______, _______, _______, SOFLE_R
#else
                             _______, _______, _______, _______,    _______, _______, _______, _______
#endif
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
        case _COLEMAK_DH:
            oled_write_ln_P(PSTR("ClmkD"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_DH:
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
        case _LOC:
            oled_write_P(PSTR("Umlt\n"), false);
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


#ifdef  USE_ROLLED_MOD_CANCEL
// Rolled modifiers cancellation' colemak example:
// https://precondition.github.io/home-row-mods#rolled-modifiers-cancellation
bool rolled_modifiers_cancellation(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {

      // ------------------------------------------------------------------------------------------
      // Rolled modifiers cancellation' colemak example:
      // https://precondition.github.io/home-row-mods#rolled-modifiers-cancellation
      // This piece of code nullifies the effect of Right Shift when tapping the RCTL_T(KC_E) key.
      // This helps rolling over RSFT_T(KC_N) and RCTL_T(KC_E) to obtain the intended "ne" instead
      // of "E".
      // Consequently, capital E can only be obtained by tapping RCTL_T(KC_E) and holding
      // LSFT_T(KC_T) (left Shift mod tap).
      case RCTL_T(KC_E):
         if (record->event.pressed && record->tap.count > 0) {
            if (get_mods() & MOD_BIT(KC_RSFT)) { // Detect right Shift
               // temporarily disable right Shift so that we can send KC_E and KC_N without Shift on.
               unregister_mods(MOD_BIT(KC_RSFT));
               tap_code(KC_N);
               tap_code(KC_E);
               // restore the mod state
               add_mods(MOD_BIT(KC_RSFT));
               // to prevent QMK from processing RCTL_T(KC_E) as usual in our special case
               return false;
            }
         }
         return true;
      case RCTL_T(KC_S):
         if (record->event.pressed && record->tap.count > 0) {
            if (get_mods() & MOD_BIT(KC_LSFT)) { // Detect left Shift
               // temporarily disable right Shift so that we can send KC_E and KC_N without Shift on.
               unregister_mods(MOD_BIT(KC_LSFT));
               tap_code(KC_T);
               tap_code(KC_S);
               // restore the mod state
               add_mods(MOD_BIT(KC_LSFT));
               // to prevent QMK from processing RCTL_T(KC_E) as usual in our special case
               return false;
            }
         }
         return true;
   }
  return true;
}
#endif

/**
* 2024-01-04: Problems having LT(_LOWER,KC_ESC)
* a) the 170 tapping term is definitive too long to activate my LOWER layer.
*   I have symbols on that layer (i.e. '{' ) which didn't fire when I type fast.
*   So I will set it also to 130
* b) is better - but not good enough. teested with 100
* c) still not good - I remove it from here and try hold_on_other_key mode for this key
*
* 2023-12-??
* - I added tapping term per key as with having 170 on LSHFT_T(ESC) the shift sometimes didn't
*   fire. 130ms seams to work better
* - Additionally 130ms seems to be more working to get caps_words with LSHFT+RSHFT
*/
#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_QUOT):
            return 130;
        default:
            return TAPPING_TERM;
    }
}
#endif

/**
* 2024-01-04: Problems having LT(_LOWER,KC_ESC)
* a) setting tapping term to 130, 100 does not work
* b) trying to sed hold_on_other_keythe 170 tapping term is definitive too long to activate my LOWER layer.
*/
#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ESC):
        case LT(_LOWER,KC_ESC):
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
#endif


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

#ifdef  USE_ROLLED_MOD_CANCEL
      case RCTL_T(KC_E):
         return rolled_modifiers_cancellation(keycode, record);
      case RCTL_T(KC_S):
         return rolled_modifiers_cancellation(keycode, record);
#endif
      case KC_COLEMAK_DH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_DH);
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
