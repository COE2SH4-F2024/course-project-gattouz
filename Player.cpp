#include "Player.h"

Player::Player(GameMechs *gameMechsRef)
{
    this->gameMechsRef = gameMechsRef;
    currentDir = STOP;

    playerPosList = new objPosArrayList();
    objPos initialPosition = objPos(gameMechsRef->getBoardSizeX() / 2, gameMechsRef->getBoardSizeY() / 2, '*');

    playerPosList->insertTail(initialPosition);
}

Player::~Player()
{
    delete playerPosList;
}

objPosArrayList *Player::getPlayerPos() const
{
    // Return the reference to the playerPosList array list
    return this->playerPosList;
}

// Update player's direction based on input
void Player::updatePlayerDir()
{
    if (gameMechsRef->getInput() != 0)
    {
        switch (gameMechsRef->getInput())
        {
        case 27:
            gameMechsRef->setExitTrue();
            break;

        case 'w':
        case 'W':
            if (currentDir != DOWN)
            {
                currentDir = UP;
            }
            break;

        case 'a':
        case 'A':
            if (currentDir != RIGHT)
            {
                currentDir = LEFT;
            }
            break;

        case 's':
        case 'S':
            if (currentDir != UP)
            {
                currentDir = DOWN;
            }
            break;

        case 'd':
        case 'D':
            if (currentDir != LEFT)
            {
                currentDir = RIGHT;
            }
            break;

        default:
            break;
        }
        gameMechsRef->clearInput();
    }
}

// Move the player based on the current direction
void Player::movePlayer()
{
    objPos snakeHead = playerPosList->getHeadElement();

    switch (currentDir)
    {
    case LEFT:
        if (snakeHead.position->x <= 0)
        {
            snakeHead.position->x = gameMechsRef->getBoardSizeX() - 2;
        }
        snakeHead.position->x--;
        break;

    case RIGHT:
        if (snakeHead.position->x == gameMechsRef->getBoardSizeX() - 2)
        {
            snakeHead.position->x = 0;
        }
        snakeHead.position->x++;
        break;

    case UP:
        if (snakeHead.position->y <= 0)
        {
            snakeHead.position->y = gameMechsRef->getBoardSizeY() - 2;
        }
        snakeHead.position->y--;
        break;

    case DOWN:
        if (snakeHead.position->y == gameMechsRef->getBoardSizeY() - 2)
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
        snakeHead.position->x = gameMechsRef->getBoardSizeX() - 2;
    }
    else if (snakeHead.position->x >= gameMechsRef->getBoardSizeX() - 1)
    {
        snakeHead.position->x = 1;
    }

    if (snakeHead.position->y <= 0)
    {
        snakeHead.position->y = gameMechsRef->getBoardSizeY() - 2;
    }
    else if (snakeHead.position->y >= gameMechsRef->getBoardSizeY() - 1)
    {
        snakeHead.position->y = 1;
    }

    playerPosList->insertHead(snakeHead);
    playerPosList->removeTail();

    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        if (playerPosList->getHeadElement() == playerPosList->getElement(i))
        {
            gameMechsRef->setExitTrue();
            gameMechsRef->setLoseFlag();
        }
    }
}

// Check if player consumes a food item
bool Player::checkFoodConsumption(Food *foodItem)
{
    return playerPosList->getElement(0) == foodItem->getFoodPos();
}

// Increase the player's length after consuming food
void Player::increasePlayerLength(Food *foodItem)
{
    objPos currentHead = playerPosList->getHeadElement();

    objPos newSnakeHead = currentHead;
    newSnakeHead.symbol = '*';

    playerPosList->insertHead(newSnakeHead);
    gameMechsRef->incrementScore();
}
