#include <iostream>

#include "algorithms.h"

using namespace std;

Greedy::Greedy(DataHolder *holder)
{
    this->holder = holder;
    this->task_array = new vector<int>[this->holder->processing_units_count];
}

void Greedy::run()
{
    sort(this->holder->tasks.begin(), this->holder->tasks.end());

    for(int i = 0; i < this->holder->task_count; i++)
    {
        this->task_array[i % this->holder->processing_units_count].push_back(
            this->holder->tasks.back()
        );
        this->holder->tasks.pop_back();
    }

}

void Greedy::show()
{
    for(int i = 0; i < this->holder->processing_units_count; i++)
    {
        cout << "Unit " << i << ": ";
        for(uint j = 0; j < this->task_array[i].size(); j++)
            cout << this->task_array[i][j] << " ";
        cout << "\n";
    }
}

// Metaheuristics begin here.
