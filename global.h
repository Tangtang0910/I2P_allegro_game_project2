#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

#define window_width 1900
#define window_height 1500
#define x_initial_position 200
#define y_initial_position 80

enum Action {
    DO_NOTHING,
    NEXT_WINDOW,
    RESET_WORKSHOP,
    CREATE_TOOL_MAN,
    CREATE_BEAST_MAN,
    CREATE_MAGICAL_GIRL,
    MAGIC_EFFECT_TOOL_MAN,
    MAGIC_EFFECT_BEAST_MAN,
    MAGIC_EFFECT_MAGICAL_GIRL
};

enum Character {
    TOOL_MAN, //工具人
    BEAST_MAN, //獸人
    MAGICAL_GIRL,
    NO_ONE
};

#endif // GLOBAL_H_INCLUDED
