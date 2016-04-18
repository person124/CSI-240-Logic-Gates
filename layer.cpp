#include "layer.h"

Layer::Layer()
{
    mCount = 0;
    mHead = NULL;
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

void Layer::add(int num, Grid& g)
{
    if (num == 0)
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

Grid* Layer::get(int num)
{
    if (num < 0 || num >= mCount)
        return NULL;

    Node* temp = mHead;
    for (int i = 1; i < num; i++)
        temp = temp->mNext;

    return temp->mData;
}

void Layer::push(Grid& g)
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

void Layer::pop()
{
    if (mHead == NULL)
        return;
    Node* temp = mHead;
    mHead = temp->mNext;
    delete temp;
    mCount--;
}

void Layer::enqueue(Grid& g)
{
    Node* temp = new Node(g);
    mTail->mNext = temp;
    mTail = temp;
    mCount++;
}

void Layer::remove(int num)
{
    if (mHead == NULL)
        return;

    Node* temp = mHead;
    Node* pre = NULL;
    for (int i = 1; i < num; i++)
    {
        pre = temp;
        temp = temp->mNext;
    }

    if (temp == mHead)
    {
        if (temp == mTail)
            mTail = NULL;
        delete temp;
        mHead = NULL;
    }
    else if (temp == mTail)
    {
        mTail = pre;
        pre->mNext = NULL;
        delete temp;
    }
    else
    {
        pre->mNext = temp->mNext;
        temp->mNext = NULL;
        delete temp;
    }

    mCount--;
}
