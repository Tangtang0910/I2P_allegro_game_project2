#include "magic_effect.h"

Magic_effect::Magic_effect() {
    set_background("./images/background/menu.png");

    sound_effect = al_load_sample("./sound/menu_button.wav");
}

Magic_effect::~Magic_effect() {
    al_destroy_sample(sound_effect);
}

Action Magic_effect::process(ALLEGRO_EVENT event) {
    if(mouse_click(670, 1190, 580, 140, event)) {
        al_play_sample(sound_effect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        return NEXT_WINDOW;
    }
    return DO_NOTHING;
}

void Magic_effect::draw() {
    draw_background();
}
