#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

// GameMechs class definition
class GameMechs
{
private:
    char playerInput;             // Stores the player's input
    bool exitGameFlag;            // Flag to indicate if the game should exit
    bool playerLoseFlag;          // Flag to indicate if the player has lost
    int playerScore;              // Tracks the player's score

    int gameBoardWidth;           // Width of the game board
    int gameBoardHeight;          // Height of the game board

    objPos foodPosition;          // Position of the food object

public:
    GameMechs();                  // Default constructor
    GameMechs(int boardWidth, int boardHeight); // Parameterized constructor

    // Destructor omitted as no heap memory is used

    bool isExitGameFlagSet() const;        // Check if the exit flag is set
    void setExitGameFlag();                // Set the exit flag to true

    bool isPlayerLoseFlagSet() const;      // Check if the lose flag is set
    void setPlayerLoseFlag();              // Set the lose flag to true

    char getPlayerInput() const;           // Get the player's input
    void setPlayerInput(char input);       // Set the player's input
    void clearPlayerInput();               // Clear the player's input

    int getGameBoardWidth() const;         // Get the width of the game board
    int getGameBoardHeight() const;        // Get the height of the game board

    int getPlayerScore() const;            // Get the player's score
    void increasePlayerScore();            // Increment the player's score
};

#endif
