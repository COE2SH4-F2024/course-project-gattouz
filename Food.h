#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"

// Food class definition
class Food
{
private:
    objPos foodPos;              // Position of the food object
    GameMechs *gameMechsRef;     // Reference to the game mechanics

public:
    Food(GameMechs *gameMechsRef, objPosArrayList *playerPosList); // Constructor
    // Destructor omitted as no dynamic memory is used

    void generateFood(objPosArrayList *blockedPositions); // Generate a new position for food

    bool checkSelfCollision(objPosArrayList *playerPosList); // Check if food collides with the player's head

    objPos const getFoodPos(); // Get the current position of the food object
};

#endif
