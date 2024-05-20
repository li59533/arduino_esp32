/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"
#include "my_gui.h"


void setup_scr_screen_start(lv_ui *ui)
{
 

    LV_IMG_DECLARE(start5);


	//Write codes screen
	ui->screen_start_base = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_start_base, 240, 320);
	lv_obj_set_scrollbar_mode(ui->screen_start_base, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_start_base, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	// lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0x0093ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_start_base, lv_palette_main(LV_PALETTE_YELLOW), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_start_base, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

 

    // ui->screen_start = lv_gif_create(lv_scr_act());
    ui->screen_start = lv_gif_create(ui->screen_start_base);
    //lv_obj_set_style_bg_color(ui->screen_start, lv_palette_main(LV_PALETTE_BLUE), LV_STATE_DEFAULT);
    
    lv_gif_set_src(ui->screen_start, &start5);
    lv_obj_align_to(ui->screen_start, NULL, LV_ALIGN_CENTER, 0, 0);

  

	//Write codes screen_start_btn_1
	ui->screen_start_btn_1 = lv_btn_create(ui->screen_start_base);
	ui->screen_start_btn_1_label = lv_label_create(ui->screen_start_btn_1);
	lv_label_set_text(ui->screen_start_btn_1_label, "进入系统");
	lv_label_set_long_mode(ui->screen_start_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_start_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_start_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_start_btn_1_label, LV_PCT(50));
	lv_obj_set_pos(ui->screen_start_btn_1, 148, 246);
	lv_obj_set_size(ui->screen_start_btn_1, 50, 30);

	//Write style for screen_start_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_start_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_start_btn_1, lv_color_hex(0x086631), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_start_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_start_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_start_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_start_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_start_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_start_btn_1, &my_font, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_start_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_start_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

 


	//The custom code of screen_tmp.
	extern lv_indev_t * indev_keypad ; 
	lv_group_t * group = lv_group_create();
	lv_indev_set_group(indev_keypad, group);
	lv_group_set_editing(group , false);
	lv_group_add_obj(group, ui->screen_start_btn_1);
 
 
	//Update current screen layout.
	lv_obj_update_layout(ui->screen_start_base);



    events_init_screen_start(ui);

}
