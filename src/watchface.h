#ifndef WATCHFACE_H
#define WATCHFACE_H

void create_watchface();
void update_time(lv_task_t *task);
void draw_analog_clock(lv_obj_t *parent);

#endif
