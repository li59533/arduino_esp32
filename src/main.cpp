
#include <lvgl.h>
#include "demos/lv_demos.h"
#include <TFT_eSPI.h>

#include "spi_sdcard.h"
#include "led.h"
#include "uart.h"

#include "gui_guider.h"
#include "my_gui.h"
lv_ui guider_ui ;






/*Change to your screen resolution*/
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight ];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp_drv );
}



void setup()
{

    led_init();
    uart_init(0, 115200);   /* ??0??? */
    lv_init();



    tft.begin();          /* TFT init */
    tft.setRotation( 2 ); /* Landscape orientation, flipped */



    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * screenHeight  );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenHeight ;
    disp_drv.ver_res = screenWidth ;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    //disp_drv.rotated = LV_DISP_ROT_270 ; 
    lv_disp_drv_register( &disp_drv );

  
    // /* Create simple label */
    // lv_obj_t *label = lv_label_create( lv_scr_act() );
    // lv_label_set_text( label, "Hello Ardino and LVGL!");
    // lv_obj_align( label, LV_ALIGN_CENTER, 0, 0 );
 
    /* Try an example. See all the examples 
     * online: https://docs.lvgl.io/master/examples.html
     * source codes: https://github.com/lvgl/lvgl/tree/e7f88efa5853128bf871dde335c0ca8da9eb7731/examples */
     //lv_example_btn_1();
   
     /*Or try out a demo. Don't forget to enable the demos in lv_conf.h. E.g. LV_USE_DEMOS_WIDGETS*/
    //lv_demo_widgets();               
    //lv_demo_benchmark();          
    // lv_demo_keypad_encoder();     
    // lv_demo_music();              
    // lv_demo_printer();
    // lv_demo_stress();

    // setup_ui(&guider_ui);
    

    while (sdcard_init())    /* ºÏ≤‚≤ªµΩSDø® */    
    {

        delay(500);
        LED_TOGGLE();       /* ∫Ïµ∆…¡À∏ */
    }

    Serial.print("my_gui_start ");
    my_gui_start();


}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay( 5 );
}
