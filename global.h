#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <allegro5/allegro_font.h>
#include <iostream>
using namespace std;

#define window_width 1900
#define window_height 1500
#define x_initial_position 100
#define y_initial_position 20

extern ALLEGRO_EVENT_QUEUE *event_queue;
extern bool key_state[ALLEGRO_KEY_MAX];

#endif // GLOBAL_H_INCLUDED
