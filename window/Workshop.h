#ifndef WORKSHOP_H_INCLUDED
#define WORKSHOP_H_INCLUDED

#include "Window.h"

class Workshop : public Window {
public:
    Workshop();
    ~Workshop();
    Action process(ALLEGRO_EVENT event) override;
    void draw() override;

    void play_sound(string material);
    void reset();

private:
    ALLEGRO_SAMPLE *button_sound_effect = NULL;
    ALLEGRO_SAMPLE *grass_sound_effect = NULL;
    ALLEGRO_SAMPLE *potion_sound_effect = NULL;
    ALLEGRO_SAMPLE *mineral_sound_effect = NULL;

    ALLEGRO_BITMAP *pot = NULL;
    ALLEGRO_BITMAP *grass = NULL;
    ALLEGRO_BITMAP *mineral = NULL;
    ALLEGRO_BITMAP *potion = NULL;

    bool grass_clicked = false;
    bool mineral_clicked = false;
    bool potion_clicked = false;

    vector<string> material_vec; //紀錄選了哪兩個材料
};

#endif
