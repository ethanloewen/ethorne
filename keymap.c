/* ETHORN Keymap */

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FIRST,
    _SECOND,
    _THIRD
};

// Homerow mod combos using OSM (One Shot Mod)
const uint16_t PROGMEM spc_a_combo[]    = {KC_SPC, KC_A, COMBO_END};
const uint16_t PROGMEM spc_s_combo[]    = {KC_SPC, KC_S, COMBO_END};
const uint16_t PROGMEM spc_d_combo[]    = {KC_SPC, KC_D, COMBO_END};
const uint16_t PROGMEM spc_f_combo[]    = {KC_SPC, KC_F, COMBO_END};
const uint16_t PROGMEM ent_j_combo[]    = {KC_ENT, KC_J, COMBO_END};
const uint16_t PROGMEM ent_k_combo[]    = {KC_ENT, KC_K, COMBO_END};
const uint16_t PROGMEM ent_l_combo[]    = {KC_ENT, KC_L, COMBO_END};
const uint16_t PROGMEM ent_scln_combo[] = {KC_ENT, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
    COMBO(spc_a_combo,    OSM(MOD_LGUI)),  // A = GUI (Cmd/Win)
    COMBO(spc_s_combo,    OSM(MOD_LALT)),  // S = Alt
    COMBO(spc_d_combo,    OSM(MOD_LCTL)),  // D = Control
    COMBO(spc_f_combo,    OSM(MOD_LSFT)),  // F = Shift
    COMBO(ent_j_combo,    OSM(MOD_RSFT)),  // J = Shift
    COMBO(ent_k_combo,    OSM(MOD_RCTL)),  // K = Control
    COMBO(ent_l_combo,    OSM(MOD_LALT)),  // L = Alt (use LALT to avoid AltGr issues)
    COMBO(ent_scln_combo, OSM(MOD_RGUI)),  // ; = GUI (Cmd/Win)
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
                                    KC_LGUI,   MO(_FIRST),  KC_SPC,  KC_ENT, MO(_SECOND), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_FIRST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC, KC_ENT, MO(_THIRD), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_SECOND] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LEFT,   KC_UP, KC_DOWN,KC_RIGHT, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_BSLS,  KC_GRV,
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
//   6 cells × CELL_STEP (14px) per row = 83px wide. Glyph drawn at (x+4, y+1).
//   Each cell is CELL_W=13 (4px left + 5px content + 1px font blank + 3px right).
//   Between cells: 1px vertical divider (the extra px in CELL_STEP).
//   Top/bottom bounding dividers frame the entire keymap.
//
//   y= 0      top bounding divider
//   y= 1.. 9  keymap row 0  (CELL_H=9)
//   y=10      horizontal divider 1
//   y=11..19  keymap row 1
//   y=20      horizontal divider 2
//   y=21..29  keymap row 2
//   y=30      bottom bounding divider
//   y=31      unused

#define CELL_W   13   // 4px left pad + 5px glyph content + 4px right (1 font blank + 3 extra)
#define CELL_H    9   // 1px top pad + 8px font (font's blank bit-7 is the bottom pad)
#define CELL_STEP 14  // CELL_W + 1px vertical divider
#define TOP_DIV_Y  0
#define ROW0_Y     1
#define DIV1_Y    10
#define ROW1_Y    11
#define DIV2_Y    20
#define ROW2_Y    21
#define BOT_DIV_Y 30

static char get_key_char(uint16_t keycode) {
    if (keycode >= KC_A && keycode <= KC_Z) return 'A' + (keycode - KC_A);
    if (keycode >= KC_1 && keycode <= KC_9) return '1' + (keycode - KC_1);
    if (keycode == KC_0) return '0';
    if (keycode >= KC_F1 && keycode <= KC_F9) return 'a' + (keycode - KC_F1);
    if (keycode >= KC_F10 && keycode <= KC_F12) return 'j' + (keycode - KC_F10);
    switch (keycode) {
        case KC_TAB:  return 't'; case KC_ENT:  return 'e'; case KC_ESC:  return 'x';
        case KC_BSPC: return '<'; case KC_DEL:  return 'd'; case KC_SPC:  return '_';
        case KC_QUOT: return '\''; case KC_COMM: return ','; case KC_DOT: return '.';
        case KC_SLSH: return '/'; case KC_BSLS: return '\\'; case KC_GRV: return '`';
        case KC_MINUS: return '-'; case KC_EQL:  return '='; case KC_SCLN: return ';';
        case KC_EXLM: return '!'; case KC_AT:   return '@'; case KC_HASH: return '#';
        case KC_DLR:  return '$'; case KC_PERC: return '%'; case KC_CIRC: return '^';
        case KC_AMPR: return '&'; case KC_ASTR: return '*'; case KC_LPRN: return '(';
        case KC_RPRN: return ')'; case KC_UNDS: return '_'; case KC_PLUS: return '+';
        case KC_LCBR: return '{'; case KC_RCBR: return '}'; case KC_LBRC: return '[';
        case KC_RBRC: return ']'; case KC_PIPE: return '|'; case KC_TILD: return '~';
        case KC_LEFT: return '<'; case KC_RIGHT: return '>'; case KC_UP: return '^'; case KC_DOWN: return 'v';
        case XXXXXXX: return ' '; case _______: return ' ';
        default: return '?';
    }
}

