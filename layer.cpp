#include "layer.h"

Layer::Layer()
{
    mCount = 0;
    mHead = NULL;
	mCurrent = 0;
	for (int i = 0; i < 2; i++)
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

void Layer::enqueue(Grid* g)
{
    Node* temp = new Node(g);
    mTail->mNext = temp;
    mTail = temp;
    mCount++;
}

Grid* Layer::get(int num)
{
    if (num < 0 || num >= mCount)
        return NULL;

    Node* temp = mHead;
    for (int i = 1; i < num; i++)
        temp = temp->mNext;
	
	mCurrent = num;

    return temp->mData;
}

int Layer::getCount()
{
	return mCount;
}

int Layer::getCurrentLayer()
{
	return mCurrent;
}

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

void Layer::pop()
{
    if (mHead == NULL)
        return;
    Node* temp = mHead;
    mHead = temp->mNext;
    delete temp;
    mCount--;
}

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

Grid* operator++(Layer& l)
{
	Grid* temp = l.get(l.getCurrentLayer() + 1);
	if (temp == NULL)
	{
		l.enqueue(new Grid());
		temp = l.get(l.getCount() - 1);
	}
	return temp;
}

Grid* operator--(Layer& l)
{
	Grid* temp = l.get(l.getCurrentLayer() - 1);
	if (temp == NULL)
	{
		l.push(new Grid());
		temp = l.get(0);
	}
	return temp;
}
