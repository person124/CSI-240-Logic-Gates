#include "startingPos.h"

StartingList::StartingList()
{
    mSize = 0;
    mArray = NULL;
    nullPos = new StartingPos();
    nullPos->mL = 0;
    nullPos->mX = 0;
    nullPos->mY = 0;
}

StartingList::~StartingList()
{
    delete [] mArray;
    delete nullPos;
}

/* Purpose: Creates and adds a new starting pos at layer, x, and y.
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
void StartingList::add(int l, int x, int y)
{
    StartingPos p;
    p.mL = l;
    p.mX = x;
    p.mY = y;
    add(p);
}

/* Purpose: Adds the specified starting pos to the list
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
void StartingList::add(StartingPos pos)
{
    StartingPos* newList = new StartingPos[mSize + 1];
    for (int i = 0; i < mSize; i++)
        newList[i] = mArray[i];
    newList[mSize] = pos;
    mArray = newList;
    mSize++;
}

/* Purpose: Returns the starting pos at the specified index, if none found, will return NULL
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
StartingPos* StartingList::get(int num)
{
    if (num < 0 || num >= mSize)
        return nullPos;

    return &mArray[num];
}

int StartingList::getSize()
{
    return mSize;
}

/* Purpose: Removes the specified starting pos
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
void StartingList::remove(int l, int x, int y)
{
    StartingPos p;
    p.mL = l;
    p.mX = x;
    p.mY = y;
    remove(p);
}

/* Purpose: Removes the specified starting pos
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
void StartingList::remove(StartingPos pos)
{
    if (mSize == 0)
        return;
    if (mSize == 1)
        delete [] mArray;

    int place = -1;
    for (int i = 0; i < mSize; i++)
    {
        if (mArray[i] == pos)
        {
            place = i;
            break;
        }
    }

    if (place == -1)
        return;

    StartingPos* newList = new StartingPos[mSize - 1];
    int j = 0;
    for (int i = 0; i < mSize; i++)
    {
        if (i == place)
            continue;
        newList[j] = mArray[i];
        j++;
    }
    delete [] mArray;

    mSize--;
}

bool operator==(StartingPos p1, StartingPos p2)
{
    return p1.mL == p2.mL || p1.mX == p2.mX || p1.mY == p2.mY;
}
