
#include "my_gui.h"
#include "gui_guider.h"
#include "lvgl.h"
#include <stdio.h>


#include "spi_sdcard.h"

 
lv_obj_t *img;
 

 
 
// lv_ui lv_ui_v ; 
lv_ui guider_ui;

void my_gui_start(void)
{
 
 
    // LV_IMG_DECLARE(start5);

    // // // lv_obj_t *label;
    // // // label = lv_label_create(lv_scr_act());
    // // // lv_label_set_text(label, "测试");
    // // // lv_obj_set_style_text_color(label, lv_palette_main(LV_PALETTE_RED), LV_STATE_DEFAULT);
    // // // lv_obj_set_style_text_font(label, &lv_font_simsun_16_cjk, LV_STATE_DEFAULT);
    // // // lv_obj_align_to(label, NULL, LV_ALIGN_TOP_MID, 0, 0);
    // // // lv_obj_set_style_bg_color(lv_scr_act(), lv_palette_main(LV_PALETTE_BLUE), LV_STATE_DEFAULT);
  
    // lv_obj_set_style_bg_color(lv_scr_act(), lv_palette_main(LV_PALETTE_BLUE), LV_STATE_DEFAULT);
    // img = lv_gif_create(lv_scr_act());
    // lv_gif_set_src(img, &start5);
    // lv_obj_align_to(img, NULL, LV_ALIGN_CENTER, 0, 0);
 
    // delay(5000);
    setup_ui(&guider_ui);


}


















