#include "Menu.h"

Menu::Menu()
{
    mouse_clicked = new Utils;
}

void
Menu::menu_process(ALLEGRO_EVENT event){
    if(mouse_clicked->mouse_click(670, 1190, 580, 140, event)){
        cout << "hi" << endl;
    }

}

void
Menu::menu_draw(){
    al_draw_rectangle(670, 1330, 1250, 1190, al_map_rgb(255, 0, 0), 3.0);
}

void
Menu::menu_destroy(){
    delete mouse_clicked;
}