//
// Created by Daniil on 15.02.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_2_6_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_2_6_H

#define SIZEOF_NODE2 \
    sizeof(NODE2)

#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>


using namespace std;


typedef struct NODE2_ {
    NODE2_ *pNext = nullptr;
    int item = INT_MAX;

    auto operator<=>(const NODE2_ &) const = default;

    bool operator==(const NODE2_ &) const = default;

} NODE2, *PNODE2;


PNODE2 Alloc();


NODE2 *create_empty_set();

bool is_empty_set(NODE2 *testing);

bool check_item(int element, NODE2 *testing);

[[nodiscard]] NODE2 *add_item(int new_element, NODE2 *list_, bool check_element_func(int) = [](int i) { return true; });

NODE2 *create_set(int item_count, int min_, int max_, bool check_element_func(int));

int len(NODE2 *set_);

std::string set_as_string(NODE2 *set_, const std::string &splitter = (", "));

[[nodiscard]] NODE2 *delete_set(NODE2 *set_);

bool is_subset(NODE2 *subset, NODE2 *base_set);

bool is_equal(NODE2 *one, NODE2 *two);

[[nodiscard]] NODE2 *union_sets(NODE2 *small_, NODE2 *big);

[[nodiscard]] NODE2 *glue_sets(NODE2 *big, NODE2 *small_);

[[nodiscard]] NODE2 *intersection_of_sets(NODE2 *big, NODE2 *small_);

[[nodiscard]] NODE2 *subtraction_of_sets(NODE2 *reduced, NODE2 *subtracted);

[[nodiscard]] NODE2 *symmetric_difference_of_sets(NODE2 *one, NODE2 *two);


#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_2_6_H
