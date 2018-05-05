#!/usr/bin/env python3

import collections
import random
import sys

def generate_random(tasks, number_of_processing_units, number_of_tasks):
    """Generates fully random data"""
    i = 0
    while i < number_of_tasks:
        tasks[i % number_of_processing_units].append(random.randint(1, 100))
        i += 1


def generate_optimal(tasks, number_of_processing_units, number_of_tasks):
    """Generates data that can have 100% usage of processing units."""
    if number_of_processing_units > number_of_tasks:
        print(
            'Can\'t do this. Number of processing units has to be at least equal to number of'
            ' tasks.'
        )
    i = 0
    while i < number_of_tasks - number_of_processing_units:
        tasks[i % number_of_processing_units].append(random.randint(1, 100))
        i += 1
    # print('After first loop: {}'.format(tasks))
    max_duration = 0
    max_duration_unit_id = None
    for unit_id, task_list in tasks.items():
        tmp_max = sum(task_list)
        if tmp_max > max_duration:
            # print('Old id: {} duration: {}'.format(max_duration_unit_id, max_duration))
            max_duration_unit_id = unit_id
            max_duration = tmp_max
            # print('New id: {} duration: {}'.format(max_duration_unit_id, max_duration))
    while i < number_of_tasks:
        if i % number_of_processing_units == max_duration_unit_id:
            tasks[i % number_of_processing_units].append(1)
        else:
            current_sum = sum(tasks[i % number_of_processing_units])
            tasks[i % number_of_processing_units].append(max_duration - current_sum + 1)
        print('For id {} tasks: {} duration sum: {}'.format(
                i % number_of_processing_units,
                tasks[i % number_of_processing_units],
                sum(tasks[i % number_of_processing_units])
        ))
        i += 1


def save_to_file(file_name, tasks, number_of_processing_units, number_of_tasks):
    with open('data/' + file_name, 'w+') as file_to_save:
        file_to_save.write(str(number_of_processing_units) + '\n')
        file_to_save.write(str(number_of_tasks) + '\n')
        for task_list in tasks.values():
            file_to_save.write('\n'.join(str(t) for t in task_list))
            file_to_save.write('\n')


tasks = collections.defaultdict(list)
number_of_processing_units = int(input('Give number of processing units: '))
number_of_tasks = int(input('Give number of processing tasks: '))
file_name = input('Give file name to save (will be moved to data/ folder): ')

if sys.argv[-1] == 'optimal':
    generate_optimal(tasks, number_of_processing_units, number_of_tasks)
else:
    generate_random(tasks, number_of_processing_units, number_of_tasks)

print(tasks)
save_to_file(file_name, tasks, number_of_processing_units, number_of_tasks)
