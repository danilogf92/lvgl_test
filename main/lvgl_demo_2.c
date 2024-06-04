#include <stdio.h>
#include <string.h>
#include "lvgl.h"
#include "driver/gpio.h"

static lv_obj_t* led1;

static void event_cb (lv_event_t* e)
{
  lv_event_code_t code = lv_event_get_code (e);
  lv_obj_t* label = lv_event_get_user_data (e);

  switch ( code )
  {
    case LV_EVENT_PRESSED:
      lv_label_set_text (label, "The last button event:\nLV_EVENT_PRESSED");
      lv_led_on (led1);
      LV_LOG_USER ("LV_EVENT_PRESSED");
      break;
    case LV_EVENT_CLICKED:
      lv_label_set_text (label, "The last button event:\nLV_EVENT_CLICKED");
      LV_LOG_USER ("LV_EVENT_CLICKED");
      break;
    case LV_EVENT_LONG_PRESSED:
      lv_label_set_text (label, "The last button event:\nLV_EVENT_LONG_PRESSED");
      LV_LOG_USER ("LV_EVENT_LONG_PRESSED");
      break;
    case LV_EVENT_LONG_PRESSED_REPEAT:
      lv_label_set_text (label, "The last button event:\nLV_EVENT_LONG_PRESSED_REPEAT");
      LV_LOG_USER ("LV_EVENT_LONG_PRESSED_REPEAT");
      break;
    case LV_EVENT_RELEASED:
      lv_label_set_text (label, "The last button event:\nLV_EVENT_RELEASED");
      LV_LOG_USER ("LV_EVENT_RELEASED");
      lv_led_off (led1);
      break;

    default:
      break;
  }
}


void lv_example_event_2 (void)
{
  lv_obj_t* btn_1 = lv_btn_create (lv_scr_act ());
  lv_obj_set_size (btn_1, 100, 50);
  // lv_obj_align (btn_1, LV_ALIGN_CENTER, 0, 0);
  // lv_obj_align (btn_1, LV_ALIGN_BOTTOM_MID, 0, 0);
  lv_obj_center (btn_1);

  lv_obj_t* btn_label_1 = lv_label_create (btn_1);
  lv_label_set_text (btn_label_1, "Bomba 1");
  lv_obj_center (btn_label_1);

  lv_obj_t* btn_2 = lv_btn_create (lv_scr_act ());
  lv_obj_set_size (btn_2, 100, 50);
  // lv_obj_align (btn_2, LV_ALIGN_BOTTOM_LEFT, +5, -5);
  lv_obj_align (btn_2, LV_ALIGN_TOP_LEFT, 0, 0);

  // lv_obj_set_pos (btn_2, 10, 60);

  lv_obj_t* btn_label_2 = lv_label_create (btn_2);
  lv_label_set_text (btn_label_2, "Bomba 2");
  // lv_obj_center (btn_label_2);

  lv_obj_t* info_label = lv_label_create (lv_scr_act ());
  lv_label_set_text (info_label, "The last button event:\nNone");

  led1 = lv_led_create (lv_scr_act ());
  lv_obj_set_size (led1, 50, 50);
  lv_led_set_color (led1, lv_palette_main (LV_PALETTE_RED));
  lv_obj_align (led1, LV_ALIGN_CENTER, 0, -80);
  lv_led_off (led1);

  lv_obj_add_event_cb (btn_1, event_cb, LV_EVENT_ALL, info_label);
}
