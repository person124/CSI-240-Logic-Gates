/* Filename:      layer.cpp
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

#include "layer.h"

/* Purpose: Default constructor for the layer system
 *     Pre: None
 *    Post: Creates two layers to start with
 *  Author: Calum M. Phillips
 */
Layer::Layer()
{
    mCount = 0;
    mHead = NULL;
    mCurrent = 0;
    for (int i = 0; i < 1; i++)
        push(new Grid());
}

Layer::~Layer()
{
    Node* temp = mHead;
    for (int i = 0; i < mCount; i++)
    {
        Node* next = temp->mNext;
        delete temp;
        temp = next;
    }
}

/* Purpose: Adds a new Grid to the layer system at the specified location.
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
void Layer::add(int num, Grid* g)
{
    if (num <= 0)
        push(g);
    else if (num >= mCount)
        enqueue(g);
    else
    {
        Node* temp = mHead;
        for (int i = 1; i < num; i++)
            temp = temp->mNext;

        Node* newNode = new Node(g);
        newNode->mNext = temp->mNext;
        temp->mNext = newNode;

        mCount++;
    }
}

/* Purpose: Removes the layer at the front
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
void Layer::dequeue()
{
    if (mHead == NULL)
        return;
    if (mHead == mTail)
        mHead = NULL;

    Node* temp = mHead;
    Node* toDel = mTail;
    while (temp->mNext != mTail)
        temp = temp->mNext;

    temp->mNext = NULL;
    mTail = temp;

    delete toDel;

    mCount--;
}

/* Purpose: Adds the specified grid to the back of the layers
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
void Layer::enqueue(Grid* g)
{
    Node* temp = new Node(g);
    mTail->mNext = temp;
    mTail = temp;
    mCount++;
}

/* Purpose: Gets the layer at the specific location, if unfound, returns NULL
 *     Pre: None
 *    Post: None
 *  Author: Calum M. Phillips
 */
Grid* Layer::get(int num)
{
    if (num < 0 || num >= mCount)
        return NULL;

    Node* temp = mHead;
    for (int i = 1; i <= num; i++)
        temp = temp->mNext;

    return temp->mData;
}

int Layer::getCount()
{
    return mCount;
}

/* Purpose: Gets the systems current layer.
 *     Pre: None
 *    Post: None
 *  Author: Calum M. Phillips
 */
int Layer::getCurrentLayer()
{
    return mCurrent;
}

/* Purpose: Adds the specified grid to the front of the list
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
void Layer::push(Grid* g)
{
    if (mHead == NULL)
    {
        Node* temp = new Node(g);
        mHead = temp;
        mTail = temp;
    }
    else
    {
        Node* temp = new Node(g);
        temp->mNext = mHead;
        mHead = temp;
    }

    mCount++;
}

/* Purpose: Removes the first layer from the list
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
void Layer::pop()
{
    if (mHead == NULL)
        return;
    Node* temp = mHead;
    mHead = temp->mNext;
    delete temp;
    mCount--;
}

/* Purpose: Removes the layer at the specified location.
 *     Pre: None
 *    Post: See "Purpose"
 *  Author: Calum M. Phillips
 */
void Layer::remove(int num)
{
    if (num <= 0)
        pop();
    else if (num >= mCount)
        dequeue();
    else
    {
        Node* temp = mHead;
        Node* pre = NULL;
        for (int i = 1; i < num; i++)
        {
            pre = NULL;
            temp = temp->mNext;
        }

        pre->mNext = temp->mNext;
        temp->mNext = NULL;
        delete temp;

        mCount--;
    }
}

void Layer::setCurrentLayer(int num)
{
    mCurrent = num;
}

/* Purpose: Moves one up in the layers.
 *     Pre: None
 *    Post: The current layer goes up by one.
 *  Author: Calum M. Phillips
 */
Grid* operator++(Layer& l)
{
    Grid* temp;
    if (l.getCurrentLayer() + 1 >= l.getCount())
    {
        temp = new Grid();
        l.enqueue(temp);
    }
    else
        temp = l.get(l.getCurrentLayer() + 1);
    l.setCurrentLayer(l.getCurrentLayer() + 1);
    return temp;
}

/* Purpose: Moves one down in the layers.
 *     Pre: None
 *    Post: The current layer goes down by one.
 *  Author: Calum M. Phillips
 */
Grid* operator--(Layer& l)
{
    Grid* temp;
    if (l.getCurrentLayer() == 0)
    {
        temp = new Grid();
        l.push(temp);
    }
    else
    {
        temp = l.get(l.getCurrentLayer() - 1);
        l.setCurrentLayer(l.getCurrentLayer() - 1);
    }
    return temp;
}
