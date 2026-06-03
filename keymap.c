/* ETHORN Keymap */

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LOWER,
    _UPPER,
    _THIRD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LGUI,   MO(_UPPER),  KC_SPC,  KC_ENT, MO(_LOWER), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                      XXXXXXX,    KC_5,    KC_6,    KC_7,    KC_8, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      XXXXXXX,    KC_9,    KC_0, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC, KC_ENT, MO(_THIRD), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_UPPER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI, MO(_THIRD), KC_SPC, KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
//   ,
//     [_THIRD] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
//                                       //`--------------------------'  `--------------------------'
//   )
};

#ifdef OLED_ENABLE

// Rename the static font array to avoid LTO duplicate-symbol conflict with oled_driver.o
#define font keymap_font
#include OLED_FONT_H
#undef font

// Pixel layout (128x32):
//   6 cells × CELL_STEP (20px) per row = 121px wide.
//   Each cell is CELL_W=19 (1px pad + 17px content + 1px pad).
//   Centering formula: gx = x + 10 - len*3.

#define CELL_W   19   // 1px pad + 3 chars (6+6+5) + 1px pad = 19px
#define CELL_H    9   // 1px top pad + 8px font (font's blank bit-7 is the bottom pad)
#define CELL_STEP 20  // CELL_W + 1px vertical divider
#define TOP_DIV_Y  0
#define ROW0_Y     1
#define DIV1_Y    10
#define ROW1_Y    11
#define DIV2_Y    20
#define ROW2_Y    21
#define BOT_DIV_Y 30

static uint8_t get_key_label(uint16_t keycode, char *buf) {
    if (keycode >= KC_A && keycode <= KC_Z) { buf[0] = 'A' + (keycode - KC_A); return 1; }
    if (keycode >= KC_1 && keycode <= KC_9) { buf[0] = '1' + (keycode - KC_1); return 1; }
    if (keycode == KC_0) { buf[0] = '0'; return 1; }
    if (keycode >= KC_F1 && keycode <= KC_F9) { buf[0] = 'F'; buf[1] = '1' + (keycode - KC_F1); return 2; }
    if (keycode == KC_F10) { buf[0] = 'F'; buf[1] = '1'; buf[2] = '0'; return 3; }
    if (keycode == KC_F11) { buf[0] = 'F'; buf[1] = '1'; buf[2] = '1'; return 3; }
    if (keycode == KC_F12) { buf[0] = 'F'; buf[1] = '1'; buf[2] = '2'; return 3; }
    switch (keycode) {
        case KC_TAB:  buf[0] = 'T'; buf[1] = 'A'; buf[2] = 'B'; return 3;
        case KC_ENT:  buf[0] = 'E'; buf[1] = 'N'; return 2;
        case KC_ESC:  buf[0] = 'E'; buf[1] = 'S'; buf[2] = 'C'; return 3;
        case KC_BSPC: buf[0] = 'B'; buf[1] = 'S'; buf[2] = 'P'; return 3;
        case KC_DEL:  buf[0] = 'D'; buf[1] = 'L'; return 2;
        case KC_SPC:  buf[0] = 'S'; buf[1] = 'P'; return 2;
        case KC_LCTL: buf[0] = 'C'; buf[1] = 'T'; buf[2] = 'L'; return 3;
        case KC_LSFT: buf[0] = 'S'; buf[1] = 'H'; buf[2] = 'F'; return 3;
        case KC_LGUI: buf[0] = 'G'; buf[1] = 'N'; return 2;
        case KC_RALT: buf[0] = 'A'; buf[1] = 'L'; buf[2] = 'T'; return 3;
        case KC_QUOT: buf[0] = '\''; return 1;
        case KC_COMM: buf[0] = ','; return 1;
        case KC_DOT:  buf[0] = '.'; return 1;
        case KC_SLSH: buf[0] = '/'; return 1;
        case KC_BSLS: buf[0] = '\\'; return 1;
        case KC_GRV:  buf[0] = '`'; return 1;
        case KC_MINUS: buf[0] = '-'; return 1;
        case KC_EQL:  buf[0] = '='; return 1;
        case KC_SCLN: buf[0] = ';'; return 1;
        case KC_EXLM: buf[0] = '!'; return 1;
        case KC_AT:   buf[0] = '@'; return 1;
        case KC_HASH: buf[0] = '#'; return 1;
        case KC_DLR:  buf[0] = '$'; return 1;
        case KC_PERC: buf[0] = '%'; return 1;
        case KC_CIRC: buf[0] = '^'; return 1;
        case KC_AMPR: buf[0] = '&'; return 1;
        case KC_ASTR: buf[0] = '*'; return 1;
        case KC_LPRN: buf[0] = '('; return 1;
        case KC_RPRN: buf[0] = ')'; return 1;
        case KC_UNDS: buf[0] = '_'; return 1;
        case KC_PLUS: buf[0] = '+'; return 1;
        case KC_LCBR: buf[0] = '{'; return 1;
        case KC_RCBR: buf[0] = '}'; return 1;
        case KC_LBRC: buf[0] = '['; return 1;
        case KC_RBRC: buf[0] = ']'; return 1;
        case KC_PIPE: buf[0] = '|'; return 1;
        case KC_TILD: buf[0] = '~'; return 1;
        case KC_LEFT: buf[0] = '<'; return 1;
        case KC_RIGHT: buf[0] = '>'; return 1;
        case KC_UP:   buf[0] = '^'; return 1;
        case KC_DOWN: buf[0] = 'v'; return 1;
        case XXXXXXX: buf[0] = ' '; return 1;
        case _______: buf[0] = ' '; return 1;
        default: buf[0] = '?'; return 1;
    }
}

