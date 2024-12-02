#include "objPosArrayList.h"
#include <stdexcept>
#include <iostream>

// Default Constructor
objPosArrayList::objPosArrayList()
    : listSize(0), arrayCapacity(200), aList(new objPos[200])
{
    // Initialize all elements to default values
    for (int i = 0; i < arrayCapacity; i++)
    {
        aList[i].setObjPos(0, 0, 0); // Default values for pos and symbol
    }
}

// Copy Constructor
objPosArrayList::objPosArrayList(const objPosArrayList& other)
    : listSize(other.listSize), arrayCapacity(other.arrayCapacity), aList(new objPos[other.arrayCapacity])
{
    for (int i = 0; i < listSize; i++)
    {
        aList[i] = other.aList[i];
    }
}

// Copy Assignment Operator
objPosArrayList& objPosArrayList::operator=(const objPosArrayList& other)
{
    if (this != &other)
    {
        delete[] aList; // Clean up existing memory

        listSize = other.listSize;
        arrayCapacity = other.arrayCapacity;
        aList = new objPos[arrayCapacity];

        for (int i = 0; i < listSize; i++)
        {
            aList[i] = other.aList[i];
        }
    }
    return *this;
}

// Destructor
objPosArrayList::~objPosArrayList()
{
    delete[] aList;
    aList = nullptr;
}

// Double the capacity of the array list
void objPosArrayList::doubleSize()
{
    arrayCapacity *= 2;
    objPos* temp = new objPos[arrayCapacity];

    for (int i = 0; i < listSize; i++)
    {
        temp[i] = aList[i];
    }

    delete[] aList;
    aList = temp; // Assign new expanded array
}

// Get the current size of the list
int objPosArrayList::getSize() const
{
    return listSize;
}

// Insert an element at the head of the list
void objPosArrayList::insertHead(const objPos& thisPos)
{
    if (listSize == arrayCapacity)
    {
        doubleSize();
    }

    for (int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i - 1];
    }

    aList[0] = thisPos;
    listSize++;
}

// Insert an element at the tail of the list
void objPosArrayList::insertTail(const objPos& thisPos)
{
    if (listSize == arrayCapacity)
    {
        doubleSize();
    }

    aList[listSize] = thisPos;
    listSize++;
}

// Remove the head element from the list
void objPosArrayList::removeHead()
{
    if (listSize == 0)
    {
        return;
    }

    for (int i = 0; i < listSize - 1; i++)
    {
        aList[i] = aList[i + 1];
    }

    listSize--;
}

// Remove the tail element from the list
void objPosArrayList::removeTail()
{
    if (listSize > 0)
    {
        listSize--;
    }
}

// Get the element at the head of the list
objPos objPosArrayList::getHeadElement() const
{
    if (listSize == 0)
    {
        throw std::out_of_range("List is empty.");
    }

    return aList[0];
}

// Get the element at the tail of the list
objPos objPosArrayList::getTailElement() const
{
    if (listSize == 0)
    {
        throw std::out_of_range("List is empty.");
    }

    return aList[listSize - 1];
}

// Get an element at a specific index
objPos objPosArrayList::getElement(int index) const
{
    if (index < 0 || index >= listSize)
    {
        throw std::out_of_range("Index out of range.");
    }

    return aList[index];
}
