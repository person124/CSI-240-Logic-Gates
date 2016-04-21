#ifndef STARTING_POS_H
#define STARTING_POS_H

#include "stddef.h"

struct StartingPos
{
        int mL, mX, mY;
};

class StartingList
{
    private:
        struct Node
        {
            StartingPos* mData;
            Node* mNext;
            Node()
            {
                mData = NULL;
                mNext = NULL;
            }
            Node(StartingPos pos)
            {
                *mData = pos;
                mNext = NULL;
            }
        };
        Node* mHead;
        int mCount;
        StartingPos* nullPos;
    public:
        StartingList();
        ~StartingList();
        void add(int, int, int);
        void add(StartingPos);
        StartingPos* get(int);
        int getCount();
        void remove(int, int, int);
        void remove(StartingPos);
};

bool operator!=(StartingPos*, StartingPos);

#endif
