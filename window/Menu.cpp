#include "Menu.h"

Menu::Menu() {
    background = al_load_bitmap("./images/background/menu.png");
}

bool Menu::process(ALLEGRO_EVENT event){
    return mouse_click(670, 1190, 580, 140, event);
}

void Menu::draw() {
    al_draw_scaled_bitmap(
        background, 0, 0, 
        al_get_bitmap_width(background), 
        al_get_bitmap_height(background), 
        0, 0, window_width, window_height, 0
    );
}

void Menu::destroy(){
    al_destroy_bitmap(background);
}
