#include "fire.h"

Fire::Fire()
{
    round = 0;
    Finish = false;
}

char Fire::Face()
{
    return 'F';
}

void Fire::Move(int x, int y, Creature*** G)
{
    if(Dead())
    {
        delete G[x][y];
        G[x][y] = NULL;
    }
    Finish = true;

}

void Fire::Breed(int x, int y, Creature *** G)
{
    round++;
}

bool Fire::Dead()
{
    if(round == 1)
        return true;
    return false;
}

bool Fire::Finished()
{
    if(Finish == true)
        return true;
    return false;
}
