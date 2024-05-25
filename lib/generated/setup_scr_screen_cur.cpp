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
#include "adc.h"
 


uint16_t adc_value = 0;
float adc_vol = 0;
 



static void event_set_value_handler(lv_event_t * e)
{
	lv_event_code_t code = lv_event_get_code(e) ;
	lv_obj_t * obj = lv_event_get_target(e) ; 
	if (LV_EVENT_VALUE_CHANGED == code && obj == guider_ui.screen_cur_label_4)
	{
		adc_value = adc_get(ADC_IN_PIN);                                                      /* 读取GPIO8引脚的ADC值 */
 
        adc_vol = (float)adc_value * 3.3 / 4095;    
		lv_label_set_text_fmt(obj , "%0.2f\r\n" , adc_vol );

		//Serial.printf("ADC V :%f\r\n " , adc_vol);

		/* code */
	}
	
}



void setup_scr_screen_cur(lv_ui *ui)
{

	//    event 





//Write codes screen
	ui->screen_cur = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_cur, 240, 320);
	lv_obj_set_scrollbar_mode(ui->screen_cur, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_cur, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cur, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cur, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_1
	ui->screen_cur_label_1 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_1, "激光控制器");
	lv_label_set_long_mode(ui->screen_cur_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_1, 4, 4);
	lv_obj_set_size(ui->screen_cur_label_1, 156, 26);

	//Write style for screen_cur_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_1, lv_color_hex(0xd8fa00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_1, &my_font_27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_2
	ui->screen_cur_label_2 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_2, "实际\n电流");
	lv_label_set_long_mode(ui->screen_cur_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_2, 9, 47);
	lv_obj_set_size(ui->screen_cur_label_2, 47, 42);

	//Write style for screen_cur_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_2, &my_font_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_3
	ui->screen_cur_label_3 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_3, "设定\n电流");
	lv_label_set_long_mode(ui->screen_cur_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_3, 9, 100);
	lv_obj_set_size(ui->screen_cur_label_3, 47, 42);

	//Write style for screen_cur_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_3, lv_color_hex(0x0dff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_3, &my_font_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_4
	ui->screen_cur_label_4 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_4, "00.00");
	lv_label_set_long_mode(ui->screen_cur_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_4, 62, 51);
	lv_obj_set_size(ui->screen_cur_label_4, 127, 38);

	//Write style for screen_cur_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_4, &lv_font_montserrat_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);


	lv_obj_add_event_cb(ui->screen_cur_label_4 , event_set_value_handler, LV_EVENT_VALUE_CHANGED , NULL);






	//Write codes screen_cur_label_5
	ui->screen_cur_label_5 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_5, "mA");
	lv_label_set_long_mode(ui->screen_cur_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_5, 194, 66);
	lv_obj_set_size(ui->screen_cur_label_5, 44, 23);

	//Write style for screen_cur_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_5, &lv_font_montserrat_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_spinbox_1
	ui->screen_cur_spinbox_1 = lv_spinbox_create(ui->screen_cur);
	lv_obj_set_pos(ui->screen_cur_spinbox_1, 105, 104);
	lv_obj_set_width(ui->screen_cur_spinbox_1, 83);
	lv_obj_set_height(ui->screen_cur_spinbox_1, 38);
	lv_spinbox_set_digit_format(ui->screen_cur_spinbox_1, 4, 2);
	lv_spinbox_set_range(ui->screen_cur_spinbox_1, -9999, 9999);
	lv_coord_t screen_cur_spinbox_1_h = lv_obj_get_height(ui->screen_cur_spinbox_1);
	ui->screen_cur_spinbox_1_btn = lv_btn_create(ui->screen);
	lv_obj_set_size(ui->screen_cur_spinbox_1_btn, screen_cur_spinbox_1_h, screen_cur_spinbox_1_h);
	lv_obj_align_to(ui->screen_cur_spinbox_1_btn, ui->screen_cur_spinbox_1, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_cur_spinbox_1_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->screen_cur_spinbox_1_btn, lv_screen_cur_spinbox_1_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->screen_cur_spinbox_1_btn_minus = lv_btn_create(ui->screen);
	lv_obj_set_size(ui->screen_cur_spinbox_1_btn_minus, screen_cur_spinbox_1_h, screen_cur_spinbox_1_h);
	lv_obj_align_to(ui->screen_cur_spinbox_1_btn_minus, ui->screen_cur_spinbox_1, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_cur_spinbox_1_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->screen_cur_spinbox_1_btn_minus, lv_screen_cur_spinbox_1_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->screen_cur_spinbox_1, 105, 104);

	//Write style for screen_cur_spinbox_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_cur_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cur_spinbox_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cur_spinbox_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_cur_spinbox_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cur_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cur_spinbox_1, lv_color_hex(0x1bde17), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cur_spinbox_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_spinbox_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_spinbox_1, &my_font_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_spinbox_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_cur_spinbox_1, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_cur_spinbox_1, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_spinbox_1, &lv_font_montserrat_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_spinbox_1, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_spinbox_1, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cur_spinbox_1, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cur_spinbox_1, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_cur_spinbox_1_extra_btns_main_default
	static lv_style_t style_screen_cur_spinbox_1_extra_btns_main_default;
	ui_init_style(&style_screen_cur_spinbox_1_extra_btns_main_default);
	
	lv_style_set_text_color(&style_screen_cur_spinbox_1_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_cur_spinbox_1_extra_btns_main_default, &lv_font_montserrat_12);
	lv_style_set_text_opa(&style_screen_cur_spinbox_1_extra_btns_main_default, 255);
	lv_style_set_bg_opa(&style_screen_cur_spinbox_1_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_cur_spinbox_1_extra_btns_main_default, lv_color_hex(0x2195f6));
	lv_style_set_bg_grad_dir(&style_screen_cur_spinbox_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_screen_cur_spinbox_1_extra_btns_main_default, 0);
	lv_style_set_radius(&style_screen_cur_spinbox_1_extra_btns_main_default, 5);
	lv_obj_add_style(ui->screen_cur_spinbox_1_btn, &style_screen_cur_spinbox_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_cur_spinbox_1_btn_minus, &style_screen_cur_spinbox_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_line_1
	ui->screen_cur_line_1 = lv_line_create(ui->screen_cur);
	static lv_point_t screen_cur_line_1[] ={{0, 0},{0, 60},};
	lv_line_set_points(ui->screen_cur_line_1, screen_cur_line_1, 2);
	lv_obj_set_pos(ui->screen_cur_line_1, 56, 61);
	lv_obj_set_size(ui->screen_cur_line_1, 4, 73);

	//Write style for screen_cur_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->screen_cur_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->screen_cur_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->screen_cur_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->screen_cur_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_line_2
	ui->screen_cur_line_2 = lv_line_create(ui->screen_cur);
	static lv_point_t screen_cur_line_2[] ={{0, 0},{200, 0},};
	lv_line_set_points(ui->screen_cur_line_2, screen_cur_line_2, 2);
	lv_obj_set_pos(ui->screen_cur_line_2, 21, 94);
	lv_obj_set_size(ui->screen_cur_line_2, 204, 1);

	//Write style for screen_cur_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->screen_cur_line_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->screen_cur_line_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->screen_cur_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->screen_cur_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_sw_1
	ui->screen_cur_sw_1 = lv_switch_create(ui->screen_cur);
	lv_obj_set_pos(ui->screen_cur_sw_1, 163, 154);
	lv_obj_set_size(ui->screen_cur_sw_1, 62, 25);

	//Write style for screen_cur_sw_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_cur_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cur_sw_1, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cur_sw_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_cur_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_sw_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_cur_sw_1, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screen_cur_sw_1, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_cur_sw_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_cur_sw_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_cur_sw_1, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screen_cur_sw_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_cur_sw_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cur_sw_1, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cur_sw_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_cur_sw_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_sw_1, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_6
	ui->screen_cur_label_6 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_6, "温度信息");
	lv_label_set_long_mode(ui->screen_cur_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_6, 6, 179);
	lv_obj_set_size(ui->screen_cur_label_6, 91, 20);

	//Write style for screen_cur_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_6, &my_font_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_7
	ui->screen_cur_label_7 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_7, "芯片");
	lv_label_set_long_mode(ui->screen_cur_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_7, 6, 218);
	lv_obj_set_size(ui->screen_cur_label_7, 47, 23);

	//Write style for screen_cur_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_7, &my_font_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_8
	ui->screen_cur_label_8 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_8, "激光器");
	lv_label_set_long_mode(ui->screen_cur_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_8, 6, 256);
	lv_obj_set_size(ui->screen_cur_label_8, 71, 23);

	//Write style for screen_cur_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_8, &my_font_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_9
	ui->screen_cur_label_9 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_9, "00.00");
	lv_label_set_long_mode(ui->screen_cur_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_9, 81, 210);
	lv_obj_set_size(ui->screen_cur_label_9, 113, 27);

	//Write style for screen_cur_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_9, &lv_font_montserrat_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_9, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_10
	ui->screen_cur_label_10 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_10, "00.00");
	lv_label_set_long_mode(ui->screen_cur_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_10, 81, 249);
	lv_obj_set_size(ui->screen_cur_label_10, 113, 27);

	//Write style for screen_cur_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_10, &lv_font_montserrat_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_10, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_11
	ui->screen_cur_label_11 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_11, "°");
	lv_label_set_long_mode(ui->screen_cur_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_11, 189, 218);
	lv_obj_set_size(ui->screen_cur_label_11, 8, 11);

	//Write style for screen_cur_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_11, &lv_font_montserrat_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_11, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_11, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_12
	ui->screen_cur_label_12 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_12, "°");
	lv_label_set_long_mode(ui->screen_cur_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_12, 189, 249);
	lv_obj_set_size(ui->screen_cur_label_12, 8, 11);

	//Write style for screen_cur_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_12, &lv_font_montserrat_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_12, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_line_3
	ui->screen_cur_line_3 = lv_line_create(ui->screen_cur);
	static lv_point_t screen_cur_line_3[] ={{0, 0},{200, 0},};
	lv_line_set_points(ui->screen_cur_line_3, screen_cur_line_3, 2);
	lv_obj_set_pos(ui->screen_cur_line_3, 12, 245);
	lv_obj_set_size(ui->screen_cur_line_3, 204, 1);

	//Write style for screen_cur_line_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->screen_cur_line_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->screen_cur_line_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->screen_cur_line_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->screen_cur_line_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_line_4
	ui->screen_cur_line_4 = lv_line_create(ui->screen_cur);
	static lv_point_t screen_cur_line_4[] ={{0, 0},{0, 60},};
	lv_line_set_points(ui->screen_cur_line_4, screen_cur_line_4, 2);
	lv_obj_set_pos(ui->screen_cur_line_4, 77, 214);
	lv_obj_set_size(ui->screen_cur_line_4, 4, 73);

	//Write style for screen_cur_line_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->screen_cur_line_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->screen_cur_line_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->screen_cur_line_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->screen_cur_line_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_btn_1
	ui->screen_cur_btn_1 = lv_btn_create(ui->screen_cur);
	ui->screen_cur_btn_1_label = lv_label_create(ui->screen_cur_btn_1);
	lv_label_set_text(ui->screen_cur_btn_1_label, "其他");
	lv_label_set_long_mode(ui->screen_cur_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_cur_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_cur_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_cur_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_cur_btn_1, 140, 282);
	lv_obj_set_size(ui->screen_cur_btn_1, 94, 31);

	//Write style for screen_cur_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_cur_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cur_btn_1, lv_color_hex(0x082842), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cur_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_cur_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_btn_1, &my_font_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_led_1
	ui->screen_cur_led_1 = lv_led_create(ui->screen_cur);
	lv_led_set_brightness(ui->screen_cur_led_1, 255);
	lv_led_set_color(ui->screen_cur_led_1, lv_color_hex(0x00a1b5));
	lv_obj_set_pos(ui->screen_cur_led_1, 191, 7);
	lv_obj_set_size(ui->screen_cur_led_1, 40, 40);





























	extern lv_indev_t * indev_keypad ; 
	lv_group_t * group = lv_group_create();
	lv_indev_set_group(indev_keypad, group);
	lv_group_set_editing(group , false);
	// lv_group_add_obj(group, ui->screen_cur_btn_cur);
	// lv_group_add_obj(group, ui->screen_cur_btn_tmp);






	//Update current screen layout.
	lv_obj_update_layout(ui->screen_cur);

}
