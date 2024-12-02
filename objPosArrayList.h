#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
private:
    objPos* aList;          // Pointer to the dynamic array of objPos
    int listSize;           // Current size of the list
    int arrayCapacity;      // Current capacity of the array

    void doubleSize();      // Private method to double the array capacity

public:
    // Constructors and Destructor
    objPosArrayList();                             // Default constructor
    objPosArrayList(const objPosArrayList& other); // Copy constructor
    objPosArrayList& operator=(const objPosArrayList& other); // Copy assignment operator
    objPosArrayList(objPosArrayList&& other) noexcept;        // Move constructor
    objPosArrayList& operator=(objPosArrayList&& other) noexcept; // Move assignment operator
    ~objPosArrayList();                            // Destructor

    // Member Functions
    int getSize() const;                           // Get the current size of the list
    void insertHead(const objPos& thisPos);        // Insert an element at the head
    void insertTail(const objPos& thisPos);        // Insert an element at the tail
    void removeHead();                             // Remove the head element
    void removeTail();                             // Remove the tail element
    objPos getHeadElement() const;                 // Get the head element
    objPos getTailElement() const;                 // Get the tail element
    objPos getElement(int index) const;            // Get an element by index
};

#endif // OBJPOS_ARRAYLIST_H
