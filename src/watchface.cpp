#include "lvgl.h"
#include "time.h"
#include "styles.h"

lv_obj_t *local_time_label;
lv_obj_t *gmt_time_label;
lv_obj_t *date_label;
lv_obj_t *battery_label;

void create_watchface() {
    lv_obj_t *screen = lv_obj_create(NULL, NULL);
    lv_scr_load(screen);

    local_time_label = lv_label_create(screen, NULL);
    gmt_time_label = lv_label_create(screen, NULL);
    date_label = lv_label_create(screen, NULL);
    battery_label = lv_label_create(screen, NULL);

    lv_label_set_style(local_time_label, LV_LABEL_STYLE_MAIN, &your_custom_style);
    lv_obj_align(local_time_label, NULL, LV_ALIGN_CENTER, 0, -40);

    lv_label_set_style(gmt_time_label, LV_LABEL_STYLE_MAIN, &your_custom_style);
    lv_obj_align(gmt_time_label, NULL, LV_ALIGN_CENTER, 0, -20);

    lv_label_set_style(date_label, LV_LABEL_STYLE_MAIN, &your_custom_style);
    lv_obj_align(date_label, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_label_set_style(battery_label, LV_LABEL_STYLE_MAIN, &your_custom_style);
    lv_obj_align(battery_label, NULL, LV_ALIGN_CENTER, 0, 20);

    lv_task_create(update_time, 1000, LV_TASK_PRIO_MID, NULL);
}

void update_time(lv_task_t *task) {
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    char local_time_str[10];
    strftime(local_time_str, sizeof(local_time_str), "%H:%M:%S", local_time);
    lv_label_set_text(local_time_label, local_time_str);

    struct tm *gmt_time = gmtime(&now);
    char gmt_time_str[10];
    strftime(gmt_time_str, sizeof(gmt_time_str), "%H:%M:%S", gmt_time);
    lv_label_set_text(gmt_time_label, gmt_time_str);

    char date_str[12];
    strftime(date_str, sizeof(date_str), "%Y-%m-%d", local_time);
    lv_label_set_text(date_label, date_str);

    int battery_level = 100;  // Placeholder value
    char battery_str[8];
    sprintf(battery_str, "%d%%", battery_level);
    lv_label_set_text(battery_label, battery_str);
}

void draw_analog_clock(lv_obj_t *parent) {
    lv_obj_t *clock_cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(clock_cont, 200, 200);
    lv_obj_align(clock_cont, NULL, LV_ALIGN_CENTER, 0, 60);

    lv_obj_t *clock_face = lv_img_create(clock_cont, NULL);
    lv_img_set_src(clock_face, &clock_face_img);

    lv_obj_t *hour_hand = lv_line_create(clock_cont, NULL);
    static lv_point_t hour_points[] = {{100, 100}, {100, 60}};
    lv_line_set_points(hour_hand, hour_points, 2);
    lv_line_set_style(hour_hand, LV_LINE_STYLE_MAIN, &hour_hand_style);
}
