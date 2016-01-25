#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "creature.h"
#include "human.h"
#include <cstdlib>

class Vampire: public Creature
{
public:
    Vampire();
    char Face();
    void Move(int x, int y, Creature*** G);
    void Breed(int x, int y, Creature *** G);

    void Turn(int x, int y, Creature *** G);
    //Turn the nearest Human to A vampire

    void Back(int x, int y, Creature *** G);
    //A dead vampire will have half of the chance to turn back to a human

    bool Dead();
    bool Finished();
private:
    int blood; // vampire's life timer
};

#endif // VAMPIRE_H
