/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void screen_btn_tmp_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_tmp, guider_ui.screen_tmp_del, &guider_ui.screen_del, setup_scr_screen_tmp, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, true, true);
		//ui_load_scr_animation(&guider_ui, &guider_ui.screen_start, guider_ui.screen_start_del, &guider_ui.screen_del, setup_scr_screen_start, LV_SCR_LOAD_ANIM_NONE, 0, 0,  false, true);
		break;
	}
	default:
		break;
	}
}
static void screen_btn_cur_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_cur, guider_ui.screen_cur_del, &guider_ui.screen_del, setup_scr_screen_cur, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}

static void screen_btn_start_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.screen_start_del, setup_scr_screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}

static void screen_tmp_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_start_base, guider_ui.screen_start_del, &guider_ui.screen_start_del, setup_scr_screen_start, LV_SCR_LOAD_ANIM_NONE, 100, 100, true, true);
		break;
	}
	default:
		break;
	}
}



void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_btn_tmp, screen_btn_tmp_event_handler, LV_EVENT_CLICKED, ui);
	lv_obj_add_event_cb(ui->screen_btn_cur, screen_btn_cur_event_handler, LV_EVENT_CLICKED, ui);
}

void events_init_screen_start(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_start_btn_1, screen_btn_start_event_handler, LV_EVENT_CLICKED, ui);
}

void events_init_screen_tmp(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_tmp_btn_1, screen_tmp_btn_1_event_handler, LV_EVENT_CLICKED, ui);
 
}



void events_init(lv_ui *ui)
{

}
