#include "StringSet.h"
#include <iostream>

//Default Constructor
StringSet::StringSet()
{
    maxSize = 4;
    currentSize = 0;
}

//Destructor
StringSet::~StringSet()
{
    delete [] Array;
    Array = nullptr;
}

//Copy Constructor
StringSet::StringSet(const StringSet & toBeCopied)
{
    this->currentSize = toBeCopied.currentSize;
    this->maxSize = toBeCopied.maxSize;
    delete [] this->Array;
    Array = new std::string[maxSize];

    for(int i = 0; i < toBeCopied.size(); i++)
    {
        this->Array[i] = toBeCopied.Array[i];
    }

}

//Insertion operator
bool StringSet::insert(std::string toBeInserted)
{
    if(this->find(toBeInserted) != -1)
    {
        return false;
    }


    if(currentSize == maxSize)
    {
        maxSize = 2*maxSize; //Increase the maximum size of the array
        std::string *biggerArray = new std::string[maxSize];
        for(int i = 0; i < currentSize; i++)
        {
            biggerArray[i] = Array[i];
        }
        delete [] Array;        //Delete the memory pointed to by Array
        Array = biggerArray;    //Set Array to point to biggerArray
        biggerArray = nullptr;  //Clear biggerArray's pointer
    }

    Array[currentSize] = toBeInserted;
    currentSize++;
    return true;
    //std::cout << Array[currentSize-1] << " current max size = " << maxSize << std::endl;
}

//String removal from set **WORK IN PROGRESS**
bool StringSet::remove(std::string toBeRemoved)
{
    int index = find(toBeRemoved);

    if(index == -1)
    {
        //std::cout << toBeRemoved << " was not removed" << std::endl;
        return false;
    }
}

//Finding given string within a set
int StringSet::find(std::string toBeFound) const
{
    for(int i = 0; i < currentSize; i++)
    {
        if(toBeFound == Array[i])
        {
            //std::cout << toBeFound << " was found at index: " << i << std::endl;
            return i;
        }
    }
    //std::cout << toBeFound << " was not found" << std::endl;
    return -1;
}

//Returns the size of the set
int StringSet::size() const
{
    return currentSize;
}

void StringSet::printAll()
{
    for(int i = 0; i<currentSize; i++)
    {
        std::cout << Array[i] << " ";
    }
}

//Union function
StringSet StringSet::unions(const StringSet & toBeUnioned) const
{
    StringSet *unionedStringSet = new StringSet();
    for(int i = 0; i < this->size(); i++)
    {
        unionedStringSet->insert(this->Array[i]);
    }

    for(int j = 0; j < toBeUnioned.size(); j++)
    {
        if(unionedStringSet->find(toBeUnioned.Array[j]) == -1)
        {
            unionedStringSet->insert(toBeUnioned.Array[j]);
        }
    }
    //unionedStringSet->printAll();
    return *unionedStringSet;

}

//Intersection function
StringSet StringSet::intersection(const StringSet & toBeIntersectioned) const
{
    StringSet *intersectionedStringSet = new StringSet();
    for(int i = 0; i < this->size(); i++)
    {
        if(toBeIntersectioned.find(this->Array[i]) != -1)
        {
            intersectionedStringSet->insert(this->Array[i]);
        }
    }
    //intersectionedStringSet->printAll();
    return *intersectionedStringSet;

}

//Difference function
StringSet StringSet::difference(const StringSet & toBeDifferenced) const
{
    StringSet *differencedStringSet = new StringSet();
        for(int i = 0; i < this->size(); i++)
        {
            if(toBeDifferenced.find(this->Array[i]) == -1)
            {
                differencedStringSet->insert(this->Array[i]);
            }
        }
        for(int i = 0; i < toBeDifferenced.size(); i++)
            {
                if(this->find(toBeDifferenced.Array[i]) == -1)
                {
                    differencedStringSet->insert(toBeDifferenced.Array[i]);
                }
            }
    //differencedStringSet->printAll();
    return *differencedStringSet;
}

