#include "Player.h"

Player::Player(GameMechs *gameMechanicsReference)
{
    mainGameMechsRef = gameMechanicsReference;
    currentDirection = STOP;

    playerPositionList = new objPosArrayList();
    objPos initialPosition = objPos(mainGameMechsRef->getGameBoardWidth() / 2, mainGameMechsRef->getGameBoardHeight() / 2, '*');

    playerPositionList->insertTail(initialPosition);
}

Player::~Player()
{
    delete playerPositionList;
}

objPosArrayList *Player::getPlayerPositions() const
{
    // Return the reference to the playerPositionList array list
    return this->playerPositionList;
}

// Update player's direction based on input
void Player::updatePlayerDirection()
{
    if (mainGameMechsRef->getPlayerInput() != 0)
    {
        switch (mainGameMechsRef->getPlayerInput())
        {
        case 27:
            mainGameMechsRef->setExitGameFlag();
            break;

        case 'w':
        case 'W':
            if (currentDirection != DOWN)
            {
                currentDirection = UP;
            }
            break;

        case 'a':
        case 'A':
            if (currentDirection != RIGHT)
            {
                currentDirection = LEFT;
            }
            break;

        case 's':
        case 'S':
            if (currentDirection != UP)
            {
                currentDirection = DOWN;
            }
            break;

        case 'd':
        case 'D':
            if (currentDirection != LEFT)
            {
                currentDirection = RIGHT;
            }
            break;

        default:
            break;
        }
        mainGameMechsRef->setPlayerInput(0);
    }
}

// Move the player based on the current direction
void Player::movePlayer()
{
    objPos snakeHead = playerPositionList->getHeadElement();

    switch (currentDirection)
    {
    case LEFT:
        if (snakeHead.position->x <= 0)
        {
            snakeHead.position->x = mainGameMechsRef->getGameBoardWidth() - 2;
        }
        snakeHead.position->x--;
        break;

    case RIGHT:
        if (snakeHead.position->x == mainGameMechsRef->getGameBoardWidth() - 2)
        {
            snakeHead.position->x = 0;
        }
        snakeHead.position->x++;
        break;

    case UP:
        if (snakeHead.position->y <= 0)
        {
            snakeHead.position->y = mainGameMechsRef->getGameBoardHeight() - 2;
        }
        snakeHead.position->y--;
        break;

    case DOWN:
        if (snakeHead.position->y == mainGameMechsRef->getGameBoardHeight() - 2)
        {
            snakeHead.position->y = 0;
        }
        snakeHead.position->y++;
        break;

    case STOP:
        break;
    }

    // Wrap around logic for board edges
    if (snakeHead.position->x <= 0)
    {
        snakeHead.position->x = mainGameMechsRef->getGameBoardWidth() - 2;
    }
    else if (snakeHead.position->x >= mainGameMechsRef->getGameBoardWidth() - 1)
    {
        snakeHead.position->x = 1;
    }

    if (snakeHead.position->y <= 0)
    {
        snakeHead.position->y = mainGameMechsRef->getGameBoardHeight() - 2;
    }
    else if (snakeHead.position->y >= mainGameMechsRef->getGameBoardHeight() - 1)
    {
        snakeHead.position->y = 1;
    }

    playerPositionList->insertHead(snakeHead);
    playerPositionList->removeTail();

    for (int i = 1; i < playerPositionList->getSize(); i++)
    {
        if (playerPositionList->getHeadElement() == playerPositionList->getElement(i))
        {
            mainGameMechsRef->setExitGameFlag();
            mainGameMechsRef->setPlayerLoseFlag();
        }
    }
}

// Check if player consumes a food item
bool Player::checkFoodConsumption(Food *foodItem)
{
    return playerPositionList->getElement(0) == foodItem->getFoodPosition();
}

// Increase the player's length after consuming food
void Player::increasePlayerLength(Food *foodItem)
{
    objPos currentHead = playerPositionList->getHeadElement();

    objPos newSnakeHead = currentHead;
    newSnakeHead.symbol = '*';

    playerPositionList->insertHead(newSnakeHead);
    mainGameMechsRef->increasePlayerScore();
}
