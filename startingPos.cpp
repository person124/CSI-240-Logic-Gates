/* Filename:      startingPos.cpp
 * File author:   Calum Phillips
 * Project Team:  Peter Belsley, Matthew Harrison, Calum Phillips
 * Class:         CSI-240-04
 * Assignment:    Final Project: Logic Gate
 * Date Assigned: April 18, 2016
 * Due Date:      April 29, 2016, at 11:59 pm
 *
 * Description:
 *   A program that simulates logic gates within a grid system.
 *
 * Certification of Authenticity:
 *   I certify that this is entirely my own work, except where I have given
 *   fully documented references to the work of others. I understand the
 *   definition and consequences of plagiarism and acknowledge that the assessor
 *   of this assignment may, for the purpose of assessing this assignment:
 *     -  Reproduce this assignment and provide a copy to another member of
 *        academic staff; and/or
 *     -  Communicate a copy of this assignment to a plagiarism checking
 *        service (which may then retain a copy of this assignment on its
 *        database for the purpose of future plagiarism checking)
 ******************************************************************************/

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
