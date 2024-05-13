
#include "my_gui.h"

#include "lvgl.h"
#include <stdio.h>


#include "spi_sdcard.h"


typedef struct
{
    char *img_path;
    char *label_text;
} img_info_t;


const img_info_t GIF_PATH[] =
{
    {"0:/PICTURE/start2.gif", "start2.gif"},   /* 解码GIF文件的尺寸不能太大 */
};

#define image_mun (int)(sizeof(GIF_PATH) / sizeof(GIF_PATH[0]))
int image = 0;
lv_obj_t *img;
extern int has_next;



/**
 * @brief       定时器函数
 * @param       timer：定时器
 * @retval      无
 */
void lv_my_timer(lv_timer_t *timer)
{ 
    if (has_next == 0)          /* 如果是最后一帧，那么切换GIF */
    {
        image++;
        lv_obj_del(img);        /* 删除前面的GIF */
      
        if (image >= image_mun) /* 判断GIF库包含的个数是否最大 */
        {
            image = 0;          /* 重新开始展示 */
            img = lv_gif_create(lv_scr_act());
            lv_gif_set_src(img, GIF_PATH[image].img_path);
        }
        else                    /* 如果不是最后的GIF */
        {
            img = lv_gif_create(lv_scr_act());
            lv_gif_set_src(img, GIF_PATH[image].img_path);
        }

        timer->user_data = img; /* 设置任务数据等于获取的图片数据 */

        lv_obj_align_to(img, NULL, LV_ALIGN_CENTER, 0, 0);
    }
}




long lv_tell(lv_fs_file_t *fd)
{
    uint32_t pos = 0;
    lv_fs_tell(fd, &pos);
    return pos;
}



/**
 * @brief  �ļ�ϵͳ����
 * @param  ��
 * @return ��
 */
static void lv_fs_test(void)
{
    char rbuf[30] = {0};    /* ��Ŷ�ȡ���ļ������� */
    uint32_t wsize = 0;     /* ��д�뵽�ļ����ݵ��ֽ��� */
    uint32_t rsize = 0;     /* ��ȡ���ļ����ݵ��ֽ��� */
    lv_fs_file_t fd;        /* �ļ�ϵͳ�ṹ����� */
    lv_fs_res_t res;        /* �ļ���������ֵ */

    /* д�����(ע���ļ����в��ܰ����»���) */
    res = lv_fs_open(&fd, "0:/lvgl.txt", LV_FS_MODE_WR);    /* ��дȨ�޴��ļ�,��SD��û�и��ļ����½� */
    if (res != LV_FS_RES_OK)
    {
        printf("open 0:/lvgl.txt ERROR\n");
        return ;
    }

    res = lv_fs_write(&fd, "hello_lvgl_123", 15, &wsize);   /* ��ɹ��򿪵��ļ�д������ */
    if (res != LV_FS_RES_OK)
    {
        printf("write /lvgl.txt fail\n");
        return ;
    }
    printf("write data to file succeed \n");                /* ������ʾ�Ѿ��ɹ�д�����ݵ��ļ��� */

    lv_fs_close(&fd);                                       /* �ر��ļ� */

    /* ��ȡ���� */
    res = lv_fs_open(&fd, "0:/lvgl.txt", LV_FS_MODE_RD);    /* �Զ�Ȩ�޴��ļ� */
    if (res != LV_FS_RES_OK)
    {
        printf("open 0:/lvgl.txt ERROR\n");
        return ;
    }

    lv_tell(&fd);                                           /* ��ȡ��дָ���λ�� */
    lv_fs_seek(&fd, 0, LV_FS_SEEK_SET);                     /* ���ö�дָ�뵽�ļ�ͷ�� */
    lv_tell(&fd);                                           /* ��ȡ��дָ���λ�� */

    res = lv_fs_read(&fd, rbuf, 100, &rsize);               /* ���Ѿ��ɹ��򿪵��ļ���ȡ�ļ����� */
    if (res != LV_FS_RES_OK)
    {
        printf("read ERROR\n");
        return ;
    }

    printf("file:lvgl.txt rd: %s \n", rbuf);                /* ������ʾ��ȡ�������� */

    lv_fs_close(&fd);                                       /* �ر��ļ� */
}





void my_gui_start(void)
{

    // lv_obj_t *label = lv_label_create(lv_scr_act());    /* ������ǩ */
    // lv_obj_set_style_text_font(label , &lv_font_simsun_16_cjk , LV_STATE_DEFAULT);
    // lv_label_set_text(label, "纳米好");             /* ��ʾ�ַ��� */
    // lv_obj_center(label);                               /* ���ж�����ʾ */
    // lv_fs_test();                                       /* �ļ�ϵͳ���� */

#if LV_USE_LABEL && LV_BUILD_EXAMPLES && LV_FONT_DEJAVU_16_PERSIAN_HEBREW && LV_FONT_SIMSUN_16_CJK && LV_USE_BIDI

    lv_obj_t * cz_label = lv_label_create(lv_scr_act());
    lv_label_set_text(cz_label,
                      "开机测试");
    lv_obj_set_style_text_font(cz_label, &lv_font_simsun_16_cjk, 0);
    lv_obj_set_width(cz_label, 310);
    lv_obj_align(cz_label, LV_ALIGN_BOTTOM_LEFT, 5, -5);

#endif

    LV_IMG_DECLARE(start5);

    lv_obj_t *label;
    label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "测试");
    lv_obj_set_style_text_color(label, lv_palette_main(LV_PALETTE_RED), LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, &lv_font_simsun_16_cjk, LV_STATE_DEFAULT);
    lv_obj_align_to(label, NULL, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_bg_color(lv_scr_act(), lv_palette_main(LV_PALETTE_BLUE), LV_STATE_DEFAULT);
  
    lv_obj_set_style_bg_color(lv_scr_act(), lv_palette_main(LV_PALETTE_BLUE), LV_STATE_DEFAULT);
    img = lv_gif_create(lv_scr_act());
    lv_gif_set_src(img, &start5);
    lv_obj_align_to(img, NULL, LV_ALIGN_CENTER, 0, 0);
    
//    lv_timer_create(lv_my_timer, 10, img);






}


















