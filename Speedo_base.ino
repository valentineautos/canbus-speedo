#include <Arduino.h>
#include <ESP_Panel_Library.h>
#include <lvgl.h>
#include "lvgl_port_v8.h"
#include "fonts/ubuntu_24.h"
#include "fonts/ubuntu_100.h"
#include "fonts/font_awesome_icons_small.h"
#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

// ESPNow structures
typedef struct struct_speedo {
  uint8_t mph;
  uint8_t fuel_perc;
}struct_speedo;

struct_speedo speedoData;


// Global components
lv_obj_t *scr; // Screen background
lv_obj_t *speed_meter; // Speed meter
lv_obj_t *fuel_meter; // Speed meter
lv_meter_indicator_t *speed_indic; // Speed moving part
lv_meter_indicator_t *fuel_indic; // Fuel moving part
lv_obj_t *fuel_icon; // fuel icon
lv_obj_t *mph_label; // Digital MPH

// Global styles
static lv_style_t style_unit_text;
static lv_style_t style_icon;

// Color palette
lv_color_t palette_amber = LV_COLOR_MAKE(250, 140, 0);
lv_color_t palette_black = LV_COLOR_MAKE(0, 0, 0);
lv_color_t palette_red = LV_COLOR_MAKE(255, 0, 0);
lv_color_t palette_white = LV_COLOR_MAKE(255, 255, 255);
lv_color_t palette_grey = LV_COLOR_MAKE(90, 90, 90);
lv_color_t palette_dark_grey = LV_COLOR_MAKE(60, 60, 60);

#define FUEL_SYMBOL "\xEF\x94\xAF"

// Attributes
volatile bool data_ready = false;
hw_timer_t* timer = nullptr;

int rpm = 0;
unsigned long previous_ticks = 0;
const int stepper_time = 30; 

uint32_t last_update_time = 0;
const uint32_t TIMEOUT_MS = 5000;

// Styles
void make_styles(void) {
    lv_style_init(&style_unit_text);
    lv_style_set_text_font(&style_unit_text, &ubuntu_24);
    lv_style_set_text_color(&style_unit_text, palette_white);

    lv_style_init(&style_icon);
    lv_style_set_text_font(&style_icon, &font_awesome_icons_small);
    lv_style_set_text_color(&style_icon, palette_grey);
}

// ESPNow received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  if (len == 1) {
    uint8_t new_channel = incomingData[0];
    esp_wifi_set_channel(new_channel, WIFI_SECOND_CHAN_NONE);
    Serial.printf("Channel updated to: %d\n", new_channel);
  } else {
    memcpy(&speedoData, incomingData, sizeof(speedoData));

    Serial.println("New Data Received");

    last_update_time = lv_tick_get();
    data_ready = true;
  }
}

void update_speed(int new_speed) {
  char mph_text[4];
  itoa(new_speed, mph_text, 10);
  lv_label_set_text(mph_label, mph_text);

  lv_meter_set_indicator_value(speed_meter, speed_indic, new_speed);
}

void update_fuel(int new_fuel_perc) {
  
  lv_arc_set_value(fuel_meter, new_fuel_perc);

  if (new_fuel_perc < 10) {
    lv_obj_set_style_arc_color(fuel_meter, palette_red, LV_PART_INDICATOR);
    lv_obj_set_style_text_color(fuel_icon, palette_red, 0);
  } else if (new_fuel_perc < 25) {
    lv_obj_set_style_arc_color(fuel_meter, palette_amber, LV_PART_INDICATOR);
    lv_obj_set_style_text_color(fuel_icon, palette_grey, 0);
  } else {
    lv_obj_set_style_arc_color(fuel_meter, palette_white, LV_PART_INDICATOR);
    lv_obj_set_style_text_color(fuel_icon, palette_grey, 0);
  }
}

