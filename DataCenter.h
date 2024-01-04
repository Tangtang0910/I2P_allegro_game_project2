#ifndef DATACENTER_H_INCLUDED
#define DATACENTER_H_INCLUDED
#include <vector>
#include <list>
#include "Monster.h"
#include "Tower.h"
#include "Hero.h"

class DataCenter{
public:
    std::vector<Monster*>& get_Monster()
    {
        return monsterSet;
    }
    std::list<Tower*>& get_Tower()
    {
        return towerSet;
    }
    Hero &get_Hero(){
        return dragonite;
    }
private:
    std::vector<Monster*> monsterSet;
    std::list<Tower*> towerSet;
    Hero dragonite;
};

extern DataCenter* const DC;

#endif
