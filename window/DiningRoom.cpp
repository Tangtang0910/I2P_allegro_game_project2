#include "DiningRoom.h"

DiningRoom::DiningRoom() {   
    set_background("./images/background/dining_room.jpg");
    heart = al_load_bitmap("./images/item/heart.png");
    text1 = al_load_bitmap("./images/item/text1.png");
    text2 = al_load_bitmap("./images/item/text2.png");

    react_button = al_load_sample("./sound/react_button.wav");
    trash_button = al_load_sample("./sound/trash_button.wav");
    home_button = al_load_sample("./sound/home_button.wav");

    last_action_time = al_get_time();  // Initialize the last action time
    fav = 6;
}

DiningRoom::~DiningRoom() {
    al_destroy_bitmap(heart);
    al_destroy_bitmap(text1);
    al_destroy_bitmap(text2);

    al_destroy_sample(react_button);
    al_destroy_sample(trash_button);
    al_destroy_sample(home_button);
}

bool DiningRoom::process(ALLEGRO_EVENT event) {
    if (mouse_click(1455, 1245, 255, 185, event)) { //按 home 鍵，切換到煉金坊
        al_play_sample(home_button, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        return true;
    }

    
    if (fav > 0) { // 愛心 > 0 --> 可和朋友互動
    
        if(mouse_click(108, 1245, 257, 185, event)){ // 按 chat
            al_play_sample(react_button, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            fav++;
            last_action_time = al_get_time();

        } else if (mouse_click(440, 1245, 257, 185, event)) { // 按 feed
            al_play_sample(react_button, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            fav++;
            last_action_time = al_get_time();

        } else if (mouse_click(772, 1245, 257, 185, event)) { // 按 pet 
            al_play_sample(react_button, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            fav++;
            last_action_time = al_get_time();

        } else if (mouse_click(1110, 1245, 251, 185, event)) { // 按 trash --> 朋友消失
            al_play_sample(trash_button, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            fav = -1;
        }

        if(al_get_time() - last_action_time > 3.0) { // 每五秒減一個愛心
            fav--;
            last_action_time = al_get_time();  
        }

        if(fav > 3) fav = 3;
    }

    return false;
}

void DiningRoom::draw() {
    draw_background();

    // 愛心 = 零 --> 朋友絕交
    if(fav == -1) al_draw_bitmap(text1, 270, 500, 0);
    else if(fav <= 0) al_draw_bitmap(text2, 270, 500, 0);
    if(fav >= 1) al_draw_bitmap(heart, 20, 10, 0);
    if(fav >= 2) al_draw_bitmap(heart, 100, 10, 0);
    if(fav == 3) al_draw_bitmap(heart, 180, 10, 0);
}
