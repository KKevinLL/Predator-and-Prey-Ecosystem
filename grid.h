#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <fstream>
#include "creature.h"
#include "dragon.h"
#include "vampire.h"
#include "fire.h"
#include "human.h"
#include "prey.h"
#include <cstdlib>



using namespace std;

class Grid
{

public:
    Grid();
    ~Grid();

    void InitializeH();
    // Add Human to the Grid

    void InitializeP();
    //Add Prey to the Grid

    void InitializeD();
    //Add Dragon to the Grid

    void InitializeV();
    //Add Vampire to the Grid

    void Display();

    void Set(int x, int y, Creature* SetThis);
    //Set a point to SetThis in the grid

    void Run();
    void Save();
    //save the current grid to file

    void Load();
    //load a file to the grid

    Creature* Getthis(int x, int y);

private:
    Creature*** grid;
};

#endif // GRID_H
