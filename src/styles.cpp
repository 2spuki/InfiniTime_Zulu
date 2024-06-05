#include "lvgl.h"

lv_style_t your_custom_style;

void init_styles() {
    lv_style_init(&your_custom_style);
    lv_style_set_text_font(&your_custom_style, LV_STATE_DEFAULT, &lv_font_montserrat_22);
    lv_style_set_text_color(&your_custom_style, LV_STATE_DEFAULT, lv_color_hex(0xFFFFFF));  // White color
}