void make_speed_meter(void) {
    speed_meter = lv_meter_create(scr);
    lv_obj_set_style_pad_all(speed_meter, 0, 10);
    lv_obj_set_style_bg_color(speed_meter, palette_black, 0);
    lv_obj_set_style_border_width(speed_meter, 0, 0);
    lv_obj_center(speed_meter);
    lv_obj_set_size(speed_meter, 470, 470);

    lv_obj_remove_style(speed_meter, NULL, LV_PART_INDICATOR);
    
    /*Add a scale first*/
    lv_meter_scale_t *scale = lv_meter_add_scale(speed_meter);
    lv_meter_set_scale_ticks(speed_meter, scale, 81, 1, 10, palette_dark_grey);
    lv_meter_set_scale_major_ticks(speed_meter, scale, 10, 2, 15, palette_white, 30);
    lv_meter_set_scale_range(speed_meter, scale, 0, 160, 270, 135);

    lv_meter_indicator_t *outline;
    outline = lv_meter_add_arc(speed_meter, scale, 2, palette_white, 2);
    lv_meter_set_indicator_start_value(speed_meter, outline, 0);
    lv_meter_set_indicator_end_value(speed_meter, outline, 160);

    lv_obj_set_style_text_font(speed_meter, &ubuntu_24, LV_PART_TICKS);
    lv_obj_set_style_text_color(speed_meter, palette_white, LV_PART_TICKS);

    speed_indic = lv_meter_add_needle_line(speed_meter, scale, 5, palette_red, -10);

    lv_obj_t *inner_circle = lv_obj_create(scr);
    lv_obj_set_size(inner_circle, 200, 200);
    lv_obj_center(inner_circle);
    lv_obj_set_style_bg_color(inner_circle, palette_black, 0);
    lv_obj_set_style_bg_opa(inner_circle, LV_OPA_COVER, 0);
    lv_obj_set_style_radius(inner_circle, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_border_width(inner_circle, 1, 0);
    lv_obj_set_style_border_color(inner_circle, palette_grey, 0);
}

void make_fuel_meter(void) {
  fuel_meter = lv_arc_create(scr);
  lv_obj_set_size(fuel_meter, 446, 446);
  lv_arc_set_rotation(fuel_meter, 65);
  lv_arc_set_bg_angles(fuel_meter, 0, 50);
  lv_arc_set_range(fuel_meter, 0, 100);
  lv_obj_center(fuel_meter);
  lv_arc_set_mode(fuel_meter, LV_ARC_MODE_REVERSE);

  lv_obj_set_style_arc_color(fuel_meter, palette_dark_grey, LV_PART_MAIN);
  lv_obj_set_style_arc_color(fuel_meter, palette_white, LV_PART_INDICATOR);
  lv_obj_set_style_arc_rounded(fuel_meter, false, LV_PART_MAIN);
  lv_obj_set_style_arc_rounded(fuel_meter, false, LV_PART_INDICATOR);
  lv_obj_set_style_arc_width(fuel_meter, 4, LV_PART_MAIN);
  lv_obj_set_style_arc_width(fuel_meter, 4, LV_PART_INDICATOR);
  lv_obj_remove_style(fuel_meter, NULL, LV_PART_KNOB); 
  
  lv_obj_set_style_arc_color(fuel_meter, palette_amber, LV_PART_INDICATOR);
  lv_arc_set_value(fuel_meter, 20);

  fuel_icon = lv_label_create(scr);
  lv_label_set_text(fuel_icon, FUEL_SYMBOL);
  lv_obj_add_style(fuel_icon, &style_icon, 0);
  lv_obj_align(fuel_icon, LV_ALIGN_CENTER, 0, 170);
}

void make_speed_digital(void) {
  static lv_style_t style_speed_text;
  lv_style_init(&style_speed_text);
  lv_style_set_text_font(&style_speed_text, &ubuntu_100);
  lv_style_set_text_color(&style_speed_text, palette_white);

  mph_label = lv_label_create(scr);
  lv_label_set_text(mph_label, "0");
  lv_obj_add_style(mph_label, &style_speed_text, 0);
  lv_obj_align(mph_label, LV_ALIGN_CENTER, 0, -5);

  lv_obj_t *mph_unit_label = lv_label_create(scr);
  lv_label_set_text(mph_unit_label, "mph");
  lv_obj_add_style(mph_unit_label, &style_unit_text, 0);
  lv_obj_align(mph_unit_label, LV_ALIGN_CENTER, 0, 50);
}

void scr_init() {
    ESP_Panel *panel = new ESP_Panel();
    panel->init();

    #if LVGL_PORT_AVOID_TEAR
        // When avoid tearing function is enabled, configure the RGB bus according to the LVGL configuration
        ESP_PanelBus_RGB *rgb_bus = static_cast<ESP_PanelBus_RGB *>(panel->getLcd()->getBus());
        rgb_bus->configRgbFrameBufferNumber(LVGL_PORT_DISP_BUFFER_NUM);
        rgb_bus->configRgbBounceBufferSize(LVGL_PORT_RGB_BOUNCE_BUFFER_SIZE);
    #endif
    panel->begin();

    lvgl_port_init(panel->getLcd(), panel->getTouch());
}

void wifi_init() {
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}

void IRAM_ATTR onTimer() {
    lv_tick_inc(1); // Increment LVGL's tick by 1ms
}

void setup()
{
  Serial.begin(115200);

  scr_init();
  wifi_init();

  scr = lv_scr_act();    
  lv_obj_set_style_bg_color(scr, palette_black, 0);

  // // Common styles
  make_styles();

  // // stuff
  make_speed_meter();
  make_fuel_meter();
  make_speed_digital();

  // // Setting values with update functions
  update_speed(20);
  update_fuel(8);

  // Setup the timer
  const uint32_t lv_tick_frequency = 1000; // 1 kHz = 1ms period

  timer = timerBegin(lv_tick_frequency); // Configure the timer with 1kHz frequency
  if (!timer) {
      Serial.println("Failed to configure timer!");
      while (1); // Halt execution on failure
  }

  timerAttachInterrupt(timer, &onTimer); // Attach the ISR to the timer
  Serial.println("Timer initialized for LVGL tick!");

  last_update_time = lv_tick_get();
}

void loop(){
    lv_timer_handler();

    Serial.println("loop");

    if (data_ready) {
      update_speed(speedoData.mph);
      update_fuel(speedoData.fuel_perc);
      data_ready = false;
    }
}