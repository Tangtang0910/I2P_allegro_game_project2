#ifndef MAGIC_EFFECT_H_INCLUDED
#define MAGIC_EFFECT_H_INCLUDED

#include "Window.h"

class Magic_effect : public Window {
public:
    Magic_effect();
    ~Magic_effect();
    Action process(ALLEGRO_EVENT event) override;
    void draw() override;

private:
    ALLEGRO_SAMPLE *sound_effect = NULL;
};

#endif
