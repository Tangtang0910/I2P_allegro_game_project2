#include "element.h"

Element::Element(int pos_x, int pos_y)
{
    this->circle = new Circle(pos_x, pos_y, 70);
}

Element::~Element()
{
    delete circle;

    al_destroy_bitmap(img);
}

void
Element::Draw()
{
    int draw_x = circle->x - (ElementWidth[this->type]/2);
    int draw_y = circle->y - (ElementHeight[this->type] - (ElementWidth[this->type]/2));


    al_draw_bitmap(img, draw_x, draw_y, 0);

    if(isClicked)
    {
        al_draw_filled_circle(circle->x, circle->y, circle->r, al_map_rgba(196, 79, 79, 200));
        al_draw_filled_circle(circle->x, circle->y, 2, al_map_rgb(0, 0, 0));
    }
}

void
Element::SelectedElement(int mouse_x, int mouse_y, int type)
{
    int draw_x = mouse_x - (ElementWidth[type]/2);
    int draw_y = mouse_y - (ElementHeight[type] - (ElementWidth[type]/2));
    char filename[50];
    ALLEGRO_BITMAP *bitmap;

    sprintf(filename, "./Element/%s.png", ElementType[type]);
    bitmap = al_load_bitmap(filename);

    al_draw_bitmap(bitmap, draw_x, draw_y, 0);
    al_draw_filled_circle(mouse_x, mouse_y, TowerRadius[type], al_map_rgba(196, 79, 79, 200));
    al_draw_filled_circle(mouse_x, mouse_y, 2, al_map_rgb(0, 0, 0));

    al_destroy_bitmap(bitmap);
}