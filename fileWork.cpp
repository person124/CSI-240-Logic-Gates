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

bool loadFromFile(string fileName, Layer& layer)
{
    layer.~Layer();
    ifstream in(fileName.c_str());
    if (in.fail())
        return false;

    int count, id, w, h;
    in >> count;
    for (int i = 0; i < count; i++)
    {
        Grid* g;
        if (i != 0)
            layer.add(i, new Grid());
        g = layer.get(i);

        in >> w >> h;
        g->resize(w, h);

        for (int j = 0; j < w * h; j++)
        {
            int x = j % w;
            int y = j / w;
            in >> id;
            g->set(x, y, Component(getIDFromInt(id)));
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
    }

    out.close();

    return true;
}
