#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _F_KEY 1
#define _VOL 2

#define L_F_KEY TG(_F_KEY)
#define L_VOL TG(_VOL)

enum custom_keycodes {
    DEFAULT = SAFE_RANGE,
    F_KEY,
    VOL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, KC_EQL, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LBRC, KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, L_F_KEY, L_VOL, KC_NO, AS_TOGG, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        // ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_LGUI, KC_RALT, KC_DOWN, KC_UP, KC_LCTL, KC_SPC, KC_ENT, KC_DEL, KC_BSPC, KC_LALT, KC_LEFT, KC_RGHT, KC_RALT, KC_RGUI // └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_F_KEY] = LAYOUT(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_NO, KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_NO, KC_NO, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_VOLU, KC_VOLD, KC_NO, KC_TRNS, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_VOL] = LAYOUT(QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_D, KC_WH_U, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_NO, KC_NO, KC_BTN2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _DEFAULT:
            set_led_off;
            break;
        case _F_KEY:
            set_led_green;
            break;
        case _VOL:
            set_led_red;
            break;
        default:
            break;
    }
    return state;
}
