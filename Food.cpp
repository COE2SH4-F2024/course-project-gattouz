#include "Food.h"
#include <cstdlib> // Use for rand() and srand()
#include <ctime>   // Use for time()

Food::Food(GameMechs* gameMechanics, objPosArrayList* playerPosition)
    : gameLogic(gameMechanics)
{
    position.symbol = 'o';
    generateNewPosition(playerPosition);
}

Food::~Food()
{
    // No dynamic memory allocation, so no cleanup needed here
}

void Food::generateNewPosition(objPosArrayList* restrictedAreas)
{
    int xCoordinate, yCoordinate;
    bool isValidPosition;

    do
    {
        // Generate random coordinates within the game board boundaries
        xCoordinate = rand() % (gameLogic->getBoardSizeX() - 2) + 1;
        yCoordinate = rand() % (gameLogic->getBoardSizeY() - 2) + 1;

        isValidPosition = true;
        for (int i = 0; i < restrictedAreas->getSize(); i++)
        {
            objPos segment = restrictedAreas->getElement(i);
            if (xCoordinate == segment.pos->x && yCoordinate == segment.pos->y)
            {
                isValidPosition = false;
                break;
            }
        }
    } while (!isValidPosition);

    position.setObjPos(xCoordinate, yCoordinate, position.symbol);
}

objPos Food::getPosition() const
{
    return position;
}

bool Food::isCollisionDetected(objPosArrayList* playerPosition) const
{
    return playerPosition->getElement(0) == position;
}
