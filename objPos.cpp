#include "objPos.h"

// Default constructor
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; // NULL
}

// Parameterized constructor
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Copy constructor
objPos::objPos(const objPos& location)
{
    pos = new Pos;
    pos->x = location.pos->x;
    pos->y = location.pos->y;
    symbol = location.symbol;
}

// Copy assignment operator
objPos& objPos::operator=(const objPos& location)
{
    if (this != &location)
    {
        symbol = location.symbol;

        // Deallocate existing memory and reallocate for deep copy
        delete pos;
        pos = new Pos;
        pos->x = location.pos->x;
        pos->y = location.pos->y;
    }
    return *this;
}

// Move constructor
objPos::objPos(objPos&& location) noexcept
{
    pos = location.pos;
    symbol = location.symbol;

    // Nullify the source object's pointer to avoid dangling
    location.pos = nullptr;
    location.symbol = 0;
}

// Move assignment operator
objPos& objPos::operator=(objPos&& location) noexcept
{
    if (this != &location)
    {
        delete pos; // Free the current resource

        // Transfer ownership
        pos = location.pos;
        symbol = location.symbol;

        // Nullify the source object
        location.pos = nullptr;
        location.symbol = 0;
    }
    return *this;
}

// Equality operator
bool objPos::operator==(const objPos& other) const {
    return pos->x == other.pos->x && pos->y == other.pos->y && symbol == other.symbol;
}

// Destructor
objPos::~objPos()
{
    delete pos; // Free allocated memory
}

// Set object position using individual values
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Get the symbol of the object
char objPos::getSymbol() const
{
    return symbol;
}

// Check if two positions are equal
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

// Return symbol if positions are equal; otherwise, return 0
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    return isPosEqual(refPos) ? symbol : 0;
}

// Removed conflicting `setObjPos(const objPos&)` and `getObjPos()` 
