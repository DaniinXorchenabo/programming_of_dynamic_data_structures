//
// Created by Daniil on 12.04.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SETLABQUEUE_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SETLABQUEUE_H

#include <list>
#include <set>
#include <queue>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <functional>

using namespace std;

class SetLabQueue {

protected:
    queue<int> container = {};
    function<bool(int)> check_element_func = [](int i) { return true; };

public:
    SetLabQueue(function<bool(int)> function1);
    SetLabQueue(bool (*checkElementFunc)(int) = [](int i) { return true; });

    SetLabQueue(int item_count, int min_, int max_,
            bool (*checkElementFunc)(int) = [](int i) { return true; });
    ~SetLabQueue();

    [[nodiscard]] bool is_empty_set() const;
    bool check_item(int element);
    bool add_item(int new_element);
    int len();
    std::string set_as_string(const std::string &splitter = (", "));
    bool is_subset(SetLabQueue *subset);

    bool is_equal(SetLabQueue *other);
    [[nodiscard]] SetLabQueue *union_sets(SetLabQueue *other);
    [[nodiscard]] SetLabQueue *intersection_of_sets(SetLabQueue *other);

    [[nodiscard]] SetLabQueue *subtraction_of_sets(SetLabQueue *subtracted);

    [[nodiscard]] SetLabQueue *symmetric_difference_of_sets(SetLabQueue *other);
};


#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SETLABQUEUE_H
