#include "GameWindow.h"
#include "global.h"
#include <iostream>

GameWindow::GameWindow()
{
    printf("Game Initializing...\n");

    al_init();

    display = al_create_display(window_width, window_height);
    event_queue = al_create_event_queue();

    al_set_window_position(display, 270, 80); //螢幕出現位置
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon
    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event
    // Register event
    al_register_event_source(event_queue, al_get_display_event_source( display ));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    fps  = al_create_timer( 1.0 / FPS );
    al_register_event_source(event_queue, al_get_timer_event_source( fps )) ;
    al_reserve_samples(20);
    al_start_timer(fps);

    init_background = al_load_bitmap("./images/background/initial_room.png");

    menu = new Menu();
    dining_room = new Dining_room();
    alchemy_room = new Alchemy_room();
}

int
GameWindow::game_establish()
{
    int msg = 0;
    
    while ( msg != GAME_EXIT ) {
        msg = game_run();
        if ( msg == GAME_EXIT )
            printf( "Game Over\n" );
    }

    game_destroy();
    return 0;
}

int
GameWindow::game_run()
{
    int error = 0;
    if( draw ){
        game_draw();
        draw = false;
    }
    if ( !al_is_event_queue_empty(event_queue) ) {
        error = process_event();
    }
    return error;
}

int
GameWindow::process_event()
{
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    
    if(window == 0){
        if(menu->menu_process(event)){
            menu->menu_destroy();
            window = 1;
        }
    }else if(window == 1){
        if(dining_room->dining_room_process(event)){cout << "hihi" << endl;
            dining_room->dining_room_destroy();
            window = 2;
        }
    }else if(window == 2){
        if(alchemy_room->alchemy_room_process(event)){cout << "hoho" << endl;
            alchemy_room->alchemy_room_destroy();
            window = 1;
        }
    }

    // Check if the display close button was pressed
    if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return GAME_EXIT; // This will cause the game loop to exit
    }
    else if(event.type == ALLEGRO_EVENT_TIMER)
        if(event.timer.source == fps)
            draw = true;
    return 0; 
}

void
GameWindow::game_draw()
{
    al_draw_scaled_bitmap(init_background, 0, 0, al_get_bitmap_width(init_background), al_get_bitmap_height(init_background), 0, 0, window_width, window_height, 0);

    if(window == 0){
        menu->menu_draw();
    }else if(window == 1){
        dining_room->dining_room_draw();
    }
    else if(window == 2){
        alchemy_room->alchemy_room_draw();
    }

    al_flip_display();//把所有畫面呈現出來
}

void
GameWindow::game_destroy()
{
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    al_destroy_bitmap(init_background);

    delete menu;
    delete dining_room;
    delete alchemy_room;
}