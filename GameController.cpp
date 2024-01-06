#include "GameController.h"

GameController::GameController() {
    al_init();

    display = al_create_display(window_width, window_height);
    event_queue = al_create_event_queue();

    al_set_window_position(display, x_initial_position, y_initial_position);
    al_set_window_title(display, title);

    al_init_primitives_addon(); // initialize the primitives addon
    al_init_font_addon();       // initialize the font addon
    al_init_ttf_addon();        // initialize the ttf (True Type Font) addon
    al_init_image_addon();      // initialize the image addon
    al_init_acodec_addon();     // initialize acodec addon

    al_install_keyboard();  // install keyboard event
    al_install_mouse();     // install mouse event
    al_install_audio();     // install audio event

    // Register event
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    fps = al_create_timer(1.0 / FPS);
    al_register_event_source(event_queue, al_get_timer_event_source(fps)) ;
    al_reserve_samples(20);
    al_start_timer(fps);

    menu = new Menu();
    dining_room = new DiningRoom();
    workshop = new Workshop();

    current_window = menu;
}

GameController::~GameController() {
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    delete menu;
    delete dining_room;
    delete workshop;
}

void GameController::game_establish() {
    GameState state = GAME_INIT;
    while (state != GAME_EXIT) {
        state = game_run();
    }
}

GameState GameController::game_run() {
    GameState state = GAME_CONTINUE;
    if (draw) {
        game_draw();
        draw = false;
    }
    if (!al_is_event_queue_empty(event_queue)) {
        state = process_event();
    }
    return state;
}

GameState GameController::process_event() {
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    
    if (current_window == menu) {
        if (current_window->process(event)) {
            current_window = dining_room;
        }
    } else if (current_window == dining_room) {
        if (current_window->process(event)) {
            current_window = workshop;
        }
    } else if (current_window == workshop) {
        if (current_window->process(event)) {
            current_window = dining_room;
        }
    }

    // Check if the display close button was pressed
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return GAME_EXIT; // This will cause the game loop to exit
    } else if (event.type == ALLEGRO_EVENT_TIMER) {
        if (event.timer.source == fps) {
            draw = true;
        }
    }
    return GAME_CONTINUE; 
}

void GameController::game_draw() {
    current_window->draw();
    al_flip_display();
}
