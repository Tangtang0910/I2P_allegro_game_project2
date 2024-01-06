#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "Object.h"
#include "Circle.h"
#include "global.h"
#include "DataCenter.h"

class Shelf_Menu
{
public:
    //create menu
    Shelf_Menu();
    //destroy menu
    virtual ~Shelf_Menu();
    //draw menu
    void Draw_Self();

    // Detect if cursor hovers over any of tower on menu
    // If so, return its type
    // Otherwise, return -1
    int MouseIn(int, int);

    // static function that detect if one point is on a line
    // This function is just used to simplify "MouseIn"
    static bool isInRange(int, int, int);
 
    void menu_process(ALLEGRO_EVENT event);

private:
    std::vector<ALLEGRO_BITMAP*> menu_element;
    ALLEGRO_FONT *menuFont;
    int selectedElement = -1;
};

#endif // MENU_H_INCLUDED
