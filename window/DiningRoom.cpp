#include "DiningRoom.h"

DiningRoom::DiningRoom() {   
    set_background("./images/background/dining_room.jpg");
    heart = al_load_bitmap("./images/item/heart.png");
    text1 = al_load_bitmap("./images/item/text1.png");
    text2 = al_load_bitmap("./images/item/text2.png");
    text3 = al_load_bitmap("./images/item/text3.png");

    react_button = al_load_sample("./sound/react_button.wav");
    trash_button = al_load_sample("./sound/trash_button.wav");
    home_button = al_load_sample("./sound/home_button.wav");

    last_action_time = al_get_time();  // Initialize the last action time
    fav = 6;

    tool_man = al_load_bitmap("./images/character/tool_man.png");
    tool_man_talk1_frames = read_video("./images/talk/tool_man/talk1/talk1_", 49);
}

DiningRoom::~DiningRoom() {
    al_destroy_bitmap(heart);
    al_destroy_bitmap(text1);
    al_destroy_bitmap(text2);
    al_destroy_bitmap(text3);

    al_destroy_sample(react_button);
    al_destroy_sample(trash_button);
    al_destroy_sample(home_button);
}

Action DiningRoom::process(ALLEGRO_EVENT event) {
    if (mouse_click(1455, 1245, 255, 185, event)) { //按 home 鍵，切換到煉金坊
        al_play_sample(home_button, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        return NEXT_WINDOW;
    }

    if(character != NO_ONE){
        if (fav > 0) { // 愛心 > 0 --> 可和朋友互動
    
            if(mouse_click(108, 1245, 257, 185, event)){ // 按 chat
                play_sound("react");
                play_action("chat");
                fav++;
                last_action_time = al_get_time();

            } else if (mouse_click(440, 1245, 257, 185, event)) { // 按 feed
                play_sound("react");

                fav++;
                last_action_time = al_get_time();

            } else if (mouse_click(772, 1245, 257, 185, event)) { // 按 pet 
                play_sound("react");

                fav++;
                last_action_time = al_get_time();

            } else if (mouse_click(1110, 1245, 251, 185, event)) { // 按 trash --> 朋友消失
                play_sound("trash");
                fav = -1;
            }

            if (al_get_time() - last_action_time > 5.0) { // 每五秒減一個愛心
                fav--;
                last_action_time = al_get_time();  
            }

            if (fav > 3) fav = 3;

        } else if (fav <= 0){
            return RESET_WORKSHOP;
        }
    }

    return DO_NOTHING;
}

void DiningRoom::draw() {
    draw_background();

    if(character == NO_ONE){
        al_draw_bitmap(text3, 430, 500, 0); // 還沒有朋友
    }
    if(character != NO_ONE){
        if (fav == -1) al_draw_bitmap(text1, 270, 500, 0); // 愛心 = -1 --> 朋友被丟掉
        else if (fav <= 0) al_draw_bitmap(text2, 270, 500, 0); // 愛心 = 零 --> 朋友絕交
        if (fav >= 1) al_draw_bitmap(heart, 20, 10, 0);
        if (fav >= 2) al_draw_bitmap(heart, 100, 10, 0);
        if (fav == 3) al_draw_bitmap(heart, 180, 10, 0);
    }
    
    if (character == TOOL_MAN && fav > 0) {
        al_draw_bitmap(tool_man, 500, 750, 0);
    } else if (character == BEAST_MAN) {

    } else if (character == MAGICAL_GIRL) {

    }
    
    if (current_video != NULL && current_frame < current_video->size()) {
        al_draw_bitmap((*current_video)[current_frame], 800, 750, 0);
        current_frame += 1;
    }
}

void DiningRoom::play_action(string button) {
    if (button == "chat") {
        if (character == TOOL_MAN) {
            current_video = &tool_man_talk1_frames;
        } else if (character == BEAST_MAN) {
            
        } else if (character == MAGICAL_GIRL) {

        }
    } else if (button == "feed") {
        if (character == TOOL_MAN) {

        } else if (character == BEAST_MAN) {

        } else if (character == MAGICAL_GIRL) {
            
        }
    } else if (button == "pet") {
        if (character == TOOL_MAN) {

        } else if (character == BEAST_MAN) {

        } else if (character == MAGICAL_GIRL) {
            
        }
    }
    current_frame = 0;
}

void DiningRoom::play_sound(string button){
    if (button == "react") al_play_sample(react_button, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    else if (button == "trash") al_play_sample(trash_button, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void DiningRoom::set_character(Character character) {
    this->character = character;
    fav = 5;
}
