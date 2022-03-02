//
// Created by Daniil on 15.02.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_2_6_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_2_6_H

#define SIZEOF_NODE \
    sizeof(NODE)

#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>


using namespace std;


typedef struct NODE_ {
    NODE_ *pNext = nullptr;
    int item = INT_MAX;

    auto operator<=>(const NODE_ &) const = default;

    bool operator==(const NODE_ &) const = default;

} NODE, *PNODE;


PNODE Alloc();


NODE *create_empty_set();

bool is_empty_set(NODE *testing);

bool check_item(int element, NODE *testing);

[[nodiscard]] NODE *add_item(int new_element, NODE *list_, bool check_element_func(int) = [](int i) { return true; });

NODE *create_set(int item_count, int min_, int max_, bool check_element_func(int));

int len(NODE *set_);

std::string set_as_string(NODE *set_, const std::string &splitter = (", "));

[[nodiscard]] NODE *delete_set(NODE *set_);

bool is_subset(NODE *subset, NODE *base_set);

bool is_equal(NODE *one, NODE *two);

[[nodiscard]] NODE *union_sets(NODE *small_, NODE *big);

[[nodiscard]] NODE *glue_sets(NODE *big, NODE *small_);

[[nodiscard]] NODE *intersection_of_sets(NODE *big, NODE *small_);

[[nodiscard]] NODE *subtraction_of_sets(NODE *reduced, NODE *subtracted);

[[nodiscard]] NODE *symmetric_difference_of_sets(NODE *one, NODE *two);


#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_2_6_H
