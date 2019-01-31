#include "dz60.h"

// Layers
#define BASE 0 // Default layer
#define SYMB 1 // Symbols and arrows

// Fillers to make layering clearer
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Tap dance
enum {
	TD_A,
	TD_E,
	TD_I,
	TD_O,
	TD_U,
	TD_C
};

void kc_a_french (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			SEND_STRING ("a");
			reset_tap_dance(state);
			break;
		case 2:
			// à
			send_unicode_hex_string("00E0");
			reset_tap_dance(state);
			break;
		case 3:
			// â
			send_unicode_hex_string("00E2");
			reset_tap_dance(state);
			break;
	}
}

void kc_e_french (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			SEND_STRING ("e");
			reset_tap_dance(state);
			break;
		case 2:
			// é
			send_unicode_hex_string("00E9");
			reset_tap_dance(state);
			break;
		case 3:
			// è
			send_unicode_hex_string("00E8");
			reset_tap_dance(state);
			break;
		case 4:
			// ê
			send_unicode_hex_string("00EA");
			reset_tap_dance(state);
			break;
		case 5:
			// ë
			send_unicode_hex_string("00EB");
			reset_tap_dance(state);
			break;
	}
}

void kc_i_french (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			SEND_STRING ("i");
			reset_tap_dance(state);
			break;
		case 2:
			// î
			send_unicode_hex_string("00EE");
			reset_tap_dance(state);
			break;
		case 3:
			// ï
			send_unicode_hex_string("00EF");
			reset_tap_dance(state);
			break;
	}
}

void kc_o_french (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			SEND_STRING ("o");
			reset_tap_dance(state);
			break;
		case 2:
			// ô
			send_unicode_hex_string("00F4");
			reset_tap_dance(state);
			break;
	}
}

void kc_u_french (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			SEND_STRING ("u");
			reset_tap_dance(state);
			break;
		case 2:
			// ù
			send_unicode_hex_string("00F9");
			reset_tap_dance(state);
			break;
		case 3:
			// û
			send_unicode_hex_string("00FB");
			reset_tap_dance(state);
			break;
		case 4:
			// ü
			send_unicode_hex_string("00FC");
			reset_tap_dance(state);
			break;
	}
}

void kc_c_french (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			SEND_STRING ("c");
			reset_tap_dance(state);
			break;
		case 2:
			// ç
			send_unicode_hex_string("00E7");
			reset_tap_dance(state);
			break;
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_A] = ACTION_TAP_DANCE_FN(kc_a_french),
	[TD_E] = ACTION_TAP_DANCE_FN(kc_e_french),
	[TD_I] = ACTION_TAP_DANCE_FN(kc_i_french),
	[TD_O] = ACTION_TAP_DANCE_FN(kc_o_french),
	[TD_U] = ACTION_TAP_DANCE_FN(kc_u_french),
	[TD_C] = ACTION_TAP_DANCE_FN(kc_c_french)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* BASE
	* ,-----------------------------------------------------------------------------------------.
	* | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bckspc  |
	* |-----------------------------------------------------------------------------------------+
	* |  Tab  |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   Del   |
	* |-----------------------------------------------------------------------------------------+
	* |   MO1   |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
	* |-----------------------------------------------------------------------------------------+
	* |   SHIFT   |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |   /   |     SHIFT     |
	* |-----------------------------------------------------------------------------------------+
	* | Ctrl |  Alt |  Gui |                   Space                |  Gui |  Alt  |     | CAPS |
	* `-----------------------------------------------------------------------------------------'
	*/

	[BASE] = LAYOUT_60_ansi (
		KC_ESC,  KC_1,     KC_2,    KC_3,     KC_4, KC_5, KC_6,   KC_7,     KC_8,     KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,  KC_Q,     KC_W,    TD(TD_E), KC_R, KC_T, KC_Y,   TD(TD_U), TD(TD_I), TD(TD_O), KC_P,    KC_LBRC, KC_RBRC, KC_DEL,
		MO(1),   TD(TD_A), KC_S,    KC_D,     KC_F, KC_G, KC_H,   KC_J,     KC_K,     KC_L,     KC_SCLN, KC_QUOT,          KC_ENT,
		KC_LSFT, KC_Z,     KC_X,    TD(TD_C), KC_V, KC_B, KC_N,   KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                   KC_RSFT,
		KC_RCTL, KC_LALT,  KC_LGUI,                       KC_SPC,                     KC_RGUI,  KC_RALT, XXXXXXX, KC_CLCK
	),

	/* SYMB
	i* ,-----------------------------------------------------------------------------------------.
	* |  ~  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |           |
	* |-----------------------------------------------------------------------------------------+
	* |       |     |     |     |     |     |     |     |     |     |     |  |  |  €  |         |
	* |-----------------------------------------------------------------------------------------+
	* |         |     |     |     |     |     |     |  ←  |  ↓  |  ↑  |  →  |  `  |             |
	* |-----------------------------------------------------------------------------------------+
	* |   Shift   |     |     |     |     | Mute|  VD | VU  | BD  | BU  |   \   |     Shift     |
	* |-----------------------------------------------------------------------------------------+
	* |      |      |      |                                        |      |       |     |      |
	* `-----------------------------------------------------------------------------------------'
	*/

	[SYMB] = LAYOUT_60_ansi (
		KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,     KC_F11,     KC_F12,     _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_PIPE,    UC(0x20AC), _______,
		_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,    UC(0x0060),             _______,
		_______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_SLCK, KC_PAUS, UC(0x005C),                         _______,
		_______, _______, _______,                            _______,                   _______, _______,    _______,    _______
	)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user (void) {
    // set_unicode_input_mode(UC_LNX); // Linux
    set_unicode_input_mode(UC_OSX); // Mac OSX
    // set_unicode_input_mode(UC_WIN); // Windows (with registry key, see wiki)
    // set_unicode_input_mode(UC_WINC); // Windows (with WinCompose, see wiki)
};