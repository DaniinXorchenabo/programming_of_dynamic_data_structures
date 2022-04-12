//
// Created by Daniil on 12.04.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SETLAB5_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SETLAB5_H


#include <list>
#include <set>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <functional>


using namespace std;


class SetLab5 {

protected:
    set<int> container = {};
    function<bool(int)> check_element_func = [](int i) { return true; };

public:
    SetLab5(function<bool(int)> function1);
    SetLab5(bool (*checkElementFunc)(int) = [](int i) { return true; });

    SetLab5(int item_count, int min_, int max_,
            bool (*checkElementFunc)(int) = [](int i) { return true; });
    ~SetLab5();

    [[nodiscard]] bool is_empty_set() const;
    bool check_item(int element);
    bool add_item(int new_element);
    int len();
    std::string set_as_string(const std::string &splitter = (", "));
    bool is_subset(SetLab5 *subset);

    bool is_equal(SetLab5 *other);
    [[nodiscard]] SetLab5 *union_sets(SetLab5 *other);
    [[nodiscard]] SetLab5 *intersection_of_sets(SetLab5 *other);

    [[nodiscard]] SetLab5 *subtraction_of_sets(SetLab5 *subtracted);

    [[nodiscard]] SetLab5 *symmetric_difference_of_sets(SetLab5 *other);

};


#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SETLAB5_H
