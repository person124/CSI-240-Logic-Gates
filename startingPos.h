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
        StartingPos* mArray;
        int mSize;
        StartingPos* nullPos;
    public:
        StartingList();
        ~StartingList();
        void add(int, int, int);
        void add(StartingPos);
        StartingPos* get(int);
        int getSize();
        void remove(int, int, int);
        void remove(StartingPos);
};

bool operator==(StartingPos, StartingPos);

#endif
