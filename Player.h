#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h" // Include Food class

class Player {
public:
    enum Dir { UP, DOWN, LEFT, RIGHT, STOP }; // Direction state

    Player(GameMechs* thisGMRef);
    ~Player();

    objPosArrayList* getPlayerPos() const; 
    void updatePlayerDir();
    void movePlayer();
    bool checkFoodConsumption(Food* foodObj);
    void increasePlayerLength(Food* foodObj);

private:
    objPosArrayList* playerPos; 
    Dir myDir;
    GameMechs* mainGameMechsRef;
};

#endif // PLAYER_H
