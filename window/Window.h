#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "../global.h"

class Window {
public:
    Window();
    ~Window();

    virtual Action process(ALLEGRO_EVENT event);
    virtual void draw();

    void set_background(string filename);
    void draw_background();
    vector<ALLEGRO_BITMAP *> read_video(string prefix, int length);

    bool mouse_click(int startx, int starty, int width, int height, ALLEGRO_EVENT event);

    const float video_speed = 0.5;
    const int video_stay_frame = 40;

private:
    ALLEGRO_BITMAP *background = NULL;
};

#endif
