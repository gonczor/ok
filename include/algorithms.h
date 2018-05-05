#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <algorithm>
#include "data.h"

class Greedy
{
    vector<int> *task_array;
    DataHolder *holder;
public:
    Greedy(DataHolder *holder);
    void run();
    void show();
};

class Heuristic
{
    DataHolder *holder;
public:
    Heuristic(DataHolder *holder);
    void run();
};

#endif
