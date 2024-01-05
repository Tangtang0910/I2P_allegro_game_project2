#ifndef DATACENTER_H_INCLUDED
#define DATACENTER_H_INCLUDED
#include <vector>
#include <list>
#include "element.h"
#include "Alchemy_room.h"

class DataCenter{
public:
    std::list<Element*>& get_Element()
    {
        return ElementSet;
    }
private:
    std::list<Element*> ElementSet;
};

extern DataCenter* const DC;

#endif
