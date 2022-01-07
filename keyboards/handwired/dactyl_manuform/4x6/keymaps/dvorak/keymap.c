#include QMK_KEYBOARD_H

#define _LAYER_0 0
#define _LAYER_1 1
#define _LAYER_2 2

#define LAYER1 TT(_LAYER_1)
#define LOWER MO(_LAYER_2)

#define LG_U MT(MOD_LGUI, KC_U)
#define LC_E CTL_T(KC_E)
#define LA_O ALT_T(KC_O)

#define RG_H MT(MOD_RGUI, KC_H)
#define RC_T CTL_T(KC_T)
#define RA_N ALT_T(KC_N)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (dvorak)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | TAB  |   '  |   ,  |   .  |   p  |   y  |                             |   f  |   g  |   c  |   r  |   l  | ESC  |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | CAPS |   a  | LA_O | LC_E | LG_U |   i  |                             |   d  |   h  |   t  |   n  |   s  | -    |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SFT( |   ;  |   q  |   j  |   k  |   x  |                             |   b  |   m  |   w  |   v  |   z  | SFT) |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               | [{   | ]}   |                                                         |   <  |   >  |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             | DEL  | BSPC |                             | SPCE | ENT  |
     *                             |------+------|                             |------+------|
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           |      | LAY1 | | LAY1 |      |
     *                                           |------+------| |------+------|
     *                                           |      | REST | | REST |      |
     *                                           +-------------+ +-------------+
     */
    [_LAYER_0] = LAYOUT(
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_ESC,
        KC_CAPS, KC_A,    LA_O,    LC_E,    LG_U,    KC_I,               KC_D,    RG_H,    RC_T,    RA_N,    KC_S,    KC_MINS,
        KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,               KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSPC,
                          KC_LBRC, KC_RBRC,                                                KC_LT,   KC_GT,
                                            KC_DEL,  KC_BSPC,            KC_SPC,  KC_ENT,
                                            KC_TAB,  LAYER1,             LAYER1,  KC_DEL,
                                            KC_BSPC, RESET,              RESET,   KC_LALT
    ),
    /*
     * +-----------------------------------------+                             +-----------------------------------------+
     * |      |      | ^    | UP   | `~   | \|   |                             | PGUP | 7    | 8    | 9    | *    | /    |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * |      | ?    | LEFT | DOWN | RGHT | !    |                             | =    | 4    | 5    | 6    | +    | -    |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SFT( | %    | &    | $    | #    | @    |                             | PGDN | 1    | 2    | 3    |      | LFT) |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |      |      |                                                         | 0    | .    |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |      |      |                             |      |      |
     *                             |------+------|                             |------+------|
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           |      |      | |      |      |
     *                                           |------+------| |------+------|
     *                                           |      |      | |      |      |
     *                                           +-------------+ +-------------+
     */

    [_LAYER_1] = LAYOUT(
        _______, _______, KC_CIRC, KC_UP,   KC_GRV,  KC_BSLS,             KC_PGUP, KC_7,    KC_8,    KC_9,    KC_PAST, KC_PSLS,
        _______, KC_QUES, KC_LEFT, KC_DOWN, KC_RGHT, KC_EXLM,             KC_EQL,  KC_4,    KC_5,    KC_6,    KC_PPLS, KC_PMNS,
        KC_LSPO, KC_PERC, KC_AMPR, KC_DLR,  KC_HASH, KC_AT,               KC_PGDN, KC_1,    KC_2,    KC_3,    _______, KC_RSPC,
                          _______, _______,                                                 KC_0,    KC_DOT,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______
    )

};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
