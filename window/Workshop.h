#ifndef WORKSHOP_H_INCLUDED
#define WORKSHOP_H_INCLUDED

#include "Window.h"

class Workshop : public Window {
public:
    Workshop();
    ~Workshop();
    bool process(ALLEGRO_EVENT event) override;
    void draw() override;
};

#endif
