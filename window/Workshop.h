#ifndef WORKSHOP_H_INCLUDED
#define WORKSHOP_H_INCLUDED

#include "Window.h"

class Workshop : public Window {
public:
    Workshop();
    ~Workshop();
    bool process(ALLEGRO_EVENT event) override;
    void draw() override;

private:
    ALLEGRO_SAMPLE *button_sound_effect = NULL;
    ALLEGRO_SAMPLE *grass_sound_effect = NULL;
    ALLEGRO_SAMPLE *potion_sound_effect = NULL;
    ALLEGRO_SAMPLE *mineral_sound_effect = NULL;

    ALLEGRO_BITMAP *pot = NULL;
    ALLEGRO_BITMAP *grass = NULL;
    ALLEGRO_BITMAP *mineral = NULL;
    ALLEGRO_BITMAP *potion = NULL;

    
};

#endif
