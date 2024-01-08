#include "Magic_effect.h"

Magic_effect::Magic_effect() {
    set_background("./images/background/workshop.jpg");

    pot = al_load_bitmap("./images/item/shatter_pot.png");
    tool_man = al_load_bitmap("./images/character/tool_man.png");
    beast_man = al_load_bitmap("./images/character/beast_man.png");
    magical_girl = al_load_bitmap("./images/character/magic_girl.png");

    tool_man_text = al_load_bitmap("./images/item/tool_man_text.png");
    beast_man_text = al_load_bitmap("./images/item/beast_man_text.png");
    magical_girl_text = al_load_bitmap("./images/item/magic_girl_text.png");
    
    sound_effect = al_load_sample("./sound/magic.wav");
}

Magic_effect::~Magic_effect() {
    al_destroy_sample(sound_effect);

    al_destroy_bitmap(pot);
    al_destroy_bitmap(tool_man);
    al_destroy_bitmap(beast_man);
    al_destroy_bitmap(magical_girl);

    al_destroy_bitmap(tool_man_text);
    al_destroy_bitmap(beast_man_text);
    al_destroy_bitmap(magical_girl_text);
}

Action Magic_effect::process(ALLEGRO_EVENT event) {
    if (frame_count == 1) al_play_sample(sound_effect, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    frame_count++;
    if(frame_count >= 300 || mouse_click(820, 1300, 250, 170, event)){
        frame_count = 0;
        return NEXT_WINDOW;
    }
    else return DO_NOTHING;
}

void Magic_effect::draw() {
    draw_background();

    if (character == TOOL_MAN) {
        al_draw_bitmap(tool_man_text, 650, 300, 0);
        al_draw_bitmap(tool_man, 860, 550, 0);
    } else if (character == BEAST_MAN) {
        al_draw_bitmap(beast_man_text, 670, 300, 0);
        al_draw_bitmap(beast_man, 800, 550, 0);
    } else if (character == MAGICAL_GIRL) {
        al_draw_bitmap(magical_girl_text, 580, 300, 0);
        al_draw_bitmap(magical_girl, 830, 550, 0);
    }
    al_draw_bitmap(pot, 480, 680, 0);
}

void Magic_effect::set_character(Character character) {
    this->character = character;
}