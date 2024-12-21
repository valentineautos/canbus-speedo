/*******************************************************************************
 * Size: 40 px
 * Bpp: 1
 * Opts: --bpp 1 --size 40 --no-compress --font fa-solid-900.woff --range 63423,61528 --format lvgl -o font_awesome_icons.c
 ******************************************************************************/
#ifndef FONT_AWESOME_ICONS
#define FONT_AWESOME_ICONS 1
#endif

#if FONT_AWESOME_ICONS

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap_fa[] = {
    /* U+F058 "" */
    0x0, 0x1, 0xff, 0x0, 0x0, 0x0, 0x1f, 0xff,
    0xc0, 0x0, 0x0, 0xff, 0xff, 0xe0, 0x0, 0x7,
    0xff, 0xff, 0xf0, 0x0, 0x1f, 0xff, 0xff, 0xf0,
    0x0, 0x7f, 0xff, 0xff, 0xf0, 0x1, 0xff, 0xff,
    0xff, 0xf0, 0x7, 0xff, 0xff, 0xff, 0xf0, 0x1f,
    0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff,
    0xff, 0xff, 0xc7, 0xff, 0xff, 0xfe, 0x3f, 0xcf,
    0xff, 0xff, 0xf8, 0x3f, 0x9f, 0xff, 0xff, 0xe0,
    0x3f, 0x7f, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff,
    0xfe, 0x3, 0xff, 0xff, 0xff, 0xf8, 0xf, 0xff,
    0xfe, 0x7f, 0xe0, 0x3f, 0xff, 0xf8, 0x7f, 0x80,
    0xff, 0xff, 0xe0, 0x7e, 0x3, 0xff, 0xff, 0xc0,
    0x78, 0xf, 0xff, 0xff, 0xc0, 0x60, 0x3f, 0xff,
    0xff, 0xc0, 0x0, 0xff, 0xff, 0x7f, 0xc0, 0x3,
    0xff, 0xfc, 0xff, 0xc0, 0xf, 0xff, 0xf9, 0xff,
    0xc0, 0x3f, 0xff, 0xf1, 0xff, 0xc0, 0xff, 0xff,
    0xc3, 0xff, 0xc3, 0xff, 0xff, 0x83, 0xff, 0xcf,
    0xff, 0xfe, 0x7, 0xff, 0xff, 0xff, 0xfc, 0x7,
    0xff, 0xff, 0xff, 0xf0, 0x7, 0xff, 0xff, 0xff,
    0xc0, 0x7, 0xff, 0xff, 0xff, 0x0, 0x7, 0xff,
    0xff, 0xfc, 0x0, 0x7, 0xff, 0xff, 0xf0, 0x0,
    0x3, 0xff, 0xff, 0x80, 0x0, 0x1, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x7f, 0xc0, 0x0, 0x0,

    /* U+F7BF "" */
    0x0, 0x0, 0xe0, 0x0, 0x0, 0x0, 0x1, 0xf0,
    0x0, 0x0, 0x0, 0x3, 0xf8, 0x0, 0x0, 0x0,
    0x7, 0xfc, 0x7, 0x80, 0x0, 0xf, 0xfe, 0xf,
    0xc0, 0x0, 0x1f, 0x3f, 0x1f, 0xe0, 0x0, 0x3e,
    0x1f, 0xbf, 0xf0, 0x0, 0x7c, 0xf, 0xff, 0xf8,
    0x0, 0xf8, 0x7, 0xff, 0xf8, 0x1, 0xf0, 0x3,
    0xff, 0xf8, 0x1, 0xf0, 0x3, 0xff, 0xf8, 0x0,
    0xf8, 0x7, 0xff, 0xf0, 0x0, 0xfc, 0xf, 0xff,
    0xe0, 0x0, 0x7e, 0x1f, 0xff, 0xc0, 0x0, 0x3f,
    0x3f, 0xff, 0x80, 0x0, 0x1f, 0xff, 0xff, 0xc0,
    0x0, 0xf, 0xff, 0xff, 0xe0, 0x0, 0x7, 0xff,
    0xff, 0xf0, 0x1f, 0xf3, 0xff, 0xf9, 0xf8, 0xff,
    0xff, 0xff, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0xe0,
    0x7e, 0xff, 0xff, 0xff, 0xc0, 0x3e, 0x7f, 0xff,
    0xff, 0x80, 0x1f, 0x3f, 0xff, 0xff, 0x80, 0x1f,
    0x1f, 0xff, 0xff, 0xc0, 0x3e, 0xf, 0xff, 0xff,
    0xe0, 0x7c, 0x7, 0xff, 0xf9, 0xf0, 0xf8, 0x3,
    0xff, 0xf8, 0xf9, 0xf0, 0x1, 0xff, 0xfc, 0xff,
    0xe0, 0x0, 0xff, 0xfc, 0x7f, 0xc0, 0x0, 0xff,
    0xfc, 0x3f, 0x80, 0x7, 0xff, 0xfc, 0x1f, 0x0,
    0xf, 0x9f, 0xfc, 0x6, 0x0, 0xf, 0x8f, 0xfc,
    0x0, 0x0, 0xf, 0x87, 0xfc, 0x0, 0x0, 0x7,
    0x3, 0xfc, 0x0, 0x0, 0x0, 0x1, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x78, 0x0, 0x0, 0x0, 0x0, 0x38, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_fa[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 640, .box_w = 39, .box_h = 39, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 191, .adv_w = 640, .box_w = 40, .box_h = 40, .ofs_x = 0, .ofs_y = -5}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0_fa[] = {
    0x0, 0x767
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps_fa[] =
{
    {
        .range_start = 61528, .range_length = 1896, .glyph_id_start = 1,
        .unicode_list = unicode_list_0_fa, .glyph_id_ofs_list = NULL, .list_length = 2, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache_fa;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc_fa = {
#else
static lv_font_fmt_txt_dsc_t font_dsc_fa = {
#endif
    .glyph_bitmap = glyph_bitmap_fa,
    .glyph_dsc = glyph_dsc_fa,
    .cmaps = cmaps_fa,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache_fa
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t font_awesome_icons = {
#else
lv_font_t font_awesome_icons = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 40,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if FONT_AWESOME_ICONS*/

