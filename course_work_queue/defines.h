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


int get_next_item(queue<int> &container, queue<int> &copied_queue);

bool reverse_copied_in_queue(queue<int> &full_queue, queue<int> &empty_queue);


#define SET_FOR_EACH(container, item)           \
    queue<int> copied_queue;                                        \
                                                \
    for (                                   \
        int (item) = (container).empty()?-1:(container).front();            \
        !(container).empty() || reverse_copied_in_queue(copied_queue, (container));  \
        (item) = get_next_item((container), copied_queue) \
        )

#define SET_FOR_EACH2(container, item, copied_queue1)      \
    queue<int> (copied_queue1);                                                    \
    for (                                   \
        int (item) = (container).empty()?-1:(container).front();            \
        !(container).empty() || reverse_copied_in_queue((copied_queue1), (container));  \
        (item) = get_next_item((container), (copied_queue1)) \
        )


#define SAFE_SET_FOR_EACH(container, item)           \
    queue<int> copied_queue1;                    \
    queue<int> copied_queue2;   \
    reverse_copied_in_queue((container), copied_queue1, copied_queue2); \
    reverse_copied_in_queue(copied_queue1, (container)); \
    for (                                   \
        int (item) = container.empty()?-1:copied_queue2.front();            \
        !copied_queue2.empty();  \
        (item) = get_next_item(copied_queue2, copied_queue1) \
        )

#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_DEFINES_3_H
