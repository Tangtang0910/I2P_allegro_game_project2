#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include "global.h"

typedef struct Node {
    int h, g, f;
    bool roadPoint;
}Node;

class LEVEL {
public:
    LEVEL(const int);
    ~LEVEL();

    void setLevel(const int);
    bool isRoad(int index) { return levelMap[index].roadPoint; }

    //void search_destination();
    std::vector<int> ReturnPath() { return pot_grid; }

private:
    Node levelMap[NumOfGrid];
    std::vector<int> pot_grid;
};


#endif // LEVEL_H_INCLUDED
