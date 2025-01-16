/*******************************************************************************
 * Size: 24 px
 * Bpp: 1
 * Opts: --bpp 1 --size 24 --no-compress --font UbuntuCondensed-Regular.ttf --symbols 0123456789mph --format lvgl -o ubuntu_24.c
 ******************************************************************************/

#ifndef UBUNTU_24
#define UBUNTU_24 1
#endif

#if UBUNTU_24

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap_u_24[] = {
    /* U+0030 "0" */
    0x3c, 0x7e, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x7e,
    0x3c,

    /* U+0031 "1" */
    0x19, 0xdf, 0xf5, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x63, 0x18,

    /* U+0032 "2" */
    0x79, 0xfa, 0x38, 0x30, 0x60, 0xc3, 0x6, 0x18,
    0x30, 0xc3, 0x6, 0x1c, 0x30, 0x7f, 0xfe,

    /* U+0033 "3" */
    0x79, 0xf8, 0x38, 0x30, 0x60, 0xc3, 0x3e, 0x7c,
    0x1c, 0x18, 0x30, 0x60, 0xe3, 0xfe, 0x78,

    /* U+0034 "4" */
    0x6, 0x7, 0x7, 0x83, 0xc1, 0x61, 0xb0, 0x98,
    0xcc, 0x66, 0x23, 0x31, 0x9f, 0xff, 0xf8, 0x30,
    0x18, 0xc, 0x6, 0x0,

    /* U+0035 "5" */
    0x7e, 0xfd, 0x83, 0x6, 0xc, 0x18, 0x3c, 0x1c,
    0x1c, 0x18, 0x30, 0x60, 0xc3, 0x7e, 0xf8,

    /* U+0036 "6" */
    0xe, 0x1e, 0x30, 0x60, 0x60, 0xc0, 0xfc, 0xfe,
    0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x67, 0x7e,
    0x3c,

    /* U+0037 "7" */
    0xff, 0xff, 0x7, 0x6, 0x6, 0xc, 0xc, 0xc,
    0x18, 0x18, 0x18, 0x18, 0x10, 0x30, 0x30, 0x30,
    0x30,

    /* U+0038 "8" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0x66, 0x7e,
    0x3c, 0x6e, 0xc7, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e,
    0x3c,

    /* U+0039 "9" */
    0x3c, 0x7e, 0xe6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xe3, 0x7f, 0x3f, 0x3, 0x6, 0x6, 0xc, 0x78,
    0x70,

    /* U+0068 "h" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xfe,
    0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3,

    /* U+006D "m" */
    0x7c, 0xf3, 0xff, 0xec, 0x71, 0xf0, 0xc3, 0xc3,
    0xf, 0xc, 0x3c, 0x30, 0xf0, 0xc3, 0xc3, 0xf,
    0xc, 0x3c, 0x30, 0xf0, 0xc3, 0xc3, 0xc,

    /* U+0070 "p" */
    0xf8, 0xfe, 0xc6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc6, 0xfe, 0xfc, 0xc0, 0xc0, 0xc0,
    0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_u_24[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 165, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 165, .box_w = 5, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 165, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 165, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 165, .box_w = 9, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 165, .box_w = 7, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 165, .box_w = 8, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 165, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 127, .adv_w = 165, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 165, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 185, .box_w = 8, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 268, .box_w = 14, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 179, .box_w = 8, .box_h = 17, .ofs_x = 2, .ofs_y = -4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1_u_24[] = {
    0x0, 0x5, 0x8
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps_u_24[] =
{
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 104, .range_length = 9, .glyph_id_start = 11,
        .unicode_list = unicode_list_1_u_24, .glyph_id_ofs_list = NULL, .list_length = 3, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache_u_24;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc_u_24 = {
#else
static lv_font_fmt_txt_dsc_t font_dsc_u_24 = {
#endif
    .glyph_bitmap = glyph_bitmap_u_24,
    .glyph_dsc = glyph_dsc_u_24,
    .cmaps = cmaps_u_24,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache_u_24
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ubuntu_24 = {
#else
lv_font_t ubuntu_24 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 23,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc_u_24,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UBUNTU_24*/

