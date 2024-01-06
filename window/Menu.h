#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Window.h"

class Menu : public Window {
public:
    Menu();
    bool process(ALLEGRO_EVENT event) override;
    void draw() override;
    void destroy() override;

private:
    ALLEGRO_BITMAP *background = NULL;
};

#endif