// Draw a glyph centred in a CELL_W × CELL_H cell with 1px top+left pad.
// Font's natural blank col-5 and blank bit-7 provide the matching right+bottom pad.
// When inverted the full cell is lit and the glyph is punched out dark.
static void draw_glyph(uint8_t x, uint8_t y, char c, bool invert) {
    if ((uint8_t)c < 0x20) c = ' ';
    uint16_t base = (uint8_t)c * OLED_FONT_WIDTH;
    if (invert) {
        for (uint8_t cx = 0; cx < CELL_W; cx++)  // CELL_W=8, excludes the vertical divider pixel
            for (uint8_t cy = 0; cy < CELL_H; cy++)
                oled_write_pixel(x + cx, y + cy, true);
    }
    for (uint8_t col = 0; col < OLED_FONT_WIDTH; col++) {
        uint8_t bits = pgm_read_byte(&keymap_font[base + col]);
        for (uint8_t row = 0; row < 8; row++) {
            bool on = (bits >> row) & 1;
            oled_write_pixel(x + col + 4, y + row + 1, invert ? !on : on);
        }
    }
}

bool oled_task_user(void) {
    oled_clear();

    uint8_t layer   = get_highest_layer(layer_state);
    bool    is_left = is_keyboard_master();

    const uint8_t row_y[3] = { ROW0_Y, ROW1_Y, ROW2_Y };

    for (uint8_t r = 0; r < 3; r++) {
        // keymaps is [LAYERS][MATRIX_ROWS=8][MATRIX_COLS=6].
        // Left:  rows 0-2, cols 0-5 (straight).
        // Right: rows 4-6, cols 5-0 (mirrored) — display col 0 = matrix col 5.
        matrix_row_t mrow = matrix_get_row(is_left ? r : r + 4);
        for (uint8_t c = 0; c < 6; c++) {
            uint16_t kc = is_left
                ? pgm_read_word(&keymaps[layer][r][c])
                : pgm_read_word(&keymaps[layer][r + 4][5 - c]);
            uint8_t  mat_col = is_left ? c : (5 - c);
            bool     pressed = (mrow >> mat_col) & 1;
            draw_glyph(1 + c * CELL_STEP, row_y[r], get_key_char(kc), pressed);
        }
    }

    // Vertical inter-cell dividers (5 gaps between 6 cells).
    // Cells start at x=1, so gap d sits at x = 1 + d*CELL_STEP - 1 = d*CELL_STEP.
    for (uint8_t r = 0; r < 3; r++) {
        for (uint8_t d = 1; d < 6; d++) {
            uint8_t vx = d * CELL_STEP;
            for (uint8_t py = row_y[r]; py < row_y[r] + CELL_H; py++)
                oled_write_pixel(vx, py, true);
        }
    }

    // Horizontal dividers: top/bottom bounds + 2 row separators (full width).
    for (uint8_t x = 0; x < 128; x++) {
        oled_write_pixel(x, TOP_DIV_Y, true);
        oled_write_pixel(x, DIV1_Y,    true);
        oled_write_pixel(x, DIV2_Y,    true);
        oled_write_pixel(x, BOT_DIV_Y, true);
    }

    // Left and right vertical borders enclosing the keymap (x=0 and x=85).
    for (uint8_t py = TOP_DIV_Y; py <= BOT_DIV_Y; py++) {
        oled_write_pixel(0,  py, true);
        oled_write_pixel(6 * CELL_STEP, py, true);
    }

    // Layer + mod indicators past the right border (col 15 = x 90).
    uint8_t mods = get_mods() | get_oneshot_mods();
    oled_set_cursor(15, 0);
    oled_write_char('L', false);
    oled_write_char('0' + layer, false);
    oled_set_cursor(15, 3);
    oled_write_char((mods & MOD_MASK_GUI)   ? 'G' : '.', false);
    oled_write_char((mods & MOD_MASK_ALT)   ? 'A' : '.', false);
    oled_write_char((mods & MOD_MASK_CTRL)  ? 'C' : '.', false);
    oled_write_char((mods & MOD_MASK_SHIFT) ? 'S' : '.', false);

    return false;
}

#endif
