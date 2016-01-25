#ifndef DRAGON_H
#define DRAGON_H
#include "creature.h"
#include "fire.h"
#include <cstdlib>

class Dragon: public Creature
{
public:
    Dragon();
    char Face();
    void Move(int x, int y, Creature*** G);
    void SpitFire(int x, int y, Creature*** G);
    //Special attack of Dragon,kill all the creatures around it

    void Breed(int x, int y, Creature *** G);
    void DragonFight(int x, int y, Creature *** G);
    //When two dragon are within each attack range, this function will determin which one survives

    bool Dead();
    bool Finished();
private:
    int life;
};

#endif // DRAGON_H
