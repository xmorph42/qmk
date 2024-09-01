# VIA allows keyboard programming without reflashing
# PBU: But when using VIA the ADJUST layer does NOT work :(
VIA_ENABLE = no         # enabling VIA will use 2100 bytes

OLED_ENABLE = yes
ENCODER_ENABLE = yes
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes

# Allow to controle mouse with keyboard
MOUSEKEY_ENABLE = yes

# This can be used to define custom shift keys (e.g. to emulate programmers dvorak).
# This method also allows for which layout the shift key should be overwritten
KEY_OVERRIDE_ENABLE = no

# allow to assign different codes if a key is only tabbed once or twice
# Need ca 680 byte of firmware (without the needed mapping table)
TAP_DANCE_ENABLE = yes

# "Caps Words" feature (https://github.com/qmk/qmk_firmware/blob/master/docs/feature_caps_word.md)
CAPS_WORD_ENABLE = yes

LEADER_ENABLE = yes

#BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE =  yes      # Enable keyboard RGB underglow
