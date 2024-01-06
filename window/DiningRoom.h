#ifndef DININGROOM_H_INCLUDED
#define DININGROOM_H_INCLUDED

#include "Window.h"

class DiningRoom : public Window {
public:
    DiningRoom();
    ~DiningRoom();
    bool process(ALLEGRO_EVENT event) override;
    void draw() override;
};

#endif
