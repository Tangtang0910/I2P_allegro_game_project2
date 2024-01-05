#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "Object.h"
#include "Circle.h"

#include "global.h"

class Element : public Object
{
public:
    Element(int = 0, int = 0);
    virtual ~Element();

    // override virtual function "Object::Draw"
    void Draw();

    void ToggleClicked() { isClicked = !isClicked; }

    virtual int getWidth() { return 40; }
    virtual int getHeight() { return 40; }

    // show selected tower image on cursor position
    static void SelectedElement(int, int, int);

protected:
    // information of tower
    int type;
    bool isClicked = false;
    ALLEGRO_BITMAP *img;
};

#endif // ELEMENT_H_INCLUDED
