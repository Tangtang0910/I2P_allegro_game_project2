#include "Window.h"

Window::Window() {

}

Window::~Window() {
    al_destroy_bitmap(background);
    al_destroy_bitmap(pot);
    al_destroy_bitmap(potion);
    al_destroy_bitmap(mineral);
    al_destroy_bitmap(grass);
}

bool Window::process(ALLEGRO_EVENT event) {
    return true;
}

void Window::draw() {
    return;
}

void Window::set_background(string filename) {
    background = al_load_bitmap(filename.c_str());
    pot = al_load_bitmap("./images/pot.png");
    grass = al_load_bitmap("./images/grass.png");
    mineral = al_load_bitmap("./images/mineral.png");
    potion = al_load_bitmap("./images/potion.png");
}   

void Window::draw_background() {
    al_draw_scaled_bitmap(
        background, 0, 0, 
        al_get_bitmap_width(background), 
        al_get_bitmap_height(background), 
        0, 0, window_width, window_height, 0
    );
}
void Window::draw_materail(){
    al_draw_scaled_bitmap(pot, 0, 0,
        al_get_bitmap_width(pot), 
        al_get_bitmap_height(pot), 
        620, 680, 
        600, 600, 0
    );
    al_draw_scaled_bitmap(grass, 0, 0,
        al_get_bitmap_width(grass), 
        al_get_bitmap_height(grass), 
        40, 940, 
        al_get_bitmap_width(grass), al_get_bitmap_height(grass),  0
    );
    al_draw_scaled_bitmap(mineral, 0, 0,
        al_get_bitmap_width(mineral), 
        al_get_bitmap_height(mineral), 
        1500, 500, 
        280, 370, 0
    );
    al_draw_scaled_bitmap(potion, 0, 0,
        al_get_bitmap_width(potion), 
        al_get_bitmap_height(potion), 
        1260 , 350 , 
        al_get_bitmap_width(potion)* 2 , al_get_bitmap_height(potion)* 2, 0
    );
}

bool Window::mouse_click(int start_x, int start_y, int width, int height, ALLEGRO_EVENT event) {
    int mouse_x = event.mouse.x;
    int mouse_y = event.mouse.y;
    return (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        && (mouse_x >= start_x && mouse_x <= start_x + width)
        && (mouse_y >= start_y && mouse_y <= start_y + height);
}