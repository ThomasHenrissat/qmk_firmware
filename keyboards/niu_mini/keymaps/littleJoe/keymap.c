#include "niu_mini.h"

// Layers
#define BASE 0 // Default layer
#define SYMB 1 // Symbols
#define ACCT 2 // Accents
#define NUMB 3 // Number and functions

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
			// à
			send_unicode_hex_string("00E0");
			reset_tap_dance(state);
			break;
		case 2:
			// â
			send_unicode_hex_string("00E2");
			reset_tap_dance(state);
			break;
	}
}

void kc_e_french (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			// é
			send_unicode_hex_string("00E9");
			reset_tap_dance(state);
			break;
		case 2:
			// è
			send_unicode_hex_string("00E8");
			reset_tap_dance(state);
			break;
		case 3:
			// ê
			send_unicode_hex_string("00EA");
			reset_tap_dance(state);
			break;
		case 4:
			// ë
			send_unicode_hex_string("00EB");
			reset_tap_dance(state);
			break;
	}
}

void kc_i_french (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			// î
			send_unicode_hex_string("00EE");
			reset_tap_dance(state);
			break;
		case 2:
			// ï
			send_unicode_hex_string("00EF");
			reset_tap_dance(state);
			break;
	}
}

void kc_o_french (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			// ô
			send_unicode_hex_string("00F4");
			reset_tap_dance(state);
			break;
	}
}

void kc_u_french (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			// ù
			send_unicode_hex_string("00F9");
			reset_tap_dance(state);
			break;
		case 2:
			// û
			send_unicode_hex_string("00FB");
			reset_tap_dance(state);
			break;
		case 3:
			// ü
			send_unicode_hex_string("00FC");
			reset_tap_dance(state);
			break;
	}
}

void kc_c_french (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
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
	* ,-----------------------------------------------------------------------.
	* | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | Bsp |
	* |-----------------------------------------------------------------------|
	* | Tab |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |
	* |-----------------------------------------------------------------------|
	* | Sht |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Etr |
	* |-----------------------------------------------------------------------|
	* | Ctl | Alt | MO3 | Cmd | MO1 |   Space   | MO2 |  ←  |  ↓  |  ↑  |  →  |
	* `-----------------------------------------------------------------------'
	*/

	[BASE] = LAYOUT_planck_mit(
		KC_ESC,  KC_Q,    KC_W,  KC_E,    KC_R,  KC_T, KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_TAB,  KC_A,    KC_S,  KC_D,    KC_F,  KC_G, KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,  KC_C,    KC_V,  KC_B, KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
		KC_LCTL, KC_LALT, MO(3), KC_LGUI, MO(1),   KC_SPC,   MO(2), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

	/* SYMB
	* ,-----------------------------------------------------------------------.
	* |  ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  | Del |
	* |-----------------------------------------------------------------------|
	* |     |     |  _  |  -  |  {  |     |     |  }  |  =  |  +  |  €  |  `  |
	* |-----------------------------------------------------------------------|
	* |     |     |     |     |  [  |     |     |  ]  |     |  |  |  \  |     |
	* |-----------------------------------------------------------------------|
	* |     |     |     |     |     |           |     |     |     |     |     |
	* `-----------------------------------------------------------------------'
	*/

	[SYMB] = LAYOUT_planck_mit(
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_DEL,
		_______, _______, KC_UNDS, KC_PMNS, KC_LCBR, _______, _______, KC_RCBR, KC_PEQL, KC_PLUS, UC(0x20AC), KC_GRV,
		_______, _______, _______, _______, KC_LBRC, _______, _______, KC_RBRC, _______, KC_PIPE, KC_BSLS,    _______,
		_______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______,    _______
    ),

	/* ACCT
	* ,-----------------------------------------------------------------------.
	* |     |     |     | TDE |     |     |     | TDU | TDI | TDO |     |     |
	* |-----------------------------------------------------------------------|
	* |     | TDA |     |     |     |     |     |     |     |     |     |     |
	* |-----------------------------------------------------------------------|
	* |     |     |     | TDC |     |     | Mut | VD  | VU  | BD  | BU  |     |
	* |-----------------------------------------------------------------------|
	* |     |     |     |     |     |           |     |     |     |     |     |
	* `-----------------------------------------------------------------------'
	*/

	[ACCT] = LAYOUT_planck_mit(
		_______, _______,  _______, TD(TD_E), _______, _______, _______, TD(TD_U), TD(TD_I), TD(TD_O), _______, _______,
		_______, TD(TD_A), _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
		_______, _______,  _______, TD(TD_C), _______, _______, KC_MUTE, KC_VOLD,  KC_VOLU,  KC_SLCK,  KC_PAUS, _______,
		_______, _______,  _______, _______,  _______,      _______,     _______,  _______,  _______,  _______, _______
    ),

	/* NUMB
	* ,-----------------------------------------------------------------------.
	* |     | F1  | F2  | F3  | F4  |     |     |     |  7  |  8  |  9  |     |
	* |-----------------------------------------------------------------------|
	* |     | F5  | F6  | F7  | F8  |     |     |     |  4  |  5  |  6  |     |
	* |-----------------------------------------------------------------------|
	* |     | F19 | F10 | F11 | F12 |     |     |     |  1  |  2  |  3  |     |
	* |-----------------------------------------------------------------------|
	* |     |     |     |     |     |           |     |     |  0  |     |     |
	* `-----------------------------------------------------------------------'
	*/

	[NUMB] = LAYOUT_planck_mit(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, KC_7,    KC_8, KC_9,    _______,
		_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, KC_4,    KC_5, KC_6,    _______,
		_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_1,    KC_2, KC_3,    _______,
		_______, _______, _______, _______, _______,      _______,     _______, _______, KC_0, _______, _______
    )
};

// Runs just one time when the keyboard initializes.
void matrix_init_user (void) {
    // set_unicode_input_mode(UC_LNX); // Linux
    set_unicode_input_mode(UC_OSX); // Mac OSX
    // set_unicode_input_mode(UC_WIN); // Windows (with registry key, see wiki)
    // set_unicode_input_mode(UC_WINC); // Windows (with WinCompose, see wiki)
};

/* LAYER
* ,-----------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |
* |-----------------------------------------------------------------------|
* |     |     |     |     |     |     |     |     |     |     |     |     |
* |-----------------------------------------------------------------------|
* |     |     |     |     |     |     |     |     |     |     |     |     |
* |-----------------------------------------------------------------------|
* |     |     |     |     |     |           |     |     |     |     |     |
* `-----------------------------------------------------------------------'
*/

// [LAYER] = LAYOUT_planck_mit(
// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// 	_______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
// )