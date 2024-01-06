#include "Workshop.h"

Workshop::Workshop() {
    set_background("./images/background/workshop.png");
}

Workshop::~Workshop() {
    
}

bool Workshop::process(ALLEGRO_EVENT event) {
    return mouse_click(670, 1190, 580, 140, event);
}

void Workshop::draw(){
    draw_background();
    al_draw_rectangle(670, 1330, 1250, 1190, al_map_rgb(255, 0, 0), 3.0);
}
