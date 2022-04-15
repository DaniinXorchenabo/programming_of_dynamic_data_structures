//
// Created by Daniil on 02.03.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SET_LAB_3_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SET_LAB_3_H

#define SIZEOF_NODE \
    sizeof(NODE)

#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <functional>

#include "../base_class/BaseClass.h"


using namespace std;


typedef struct NODE_ {
    NODE_ *pNext = nullptr;
    int item = INT_MAX;

    auto operator<=>(const NODE_ &) const = default;

    bool operator==(const NODE_ &) const = default;

} NODE, *PNODE;

class SetLab3 {
public:
    NODE *pHead = nullptr;

    SetLab3(function<bool(int)> function1);

    static PNODE Alloc();

    SetLab3(bool (*checkElementFunc)(int) = [](int i) { return true; });

    SetLab3(int item_count, int min_, int max_,
            bool (*checkElementFunc)(int) = [](int i) { return true; });

    ~SetLab3();

    [[nodiscard]] bool is_empty_set() const;

    bool check_item(int element);

    NODE *add_item(int new_element);

    int len();

    std::string set_as_string(const std::string &splitter = (", "));

    bool is_subset(SetLab3 *subset);

    bool is_equal(SetLab3 *other);

    [[nodiscard]] SetLab3 *union_sets(SetLab3 *other);

    [[nodiscard]] SetLab3 *glue_sets(SetLab3 *other);

    [[nodiscard]] SetLab3 *intersection_of_sets(SetLab3 *other);

    [[nodiscard]] SetLab3 *subtraction_of_sets(SetLab3 *subtracted);

    [[nodiscard]] SetLab3 *subtraction_of_sets(SetLab3 *subtracted, const function<bool(int)> &function1);

    [[nodiscard]] SetLab3 *symmetric_difference_of_sets(SetLab3 *other);

private:
    function<bool(int)> check_element_func = [](int i) { return true; };
};

#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SET_LAB_3_H
