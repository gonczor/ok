#ifndef READER_H
#define READER_H

#include <fstream>
#include <vector>
#include <cstring>

#include "errors.h"

using namespace std;


class DataHolder
{
public:
    int processing_units_count;
    int task_count;
    vector<int> tasks;
};


void read_data_from_file(string filename, DataHolder *holder);

#endif
