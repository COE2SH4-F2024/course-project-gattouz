#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

// objPosArrayList class definition
class objPosArrayList
{
private:
    objPos *objList;       // Pointer to the array of objPos objects
    int listSize;          // Current size of the list
    int arrayCapacity;     // Current capacity of the array

public:
    objPosArrayList();      // Default constructor
    ~objPosArrayList();     // Destructor to deallocate memory

    int getSize() const;    // Get the current size of the list
    void insertHead(objPos position);  // Insert a new element at the head of the list
    void insertTail(objPos position);  // Insert a new element at the tail of the list
    void removeHead();      // Remove the element at the head of the list
    void removeTail();      // Remove the element at the tail of the list

    objPos getHeadElement() const; // Get the element at the head of the list
    objPos getTailElement() const; // Get the element at the tail of the list
    objPos getElement(int index) const; // Get the element at the specified index


    objPosArrayList(const objPosArrayList &other);          // Copy constructor
    objPosArrayList &operator=(const objPosArrayList &other); // Copy assignment operator
};

#endif
