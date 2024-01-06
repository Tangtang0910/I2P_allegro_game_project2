#include "utils.h"

bool mouse_click(int startx, int starty, int width, int height, ALLEGRO_EVENT event) {
    int mouse_x = event.mouse.x;
    int mouse_y = event.mouse.y;
    if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
        if(mouse_x >= startx && mouse_x <= startx + width && mouse_y >= starty && mouse_y <= starty + height)
            return true;
    }
    return false;
}
