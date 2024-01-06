#include "global.h"
#ifndef UTILS_H
#define UTILS_H

class Utils
{
private:
    int mouse_x = 0;
    int mouse_y = 0;
public:
    bool mouse_click(int startx, int starty, int width, int height, ALLEGRO_EVENT event);
};

#endif 