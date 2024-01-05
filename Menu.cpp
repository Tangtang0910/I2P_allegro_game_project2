#include "Menu.h"

const int ThumbWidth = 50;
const int ThumbHeight = 50;
const int gapX = 40, gapY = 30;
const int offsetX = 30 + field_width, offsetY = 150;
const int Initial_Health = 1;
const int Initial_Coin = 10;

bool
Menu::isInRange(int point, int startPos, int length)
{
    if(point >= startPos && point <= startPos + length)
        return true;

    return false;
}

bool
Menu::Enough_Coin(int type)
{

    if(type < 0 || type >= Num_TowerType)
        return false;

    return (Coin + need_coin[type] >= 0);
}

Menu::Menu()
{
    char filename[50];

    HealthPoint = 10;
    Coin = 0;
    Score = 0;

    for(int i=0;i<Num_TowerType; i++)
    {
        ALLEGRO_BITMAP *tower;
        sprintf(filename, "./Tower/%s_Menu.png", TowerClass[i]);

        tower = al_load_bitmap(filename);
        menu_tower.push_back(tower);
    }

    love = al_load_bitmap("./Tower/love.png");

    menuFont = al_load_ttf_font("pirulen.ttf", 12, 0); // load font
}

Menu::~Menu()
{
    al_destroy_bitmap(love);
    al_destroy_font(menuFont);

    for(int i=0; i < Num_TowerType; i++)
        al_destroy_bitmap(menu_tower[i]);

    menu_tower.clear();
}

void
Menu::Reset()
{
    HealthPoint = Initial_Health;
    Coin = Initial_Coin;
    Score = 0;
    killedMonster = 0;
}

void
Menu::Draw()
{
    al_draw_rectangle(670, 1330, 1250, 1190, al_map_rgb(255, 0, 0), 3.0);
}

int
Menu::MouseIn(int mouse_x, int mouse_y)
{
    bool enoughCoin;

    selectedTower = -1;

    for(int i=0; i < Num_TowerType; i++)
    {
        int pos_x = offsetX + (ThumbWidth + gapX) * (i % 2);
        int pos_y = offsetY + (ThumbHeight + gapY) * (i / 2);

        if(isInRange(mouse_x, pos_x, ThumbWidth) && isInRange(mouse_y, pos_y, ThumbHeight))
        {
            if(Enough_Coin(i))
            {
                selectedTower = i;
                break;
            }
        }
    }
    return selectedTower;
}

bool
Menu::Subtract_HP(int escapeNum)
{
    HealthPoint -= escapeNum;

    return (HealthPoint == 0);
}

void
Menu::Gain_Score(int scoreWorth)
{
    killedMonster++;
    Score += scoreWorth;
}


