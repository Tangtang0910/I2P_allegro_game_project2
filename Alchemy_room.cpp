#include<allegro5/allegro.h>
#include<algorithm>
#include"Alchemy_room.h"
#include "global.h"
#include "element.h"

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

void Alchemy_room::Alchemy_init()
{
    char buffer[50];

    pot = al_load_bitmap("./Alchemy_workshop/pot.png");
    background = al_load_bitmap("./Alchemy_workshop/room.jpg");

    al_set_display_icon(display, pot);

    for(int i = 0; i < Num_ElementType; i++)
    {
        sprintf(buffer, "./Element/%s.png", ElementType[i]);
        element[i] = al_load_bitmap(buffer);
    }
    menu = new Menu();
}

bool
Alchemy_room::mouse_hover(int startx, int starty, int width, int height)
{
    if(mouse_x >= startx && mouse_x <= startx + width)
        if(mouse_y >= starty && mouse_y <= starty + height)
            return true;

    return false;
}

bool
Alchemy_room::isOnPot()
{
    int startx, starty;
    int widthOfElement;

    widthOfElement = ElementWidth[selectedElement];

    for(int i=0; i < NumOfGrid; i++)
    {
        startx = (i % 15) * 40;
        starty = (i / 15) * 40;

        if(level->isPot(i)) {
            if((mouse_x + (widthOfElement/2) < startx) || (mouse_x - (widthOfElement/2) > startx + grid_width))
                continue;
            else if((mouse_y + (widthOfElement/2) < starty) || (mouse_y > starty + grid_height))
                continue;
            else
                return true;
        }
    }
    return false;
}

Tower*
Alchemy_room::create_element(int type)
{
    Tower *t = NULL;

    if(isOnPot())
        return t;

    switch(type)
    {
    case 1:
        //t = new Grass(mouse_x, mouse_y);
        break;
    case 2:
        //t = new Stone(mouse_x, mouse_y);
        break;
    case 3:
        //t = new Water(mouse_x, mouse_y);
        break;
    default:
        break;
    }
    return t;
}

void
Alchemy_room::Alchemy_play()
{
    int msg;

    srand(time(NULL));

    msg = -1;
    Alchemy_reset();
    Alchemy_begin();

    while(msg != GAME_EXIT)
    {
        msg = Alchemy_run();
    }

    Alchemy_err_msg(msg);
}

void
Alchemy_room::Alchemy_err_msg(int msg)
{
    if(msg == GAME_TERMINATE)
        fprintf(stderr, "Alchemy Terminated...");
    else
        fprintf(stderr, "Alchemy unexpected msg: %d", msg);

    Alchemy_destroy();
    exit(9);
}

Alchemy_room::Alchemy_room()
{
    if (!al_init())
        Alchemy_err_msg(-1);
    printf("Game Initializing...\n");
    display = al_create_display(window_width, window_height);
    event_queue = al_create_event_queue();

    //timer = al_create_timer(1.0 / FPS);

    if(timer == NULL)
        Alchemy_err_msg(-1);

    if (display == NULL || event_queue == NULL)
        Alchemy_err_msg(-1);

    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon

    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event

    font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",12,0); // load small font
    Medium_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",24,0); //load medium font
    Large_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",36,0); //load large font

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    Alchemy_init();
}

void
Alchemy_room::Alchemy_begin()
{
    printf(">>> Start Level[%d]\n", level->getLevel());
    draw_Alchemy_running_map();

    al_start_timer(timer);
}

int
Alchemy_room::Alchemy_run()
{
    int error = GAME_CONTINUE;

    if (!al_is_event_queue_empty(event_queue)) {

        error = process_Alchemy_event();
    }
    return error;
}

int
Alchemy_room::Alchemy_update()
{
    unsigned int i, j;
    std::list<Tower*>::iterator it;

    return GAME_CONTINUE;
}

void
Alchemy_room::Alchemy_reset()
{
    // reset game and begin
    for(auto&& child : towerSet) {
        delete child;
    }
    towerSet.clear();


    selectedElement = -1;
    lastClicked = -1;

    redraw = false;
    menu->Reset();

    // stop timer
    al_stop_timer(timer);
}

void
Alchemy_room::Alchemy_destroy()
{
    Alchemy_reset();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font);
    al_destroy_font(Medium_font);
    al_destroy_font(Large_font);

    al_destroy_timer(timer);

    for(int i=0;i<3; i++)
        al_destroy_bitmap(element[i]);

    al_destroy_bitmap(pot);
    al_destroy_bitmap(background);


    delete level;
    delete menu;
}

int
Alchemy_room::process_Alchemy_event()
{
    int i;
    int instruction = GAME_CONTINUE;

    // offset for pause window
    int offsetX = field_width/2 - 200;
    int offsetY = field_height/2 - 200;

    al_wait_for_event(event_queue, &event);
    redraw = false;
    if(event.type == ALLEGRO_EVENT_TIMER) {
        if(event.timer.source == timer) {
            redraw = true;
        }
    }
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return GAME_EXIT;
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        if(event.mouse.button == 1) {
            if(selectedElement != -1 && mouse_hover(0, 0, field_width, field_height)) {
                Tower *t = create_element(selectedElement);

                if(t == NULL)
                    printf("Wrong place\n");
                else {
                    towerSet.push_back(t);
                    //towerSet.sort(compare);
                }
            } else if(selectedElement == -1){
                std::list<Tower*>::iterator it = towerSet.begin();
                if(lastClicked != -1)
                {
                    std::advance(it, lastClicked);
                    (*it)->ToggleClicked();
                }
                for(i=0, it = towerSet.begin(); it != towerSet.end(); it++, i++)
                {
                    Circle *circle = (*it)->getCircle();
                    int t_width = (*it)->getWidth();

                    if(mouse_hover(circle->x - t_width/2, circle->y, t_width, t_width/2))
                    {
                        (*it)->ToggleClicked();
                        lastClicked = i;
                        break;
                    } else {
                        lastClicked = -1;
                    }
                }

            }
            // check if user wants to create some kind of tower
            // if so, show tower image attached to cursor
            selectedElement = menu->MouseIn(mouse_x, mouse_y);

        }
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;

        menu->MouseIn(mouse_x, mouse_y);

    }

    if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;

    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }

    if(redraw) {
        // update each object in game
        instruction = Alchemy_update();

        // Re-draw map
        draw_Alchemy_running_map();
        redraw = false;
    }

    return instruction;
}

void
Alchemy_room::draw_Alchemy_running_map()
{
    unsigned int i, j;

    al_clear_to_color(al_map_rgb(100, 100, 100));
    al_draw_bitmap(background, 0, 0, 0);

    for(i = 0; i < field_height/40; i++)
    {
        for(j = 0; j < field_width/40; j++)
        {
            char buffer[50];
            sprintf(buffer, "%d", i*15 + j);
            if(level->isRoad(i*15 + j)) {
                al_draw_filled_rectangle(j*40, i*40, j*40+40, i*40+40, al_map_rgb(255, 244, 173));
            }
            //al_draw_text(font, al_map_rgb(0, 0, 0), j*40, i*40, ALLEGRO_ALIGN_CENTER, buffer);
        }
    }

    for(std::list<Tower*>::iterator it = towerSet.begin(); it != towerSet.end(); it++)
        (*it)->Draw();

    /*if(selectedElement != -1)
        Tower::selectedElement(mouse_x, mouse_y, selectedElement);
    */
    al_draw_filled_rectangle(field_width, 0, window_width, window_height, al_map_rgb(100, 100, 100));

    menu->Draw();

    al_flip_display();//把所有畫面呈現出來
}