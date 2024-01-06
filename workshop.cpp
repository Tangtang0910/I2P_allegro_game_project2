#include "workshop.h"

Alchemy_room::Alchemy_room()
{
    mouse_clicked = new Utils;
    alchemy_room_background = al_load_bitmap("./workshop.png");
}

bool
Alchemy_room::alchemy_room_process(ALLEGRO_EVENT event){
    if(mouse_clicked->mouse_click(670, 1190, 580, 140, event)){
         return true;
    }
    return false;
}

void
Alchemy_room::alchemy_room_draw(){
    al_draw_scaled_bitmap(
        alchemy_room_background, 0, 0, 
        al_get_bitmap_width(alchemy_room_background), 
        al_get_bitmap_height(alchemy_room_background), 
        0, 0, window_width, window_height, 0);
        al_draw_rectangle(670, 1330, 1250, 1190, al_map_rgb(255, 0, 0), 3.0);
}

void
Alchemy_room::alchemy_room_destroy(){
    delete mouse_clicked;
    al_destroy_bitmap(alchemy_room_background);
}