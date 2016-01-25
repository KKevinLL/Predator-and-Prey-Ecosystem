#ifndef CREATURE_H
#define CREATURE_H

const int size = 200; //Size of the Grid

class Creature
{
public:
    Creature();
    virtual char Face() = 0;
    //Return a char to represent its type
    virtual void Move(int x, int y, Creature*** G) = 0;
    //Move function for Creatures
    virtual void Breed(int x, int y, Creature*** G) = 0;
    //Breed function for Creatures
    virtual bool Dead() = 0;
    //Determin if the Creature is dead
    virtual bool Finished() = 0;
    //Determin if the Creature has finished its movement
    bool Finish;
    int round; //round that Creature has existed
};

#endif // CREATURE_H
