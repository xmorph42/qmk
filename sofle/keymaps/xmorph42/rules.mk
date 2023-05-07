# VIA
#
# VIA allows tp programm the keyboard without the need to reflash it
#
# 2023-01-14 PBU: I observed that with VIA enabled the ADJUST layer is TOTALLY not working! \
#                 With VIA disabled it works
VIA_ENABLE = no            # enabling VIA will use 2100 bytes

OLED_ENABLE = yes
OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes

# Allow to controle mouse with keyboard
MOUSEKEY_ENABLE = yes

# Allows e.g. custom shift keys (programmers dvorak). 
# Need min 1376 bytes of firmware space
# This method also allows for which layout the shift key should be overwritten
KEY_OVERRIDE_ENABLE = yes 

# allow to assign different codes if a key is only tabbed once or twice
# Need ca 680 byte of firmware (without the needed mapping table)
TAP_DANCE_ENABLE = yes 

BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE =  no      # Enable keyboard RGB underglow
