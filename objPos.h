#ifndef OBJPOS_H
#define OBJPOS_H

// Struct to represent a position with x and y coordinates
typedef struct
{
    int x;
    int y;
} Position;

class objPos
{
public:
    Position *position; // Pointer to a Position object
    char symbol;        // Symbol representing the object

    objPos();                                  // Default constructor
    objPos(int xPosition, int yPosition, char sym); // Parameterized constructor

    // Respect the rule of six / minimum four
    // [TODO] Implement the missing special member functions to meet the minimum four rule

    ~objPos();                                 // Destructor

    objPos(const objPos &reference);           // Copy constructor
    objPos &operator=(const objPos &reference); // Copy assignment operator

    bool operator==(const objPos &other);      // Equality operator to compare two objPos objects

    void setObjPos(objPos obj);                // Set position using another objPos object
    void setObjPos(int xPosition, int yPosition, char sym); // Set position using explicit values

    objPos getObjPos() const;                  // Get the current position as an objPos object
    char getSymbol() const;                    // Retrieve the symbol
    char getSymbolIfPosEqual(const objPos *referencePosition) const; // Get symbol if position matches

    bool isPosEqual(const objPos *referencePosition) const; // Check if position matches another objPos

    void xPosIncrease();                       // Increment x-coordinate
    void xPosDecrease();                       // Decrement x-coordinate
    void yPosIncrease();                       // Increment y-coordinate
    void yPosDecrease();                       // Decrement y-coordinate
};

#endif