static void draw_glyph(uint8_t x, uint8_t y, const char *label, uint8_t len, bool invert) {
    for (uint8_t cx = 0; cx < CELL_W; cx++)
        for (uint8_t cy = 0; cy < CELL_H; cy++)
            oled_write_pixel(x + cx, y + cy, invert);
    uint8_t gx = x + 10 - len * 3;
    for (uint8_t i = 0; i < len; i++) {
        char c = label[i];
        if ((uint8_t)c < 0x20) c = ' ';
        uint16_t base = (uint8_t)c * OLED_FONT_WIDTH;
        for (uint8_t col = 0; col < OLED_FONT_WIDTH; col++) {
            uint8_t bits = pgm_read_byte(&keymap_font[base + col]);
            for (uint8_t row = 0; row < 8; row++) {
                bool on = (bits >> row) & 1;
                oled_write_pixel(gx + col, y + row + 1, invert ? !on : on);
            }
        }
        gx += OLED_FONT_WIDTH;
    }
}

bool oled_task_user(void) {
    uint8_t layer   = get_highest_layer(layer_state);
    bool    is_left = is_keyboard_master();

    static bool     borders_drawn = false;
    static uint8_t  prev_layer = 255;
    static bool     prev_pressed[3][6];

    const uint8_t row_y[3] = { ROW0_Y, ROW1_Y, ROW2_Y };
    uint8_t kx0   = is_left ? 7 : 0;
    uint8_t ind_x = is_left ? 2 : 122;

    if (!borders_drawn) {
        for (uint8_t r = 0; r < 3; r++) {
            for (uint8_t d = 1; d < 6; d++) {
                uint8_t vx = kx0 + d * CELL_STEP;
                for (uint8_t py = row_y[r]; py < row_y[r] + CELL_H; py++)
                    oled_write_pixel(vx, py, true);
            }
        }
        uint8_t keymap_right = kx0 + 6 * CELL_STEP;
        for (uint8_t x = kx0; x <= keymap_right; x++) {
            oled_write_pixel(x, DIV1_Y, true);
            oled_write_pixel(x, DIV2_Y, true);
        }
        for (uint8_t x = kx0; x <= keymap_right; x++) {
            oled_write_pixel(x, TOP_DIV_Y, true);
            oled_write_pixel(x, BOT_DIV_Y, true);
        }
        for (uint8_t py = TOP_DIV_Y; py <= BOT_DIV_Y; py++) {
            oled_write_pixel(kx0,          py, true);
            oled_write_pixel(keymap_right,  py, true);
        }
        borders_drawn = true;
    }

    bool layer_changed = (layer != prev_layer);

    for (uint8_t r = 0; r < 3; r++) {
        matrix_row_t mrow = matrix_get_row(is_left ? r : r + 4);
        for (uint8_t c = 0; c < 6; c++) {
            uint16_t kc = is_left
                ? pgm_read_word(&keymaps[layer][r][c])
                : pgm_read_word(&keymaps[layer][r + 4][5 - c]);
            uint8_t  mat_col = is_left ? c : (5 - c);
            bool     pressed = (mrow >> mat_col) & 1;
            if (layer_changed || pressed != prev_pressed[r][c]) {
                char label[3];
                uint8_t len = get_key_label(kc, label);
                draw_glyph(kx0 + 1 + c * CELL_STEP, row_y[r], label, len, pressed);
                prev_pressed[r][c] = pressed;
            }
        }
    }

    if (layer_changed) {
        const uint8_t ind_layers[3] = { _UPPER, _BASE, _LOWER };
        for (uint8_t r = 0; r < 3; r++) {
            bool active = (layer == ind_layers[r]);
            uint8_t iy = row_y[r];
            for (uint8_t px = ind_x; px < ind_x + 4; px++)
                for (uint8_t py = iy; py < iy + CELL_H; py++) {
                    bool border = (px == ind_x || px == ind_x + 3 || py == iy || py == iy + CELL_H - 1);
                    oled_write_pixel(px, py, active || border);
                }
        }
        prev_layer = layer;
    }

    return false;
}

#endif
