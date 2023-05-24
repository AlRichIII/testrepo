#ifndef CONFIG_H
#define CONFIG_H

/*
#define HD44780_DATA_PINS
#define HD44780_RS_PIN
#define HD44780_RW_PIN
#define HD44780_E_PIN 
#define HD44780_DISPLAY_COLS = 20
#define HD44780_DISPLAY_LINES = 4
#define HD44780_WRAP_LINES
*/


#define OLED_DISPLAY_128x64
//#define OLED_DISPLAY_ADDRESS 0x78
#define OLED_BRIGHTNESS 128


#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B6 }
#define ENCODER_RESOLUTION 4


/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { D4, C6 }
#define MATRIX_COL_PINS { D7, E6, B4, B5 }
//#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
//#define PREVENT_STUCK_MODIFIERS


#ifdef RGB_DI_PIN
//#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 0
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

#endif