#include "Workshop.h"

Workshop::Workshop() {
    set_background("./images/background/workshop.jpg");

    button_sound_effect = al_load_sample("./sound/home_button.wav");
    grass_sound_effect = al_load_sample("./sound/grass.wav");
    potion_sound_effect = al_load_sample("./sound/potion.wav");
    mineral_sound_effect = al_load_sample("./sound/mineral.wav");

    pot = al_load_bitmap("./images/pot.png");
    grass = al_load_bitmap("./images/grass.png");
    mineral = al_load_bitmap("./images/mineral.png");
    potion = al_load_bitmap("./images/potion.png");
}

Workshop::~Workshop() {
    al_destroy_sample(button_sound_effect);
    al_destroy_sample(potion_sound_effect);
    al_destroy_sample(grass_sound_effect);
    al_destroy_sample(mineral_sound_effect);

    al_destroy_bitmap(pot);
    al_destroy_bitmap(potion);
    al_destroy_bitmap(mineral);
    al_destroy_bitmap(grass);
}

bool Workshop::process(ALLEGRO_EVENT event) {
    if (mouse_click(820, 1300, 250, 170, event)) { // 按 home 鍵，切換到客廳
        al_play_sample(button_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        return true;
    }

    if (mouse_click(100, 1100, 300, 250, event)) { // 按下蘿蔔
        al_play_sample(grass_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        
    } else if (mouse_click(1280, 430, 170, 150, event)) { // 按下玻璃瓶
        al_play_sample(potion_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        
    } else if (mouse_click(1520, 530, 230, 270, event)) { // 按下水晶
        al_play_sample(mineral_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        
    }

    return false;
}

void Workshop::draw(){
    draw_background();

    al_draw_scaled_bitmap(pot, 0, 0,
        al_get_bitmap_width(pot), 
        al_get_bitmap_height(pot), 
        620, 680, 
        600, 600, 0
    );

    al_draw_scaled_bitmap(grass, 0, 0,al_get_bitmap_width(grass), al_get_bitmap_height(grass), 40, 940, al_get_bitmap_width(grass), al_get_bitmap_height(grass),  0);
    
    
    al_draw_scaled_bitmap(mineral, 0, 0,al_get_bitmap_width(mineral), al_get_bitmap_height(mineral), 1500, 500, 280, 370, 0);

    al_draw_scaled_bitmap(potion, 0, 0,al_get_bitmap_width(potion), al_get_bitmap_height(potion), 1260 , 350 , al_get_bitmap_width(potion)* 2 , al_get_bitmap_height(potion)* 2, 0);
}
