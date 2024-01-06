#include "Menu.h"

Menu::Menu()
{
    mouse_clicked = new Utils;
}

bool
Menu::menu_process(ALLEGRO_EVENT event){
    if(mouse_clicked->mouse_click(670, 1190, 580, 140, event)){
        return true;
    }else{
        return false;
    }
}

void
Menu::menu_draw(){
}

void
Menu::menu_destroy(){
    delete mouse_clicked;
}