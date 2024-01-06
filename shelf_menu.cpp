#include "shelf_menu.h"

const int ThumbWidth = 50;
const int ThumbHeight = 50;
const int gapX = 40, gapY = 30;
const int offsetX = 30 + field_width, offsetY = 150;


bool
Shelf_Menu::isInRange(int point, int startPos, int length)
{
    if(point >= startPos && point <= startPos + length)
        return true;

    return false;
}

Shelf_Menu::Shelf_Menu()
{
    char filename[50];

    for(int i=0;i<Num_TowerType; i++)
    {
        ALLEGRO_BITMAP *element;
        sprintf(filename, "./Element/%s_Menu.png", ElementType[i]);

        element = al_load_bitmap(filename);
        menu_element.push_back(element);
    }
    menuFont = al_load_ttf_font("pirulen.ttf", 12, 0); // load font
}
//destroy
Shelf_Menu::~Shelf_Menu()
{
    al_destroy_font(menuFont);

    for(int i=0; i < Num_TowerType; i++)
        al_destroy_bitmap(menu_element[i]);
    menu_element.clear();
}

void
Shelf_Menu::menu_process(ALLEGRO_EVENT event){
    
}

int
Shelf_Menu::MouseIn(int mouse_x, int mouse_y)
{
    selectedElement = -1;

    for(int i=0; i < Num_TowerType; i++)
    {
        int pos_x = offsetX + (ThumbWidth + gapX) * (i % 2);
        int pos_y = offsetY + (ThumbHeight + gapY) * (i / 2);

        if(isInRange(mouse_x, pos_x, ThumbWidth) && isInRange(mouse_y, pos_y, ThumbHeight))
        {
            selectedElement = i;
            break;
        }
    }
    return selectedElement;
}

void
Shelf_Menu::Draw_Self(){
    char buffer[50];

    for(int i=0; i < Num_TowerType; i++)
    {
        int pos_x = offsetX + (ThumbWidth + gapX) * (i % 2);
        int pos_y = offsetY + (ThumbHeight + gapY) * (i / 2);

        al_draw_bitmap(menu_element[i], pos_x, pos_y, 0);

        if(i == selectedElement)
            al_draw_rectangle(pos_x, pos_y, pos_x + ThumbWidth, pos_y + ThumbHeight, al_map_rgb(255, 0, 0), 0);
        else
            al_draw_rectangle(pos_x, pos_y, pos_x + ThumbWidth, pos_y + ThumbHeight, al_map_rgb(255, 255, 255), 0);
    }
}