#include "Menu.h"

Menu::Menu() {
    set_background("./images/background/menu.png");

    sound_effect = al_load_sample("./sound/menu_button.wav");
}

Menu::~Menu() {
    al_destroy_sample(sound_effect);
}

bool Menu::process(ALLEGRO_EVENT event) {
    if(mouse_click(670, 1190, 580, 140, event)) {
        al_play_sample(sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        return true;
    }
    return false;
}

void Menu::draw() {
    draw_background();
}
