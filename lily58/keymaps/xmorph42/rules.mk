BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_ENABLE= yes     # OLED display

# -- xmorph42 -----------------------------------------------------------------------------
LTO_ENABLE = yes

# use 42keebs frood 
CONVERT_TO=promicro_rp2040

# Allows e.g. custom shift keys (programmers dvorak). 
# Need min 1376 bytes of firmware space
# This method also allows for which layout the shift key should be overwritten
KEY_OVERRIDE_ENABLE = yes 

# allow to assign different codes if a key is only tapped once or twice
# Need ca 680 byte of firmware (without the needed mapping table)
# 2023-03-07:PBU:hmmm .. I used TAP_DANCE on the sofles encoder buttons. So not needed for lily
TAP_DANCE_ENABLE = no

# If you want to change the display of OLED, you need to change here
#SRC +=  ./lib/rgb_state_reader.c \
#        ./lib/layer_state_reader.c \
#        ./lib/logo_reader.c \
#        ./lib/keylogger.c \
#        ./lib/mode_icon_reader.c \
#        ./lib/host_led_state_reader.c \
#        ./lib/timelogger.c \
