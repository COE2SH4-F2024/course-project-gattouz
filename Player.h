#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Declaration based on project requirements

    // Add more data members and member functions to complete the design

public:
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        STOP
    }; // Enum representing player's direction state

    Player(GameMechs *gameMechsRef); // Constructor
    ~Player();                       // Destructor

    objPosArrayList *getPlayerPos() const; // Get player's positions
    void updatePlayerDir();               // Update the player's direction based on input

    void movePlayer(); // Move the player

    bool checkFoodConsumption(Food *foodItem);  // Check if the player consumes a food item
    void increasePlayerLength(Food *foodItem);  // Increase the player's length after consuming food

private:
    objPosArrayList *playerPosList; // Stores the player's positions
    enum Direction currentDir;      // Current direction of the player

    GameMechs *gameMechsRef; // Reference to the main game mechanics
};

#endif
