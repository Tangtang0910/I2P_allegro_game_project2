#include "Workshop.h"

Workshop::Workshop() {
    set_background("./images/background/workshop.jpg");

    button_sound_effect = al_load_sample("./sound/home_button.wav");
    carrot_sound_effect = al_load_sample("./sound/carrot.wav");
    bottle_sound_effect = al_load_sample("./sound/bottle.wav");
    crystal_sound_effect = al_load_sample("./sound/crystal.wav");
}

Workshop::~Workshop() {
    al_destroy_sample(button_sound_effect);
    al_destroy_sample(bottle_sound_effect);
    al_destroy_sample(carrot_sound_effect);
    al_destroy_sample(crystal_sound_effect);
}

bool Workshop::process(ALLEGRO_EVENT event) {
    if (mouse_click(820, 1300, 250, 170, event)) { // 按 home 鍵，切換到客廳
        al_play_sample(button_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        return true;
    }

    if (mouse_click(100, 1100, 300, 250, event)) { // 按下蘿蔔
        al_play_sample(carrot_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        
    } else if (mouse_click(1280, 430, 170, 150, event)) { // 按下玻璃瓶
        al_play_sample(bottle_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        
    } else if (mouse_click(1520, 530, 230, 270, event)) { // 按下水晶
        al_play_sample(crystal_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        
    }

    return false;
}

void Workshop::draw(){
    draw_background();
    draw_materail();
}
