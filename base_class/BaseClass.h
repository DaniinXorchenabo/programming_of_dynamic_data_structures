//
// Created by Daniil on 14.04.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_BASECLASS_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_BASECLASS_H

#include <list>
#include <set>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <functional>
#include <random>
#include <ranges>
#include <string>
#include <utility>


using namespace std;
namespace rng = ranges;
namespace vw = ranges::views;

class BaseClass {
//    virtual BaseClass(function<bool(int)> function1) = 0;
//
//    virtual BaseClass(bool (*checkElementFunc)(int) = [](int i) { return true; }) = 0;
//
//    virtual BaseClass(int item_count, int min_, int max_,
//            bool (*checkElementFunc)(int) = [](int i) { return true; }) = 0;
public:

    [[nodiscard]] virtual bool is_empty_set() const = 0;

    virtual bool check_item(int element) = 0;

    virtual int len() = 0;

    virtual std::string set_as_string(const std::string &splitter = (", ")) = 0;

    virtual bool is_subset(BaseClass *subset) = 0;

    virtual bool is_equal(BaseClass *other) = 0;

    [[nodiscard]] virtual BaseClass *union_sets(BaseClass *other) = 0;

    [[nodiscard]] virtual BaseClass *intersection_of_sets(BaseClass *other) = 0;

    [[nodiscard]] virtual BaseClass *subtraction_of_sets(BaseClass *subtracted) = 0;

    [[nodiscard]] virtual BaseClass *symmetric_difference_of_sets(BaseClass *other) = 0;
};


#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_BASECLASS_H
