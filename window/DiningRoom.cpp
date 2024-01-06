#include "DiningRoom.h"

DiningRoom::DiningRoom() {   
    set_background("./images/background/dining_room.png");
}

DiningRoom::~DiningRoom() {

}

bool DiningRoom::process(ALLEGRO_EVENT event) {
    return mouse_click(1450, 1300, 200, 200, event);
}

void DiningRoom::draw() {
    draw_background();
    al_draw_rectangle(1450, 1300, 1650, 1500, al_map_rgb(255, 0, 0), 3.0);
}
