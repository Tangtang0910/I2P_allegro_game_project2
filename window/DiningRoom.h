#ifndef DININGROOM_H_INCLUDED
#define DININGROOM_H_INCLUDED

#include "Window.h"

class DiningRoom : public Window {
public:
    DiningRoom();
    ~DiningRoom();
    Action process(ALLEGRO_EVENT event) override;
    void draw() override;

    // void play_action(string button);
    void play_sound(string button);
    void set_character(Character character);

private:
    ALLEGRO_BITMAP *text1 = NULL;
    ALLEGRO_BITMAP *text2 = NULL;
    ALLEGRO_BITMAP *text3 = NULL;
    ALLEGRO_BITMAP *heart = NULL;

    ALLEGRO_BITMAP *tool_man = NULL;
    ALLEGRO_BITMAP *beast_man = NULL;
    ALLEGRO_BITMAP *magical_girl= NULL;

    ALLEGRO_SAMPLE *react_button = NULL;
    ALLEGRO_SAMPLE *trash_button = NULL;
    ALLEGRO_SAMPLE *home_button = NULL;

    double last_action_time;
    int fav;

    Character character = NO_ONE;
};

#endif
