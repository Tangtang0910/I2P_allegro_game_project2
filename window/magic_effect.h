#ifndef MAGIC_EFFECT_H_INCLUDED
#define MAGIC_EFFECT_H_INCLUDED

#include "Window.h"

class Magic_effect : public Window {
public:
    Magic_effect();
    ~Magic_effect();
    Action process(ALLEGRO_EVENT event) override;
    void draw() override;

    void set_character(Character character);

private:
    ALLEGRO_BITMAP *pot = NULL;
    ALLEGRO_BITMAP *tool_man = NULL;
    ALLEGRO_BITMAP *beast_man = NULL;
    ALLEGRO_BITMAP *magical_girl= NULL;

    ALLEGRO_BITMAP *tool_man_text = NULL;
    ALLEGRO_BITMAP *beast_man_text = NULL;
    ALLEGRO_BITMAP *magical_girl_text= NULL;

    Character character = NO_ONE;

    ALLEGRO_SAMPLE *sound_effect = NULL;

    int frame_count = 0;
};

#endif
