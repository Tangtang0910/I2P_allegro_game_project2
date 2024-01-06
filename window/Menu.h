#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Window.h"

class Menu : public Window {
public:
    Menu();
    ~Menu();
    bool process(ALLEGRO_EVENT event) override;
    void draw() override;

private:
    ALLEGRO_SAMPLE *sound_effect = NULL;
};

#endif
