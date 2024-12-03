#include "objPosArrayList.h"
#include <stdexcept>

// Default constructor: Initializes the array list with default values
objPosArrayList::objPosArrayList()
{
    int i;
    arrayCapacity = ARRAY_MAX_CAP;
    objList = new objPos[arrayCapacity];
    listSize = 0;

    for (i = 0; i < arrayCapacity; i++)
    {
        (*(objList + i)->position).x = 0;
        (*(objList + i)->position).y = 0;
        (objList + i)->symbol = 0;
    }
}

// Copy constructor: Creates a copy of another objPosArrayList
objPosArrayList::objPosArrayList(const objPosArrayList &other)
{
    int i;

    listSize = other.listSize;
    arrayCapacity = other.arrayCapacity;
    objList = new objPos[arrayCapacity];

    for (i = 0; i < listSize; i++)
    {
        *(objList + i) = other.objList[i];
    }
}

// Copy assignment operator: Assigns values from another objPosArrayList
objPosArrayList &objPosArrayList::operator=(const objPosArrayList &other)
{
    int i;

    if (this != &other)
    {
        listSize = other.listSize;
        arrayCapacity = other.arrayCapacity;

        for (i = 0; i < listSize; i++)
        {
            objList[i] = other.objList[i];
        }
    }
    return *this;
}

// Destructor: Frees the memory allocated for the array
objPosArrayList::~objPosArrayList()
{
    delete[] objList;
}

// Returns the current size of the list
int objPosArrayList::getSize() const
{
    return listSize;
}

// Inserts a new element at the head of the list
void objPosArrayList::insertHead(objPos position)
{
    if (listSize == arrayCapacity)
    {
        throw std::overflow_error("List capacity exceeded. Cannot insert new element at the head.");
    }

    for (int i = listSize; i > 0; i--)
    {
        *(objList + i) = *(objList + i - 1);
    }
    *objList = position;

    listSize++; // Increment size as an element is added
}

// Inserts a new element at the tail of the list
void objPosArrayList::insertTail(objPos position)
{
    if (listSize == arrayCapacity)
    {
        throw std::overflow_error("List capacity exceeded. Cannot insert new element at the tail.");
    }

    *(objList + listSize) = position;
    listSize++; // Increment size as an element is added
}

// Removes the element at the head of the list
void objPosArrayList::removeHead()
{
    if (listSize > 0)
    {
        for (int i = 0; i < listSize; i++)
        {
            *(objList + i) = *(objList + i + 1);
        }
        listSize--; // Decrement size as an element is removed
    }
}

// Removes the element at the tail of the list
void objPosArrayList::removeTail()
{
    if (listSize > 0)
    {
        listSize--; // Decrement size as an element is removed
    }
}

// Returns the element at the head of the list
objPos objPosArrayList::getHeadElement() const
{
    return *(objList);
}

// Returns the element at the tail of the list
objPos objPosArrayList::getTailElement() const
{
    return *(objList + listSize - 1);
}

// Returns the element at a specified index
objPos objPosArrayList::getElement(int index) const
{
    if (index < 0 || index >= listSize)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return *(objList + index); // Return the requested value
}
