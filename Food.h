#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"

class Food
{
private:
    objPos position;       
    GameMechs* gameLogic;  // Updated variable name for readability

public:
    Food(GameMechs* gameMechanics, objPosArrayList* playerPosition);
    ~Food();

    void generateNewPosition(objPosArrayList* restrictedAreas); 
    bool isCollisionDetected(objPosArrayList* playerPosition);  
    objPos getPosition() const;                                

};

#endif // FOOD_H
