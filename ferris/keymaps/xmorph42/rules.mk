BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
BOOTLOADER = atmel-dfu
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control

# allow to assign different codes if a key is only tapped once or twice
# Need ca 680 byte of firmware (without the needed mapping table)
# 2024-02-18:PBU:start with double press m for ESC
TAP_DANCE_ENABLE = yes

# "Caps Words" feature (https://github.com/qmk/qmk_firmware/blob/master/docs/feature_caps_word.md)
CAPS_WORD_ENABLE = yes
