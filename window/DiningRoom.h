#ifndef DININGROOM_H_INCLUDED
#define DININGROOM_H_INCLUDED

#include "Window.h"

class DiningRoom : public Window {
public:
    DiningRoom();
    ~DiningRoom();
    Action process(ALLEGRO_EVENT event) override;
    void draw() override;

    void play_action(string button);
    void play_sound(string button);
    void set_character(Character character);

private:
    ALLEGRO_BITMAP *text1 = NULL;
    ALLEGRO_BITMAP *text2 = NULL;
    ALLEGRO_BITMAP *text3 = NULL;
    ALLEGRO_BITMAP *heart = NULL;
    ALLEGRO_BITMAP *arrow = NULL;

    ALLEGRO_BITMAP *tool_man = NULL;
    ALLEGRO_BITMAP *beast_man = NULL;
    ALLEGRO_BITMAP *magical_girl= NULL;

    vector<ALLEGRO_BITMAP *> *current_video = NULL;
    vector<ALLEGRO_BITMAP *> tool_man_talk1_frames;
    vector<ALLEGRO_BITMAP *> tool_man_talk2_frames;
    vector<ALLEGRO_BITMAP *> tool_man_talk3_frames;
    vector<ALLEGRO_BITMAP *> tool_man_pet_frames;
    vector<ALLEGRO_BITMAP *> tool_man_feed_frames;

    vector<ALLEGRO_BITMAP *> beast_man_talk1_frames;
    vector<ALLEGRO_BITMAP *> beast_man_talk2_frames;
    vector<ALLEGRO_BITMAP *> beast_man_talk3_frames;
    vector<ALLEGRO_BITMAP *> beast_man_pet_frames;
    vector<ALLEGRO_BITMAP *> beast_man_feed_frames;

    vector<ALLEGRO_BITMAP *> magical_girl_talk1_frames;
    vector<ALLEGRO_BITMAP *> magical_girl_talk2_frames;
    vector<ALLEGRO_BITMAP *> magical_girl_talk3_frames;
    vector<ALLEGRO_BITMAP *> magical_girl_pet_frames;
    vector<ALLEGRO_BITMAP *> magical_girl_feed_frames;

    ALLEGRO_SAMPLE *react_button = NULL;
    ALLEGRO_SAMPLE *trash_button = NULL;
    ALLEGRO_SAMPLE *home_button = NULL;

    double last_action_time;
    int fav;
    int current_frame = INT_MAX;
    int frame_count;
    int tool_man_talk_ver;
    int magical_girl_talk_ver;

    Character character = NO_ONE;
};

#endif
