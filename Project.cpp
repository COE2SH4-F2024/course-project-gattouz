#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000
#define MAX_SPEED_LEVELS 5 // Maximum levels of speed

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
GameMechs *gameMechanics;
Food *food;

int speedLevels[MAX_SPEED_LEVELS]; // Array containing different speed levels
int currentSpeedLevel;            // Current speed level

int main(void)
{
    Initialize();

    while (!gameMechanics->isExitGameFlagSet())
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

    gameMechanics = new GameMechs(30, 15);
    player = new Player(gameMechanics);
    food = new Food(gameMechanics, player->getPlayerPositions());
    hasWon = false;

    currentSpeedLevel = 2; // Start with medium speed

    // Define speed levels
    speedLevels[0] = 330000;
    speedLevels[1] = 250000;
    speedLevels[2] = 100000;
    speedLevels[3] = 70000;
    speedLevels[4] = 48000;
}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        char userInput = MacUILib_getChar();
        gameMechanics->setPlayerInput(userInput);

        if (userInput == 27)
        {
            gameMechanics->setExitGameFlag(); // Exit the game when ESC is pressed
        }

        // Adjust speed level
        if (userInput == '+' && currentSpeedLevel < MAX_SPEED_LEVELS - 1)
        {
            currentSpeedLevel++;
        }
        else if (userInput == '-' && currentSpeedLevel > 0)
        {
            currentSpeedLevel--;
        }
    }
    else
    {
        gameMechanics->setPlayerInput(0); // No input
    }
}

void RunLogic(void)
{
    player->updatePlayerDirection();
    player->movePlayer();

    if (player->checkFoodConsumption(food))
    {
        food->generateFood(player->getPlayerPositions());
        player->increasePlayerLength(food);
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    // Print header and instructions
    MacUILib_printf("2SH4 Snake Game: Built Using C/C++!\n");
    MacUILib_printf("-------------------------------------------------------------------\n");
    MacUILib_printf("Instructions: Use W, A, S, D to move, collect food items to grow.\n");
    MacUILib_printf("DO NOT COLLIDE WITH YOURSELF. Press ESC key to exit.\n");
    MacUILib_printf("-------------------------------------------------------------------\n");

    // Display warning if snake can collide with itself
    if (gameMechanics->getPlayerScore() >= 4)
    {
        MacUILib_printf("\nWARNING: Your snake can collide with itself. Move wisely.\n\n");
    }

    MacUILib_printf("1: Turtle Speed,   2: Slow,   3: Medium,   4: Fast,   5: Fastest\n\n");
    MacUILib_printf("Speed Level: %d (Press '+' to increase, '-' to decrease)\n", currentSpeedLevel + 1);
    MacUILib_printf("-------------------------------------------------------------------\n");

    // Draw game board
    for (int y = 0; y < gameMechanics->getGameBoardHeight(); y++)
    {
        for (int x = 0; x < gameMechanics->getGameBoardWidth(); x++)
        {
            // Draw borders
            if (x == 0 || x == gameMechanics->getGameBoardWidth() - 1 || y == 0 || y == gameMechanics->getGameBoardHeight() - 1)
            {
                MacUILib_printf("#");
            }
            else
            {
                bool isOccupied = false;

                // Check if cell is part of the snake
                for (int i = 0; i < player->getPlayerPositions()->getSize(); i++)
                {
                    objPos segment = player->getPlayerPositions()->getElement(i);
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
                    if (x == food->getFoodPosition().position->x && y == food->getFoodPosition().position->y)
                    {
                        MacUILib_printf("%c", food->getFoodPosition().symbol);
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
MacUILib_printf("Food Eaten/Game Score: %d\n", gameMechanics->getPlayerScore());
MacUILib_printf("Current Snake Length: %d\n", gameMechanics->getPlayerScore() + 1);

    if (gameMechanics->isPlayerLoseFlagSet())
    {
        gameMechanics->setExitGameFlag();
    }

    if ((gameMechanics->getPlayerScore() + 1) >= 364) // Winning condition
    {
        hasWon = true;
        gameMechanics->setExitGameFlag();
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(speedLevels[currentSpeedLevel]);
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
else if (gameMechanics->isPlayerLoseFlagSet())
{
    MacUILib_printf("-------------------------------------------------------------\n");
    MacUILib_printf("GAME OVER! Alas, you bit yourself. Snakes do that sometimes.\n");
    MacUILib_printf("But hey, every great gamer learns from their mistakes. Try again soon!\n");
    MacUILib_printf("-------------------------------------------------------------\n");
}
else if (gameMechanics->isExitGameFlagSet())
{
    MacUILib_printf("-------------------------------------------------------------\n");
    MacUILib_printf("EXITING GAME: We hope you had fun slithering around!\n");
    MacUILib_printf("Thanks for playing. Remember, practice makes perfect—see you next time!\n");
    MacUILib_printf("-------------------------------------------------------------\n");
}

    MacUILib_uninit();

    // Deallocate memory
    delete player;
    delete gameMechanics;
    delete food;
}
