#include "Window.h"

Window::Window() {

}

Window::~Window() {
    al_destroy_bitmap(background);
}

bool Window::process(ALLEGRO_EVENT event) {
    return true;
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

bool Window::mouse_click(int start_x, int start_y, int width, int height, ALLEGRO_EVENT event) {
    int mouse_x = event.mouse.x;
    int mouse_y = event.mouse.y;
    return (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        && (mouse_x >= start_x && mouse_x <= start_x + width)
        && (mouse_y >= start_y && mouse_y <= start_y + height);
}