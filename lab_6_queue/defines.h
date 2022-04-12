//
// Created by Daniil on 17.02.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_DEFINES_3_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_DEFINES_3_H

#include <list>
#include <set>
#include <queue>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <functional>

using namespace std;



int get_next_item(queue<int>& container, queue<int>& copied_queue){
    auto last_item = container.front();
    copied_queue.push(last_item);
    container.pop();
    if (container.empty()){
        return last_item;
    }
    return container.front();
}

bool reverse_copied_in_queue(queue<int> &container, queue<int> &copied_queue) {
    for (
            int j = copied_queue.front();
            !copied_queue.empty();
            j = get_next_item(copied_queue, container)
            ) {}
    return false;
}


#define SET_FOR_EACH(container, item)           \
    queue<int> copied_queue;                                        \
    for (                                   \
        int (item) = (container).front();            \
        !(container).empty() || reverse_copied_in_queue((container), copied_queue);  \
        (item) = get_next_item((container), copied_queue) \
        )

#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_DEFINES_3_H
