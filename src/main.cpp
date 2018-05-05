#include <iostream>

#include "algorithms.h"
#include "data.h"
#include "errors.h"

using namespace std;

int main(int argc, char** argv)
{
    DataHolder *holder;
    Greedy *greedy;

    if(argc != 2)
    {
        cerr << "Wrong number of arguments." << endl;
        return 1;
    }

    try
    {
        holder = new DataHolder();
        read_data_from_file(argv[1], holder);

        greedy = new Greedy(holder);
        greedy->run();
        greedy->show();
    }
    catch(FileHandlerException& e)
    {
        e.show_message();
        delete holder;
        return 1;
    }

    delete holder;
    delete greedy;

    return 0;
}
