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
	if (LV_EVENT_VALUE_CHANGED == code && obj == guider_ui.screen_cur_label_setcur)
	{
		adc_value = adc_get(ADC_IN_PIN);                                                      /* 读取GPIO8引脚的ADC值 */
 
        adc_vol = (float)adc_value * 3.3 / 4095;    
		lv_label_set_text_fmt(obj , "%f\r\n" , adc_vol );

		Serial.printf("ADC V :%f\r\n " , adc_vol);

		/* code */
	}
	
}



void setup_scr_screen_cur(lv_ui *ui)
{
	//Write codes screen_cur
	ui->screen_cur = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_cur, 240, 320);
	lv_obj_set_scrollbar_mode(ui->screen_cur, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cur, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_cur, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cur, lv_palette_main(LV_PALETTE_YELLOW), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cur, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_1
	ui->screen_cur_label_1 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_1, "电流控制");
	lv_label_set_long_mode(ui->screen_cur_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_1, 50, 3);
	lv_obj_set_size(ui->screen_cur_label_1, 144, 38);

	//Write style for screen_cur_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_1, &my_font, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_1, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cur_label_1, lv_color_hex(0x00ffd2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cur_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_2
	ui->screen_cur_label_2 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_2, "设定电流:");
	lv_label_set_long_mode(ui->screen_cur_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_2, 4, 89);
	lv_obj_set_size(ui->screen_cur_label_2, 99, 19);

	//Write style for screen_cur_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_2, &my_font, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_3
	ui->screen_cur_label_3 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_3, "实际电流:");
	lv_label_set_long_mode(ui->screen_cur_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_3, 4, 148);
	lv_obj_set_size(ui->screen_cur_label_3, 99, 19);

	//Write style for screen_cur_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_3, &my_font, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_4
	ui->screen_cur_label_4 = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_4, "输出状态:");
	lv_label_set_long_mode(ui->screen_cur_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_4, 4, 237);
	lv_obj_set_size(ui->screen_cur_label_4, 99, 19);

	//Write style for screen_cur_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_4, &my_font, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_setcur
	ui->screen_cur_label_setcur = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_setcur, "##");
	lv_label_set_long_mode(ui->screen_cur_label_setcur, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_setcur, 100, 89);
	lv_obj_set_size(ui->screen_cur_label_setcur, 99, 19);

	//Write style for screen_cur_label_setcur, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_setcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_setcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_setcur, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_setcur, LV_FONT_DEFAULT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_setcur, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_setcur, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_setcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_setcur, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_setcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_setcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_setcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_setcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_setcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_setcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);


	//    event 

	lv_obj_add_event_cb(ui->screen_cur_label_setcur , event_set_value_handler, LV_EVENT_VALUE_CHANGED , NULL);

	//Write codes screen_cur_label_realcur
	ui->screen_cur_label_realcur = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_realcur, "##");
	lv_label_set_long_mode(ui->screen_cur_label_realcur, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_realcur, 98, 148);
	lv_obj_set_size(ui->screen_cur_label_realcur, 99, 19);

	//Write style for screen_cur_label_realcur, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_realcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_realcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_realcur, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_realcur, LV_FONT_DEFAULT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_realcur, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_realcur, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_realcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_realcur, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_realcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_realcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_realcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_realcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_realcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_realcur, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cur_label_status
	ui->screen_cur_label_status = lv_label_create(ui->screen_cur);
	lv_label_set_text(ui->screen_cur_label_status, "##");
	lv_label_set_long_mode(ui->screen_cur_label_status, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_cur_label_status, 95, 237);
	lv_obj_set_size(ui->screen_cur_label_status, 99, 19);

	//Write style for screen_cur_label_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cur_label_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cur_label_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_cur_label_status, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cur_label_status, LV_FONT_DEFAULT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cur_label_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cur_label_status, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_cur_label_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cur_label_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cur_label_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cur_label_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cur_label_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cur_label_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cur_label_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cur_label_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen_cur.
	

	extern lv_indev_t * indev_keypad ; 
	lv_group_t * group = lv_group_create();
	lv_indev_set_group(indev_keypad, group);
	lv_group_set_editing(group , false);
	// lv_group_add_obj(group, ui->screen_btn_cur);
	// lv_group_add_obj(group, ui->screen_btn_tmp);






	//Update current screen layout.
	lv_obj_update_layout(ui->screen_cur);

}
