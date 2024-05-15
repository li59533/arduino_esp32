
#include <lvgl.h>
#include "demos/lv_demos.h"
#include <TFT_eSPI.h>

#include "spi_sdcard.h"
#include "led.h"
#include "uart.h"

#include "gui_guider.h"
#include "my_gui.h"

#include "FreeRTOS.h"

lv_ui guider_ui;

/*Change to your screen resolution*/
static const uint16_t screenWidth = 320;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char *buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp_drv);
}

TaskHandle_t task_handle_first = NULL;
TaskHandle_t task_handle_sec = NULL;



static void task_first(void *parm);

void task_sec(void *parm);







void setup()
{

    led_init();
    uart_init(0, 115200); /* ??0??? */
    lv_init();

    tft.begin();        /* TFT init */
    tft.setRotation(2); /* Landscape orientation, flipped */

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenHeight;
    disp_drv.ver_res = screenWidth;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    // disp_drv.rotated = LV_DISP_ROT_270 ;
    lv_disp_drv_register(&disp_drv);

    while (sdcard_init()) /* ºÏ≤‚≤ªµΩSDø® */
    {
        delay(500);
        LED_TOGGLE(); /* ∫Ïµ∆…¡À∏ */
    }

    Serial.print("my_gui_start ");
    my_gui_start();

    xTaskCreate(
        task_first,
        "taskfirst",
        3 * 1024,
        NULL,
        4,
        &task_handle_first);

    xTaskCreate(
        task_sec,
        "tasksec",
        3 * 1024,
        NULL,
        4,
        &task_handle_sec);
}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay(5);
}

void task_first(void *parm)
{
    while (1)
    {
        Serial.print("task_first\r\n ");
        delay(1000);
        /* code */
    }
    
}

void task_sec(void *parm)
{

    while (1)
    {
        Serial.print("task_sec\r\n ");
        delay(5000);
        /* code */
    }

}
