#include "Menu.h"

Menu::Menu() {
    background = al_load_bitmap("./images/background/menu.png");
}

bool Menu::menu_process(ALLEGRO_EVENT event){
    if(mouse_click(670, 1190, 580, 140, event)){
        return true;
    }else{
        return false;
    }
}

void Menu::menu_draw() {
    al_draw_scaled_bitmap(
        background, 0, 0, 
        al_get_bitmap_width(background), 
        al_get_bitmap_height(background), 
        0, 0, window_width, window_height, 0
    );
}

void Menu::menu_destroy(){
    al_destroy_bitmap(background);
}
