#ifndef FIRE_H
#define FIRE_H
#include "creature.h"
#include <cstdlib>

class Fire: public Creature //Fire of Dragon
{
public:
    Fire();
    char Face();
    void Move(int x, int y, Creature*** G);
    void Breed(int x, int y, Creature *** G);
    bool Dead();
    bool Finished();
};

#endif // FIRE_H
