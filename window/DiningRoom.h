#ifndef DININGROOM_H_INCLUDED
#define DININGROOM_H_INCLUDED

#include "Window.h"

class DiningRoom : public Window {
public:
    DiningRoom();
    ~DiningRoom();
    bool process(ALLEGRO_EVENT event) override;
    void draw() override;

private:
    ALLEGRO_BITMAP *text1 = NULL;
    ALLEGRO_BITMAP *text2 = NULL;
    ALLEGRO_BITMAP *heart = NULL;

    ALLEGRO_SAMPLE *react_button = NULL;
    ALLEGRO_SAMPLE *trash_button = NULL;
    ALLEGRO_SAMPLE *home_button = NULL;

    double last_action_time;
    int fav;
};

#endif
