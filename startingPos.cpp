#include "startingPos.h"

StartingList::StartingList()
{
    mCount = 0;
    mHead = NULL;
    nullPos = new StartingPos();
}

StartingList::~StartingList()
{
    Node* temp = mHead;
    for (int i = 1; i < mCount; i++)
    {
        Node* next = temp->mNext;
        delete temp;
        temp = next;
    }
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
    Node* node = new Node(pos);
    if (mHead == NULL)
        mHead = node;
    else
    {
        Node* temp = mHead;
        for (int i = 1; i < mCount; i++)
            temp = temp->mNext;
        temp->mNext = node;
    }
    mCount++;
}

/* Purpose: Returns the starting pos at the specified index, if none found, will return NULL
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
StartingPos* StartingList::get(int num)
{
    if (num < 0 || num >= mCount)
        return nullPos;

    Node* temp = mHead;
    for (int i = 1; i <= num; i++)
        temp = temp->mNext;

    return temp->mData;
}

int StartingList::getCount()
{
    return mCount;
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
    if (mHead == NULL)
        return;

    Node* temp = mHead;
    Node* pre = NULL;
    while (temp != NULL && temp->mData != pos)
    {
        pre = temp;
        temp = temp->mNext;
    }
    if (temp == NULL)
        return;

    pre->mNext = temp->mNext;
    temp->mNext = NULL;
    delete temp;

    mCount--;
}

bool operator!=(StartingPos* p1, StartingPos p2)
{
    return p1->mL != p2.mL || p1->mX != p2.mX || p1->mY != p2.mY;
}
