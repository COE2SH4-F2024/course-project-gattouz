#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h" // Include this to use objPosArrayList
#include "GameMechs.h"

class Food
{
private:
    objPos position;       
    GameMechs* gameLogic;  // Game mechanics pointer for board size and logic

public:
    Food(GameMechs* gameMechanics, objPosArrayList* playerPosition);
    ~Food();

    void generateNewPosition(objPosArrayList* restrictedAreas); 
    bool isCollisionDetected(objPosArrayList* playerPosition) const; // Updated to `const`
    objPos getFoodPos() const;
};

#endif // FOOD_H
