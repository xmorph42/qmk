// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define GUI_a LGUI_T(KC_A)
#define ALT_r LALT_T(KC_R)
#define CTL_s LCTL_T(KC_S)
#define SFT_t LSFT_T(KC_T)

#define GUI_o RGUI_T(KC_O)
#define ALT_i LALT_T(KC_I)
#define CTL_e RCTL_T(KC_E)
#define SFT_n RSFT_T(KC_N)

#define KC_ALT_CTL LALT(KC_LCTL)

#define ESC_LOWER LT(_LOWER, KC_ESC)
#define SPC_SYM  LT(_SYM, KC_SPC)
#define BSPC_RAISE LT(_RAISE, KC_BSPC)

enum xmorph_layers {
   _COLEMAK_DH,
   _LOWER,
   _RAISE,
   _SYM,
   _FUN,
   _MEDIA,
   _ADJUST
};

enum custom_keycodes {
   KC_COLEMAK_DH = SAFE_RANGE,
   KC_PRVWD,
   KC_NXTWD,
   KC_LSTRT,
   KC_LEND,
   KC_DLINE,
};

enum { M_ESC } tap_dances;

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [M_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_ESC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT( /* COLEMAK MOD DH */
    KC_Q,  KC_W,  KC_F,  KC_P,      KC_B,                  KC_J,      KC_L,  KC_U,    KC_Y,   KC_SCLN,
    GUI_a, ALT_r, CTL_s, SFT_t,     KC_G,                  KC_M,      SFT_n, CTL_e,   ALT_i,  GUI_o,
    KC_Z,  KC_X,  KC_C,  KC_D,      KC_V,                  KC_K,      KC_H,  KC_COMM, KC_DOT, KC_SLSH,
                         ESC_LOWER, KC_ENT,                SPC_SYM,   BSPC_RAISE
  ),

  [_LOWER] = LAYOUT( /* [> Number layer <] */
    KC_F1  , KC_F2  , KC_F3  , KC_F4     , KC_F5   ,    KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_10,
    KC_1   , KC_2   , KC_3   , KC_4      , KC_F5   ,    KC_6   , KC_7   , KC_8   , KC_9   , KC_10,
    KC_EQL , KC_MINS, KC_PLUS, KC_LCBR   , KC_RCBR ,    KC_LBRC, KC_RBRC, _______, _______, KC_PIPE,
//                               MO(_MEDIA), MO(_FUN),    _______, _______
                               _______, MO(_FUN),    _______, _______
  ),

  [_RAISE] = LAYOUT( /* [> Navigation layer <] */
    KC_INS,  KC_PSCR, KC_APP , _______, _______ ,        KC_PAUS, KC_PRVWD, KC_PGUP, KC_NXTWD, KC_DLINE,
    KC_TAB,  KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN ,        KC_LEFT, KC_DOWN , KC_UP  , KC_RIGHT, KC_DEL  ,
    KC_UNDO, KC_CUT , KC_COPY, _______, KC_PASTE,        _______, KC_LSTRT, KC_PGDN, KC_LEND , _______ ,
                               _______,  _______ ,        _______, _______
  ),

  [_SYM] = LAYOUT( /* [> Symbol layer <] */
    KC_GRV,  KC_EXLM, KC_PERC, KC_DLR,  KC_AT,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_HASH, KC_QUOT, KC_ASTR, KC_MINS, KC_EQL,         KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_AMPR, KC_CIRC, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
                               KC_TRNS, KC_SPC,         KC_TRNS, KC_TRNS
  ),


  [_MEDIA] = LAYOUT( /* [> Media layer <] */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
  ),

  [_FUN] = LAYOUT( /* [> Function layer <] */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_ALT_CTL, KC_TRNS,        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS
  ),

  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______,    _______,        KC_WH_U, KC_BTN1, KC_BTN3, KC_BTN2, KC_WH_L,
    _______, _______, _______, _______,    _______,        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    _______, _______, _______, _______,    _______,        KC_WH_D, KC_MPRV, KC_MPLY, KC_MNXT, KC_WH_R,
                               _______,    _______,        _______, _______
  ),


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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

