#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

bool hasWon; // Tracks the winning condition (if the snake is as long as the board)

// Function prototypes
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// Game objects
Player *player;
GameMechs *gameMechsRef;
Food *food;

int main(void)
{
    Initialize();

    while (!gameMechsRef->getExitFlagStatus())
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    gameMechsRef = new GameMechs(30, 15);
    player = new Player(gameMechsRef);
    food = new Food(gameMechsRef, player->getPlayerPos());
    hasWon = false;
}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        char userInput = MacUILib_getChar();
        gameMechsRef->setInput(userInput);

        if (userInput == 27)
        {
            gameMechsRef->setExitTrue(); // Exit the game when ESC is pressed
        }
    }
    else
    {
        gameMechsRef->clearInput(); // No input
    }
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();

    if (player->checkFoodConsumption(food))
    {
        food->generateFood(player->getPlayerPos());
        player->increasePlayerLength(food);
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    // Print header and instructions
    MacUILib_printf("Welcome to the Ultimate 2SH4 Snake Challenge - Built in C/C++!\n");
    MacUILib_printf("-------------------------------------------------------------------\n");
    MacUILib_printf("How to Play: Use W, A, S, D to navigate and collect food to grow your snake.\n");
    MacUILib_printf("Tip: The ESC key is your way out if you need to quit the game.\n");
    MacUILib_printf("-------------------------------------------------------------------\n");

    if (gameMechsRef->getScore() >= 4)
    {
        MacUILib_printf("\nCAUTION: Your snake is long enough to collide with itself. Think before you slither!\n\n");
    }

    // Draw game board
    for (int y = 0; y < gameMechsRef->getBoardSizeY(); y++)
    {
        for (int x = 0; x < gameMechsRef->getBoardSizeX(); x++)
        {
            // Draw borders
            if (x == 0 || x == gameMechsRef->getBoardSizeX() - 1 || y == 0 || y == gameMechsRef->getBoardSizeY() - 1)
            {
                MacUILib_printf("#");
            }
            else
            {
                bool isOccupied = false;

                // Check if cell is part of the snake
                for (int i = 0; i < player->getPlayerPos()->getSize(); i++)
                {
                    objPos segment = player->getPlayerPos()->getElement(i);
                    if (x == segment.position->x && y == segment.position->y)
                    {
                        MacUILib_printf("%c", segment.symbol);
                        isOccupied = true;
                        break;
                    }
                }

                // Check if cell contains food
                if (!isOccupied)
                {
                    if (x == food->getFoodPos().position->x && y == food->getFoodPos().position->y)
                    {
                        MacUILib_printf("%c", food->getFoodPos().symbol);
                    }
                    else
                    {
                        MacUILib_printf(" ");
                    }
                }
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("-------------------------------------------------------------------\n");
    MacUILib_printf("GAME STATS\n");
    MacUILib_printf("-------------------------------------------------------------------\n");
    MacUILib_printf("Food Eaten/Game Score: %d\n", gameMechsRef->getScore());
    MacUILib_printf("Current Snake Length: %d\n", gameMechsRef->getScore() + 1);

    if (gameMechsRef->getLoseFlagStatus())
    {
        gameMechsRef->setExitTrue();
    }

    if ((gameMechsRef->getScore() + 1) >= 364) // Winning condition
    {
        hasWon = true;
        gameMechsRef->setExitTrue();
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST);
}

void CleanUp(void)
{
    MacUILib_clearScreen();
    MacUILib_Delay(1);

    if (hasWon)
    {
        MacUILib_printf("VICTORY UNLOCKED! You're officially a Snake Master!\n");
        MacUILib_printf("Few have conquered this challenge, but you did it with style. Amazing work!\n");
    }
    else if (gameMechsRef->getLoseFlagStatus())
    {
        MacUILib_printf("-------------------------------------------------------------\n");
        MacUILib_printf("GAME OVER! Alas, you bit yourself. Snakes do that sometimes.\n");
        MacUILib_printf("But hey, every great gamer learns from their mistakes. Try again soon!\n");
        MacUILib_printf("-------------------------------------------------------------\n");
    }
    else if (gameMechsRef->getExitFlagStatus())
    {
        MacUILib_printf("-------------------------------------------------------------\n");
        MacUILib_printf("EXITING GAME: We hope you had fun slithering around!\n");
        MacUILib_printf("Thanks for playing. Remember, practice makes perfect—see you next time!\n");
        MacUILib_printf("-------------------------------------------------------------\n");
    }

    MacUILib_uninit();

    // Deallocate memory
    delete player;
    delete gameMechsRef;
    delete food;
}
