#include "Window.h"

Window::Window() {
}

Window::~Window() {
    al_destroy_bitmap(background);
}

Action Window::process(ALLEGRO_EVENT event) {
    return DO_NOTHING;
}

void Window::draw() {
    return;
}

void Window::set_background(string filename) {
    background = al_load_bitmap(filename.c_str());
}   

void Window::draw_background() {
    al_draw_scaled_bitmap(
        background, 0, 0, 
        al_get_bitmap_width(background), 
        al_get_bitmap_height(background), 
        0, 0, window_width, window_height, 0
    );
}

vector<ALLEGRO_BITMAP *> Window::read_video(string prefix, int length) {
    vector<ALLEGRO_BITMAP *> frames(length, NULL);
    for (int i = 0; i < length; i++) {
        ostringstream stream;
        stream << setw(5) << setfill('0') << i;
        string filename = prefix + stream.str() + ".png";
        frames[i] = al_load_bitmap(filename.c_str());
    }
    return frames;
}

bool Window::mouse_click(int start_x, int start_y, int width, int height, ALLEGRO_EVENT event) {
    int mouse_x = event.mouse.x;
    int mouse_y = event.mouse.y;
    return (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        && (mouse_x >= start_x && mouse_x <= start_x + width)
        && (mouse_y >= start_y && mouse_y <= start_y + height);
}