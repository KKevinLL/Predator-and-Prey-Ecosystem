#include "vampire.h"
#include <iostream>
#include <vector>

using namespace std;

Vampire::Vampire()
{
    Finish = false;
    blood = 100;
    round = 0;
}

char Vampire::Face()
{
    return 'V';
}

void Vampire::Move(int x, int y, Creature*** G)
{
    if(Dead())
    {
        int revive = rand()%2;
        if(revive == 1)
        {
            delete G[x][y];
            G[x][y] = NULL;
        }
        else
            Back(x,y,G);
    }
    else
    {
        vector<int> d;
        if(y > 0 && G[x][y-1] == NULL )
            d.push_back(1);
        if(x < size-1 && G[x+1][y] == NULL)
            d.push_back(2);
        if(y < size-1 && G[x][y+1] == NULL)
            d.push_back(3);
        if(x > 0 && G[x-1][y] == NULL)
            d.push_back(4);
        int l = d.size();
        if(l != 0)
        {
            int dr = rand()%l;
            switch(d[dr])
            {
            case 1:
                G[x][y-1] = G[x][y];
                G[x][y] = NULL;
                break;
            case 2:
                G[x+1][y] = G[x][y];
                G[x][y] = NULL;
                break;
            case 3:
                G[x][y+1] = G[x][y];
                G[x][y] = NULL;
                break;
            case 4:
                G[x-1][y] = G[x][y];
                G[x][y] = NULL;
                break;
            }
            Finish = true;
        }
        blood--;
    }
}

void Vampire::Breed(int x, int y, Creature *** G)
{
        Turn(x,y,G);
}

void Vampire::Turn(int x, int y, Creature *** G)
{
    vector<int> t;
    if(y > 0 && G[x][y-1] != NULL && G[x][y-1]->Face()=='H')
    {
        t.push_back(1);
    }
    if(x < size-1 && G[x+1][y] != NULL && G[x+1][y]->Face()=='H')
    {
        t.push_back(2);
    }
    if(y < size-1 && G[x][y+1] != NULL && G[x][y+1]->Face()=='H')
    {
        t.push_back(3);
    }
    if(x > 0 && G[x-1][y] != NULL && G[x-1][y]->Face()=='H')
    {
        t.push_back(4);
    }
    int l = t.size();
    if(l!=0)
    {
        int dr = rand()%l;
        switch(t[dr])
        {
        case 1:
            delete G[x][y-1];
            G[x][y-1] = NULL;
            G[x][y-1] = new Vampire;
            break;
        case 2:
            delete G[x+1][y];
            G[x+1][y] = NULL;
            G[x+1][y] = new Vampire;
            break;
        case 3:
            delete G[x][y+1];
            G[x][y+1] = NULL;
            G[x][y+1] = new Vampire;
            break;
        case 4:
            delete G[x-1][y];
            G[x-1][y] = NULL;
            G[x-1][y] = new Vampire;
            break;
        }
        blood++;
    }
}

void Vampire::Back(int x, int y, Creature *** G)
{
    delete G[x][y];
    G[x][y] = NULL;
    G[x][y] = new Human;
}

bool Vampire::Dead()
{
    if(blood == 0)
        return true;
    return false;
}

bool Vampire::Finished()
{
    if(Finish == true)
        return true;
    return false;
}
