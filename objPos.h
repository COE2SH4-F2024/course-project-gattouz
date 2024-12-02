#ifndef OBJPOS_H
#define OBJPOS_H

struct Pos {
    int x;
    int y;
};

class objPos {
private:
    Pos* pos;      // Pointer to position data
    char symbol;   // Symbol representing the object

public:
    // Constructors and Destructor
    objPos();                                      // Default constructor
    objPos(int xPos, int yPos, char sym);          // Parameterized constructor
    objPos(const objPos& other);                  // Copy constructor
    objPos(objPos&& other) noexcept;              // Move constructor
    ~objPos();                                     // Destructor

    // Assignment Operators
    objPos& operator=(const objPos& other);       // Copy assignment operator
    objPos& operator=(objPos&& other) noexcept;   // Move assignment operator

    // Member Functions
    void setObjPos(const objPos& other);          // Set position using another objPos
    void setObjPos(int xPos, int yPos, char sym); // Set position using individual values

    objPos getObjPos() const;                     // Get a copy of the position
    char getSymbol() const;                       // Get the symbol of the object
    char getSymbolIfPosEqual(const objPos* refPos) const; // Get symbol if positions match

    bool isPosEqual(const objPos* refPos) const;  // Check if positions are equal
};

#endif // OBJPOS_H
