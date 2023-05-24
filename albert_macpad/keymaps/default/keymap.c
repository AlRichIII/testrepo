#include "albert_macpad.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      /* This is where the actual magic happens: this bit of code taps on the
         Page Down key. You can do anything QMK allows you to do here.
         You'll want to replace these lines with the things you want your
         encoders to do. */
      tap_code(KC_VOLD);
    } else {
      /* And likewise for the other direction, this time Page Down is pressed. */
      tap_code(KC_VOLU);
    }
	return false;
}

//enum layer_names {
//  LAYER_INCREMENT
//};
//int LAYER_LEVEL = 0;

enum {
	
	M_HELLO,
	M_FOSHO,
	M_LETS_GO,
	M_BOO,
	M_PASSWORD,
	M_YEA,
	M_WHATEVER,
	M_KEYS,
	M_GAMES,
	
	D_CNTLP,
	D_DISCORD,
	D_NOTEPAD,
	D_COMANDLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
					KC_1, KC_2, KC_3, KC_4,
					KC_5, KC_6, KC_7, TO(1)
					),
	KEYMAP(
					M_HELLO, M_FOSHO, M_LETS_GO, M_BOO,
					M_PASSWORD, M_YEA, KC_ENT, TO(2)
					),
	KEYMAP(
					KC_CALC, D_NOTEPAD, KC_VOLU, KC_VOLD, 
					KC_PGUP, D_COMANDLINE, D_DISCORD, TO(0) 
					)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed){
		switch (keycode) {
			case M_HELLO:
				//if (record->event.pressed) {
				SEND_STRING("Hello!");
				//}
				return false; break;
			case M_FOSHO:
				SEND_STRING("Fo Sho!!");
				return false; break;
			case M_LETS_GO:
				SEND_STRING("Let's go");
				return false; break;
			case M_BOO:
				SEND_STRING("Boo!");
				return false; break;
			case M_PASSWORD:
				SEND_STRING("Password");
				return false; break;
			case M_YEA:
				SEND_STRING("Yea!!!");
				return false; break;
			case M_KEYS:
				SEND_STRING("*%&$#@&");
				return false; break;
			case M_GAMES:
				SEND_STRING("Super Smash Bros");
				return false; break;
				//////////////////////////////////
			case D_CNTLP:
				SEND_STRING(SS_DOWN(X_LEFT_GUI)SS_TAP(X_R)SS_UP(X_LEFT_GUI)SS_DELAY(150)"control"SS_DELAY(500)SS_TAP(X_ENT));
				return false; break;
			case D_DISCORD:
				SEND_STRING(SS_DOWN(X_LEFT_GUI)SS_TAP(X_R)SS_UP(X_LEFT_GUI)SS_DELAY(150)"C:/Users/AlRichIII/AppData/Local/Discord/app-1.0.9011/Discord"SS_DELAY(500)SS_TAP(X_ENT));
				return false; break;
			case D_NOTEPAD:
				SEND_STRING(SS_DOWN(X_LEFT_GUI)SS_TAP(X_R)SS_UP(X_LEFT_GUI)SS_DELAY(150)"notepad"SS_DELAY(500)SS_TAP(X_ENT));
				return false; break;
			case D_COMANDLINE:
				SEND_STRING(SS_DOWN(X_LEFT_GUI)SS_TAP(X_R)SS_UP(X_LEFT_GUI)SS_DELAY(150)"cmd"SS_DELAY(500)SS_TAP(X_ENT));
				return false; break;

		}
	}
    return true;
};

/*
void keyboard_post_init_user(void) {
    hd44780_init(true, true); // Show blinking cursor
    hd44780_puts_P(PSTR("Hello, world!\n"));
}
*/

/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}
*/

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}
*/

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    return false;
}