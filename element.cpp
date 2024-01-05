#include "element.h"

Tower::Tower(int pos_x, int pos_y)
{
    this->circle = new Circle(pos_x, pos_y, 70);
}

Tower::~Tower()
{
    delete circle;

    al_destroy_bitmap(img);

    
}

void
Tower::Draw()
{
    int draw_x = circle->x - (TowerWidth[this->type]/2);
    int draw_y = circle->y - (TowerHeight[this->type] - (TowerWidth[this->type]/2));


    al_draw_bitmap(img, draw_x, draw_y, 0);

    if(isClicked)
    {
        al_draw_filled_circle(circle->x, circle->y, circle->r, al_map_rgba(196, 79, 79, 200));
        al_draw_filled_circle(circle->x, circle->y, 2, al_map_rgb(0, 0, 0));
    }
}

void
Tower::SelectedElement(int mouse_x, int mouse_y, int type)
{
    int draw_x = mouse_x - (TowerWidth[type]/2);
    int draw_y = mouse_y - (TowerHeight[type] - (TowerWidth[type]/2));
    char filename[50];
    ALLEGRO_BITMAP *bitmap;

    sprintf(filename, "./Tower/%s.png", TowerClass[type]);
    bitmap = al_load_bitmap(filename);

    al_draw_bitmap(bitmap, draw_x, draw_y, 0);
    al_draw_filled_circle(mouse_x, mouse_y, TowerRadius[type], al_map_rgba(196, 79, 79, 200));
    al_draw_filled_circle(mouse_x, mouse_y, 2, al_map_rgb(0, 0, 0));

    al_destroy_bitmap(bitmap);
}