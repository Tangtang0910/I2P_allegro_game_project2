#include "Menu.h"

Menu::Menu() {
    set_background("./images/background/menu.png");
}

Menu::~Menu() {

}

bool Menu::process(ALLEGRO_EVENT event){
    return mouse_click(670, 1190, 580, 140, event);
}

void Menu::draw() {
    draw_background();
}
