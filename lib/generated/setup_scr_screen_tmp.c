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



void setup_scr_screen_tmp(lv_ui *ui)
{
	//Write codes screen_tmp
	ui->screen_tmp = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_tmp, 240, 320);
	lv_obj_set_scrollbar_mode(ui->screen_tmp, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_tmp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_tmp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_tmp, lv_color_hex(0x0093ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_tmp, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_tmp_label_1
	ui->screen_tmp_label_1 = lv_label_create(ui->screen_tmp);
	lv_label_set_text(ui->screen_tmp_label_1, "温度控制界面");
	lv_label_set_long_mode(ui->screen_tmp_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_tmp_label_1, 50, 3);
	lv_obj_set_size(ui->screen_tmp_label_1, 144, 38);

	//Write style for screen_tmp_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_tmp_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_tmp_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_tmp_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_tmp_label_1, &my_font, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_tmp_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_tmp_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_tmp_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_tmp_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_tmp_label_1, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_tmp_label_1, lv_color_hex(0x00ffd2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_tmp_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_tmp_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_tmp_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_tmp_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_tmp_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_tmp_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_tmp_btn_1
	ui->screen_tmp_btn_1 = lv_btn_create(ui->screen_tmp);
	ui->screen_tmp_btn_1_label = lv_label_create(ui->screen_tmp_btn_1);
	lv_label_set_text(ui->screen_tmp_btn_1_label, "主芯片温度控制");
	lv_label_set_long_mode(ui->screen_tmp_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_tmp_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_tmp_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_tmp_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_tmp_btn_1, 48, 46);
	lv_obj_set_size(ui->screen_tmp_btn_1, 145, 85);

	//Write style for screen_tmp_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_tmp_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_tmp_btn_1, lv_color_hex(0x086631), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_tmp_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_tmp_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_tmp_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_tmp_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_tmp_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_tmp_btn_1, &my_font, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_tmp_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_tmp_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_tmp_btn_2
	ui->screen_tmp_btn_2 = lv_btn_create(ui->screen_tmp);
	ui->screen_tmp_btn_2_label = lv_label_create(ui->screen_tmp_btn_2);
	lv_label_set_text(ui->screen_tmp_btn_2_label, "激光器温度控制");
	lv_label_set_long_mode(ui->screen_tmp_btn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_tmp_btn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_tmp_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_tmp_btn_2_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_tmp_btn_2, 48, 136);
	lv_obj_set_size(ui->screen_tmp_btn_2, 145, 85);

	//Write style for screen_tmp_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_tmp_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_tmp_btn_2, lv_color_hex(0x086631), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_tmp_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_tmp_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_tmp_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_tmp_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_tmp_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_tmp_btn_2, &my_font, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_tmp_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_tmp_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_tmp_btn_3
	ui->screen_tmp_btn_3 = lv_btn_create(ui->screen_tmp);
	ui->screen_tmp_btn_3_label = lv_label_create(ui->screen_tmp_btn_3);
	lv_label_set_text(ui->screen_tmp_btn_3_label, "备用芯片温度控制");
	lv_label_set_long_mode(ui->screen_tmp_btn_3_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_tmp_btn_3_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_tmp_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_tmp_btn_3_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_tmp_btn_3, 48, 226);
	lv_obj_set_size(ui->screen_tmp_btn_3, 145, 85);

	//Write style for screen_tmp_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_tmp_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_tmp_btn_3, lv_color_hex(0x086631), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_tmp_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_tmp_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_tmp_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_tmp_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_tmp_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_tmp_btn_3, &my_font, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_tmp_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_tmp_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen_tmp.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_tmp);

}
