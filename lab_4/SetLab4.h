//
// Created by Daniil on 12.04.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SETLAB4_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SETLAB4_H

#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <functional>


using namespace std;

class SetLab4 {

protected:
    function<bool(int)> check_element_func = [](int i) { return true; };

public:
    SetLab4(function<bool(int)> function1);
    SetLab4(bool (*checkElementFunc)(int) = [](int i) { return true; });

    SetLab4(int item_count, int min_, int max_,
            bool (*checkElementFunc)(int) = [](int i) { return true; });
    ~SetLab4();

    [[nodiscard]] bool is_empty_set() const;
    bool check_item(int element);
    bool add_item(int new_element);
    int len();
    std::string set_as_string(const std::string &splitter = (", "));
    bool is_subset(SetLab4 *subset);

    bool is_equal(SetLab4 *other);
    [[nodiscard]] SetLab4 *union_sets(SetLab4 *other);
    [[nodiscard]] SetLab4 *intersection_of_sets(SetLab4 *other);

    [[nodiscard]] SetLab4 *subtraction_of_sets(SetLab4 *subtracted);
    [[nodiscard]] SetLab4 *subtraction_of_sets(SetLab4 *subtracted, const function<bool(int)>& function1);

    [[nodiscard]] SetLab4 *symmetric_difference_of_sets(SetLab4 *other);

    list<int> container = {};
};


#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SETLAB4_H
