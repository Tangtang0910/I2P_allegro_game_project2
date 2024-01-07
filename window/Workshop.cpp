#include "Workshop.h"

Workshop::Workshop() {
    set_background("./images/background/workshop.jpg");

    button_sound_effect = al_load_sample("./sound/home_button.wav");
    grass_sound_effect = al_load_sample("./sound/grass.wav");
    potion_sound_effect = al_load_sample("./sound/potion.wav");
    mineral_sound_effect = al_load_sample("./sound/mineral.wav");

    pot = al_load_bitmap("./images/item/pot.png");
    grass = al_load_bitmap("./images/item/grass.png");
    mineral = al_load_bitmap("./images/item/mineral.png");
    potion = al_load_bitmap("./images/item/potion.png");

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

Action Workshop::process(ALLEGRO_EVENT event) {
    if (mouse_click(820, 1300, 250, 170, event)) { // 按 home 鍵，切換到客廳
        al_play_sample(button_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        return NEXT_WINDOW;
    }

    if (material_vec.size() < 2) { // 一次只可以選 2 個材料
        if (mouse_click(100, 1100, 300, 250, event)) { // 按下蘿蔔
            play_sound("grass");

            grass_clicked = true;
            material_vec.push_back("grass");
        }
        if (mouse_click(1280, 430, 170, 150, event)) { // 按下玻璃
            play_sound("potion");

            potion_clicked = true;
            material_vec.push_back("potion");
        }
        if (mouse_click(1520, 530, 230, 270, event)) { // 按下水晶
            play_sound("mineral");

            mineral_clicked = true;
            material_vec.push_back("mineral");
        }
    }

    if (material_vec.size() == 2) { // 已經選 2 個材料 --> 生成朋友
        if ((material_vec[0] == "grass" && material_vec[1] == "potion") || (material_vec[0] == "potion" && material_vec[1] == "grass")) {
            return CREATE_TOOL_MAN;
        } else if ((material_vec[0] == "grass" && material_vec[1] == "mineral") || (material_vec[0] == "mineral" && material_vec[1] == "grass")) {
            return CREATE_BEAST_MAN;
        } else if ((material_vec[0] == "mineral" && material_vec[1] == "potion") || (material_vec[0] == "potion" && material_vec[1] == "mineral")) {
            return CREATE_MAGICAL_GIRL;
        }
    }

    return DO_NOTHING;
}

void Workshop::draw() {
    draw_background();

    al_draw_scaled_bitmap(pot, 0, 0, al_get_bitmap_width(pot), al_get_bitmap_height(pot), 620, 680, 600, 600, 0);

    if (! grass_clicked) {
        al_draw_scaled_bitmap(grass, 0, 0, al_get_bitmap_width(grass), al_get_bitmap_height(grass), 40, 940, al_get_bitmap_width(grass), al_get_bitmap_height(grass),  0);
    }
    if (! mineral_clicked) {
        al_draw_scaled_bitmap(mineral, 0, 0, al_get_bitmap_width(mineral), al_get_bitmap_height(mineral), 1500, 500, 280, 370, 0);
    }
    if (! potion_clicked) {
        al_draw_scaled_bitmap(potion, 0, 0, al_get_bitmap_width(potion), al_get_bitmap_height(potion), 1260 , 350 , al_get_bitmap_width(potion)* 2 , al_get_bitmap_height(potion)* 2, 0);
    }
    
}

void Workshop::play_sound(string material) {
    if (material == "grass") al_play_sample(grass_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    else if (material == "potion") al_play_sample(potion_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    else if (material == "mineral") al_play_sample(mineral_sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Workshop::reset() {
    grass_clicked = false;
    potion_clicked = false;
    mineral_clicked = false;

    material_vec.clear();
}
