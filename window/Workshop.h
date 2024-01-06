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
    ALLEGRO_SAMPLE *carrot_sound_effect = NULL;
    ALLEGRO_SAMPLE *bottle_sound_effect = NULL;
    ALLEGRO_SAMPLE *crystal_sound_effect = NULL;
};

#endif
