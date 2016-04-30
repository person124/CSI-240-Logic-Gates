/* Filename:      fileWork.cpp
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

#include "fileWork.h"

string getIDFromInt(int id)
{
    if (id <= 0 || id >= COMPONENT_SIZE + 1)
        return "NULL";
    return COMPONENT_NAME[id - 1];
}

int getIntFromID(string name)
{
    for (int i = 1; i < COMPONENT_SIZE + 1; i++)
    {
        if (COMPONENT_NAME[i - 1] == name)
            return i;
    }
    return 0;
}

bool loadFromFile(string fileName, Layer& layer, StartingList& list)
{
    layer.~Layer();
    list.~StartingList();

    ifstream in(fileName.c_str());
    if (in.fail())
        return false;

    int count, id, w, h;
    in >> count;
    for (int i = 0; i < count; i++)
    {
        Grid* g;
        if (i != 0 || layer.getCount() == 0)
            layer.add(i, new Grid());
        g = layer.get(i);

        in >> w >> h;
        g->resize(w, h);

        for (int j = 0; j < w * h; j++)
        {
            int x = j % w;
            int y = j / w;
            in >> id;
            string sId = getIDFromInt(id);
            if (sId == "POWER")
                list.add(i, x, y);
            g->set(x, y, Component(sId));
        }
    }

    in.close();
    return true;
}

bool saveToFile(string fileName, Layer& layer)
{
    ofstream out(fileName.c_str());
    if (out.fail())
        return false;

    out << layer.getCount() << ' ';
    for (int i = 0; i < layer.getCount(); i++)
    {
        Grid* g = layer.get(i);
        int w = g->getWidth();
        int h = g->getHeight();

        out << w << ' ' << h;
        for (int j = 0; j < w * h; j++)
        {
            int x = j % w;
            int y = j / w;
            out << ' ' << getIntFromID(g->get(x, y).getID());
        }
        if (i + 1 < layer.getCount())
            out << ' ';
    }

    out.close();

    return true;
}
