#ifndef ARCANE_H_INCLUDED
#define ARCANE_H_INCLUDED

#include "element.h" 

class Grass : public Element
{
public:
    Grass(int mouse_x, int mouse_y) : Element(mouse_x, mouse_y)
    {
        type = Material;

        circle->r = 80;

        img = al_load_bitmap("./element/Grass.png");
    }

    int getWidth() override { return ElementWidth[Material]; }
    int getHeight() override { return ElementHeight[Material]; }
};

#endif // ARCANE_H_INCLUDED
