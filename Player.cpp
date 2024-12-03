#include "Player.h"
#include "MacUILib.h"
#include <iostream>

Player::Player(GameMechs* gameMechsRef)
    : mainGameMechsRef(gameMechsRef), myDir(STOP), playerPos(new objPosArrayList())
{
    // Initialize player with a starting position
    objPos start1(15, 20, '*');
    playerPos->insertTail(start1);
}

Player::~Player()
{
    delete playerPos; // Clean up dynamically allocated memory
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPos; // Return reference to the player's position array list
}

void Player::updatePlayerDir()
{
    if (mainGameMechsRef->getInput() != 0)
    {
        switch (mainGameMechsRef->getInput())
        {
            case ' ':
                mainGameMechsRef->setExitTrue();
                break;

            case 'A': case 'a':
                if (myDir != LEFT && myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;

            case 'W': case 'w':
                if (myDir != UP && myDir != DOWN)
                {
                    myDir = UP;
                }
                break;

            case 'D': case 'd':
                if (myDir != RIGHT && myDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;

            case 'S': case 's':
                if (myDir != DOWN && myDir != UP)
                {
                    myDir = DOWN;
                }
                break;

            default:
                break;
        }

        mainGameMechsRef->setInput(0); // Clear the input
    }
}

void Player::movePlayer()
{
    objPos newHead = playerPos->getHeadElement();

    // Update position based on direction
    switch (myDir)
    {
        case LEFT:
            newHead.getPos()->x -= 1;
            break;
        case UP:
            newHead.getPos()->y -= 1;
            break;
        case RIGHT:
            newHead.getPos()->x += 1;
            break;
        case DOWN:
            newHead.getPos()->y += 1;
            break;
        case STOP:
            return; // No movement if STOP
    }

    // Handle wrapping around the board
    if (newHead.getPos()->x <= 0)
    {
        newHead.getPos()->x = mainGameMechsRef->getBoardSizeX() - 2;
    }
    else if (newHead.getPos()->x >= mainGameMechsRef->getBoardSizeX() - 1)
    {
        newHead.getPos()->x = 1;
    }

    if (newHead.getPos()->y <= 0)
    {
        newHead.getPos()->y = mainGameMechsRef->getBoardSizeY() - 2;
    }
    else if (newHead.getPos()->y >= mainGameMechsRef->getBoardSizeY() - 1)
    {
        newHead.getPos()->y = 1;
    }

    // Add new head and remove tail to simulate movement
    playerPos->insertHead(newHead);
    playerPos->removeTail();

    // Check for collision with itself
    for (int i = 1; i < playerPos->getSize(); i++)
    {
        if (playerPos->getHeadElement() == playerPos->getElement(i))
        {
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();
            break;
        }
    }
}

bool Player::checkFoodConsumption(Food* foodObj)
{
    // Check if the player's head is at the same position as the food
    return playerPos->getHeadElement() == foodObj->getFoodPos();
}

void Player::increasePlayerLength(Food* foodObj)
{
    objPos currentHead = playerPos->getHeadElement();
    objPos newHead = currentHead;
    newHead.setSymbol('*');

    playerPos->insertHead(newHead); // Add the new head to grow the snake
    mainGameMechsRef->incrementScore();
}

// Add more player-related methods here if needed
