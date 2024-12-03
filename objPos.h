#ifndef OBJPOS_H
#define OBJPOS_H

struct Pos {
    int x;
    int y;
};

class objPos {
private:
    Pos* pos;
    char symbol;

public:
    objPos();
    objPos(int xPos, int yPos, char sym);
    objPos(const objPos& other);
    objPos(objPos&& other) noexcept;
    ~objPos();

    objPos& operator=(const objPos& other);
    objPos& operator=(objPos&& other) noexcept;

    Pos* getPos() const { return pos; }
    void setPos(int x, int y);

    char getSymbol() const;
    void setSymbol(char sym) { symbol = sym; }
    void setObjPos(int xPos, int yPos, char sym);

    objPos getObjPos() const;  // Declaration for getObjPos
    bool isPosEqual(const objPos* refPos) const; // Declaration for isPosEqual
    char getSymbolIfPosEqual(const objPos* refPos) const; // Declaration for getSymbolIfPosEqual

    bool operator==(const objPos& other) const;
};

#endif // OBJPOS_H
