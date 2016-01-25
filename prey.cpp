#include "prey.h"
#include <iostream>
#include <vector>

using namespace std;

Prey::Prey()
{
    Finish = false;
    round = 0;
}

char Prey::Face()
{
    return 'P';
}

void Prey::Move(int x, int y, Creature*** G)
{
    vector<int> d;
    if(y > 0 && G[x][y-1] == NULL)
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
        round++;
    }
}

void Prey::Breed(int x, int y, Creature*** G)
{
    if(round == 4)
    {
        vector<int> d;
        if(y > 0 && G[x][y-1] == NULL)
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
                G[x][y-1] = new Prey;
                break;
            case 2:
                G[x+1][y] = new Prey;
                break;
            case 3:
                G[x][y+1] = new Prey;
                break;
            case 4:
                G[x-1][y] = new Prey;
                break;
            }
            round = 0;
        }
    }
    else if(round > 4)
    {
        round = 0;
    }
}

bool Prey::Dead()
{
    return false;
}

bool Prey::Finished()
{
    if(Finish == true)
        return true;
    return false;
}
