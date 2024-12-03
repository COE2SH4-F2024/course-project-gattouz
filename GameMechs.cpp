#include "GameMechs.h"

// Default constructor for GameMechs
GameMechs::GameMechs()
{
    // Initializing the game variables
    playerInput = 0;
    exitGameFlag = false;
    playerLoseFlag = false;
    playerScore = 0;

    // Setting the default board size
    gameBoardWidth = 30;
    gameBoardHeight = 15;
}

// Parameterized constructor for GameMechs
GameMechs::GameMechs(int boardWidth, int boardHeight)
{
    playerInput = 0;
    exitGameFlag = false;
    playerLoseFlag = false;
    playerScore = 0;

    // Setting different sizes for the board
    gameBoardWidth = boardWidth;
    gameBoardHeight = boardHeight;
}

// Check if the exit flag is set
bool GameMechs::isExitGameFlagSet() const
{
    return exitGameFlag;
}

// Check if the lose flag is set
bool GameMechs::isPlayerLoseFlagSet() const
{
    return playerLoseFlag;
}

// Get the player's input
char GameMechs::getPlayerInput() const
{
    return playerInput;
}

// Get the player's score
int GameMechs::getPlayerScore() const
{
    return playerScore;
}

// Increment the player's score
void GameMechs::increasePlayerScore()
{
    playerScore++;
}

// Get the width of the game board
int GameMechs::getGameBoardWidth() const
{
    return gameBoardWidth;
}

// Get the height of the game board
int GameMechs::getGameBoardHeight() const
{
    return gameBoardHeight;
}

// Set the exit flag to true
void GameMechs::setExitGameFlag()
{
    exitGameFlag = true;
}

// Set the lose flag to true
void GameMechs::setPlayerLoseFlag()
{
    playerLoseFlag = true;
}

// Set the player's input
void GameMechs::setPlayerInput(char input)
{
    playerInput = input; // Setting the input with what the user entered
}

// Clear the player's input
void GameMechs::clearPlayerInput()
{
    playerInput = 0;
}
