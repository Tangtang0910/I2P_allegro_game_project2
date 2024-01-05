#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <allegro5/allegro_font.h>

#define font_size 12
#define grid_width 40
#define grid_height 40

#define window_width 1900
#define window_height 1500
#define field_width 600
#define field_height 600

//new created Element
#define Num_ElementType 3

#define Num_TowerType 5
#define Num_MonsterType 4
#define NumOfGrid (field_width / grid_width) * (field_height / grid_height)

extern int TowerRadius[];
extern char TowerClass[][20];

//new created Element
extern char ElementType[][3];
extern int ElementWidth[];
extern int ElementHeight[];

extern int TowerWidth[];
extern int TowerHeight[];
extern bool key_state[ALLEGRO_KEY_MAX];

enum {ARCANE = 0, ARCHER, CANON, POISON, STORM};
enum {WOLF = 0, WOLFKNIGHT, DEMONNIJIA, CAVEMAN};

#endif // GLOBAL_H_INCLUDED
