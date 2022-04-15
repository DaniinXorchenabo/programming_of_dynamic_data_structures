//
// Created by Daniil on 13.04.2022.
//

#include "defines.h"

int get_next_item(queue<int> &container, queue<int> &copied_queue) {
    auto last_item = container.front();
    copied_queue.push(last_item);
    container.pop();
    if (container.empty()) {
        return last_item;
    }
    return container.front();
}

bool reverse_copied_in_queue(queue<int> &full_queue, queue<int> &empty_queue) {
    for (
            int j = full_queue.empty() ? -1 : full_queue.front();
            !full_queue.empty();
            j = get_next_item(full_queue, empty_queue)
            ) {}
    return false;
}

bool reverse_copied_in_queue(
        queue<int> &full_queue,
        queue<int> &empty_queue1,
        queue<int> &empty_queue2
) {
    for (
            int j = full_queue.empty() ? -1 : full_queue.front();
            !full_queue.empty();
            j = get_next_item(full_queue, empty_queue1)
            ) {
        empty_queue2.push(j);
    }
    return false;
}