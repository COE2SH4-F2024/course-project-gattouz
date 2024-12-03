#include "Food.h"
#include <time.h>

// Constructor for the Food class
Food::Food(GameMechs *gameReference, objPosArrayList *playerPosList)
{
    gameMechsRef = gameReference;   // Reference to the game mechanics
    foodPos.symbol = '$';            // Set the symbol for the food object
    generateFood(playerPosList);     // Generate food position
}

// Generates a valid position for the food object
void Food::generateFood(objPosArrayList *blockedPositions)
{
    srand(time(0)); // Seeds the random number generator with the current time

    int index;                  // Iterator variable
    int foodPosX, foodPosY;     // Variables to store food position
    bool isValidPosition = false; // Flag to check validity of the position

    // Setting the range for random position generation (inside board boundaries)
    int xBoundary = gameMechsRef->getBoardSizeX() - 2;  // Assuming getBoardSizeX() exists
    int yBoundary = gameMechsRef->getBoardSizeY() - 2;  // Assuming getBoardSizeY() exists

    // Keep generating random positions until a valid one is found
    while (!isValidPosition)
    {
        // Generate random food position within board boundaries (not touching borders)
        foodPosX = 1 + rand() % xBoundary;
        foodPosY = 1 + rand() % yBoundary;

        // Assume the position is valid initially
        isValidPosition = true;

        // Check if the generated position overlaps with any blocked area (e.g., snake's body)
        for (index = 0; index < blockedPositions->getSize(); index++)
        {
            objPos blockedSegment = blockedPositions->getElement(index);

            // If food position overlaps with any blocked segment, mark it invalid
            if (foodPosX == blockedSegment.position->x && foodPosY == blockedSegment.position->y)
            {
                isValidPosition = false; // Mark position as invalid
                break;                   // Exit the loop early, as we need to generate a new position
            }
        }
    }

    // Set the valid food position once found
    this->foodPos.setObjPos(foodPosX, foodPosY, foodPos.symbol);
}

// Returns the current position of the food object
objPos const Food::getFoodPos()
{
    return foodPos;
}

// Checks if the food position collides with the player's head
bool Food::checkSelfCollision(objPosArrayList *playerPositionList)
{
    return playerPositionList->getElement(0) == foodPos; // Check if head matches the food position
}
