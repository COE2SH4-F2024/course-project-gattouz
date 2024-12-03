#include "objPos.h"
#include <cstddef>

// Default constructor: Initializes position to (0, 0) and symbol to null
objPos::objPos()
{
    position = new Position;
    position->x = 0;
    position->y = 0;
    symbol = 0; // NULL
}

// Initializes position and symbol with given values
objPos::objPos(int xPosition, int yPosition, char sym)
{
    position = new Position;
    position->x = xPosition;
    position->y = yPosition;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

// Destructor
objPos::~objPos()
{
    delete position; // Deallocate memory
}

// Copy Constructor
objPos::objPos(const objPos &reference)
{
    this->symbol = reference.symbol;
    this->position = new Position;
    position->x = reference.position->x;
    position->y = reference.position->y;
}

// Copy Assignment Operator
objPos &objPos::operator=(const objPos &reference)
{
    if (this != &reference)
    {
        this->symbol = reference.symbol;
        position->x = reference.position->x;
        position->y = reference.position->y;
    }
    return *this;
}

// Equality operator to compare two objPos objects
bool objPos::operator==(const objPos &other)
{
    return this->position->x == other.position->x &&
           this->position->y == other.position->y;
}

// Set object position using another objPos object
void objPos::setObjPos(objPos obj)
{
    position->x = obj.position->x;
    position->y = obj.position->y;
    symbol = obj.symbol;
}

// Set object position with explicit values
void objPos::setObjPos(int xPosition, int yPosition, char sym)
{
    position->x = xPosition;
    position->y = yPosition;
    symbol = sym;
}

// Return the object position as an objPos object
objPos objPos::getObjPos() const
{
    objPos returnPosition;
    returnPosition.position->x = position->x;
    returnPosition.position->y = position->y;
    returnPosition.symbol = symbol;

    return returnPosition;
}

// Retrieve the symbol
char objPos::getSymbol() const
{
    return symbol;
}

// Check if the position is equal to another objPos object's position
bool objPos::isPosEqual(const objPos *referencePosition) const
{
    return (referencePosition->position->x == position->x && 
            referencePosition->position->y == position->y);
}

// Return the symbol if the position matches the given reference position
char objPos::getSymbolIfPosEqual(const objPos *referencePosition) const
{
    if (isPosEqual(referencePosition))
        return symbol;
    else
        return 0;
}

// Increase x position
void objPos::xPosIncrease()
{
    (position->x)++;
}

// Decrease x position
void objPos::xPosDecrease()
{
    (position->x)--;
}

// Increase y position
void objPos::yPosIncrease()
{
    (position->y)++;
}

// Decrease y position
void objPos::yPosDecrease()
{
    (position->y)--;
}
