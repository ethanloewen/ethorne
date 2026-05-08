/* ETHORN Keymap */

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LOWER,
    _UPPER,
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
                                    KC_LGUI,   MO(_LOWER),  KC_SPC,  KC_ENT, MO(_UPPER), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_LOWER] = LAYOUT_split_3x6_3(
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

    [_UPPER] = LAYOUT_split_3x6_3(
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
    if (keycode >= KC_F1 && keycode <= KC_F9) return '1' + (keycode - KC_F1);
    if (keycode == KC_F10) return '0';
    // KC_F11, KC_F12 fall through to '?'
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

// Draw a character directly at pixel coordinates (x, y) using raw font data.
static void draw_pixel_char(uint8_t x, uint8_t y, char c, bool invert) {
    if ((uint8_t)c < 0x20) c = ' ';
    uint16_t base = (uint8_t)c * OLED_FONT_WIDTH;
    for (uint8_t col = 0; col < OLED_FONT_WIDTH; col++) {
        uint8_t bits = pgm_read_byte(&keymap_font[base + col]);
        for (uint8_t row = 0; row < 8; row++) {
            bool on = (bits >> row) & 1;
            oled_write_pixel(x + col, y + row, invert ? !on : on);
        }
    }
}

static void draw_pixel_str(uint8_t x, uint8_t y, const char *s, bool invert) {
    for (; *s; s++, x += OLED_FONT_WIDTH)
        draw_pixel_char(x, y, *s, invert);
}

// Right-panel mod badge layout.
// 4 vertical badges, side by side: x=87-125, y=11-30 (20px tall).
// Layer pill sits above them: x=100-113, y=0-9.
#define BADGE_W    9
#define BADGE_H   19
#define BADGE_GAP  1
#define BADGE_X0  89
#define BADGE_Y0  12

static void draw_mod_badge(uint8_t idx, char label, bool active) {
    uint8_t x = BADGE_X0 + idx * (BADGE_W + BADGE_GAP);
    uint8_t y = BADGE_Y0;

    // 2px rounded-corner border: edges skip 2px at each end, sides skip 2 rows,
    // then one diagonal closure pixel per corner connects them (CSS border-radius style).
    for (uint8_t px = x + 2; px < x + BADGE_W - 2; px++) {
        oled_write_pixel(px, y,               true);
        oled_write_pixel(px, y + BADGE_H - 1, true);
    }
    for (uint8_t py = y + 2; py < y + BADGE_H - 2; py++) {
        oled_write_pixel(x,               py, true);
        oled_write_pixel(x + BADGE_W - 1, py, true);
    }
    // Corner closure pixels — the single diagonal pixel that closes each corner.
    oled_write_pixel(x + 1,           y + 1,           true);
    oled_write_pixel(x + BADGE_W - 2, y + 1,           true);
    oled_write_pixel(x + 1,           y + BADGE_H - 2, true);
    oled_write_pixel(x + BADGE_W - 2, y + BADGE_H - 2, true);

    // Solid fill when active (corner closure pixels are border, so no exclusions needed).
    if (active) {
        for (uint8_t px = x + 1; px < x + BADGE_W - 1; px++)
            for (uint8_t py = y + 1; py < y + BADGE_H - 1; py++)
                oled_write_pixel(px, py, true);
    }

    // Glyph with 1px left pad to match font's natural right blank (col 5).
    // Interior is 7px wide: 1px left pad + 5px content + 1px font-blank = 7px exact.
    // glyph_y is fixed at y+6 (5px from interior top) so that reducing BADGE_H by 1
    // removes 1px from below the glyph rather than recalculating it away from above.
    uint8_t glyph_x = x + 2;
    uint8_t glyph_y = y + 6;
    draw_pixel_char(glyph_x, glyph_y, label, active);
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

    uint8_t keymap_right = 6 * CELL_STEP;
    // Inner row-dividers span the full keymap width (no corner rounding needed).
    for (uint8_t x = 0; x <= keymap_right; x++) {
        oled_write_pixel(x, DIV1_Y, true);
        oled_write_pixel(x, DIV2_Y, true);
    }
    // Outer top/bottom borders: 2px corner rounding, skip 2 pixels at each end.
    for (uint8_t x = 2; x < keymap_right - 1; x++) {
        oled_write_pixel(x, TOP_DIV_Y, true);
        oled_write_pixel(x, BOT_DIV_Y, true);
    }
    // Vertical borders: skip 2 rows at each end to match.
    for (uint8_t py = TOP_DIV_Y + 2; py < BOT_DIV_Y - 1; py++) {
        oled_write_pixel(0,            py, true);
        oled_write_pixel(keymap_right, py, true);
    }
    // Corner closure pixels for the keymap outer border.
    oled_write_pixel(1,                TOP_DIV_Y + 1, true);
    oled_write_pixel(keymap_right - 1, TOP_DIV_Y + 1, true);
    oled_write_pixel(1,                BOT_DIV_Y - 1, true);
    oled_write_pixel(keymap_right - 1, BOT_DIV_Y - 1, true);

    // Layer pill: x=89-127 (39px), y=0-10 (11px), 2px rounded corners.
    // Interior x=91-125 (35px visible between sides); text centred within x=90-126 (37px).
    for (uint8_t px = 91; px < 126; px++) {
        oled_write_pixel(px, 0,  true);
        oled_write_pixel(px, 10, true);
    }
    for (uint8_t py = 2; py < 9; py++) {
        oled_write_pixel(89,  py, true);
        oled_write_pixel(127, py, true);
    }
    // Corner closure pixels for the pill.
    oled_write_pixel(90, 1,  true);
    oled_write_pixel(126, 1, true);
    oled_write_pixel(90, 9,  true);
    oled_write_pixel(126, 9, true);
    // Layer name centred in 37px interior (x=90-126).
    // BASE=24px offset 6 → x=96; LOWER/UPPER=30px offset 3 → x=93.
    const char *layer_name;
    switch (layer) {
        case _BASE:  layer_name = "BASE";  break;
        case _LOWER: layer_name = "LOWER"; break;
        case _UPPER: layer_name = "UPPER"; break;
        default:     layer_name = "????";  break;
    }
    uint8_t name_len = 0;
    while (layer_name[name_len]) name_len++;
    // Centre on visible text width (name_len*6 - 1) by using 38 instead of 37,
    // offsetting the font's built-in 1px blank trailing column on the last character.
    uint8_t text_x = 90 + (38 - name_len * OLED_FONT_WIDTH) / 2;
    draw_pixel_str(text_x, 2, layer_name, false);

    // Mod badges: four vertical badges G A C S in the right panel.
    uint8_t mods = get_mods() | get_oneshot_mods();
    draw_mod_badge(0, 'G', mods & MOD_MASK_GUI);
    draw_mod_badge(1, 'A', mods & MOD_MASK_ALT);
    draw_mod_badge(2, 'C', mods & MOD_MASK_CTRL);
    draw_mod_badge(3, 'S', mods & MOD_MASK_SHIFT);

    return false;
}

#endif
