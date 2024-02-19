# History


## 2024-02-18 - REMOVED BSPC an RAISE

* BSPC when tapping RAISE is really bad !!!!
  - the BSPC setting intefers with my RAISE-`vim move-keys`
    when I (accidentally) press BSPC twice and then RAISE-mnei no movement works but strange jumps

## 2024-02-18 - add ESC on LOWER, BSPC an RAISE

* to get my ferris/sweep layout in sync with lily and ergo I set
  - ESC when tapping LOWER `LT(_LOWER, KC_ESC)`
  - BACKSPACE when tapping RAISE `LT(_RAISE, KC_BSPC)`

## 2024-02-18

* to get my ferris/sweep layout in sync with lily and ergo I set
  - ESC when tapping LOWER `LT(_LOWER, KC_ESC)`
  - BACKSPACE when tapping RAISE `LT(_RAISE, KC_BSPC)`

## 2024-01-05 01:09

* us now HOLD_ON_OTHER_KEY_PRESS_PER_KEY for LT(LOWER,ESC) and LSHFT_T(ESC) - seems to work good
  - Therefore removed the tapping term stuff for LT(LOWER,ESC) again which was not working for me

## 2024-01-04

* Set tapping term 130 to LT(_LOWER,KC_ESC)
* - Ugh bad expierience. The 170 tapping term is definitive too long to activate the LOWER layer.
*   I have symbols on that layer (i.e. '{' ) which didn't fire when I type fast.
*   So I will set it also to 130

## 2024-01-02

* added ESC as tap to 'LOWER' key using LT(LOWER,KC_ESC)


