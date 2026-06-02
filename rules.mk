# MCU type
MCU = atmega32u4

# Set the correct bootloader
BOOTLOADER = caterina

# Enable basic QMK features
NKRO_ENABLE = yes       # Enable N-Key Rollover
# BOOTMAGIC_ENABLE = yes  # Enable bootmagic for key combos
# MOUSEKEY_ENABLE = no    # Set to yes if using mouse keys
# EXTRAKEY_ENABLE = yes   # Needed for media keys (volume, etc.)
CONSOLE_ENABLE = no     # Set to yes for debugging via console
COMMAND_ENABLE = no     # Enable "magic" command keycodes
SLEEP_LED_ENABLE = no   # If you use LED breathing
LTO_ENABLE = yes        # Smaller firmware binary
OLED_ENABLE = yes       # it's 128 x 32


# Split-specific
SPLIT_KEYBOARD = yes
MASTER_LEFT = yes
# EE_HANDS = yes          # Or use MASTER_LEFT or MASTER_RIGHT

# # Optional features
# TAP_DANCE_ENABLE = yes  # Tap dance keys
COMBO_ENABLE = no

