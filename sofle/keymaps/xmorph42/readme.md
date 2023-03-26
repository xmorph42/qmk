# Programmers Sofle Keyboard

[Sofle RGB Keyhive](https://keyhive.xyz/shop/sofle)


# Default keymap for Sofle Keyboard

Layout in [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/#/gists/76efb423a46cbbea75465cb468eef7ff) and [adjust layer](http://www.keyboard-layout-editor.com/#/gists/4bcf66f922cfd54da20ba04905d56bd4)


Features:

- with VIA: ADJUST layer is not working when VIA is enabled
- Symmetric modifiers (CMD/Super, Alt/Opt, Ctrl, Shift)
- Various modes, can be switched (using Adjust layer and the selected one is stored in EEPROM.
- Modes for Qwerty, Programmers Dvorak, Colemak vanilla, Colemak DH, Workman
- Exchange Tab with ESC for simpler VIM editing
- Modes for Mac vs Linux/Win support -> different order of modifiers and different action shortcuts on the "UPPER" layer (the red one in the image). Designed to simplify transtions when switching between operating systems often.
- The OLED on master half shows selected mode and caps lock state and is rotated.
- Left encoder controls volume up/down/mute. Right encoder PGUP/PGDOWN.

- Right-hand is primary OLED. My setup has the problem that the left half supplies insufficient power
to the right half via TRRS. This leads to the right side not being responsive at all (no OLED, no LED, no buttons).


## Compiling

Build example:

    make sofle/keyhive:xmorph42_via

## Flashing

Flash using the correct command below (or use QMK Toolbox). These commands can be mixed if, for 
example, you have an Elite C on the left and a pro micro on the right.

Press reset button on the keyboard when asked.

Disconnect the first half, connect the second one and repeat the process.

    # for Pro Micro-based builds
    make sofle/keyhive:xmorph42_via:avrdude-split-left
    make sofle/keyhive:xmorph42_via:avrdude-split-right

or 

    qmk flash -kb sofle/keyhive -km xmorph42_via -bl avrdude-split-left
    qmk flash -kb sofle/keyhive -km xmorph42_via -bl avrdude-split-right


