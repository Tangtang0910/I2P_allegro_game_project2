#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "../global.h"
#include "../utils.h"

class Window {
public:
    Window();
    virtual bool process(ALLEGRO_EVENT event);
    virtual void draw();
    virtual void destroy();
};

#endif
