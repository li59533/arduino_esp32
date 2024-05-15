/*******************************************************************************
 * Size: 16 px
 * Bpp: 4
 * Opts: --bpp 4 --size 16 --no-compress --font SourceHanSansCN-Medium-2.otf --symbols 控制选择温度激光器电流 --format lvgl -o my_font.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef MY_FONT
#define MY_FONT 1
#endif

#if MY_FONT

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+5149 "光" */
    0x0, 0x0, 0x0, 0xc, 0xb0, 0x0, 0x0, 0x0,
    0x0, 0x7b, 0x0, 0xc, 0xb0, 0x0, 0xaa, 0x0,
    0x0, 0x3f, 0x90, 0xc, 0xb0, 0x5, 0xf7, 0x0,
    0x0, 0x6, 0xf5, 0xc, 0xb0, 0x2e, 0xb0, 0x0,
    0x0, 0x0, 0x83, 0xc, 0xb0, 0x39, 0x0, 0x0,
    0x7, 0x77, 0x77, 0x7e, 0xd7, 0x77, 0x77, 0x60,
    0xe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd0,
    0x0, 0x0, 0xd, 0xa0, 0xe, 0x90, 0x0, 0x0,
    0x0, 0x0, 0xf, 0x80, 0xe, 0x90, 0x0, 0x0,
    0x0, 0x0, 0x4f, 0x50, 0xe, 0x90, 0x0, 0x0,
    0x0, 0x0, 0xbf, 0x0, 0xe, 0x90, 0x0, 0x0,
    0x0, 0x8, 0xf8, 0x0, 0xe, 0x90, 0x2, 0x80,
    0x3, 0xaf, 0xa0, 0x0, 0xd, 0xd6, 0x6a, 0xf1,
    0xe, 0xf8, 0x0, 0x0, 0x7, 0xff, 0xff, 0x90,
    0x2, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+5236 "制" */
    0x0, 0x96, 0x4f, 0x10, 0x0, 0x0, 0x6, 0xd0,
    0x1f, 0x87, 0xf4, 0x33, 0x3, 0xf1, 0x6f, 0x6,
    0xff, 0xff, 0xff, 0xf2, 0x3f, 0x16, 0xf0, 0xea,
    0x26, 0xf3, 0x22, 0x3, 0xf1, 0x6f, 0xc, 0x86,
    0x9f, 0x76, 0x64, 0x3f, 0x16, 0xf1, 0xff, 0xff,
    0xff, 0xff, 0xb3, 0xf1, 0x6f, 0x0, 0x0, 0x4f,
    0x10, 0x0, 0x3f, 0x16, 0xf0, 0x39, 0x9b, 0xfa,
    0x99, 0x23, 0xf1, 0x6f, 0x6, 0xfb, 0xcf, 0xbb,
    0xf4, 0x3f, 0x16, 0xf0, 0x6e, 0x4, 0xf1, 0xf,
    0x43, 0xd1, 0x6f, 0x6, 0xe0, 0x4f, 0x10, 0xf4,
    0x0, 0x6, 0xf0, 0x6e, 0x4, 0xf3, 0x4f, 0x40,
    0x0, 0x6f, 0x6, 0xe0, 0x4f, 0x5f, 0xd1, 0x5,
    0x7c, 0xf0, 0x0, 0x4, 0xf1, 0x0, 0x0, 0x7f,
    0xe7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+5668 "器" */
    0x0, 0xff, 0xff, 0xf1, 0x5f, 0xff, 0xff, 0x0,
    0x0, 0xf7, 0x47, 0xf1, 0x5f, 0x44, 0x8f, 0x0,
    0x0, 0xf4, 0x4, 0xf1, 0x5f, 0x0, 0x6f, 0x0,
    0x0, 0xf8, 0x58, 0xf1, 0x5f, 0x55, 0x9f, 0x0,
    0x0, 0xee, 0xee, 0xf4, 0x5e, 0xfe, 0xee, 0x0,
    0x0, 0x0, 0x0, 0xcd, 0x0, 0xbd, 0x50, 0x0,
    0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf2,
    0x5, 0x57, 0xfe, 0x65, 0x58, 0xfc, 0x65, 0x50,
    0x1, 0x7f, 0xc1, 0x0, 0x0, 0x4e, 0xd6, 0x10,
    0x3f, 0xff, 0xee, 0xe4, 0x5e, 0xef, 0xff, 0xf2,
    0x5, 0xcc, 0x67, 0xf4, 0x6f, 0x66, 0xcd, 0x30,
    0x0, 0xc9, 0x2, 0xf4, 0x6f, 0x0, 0x9c, 0x0,
    0x0, 0xcb, 0x46, 0xf4, 0x6f, 0x44, 0xbc, 0x0,
    0x0, 0xcf, 0xff, 0xe4, 0x6f, 0xff, 0xfb, 0x0,

    /* U+5EA6 "度" */
    0x0, 0x0, 0x0, 0x2, 0x60, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4, 0xf6, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf2,
    0x0, 0xfa, 0x66, 0x87, 0x66, 0x68, 0x76, 0x60,
    0x0, 0xf7, 0x0, 0xe7, 0x0, 0xe, 0x80, 0x0,
    0x0, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0x0, 0xf7, 0x33, 0xf9, 0x33, 0x3f, 0xa3, 0x30,
    0x0, 0xf6, 0x0, 0xea, 0x44, 0x4f, 0x80, 0x0,
    0x0, 0xf6, 0x0, 0xde, 0xee, 0xee, 0x70, 0x0,
    0x2, 0xf5, 0x33, 0x33, 0x33, 0x33, 0x31, 0x0,
    0x3, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x0,
    0x6, 0xf1, 0x5, 0xf6, 0x0, 0x1c, 0xe1, 0x0,
    0x9, 0xd0, 0x0, 0x5f, 0xb8, 0xfc, 0x20, 0x0,
    0xe, 0x91, 0x36, 0x9e, 0xff, 0xfa, 0x53, 0x0,
    0x3f, 0x38, 0xff, 0xc8, 0x32, 0x7c, 0xff, 0xf1,
    0x1, 0x0, 0x20, 0x0, 0x0, 0x0, 0x2, 0x20,

    /* U+62E9 "择" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x4f, 0x20, 0x9f, 0xff, 0xff, 0xff, 0x50,
    0x0, 0x4f, 0x20, 0x39, 0xf6, 0x55, 0xde, 0x0,
    0x14, 0x7f, 0x64, 0x0, 0xcb, 0x8, 0xf5, 0x0,
    0x3f, 0xff, 0xff, 0x0, 0x2f, 0xcf, 0x60, 0x0,
    0x0, 0x4f, 0x30, 0x0, 0x5d, 0xff, 0x72, 0x0,
    0x0, 0x4f, 0x21, 0xae, 0xf8, 0x28, 0xff, 0xc3,
    0x0, 0x4f, 0xab, 0xa7, 0x13, 0xe3, 0x17, 0xb0,
    0x18, 0xef, 0xfa, 0x14, 0x47, 0xf7, 0x44, 0x0,
    0x3f, 0xdf, 0x30, 0x5f, 0xff, 0xff, 0xff, 0x20,
    0x0, 0x4f, 0x20, 0x0, 0x4, 0xf4, 0x0, 0x0,
    0x0, 0x4f, 0x20, 0x55, 0x58, 0xf8, 0x55, 0x51,
    0x0, 0x4f, 0x22, 0xff, 0xff, 0xff, 0xff, 0xf4,
    0x5, 0x9f, 0x20, 0x0, 0x3, 0xf3, 0x0, 0x0,
    0xb, 0xfb, 0x0, 0x0, 0x3, 0xf3, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+63A7 "控" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x4f, 0x10, 0x0, 0x3, 0xe3, 0x0, 0x0,
    0x0, 0x4f, 0x10, 0x77, 0x77, 0xfc, 0x77, 0x72,
    0x8, 0xaf, 0x95, 0xfc, 0x99, 0x99, 0x99, 0xf6,
    0x1c, 0xdf, 0xd7, 0xf6, 0x15, 0x1, 0x30, 0xf6,
    0x0, 0x4f, 0x10, 0x21, 0xcd, 0x18, 0xf4, 0x0,
    0x0, 0x4f, 0x10, 0x2d, 0xf2, 0x0, 0x9f, 0x50,
    0x0, 0x4f, 0x12, 0xae, 0x30, 0x0, 0x9, 0xc0,
    0x0, 0x7f, 0xfa, 0x27, 0x55, 0x55, 0x55, 0x30,
    0x2e, 0xff, 0x82, 0x3f, 0xff, 0xff, 0xff, 0x60,
    0x9, 0x7f, 0x10, 0x0, 0x1, 0xf6, 0x0, 0x0,
    0x0, 0x4f, 0x10, 0x0, 0x1, 0xf6, 0x0, 0x0,
    0x0, 0x4f, 0x10, 0x0, 0x1, 0xf6, 0x0, 0x0,
    0x5, 0x9f, 0x2, 0x55, 0x56, 0xfa, 0x55, 0x53,
    0xb, 0xfa, 0x7, 0xff, 0xff, 0xff, 0xff, 0xf8,

    /* U+6D41 "流" */
    0x0, 0x0, 0x0, 0x0, 0x3, 0x10, 0x0, 0x0,
    0x5, 0xe6, 0x0, 0x0, 0xe, 0x90, 0x0, 0x0,
    0x1, 0x9f, 0xa5, 0x66, 0x6c, 0xf6, 0x66, 0x60,
    0x0, 0x5, 0x5c, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x6, 0xf5, 0x4, 0xc1, 0x0,
    0xb, 0x70, 0x0, 0x4f, 0x70, 0x13, 0xec, 0x0,
    0x18, 0xfe, 0x28, 0xff, 0xff, 0xff, 0xff, 0xa0,
    0x0, 0x18, 0x3, 0x65, 0x32, 0x10, 0x5, 0xa0,
    0x0, 0x0, 0x0, 0x9b, 0xc, 0x61, 0xf3, 0x0,
    0x0, 0x5, 0xa0, 0x9b, 0xd, 0x71, 0xf3, 0x0,
    0x0, 0xd, 0xc0, 0xaa, 0xd, 0x71, 0xf3, 0x0,
    0x0, 0x6f, 0x40, 0xd9, 0xd, 0x71, 0xf3, 0x10,
    0x1, 0xfb, 0x4, 0xf4, 0xd, 0x71, 0xf3, 0x95,
    0xa, 0xf2, 0x2e, 0xd0, 0xd, 0x71, 0xf6, 0xc5,
    0x7, 0x90, 0x5e, 0x20, 0x5, 0x20, 0xbf, 0xd1,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+6E29 "温" */
    0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x4, 0xfd, 0x31, 0xff, 0xff, 0xff, 0xfa, 0x0,
    0x0, 0x3d, 0xe2, 0xf7, 0x33, 0x33, 0xda, 0x0,
    0x0, 0x0, 0x31, 0xf7, 0x33, 0x33, 0xda, 0x0,
    0x0, 0x0, 0x1, 0xff, 0xff, 0xff, 0xfa, 0x0,
    0x2c, 0x50, 0x1, 0xf4, 0x0, 0x0, 0xca, 0x0,
    0x18, 0xfd, 0x1, 0xff, 0xff, 0xff, 0xfa, 0x0,
    0x0, 0x27, 0x0, 0x44, 0x44, 0x44, 0x43, 0x0,
    0x0, 0x0, 0x3, 0x44, 0x44, 0x44, 0x44, 0x10,
    0x0, 0x8, 0x39, 0xff, 0xff, 0xff, 0xff, 0x30,
    0x0, 0x2f, 0x79, 0xb0, 0xf1, 0x98, 0x3f, 0x30,
    0x0, 0x9e, 0x9, 0xb0, 0xf1, 0x98, 0x3f, 0x30,
    0x2, 0xf8, 0x9, 0xb0, 0xf1, 0x98, 0x3f, 0x30,
    0xb, 0xe0, 0x4b, 0xc5, 0xf5, 0xba, 0x7f, 0x71,
    0xb, 0x70, 0xef, 0xff, 0xff, 0xff, 0xff, 0xf3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+6FC0 "激" */
    0x0, 0x0, 0x0, 0x33, 0x0, 0x4, 0x10, 0x0,
    0xb, 0xb1, 0x0, 0xda, 0x0, 0x1f, 0x40, 0x0,
    0x1, 0xdc, 0x7d, 0xfe, 0xd5, 0x4f, 0x10, 0x0,
    0x0, 0x15, 0x8c, 0x33, 0xd6, 0x7f, 0x66, 0x62,
    0x0, 0x0, 0x8e, 0xbb, 0xf6, 0xcf, 0xff, 0xf5,
    0x2b, 0x30, 0x8c, 0x33, 0xd9, 0xf8, 0xa, 0x90,
    0x8, 0xf4, 0x8f, 0xee, 0xff, 0xfa, 0xc, 0x60,
    0x0, 0x50, 0x13, 0xc5, 0x28, 0xad, 0xe, 0x40,
    0x0, 0x0, 0x44, 0xfa, 0x44, 0x1e, 0x3f, 0x10,
    0x0, 0x12, 0xef, 0xfe, 0xec, 0xa, 0xcd, 0x0,
    0x0, 0x8b, 0xa, 0xb3, 0x31, 0x6, 0xf8, 0x0,
    0x0, 0xe6, 0xc, 0xff, 0xf5, 0x4, 0xf5, 0x0,
    0x6, 0xf0, 0x2f, 0x40, 0xf4, 0xc, 0xfd, 0x0,
    0xd, 0x90, 0xcd, 0x24, 0xf3, 0xae, 0x2d, 0xc1,
    0xb, 0x27, 0xe2, 0x9f, 0xb6, 0xe3, 0x2, 0xd2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+7535 "电" */
    0x0, 0x0, 0x0, 0xea, 0x0, 0x0, 0x0, 0x0,
    0x11, 0x11, 0x1e, 0xb1, 0x11, 0x11, 0x0, 0xf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x0, 0xfa,
    0x55, 0x5f, 0xc5, 0x55, 0xbe, 0x0, 0xf, 0x80,
    0x0, 0xea, 0x0, 0x9, 0xe0, 0x0, 0xff, 0xee,
    0xef, 0xfe, 0xee, 0xfe, 0x0, 0xf, 0xb6, 0x66,
    0xfc, 0x66, 0x6c, 0xe0, 0x0, 0xf8, 0x0, 0xe,
    0xa0, 0x0, 0x9e, 0x0, 0xf, 0xb6, 0x66, 0xfc,
    0x66, 0x6c, 0xe0, 0x0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x0, 0xf, 0x80, 0x0, 0xea, 0x0,
    0x0, 0x1b, 0x20, 0x0, 0x0, 0xe, 0xb0, 0x0,
    0x3, 0xf5, 0x0, 0x0, 0x0, 0xcf, 0x87, 0x78,
    0xcf, 0x10, 0x0, 0x0, 0x4, 0xdf, 0xff, 0xfe,
    0x70,

    /* U+9009 "选" */
    0x4, 0x40, 0x0, 0x18, 0x27, 0xf0, 0x0, 0x0,
    0x8, 0xf7, 0x0, 0x7f, 0x5a, 0xf5, 0x44, 0x20,
    0x0, 0x8f, 0x41, 0xef, 0xff, 0xff, 0xff, 0x70,
    0x0, 0x5, 0xa, 0xe1, 0x7, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x30, 0x7, 0xf0, 0x0, 0x0,
    0x5, 0x55, 0xc, 0xee, 0xef, 0xfe, 0xee, 0xe2,
    0x1f, 0xff, 0x25, 0x58, 0xf9, 0x8f, 0x85, 0x51,
    0x0, 0x4f, 0x20, 0x6, 0xf2, 0x3f, 0x30, 0x0,
    0x0, 0x3f, 0x20, 0xd, 0xd0, 0x3f, 0x30, 0x71,
    0x0, 0x3f, 0x21, 0xaf, 0x50, 0x3f, 0x31, 0xf4,
    0x0, 0x3f, 0x3e, 0xf6, 0x0, 0x1f, 0xff, 0xf1,
    0x0, 0x7f, 0xc7, 0x10, 0x0, 0x3, 0x66, 0x30,
    0xa, 0xfb, 0xbf, 0xc7, 0x65, 0x55, 0x67, 0x83,
    0xd, 0x80, 0x4, 0xae, 0xff, 0xff, 0xff, 0xe1,
    0x1, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 256, .box_w = 16, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 120, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 233, .adv_w = 256, .box_w = 16, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 345, .adv_w = 256, .box_w = 16, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 473, .adv_w = 256, .box_w = 16, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 601, .adv_w = 256, .box_w = 16, .box_h = 15, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 721, .adv_w = 256, .box_w = 16, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 849, .adv_w = 256, .box_w = 16, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 977, .adv_w = 256, .box_w = 16, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1105, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1210, .adv_w = 256, .box_w = 16, .box_h = 15, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xed, 0x51f, 0xd5d, 0x11a0, 0x125e, 0x1bf8, 0x1ce0,
    0x1e77, 0x23ec, 0x3ec0
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 20809, .range_length = 16065, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 11, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t my_font = {
#else
lv_font_t my_font = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */

    .user_data = NULL,
};



#endif /*#if MY_FONT*/
