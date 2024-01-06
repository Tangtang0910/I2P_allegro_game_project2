#include "Dining_room.h"

Dining_room::Dining_room() {   
    dining_room_background = al_load_bitmap("./images/background/dining_room.png");
    mouse_clicked = new Utils;
}

bool Dining_room::dining_room_process(ALLEGRO_EVENT event) {
     if (mouse_clicked->mouse_click(1450, 1300, 200, 200, event)) {
         return true;
     }
    return false;
}

void Dining_room::dining_room_draw() {
    al_draw_scaled_bitmap(
        dining_room_background, 0, 0, 
        al_get_bitmap_width(dining_room_background), 
        al_get_bitmap_height(dining_room_background), 
        0, 0, window_width, window_height, 0
    );
    al_draw_rectangle(1450, 1300, 1650, 1500, al_map_rgb(255, 0, 0), 3.0);
}

void Dining_room::dining_room_destroy() {
    delete mouse_clicked;
    al_destroy_bitmap(dining_room_background);
}