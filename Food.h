#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"

// Food class definition
class Food
{

private:
    objPos foodPosition;                // Position of the food object
    GameMechs *gameMechanicsReference;  // Reference to the game mechanics

public:
    Food(GameMechs *gameReference, objPosArrayList *playerPositionList); // Constructor
    // Destructor omitted as no heap memory is used

    void generateFood(objPosArrayList *blockedPositions); // Generate a new position for food

    bool checkSelfCollision(objPosArrayList *playerPositionList); // Check if food collides with the player's head

    objPos const getFoodPosition(); // Get the current position of the food object
};

#endif
