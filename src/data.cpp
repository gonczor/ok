#include "data.h"

void read_data_from_file(string filename, DataHolder *holder)
{
    ifstream data_file;
    string data;
    int processing_units_count, task_count, process_duration;

    data_file.open(filename);
    if(!data_file.good())
    {
        string message = "Could not open file " + filename;
        throw FileHandlerException(message);
    }

    getline(data_file, data);
    processing_units_count = stoi(data);
    holder->processing_units_count = processing_units_count;

    getline(data_file, data);
    task_count = stoi(data);
    holder->task_count = task_count;

    while(getline(data_file, data))
    {
        process_duration = stoi(data);
        holder->tasks.push_back(process_duration);
    }
    data_file.close();
}
