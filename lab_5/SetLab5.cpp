//
// Created by Daniil on 12.04.2022.
//
#include <random>
#include <ranges>
#include <string>
#include <utility>


#include "SetLab5.h"

namespace rng = ranges;
namespace vw = ranges::views;


bool SetLab5::check_item(int element) {
    return container.find(element) != container.end();
}

int SetLab5::len() {
    return container.size();
}

bool SetLab5::is_empty_set() const {
    return container.empty();
}

bool SetLab5::add_item(int new_element) {
    if (check_element_func(new_element) && !check_item(new_element)) {
        container.insert(new_element);
        return true;
    }
    return false;
}


string SetLab5::set_as_string(const std::string &splitter) {

    if (is_empty_set()) {
        return "<empty set>";
    }
    string data;
    for (auto item: container) {
        if (!data.empty()) {
            data += splitter;
        }
        data += std::to_string(item);
    }
    return "(<" + data + ">)";

}

bool SetLab5::is_subset(SetLab5 *subset) {
    return rng::includes(container, subset->container);
}

bool SetLab5::is_equal(SetLab5 *other) {
    return is_subset(other) && other->is_subset(this);
}


SetLab5 *SetLab5::union_sets(SetLab5 *other) {
    auto result = new SetLab5([this, other](int i) {
        return this->check_element_func(i) || other->check_element_func(i);
    });
    list<int> d = {};
    rng::set_union(container, other->container, std::inserter(result->container, result->container.begin()));
    return result;
}

SetLab5 *SetLab5::intersection_of_sets(SetLab5 *other) {
    auto result = new SetLab5([this, other](int i) {
        return this->check_element_func(i) && other->check_element_func(i);
    });
    rng::set_intersection(container, other->container, std::inserter(result->container, result->container.begin()));
    return result;
}

SetLab5 *SetLab5::subtraction_of_sets(SetLab5 *subtracted) {
    return subtraction_of_sets(subtracted, static_cast<function<bool(int)>>(check_element_func));
}

SetLab5 *SetLab5::subtraction_of_sets(SetLab5 *subtracted, const function<bool(int)> &function1) {
    auto result = new SetLab5(static_cast<function<bool(int)>>(function1));
    rng::set_difference(container, subtracted->container, std::inserter(result->container, result->container.begin()));
    return result;
}

SetLab5 *SetLab5::symmetric_difference_of_sets(SetLab5 *other) {
    auto result = new SetLab5(
            [this, other](int i) {
                return this->check_element_func(i) || other->check_element_func(i);
            }
    );
    rng::set_symmetric_difference(container, other->container,
                                  std::inserter(result->container, result->container.begin()));
    return result;
}


SetLab5::SetLab5(function<bool(int)> function1) {
    check_element_func = std::move(function1);
}

SetLab5::SetLab5(int item_count, int min_, int max_,
                 bool (*checkElementFunc)(int)
) : check_element_func(checkElementFunc) {
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());
    auto numbers_out = vw::iota(min_, max_) | vw::filter(check_element_func);

    std::vector<int> second(numbers_out.begin(), numbers_out.end());

    rng::shuffle(second, gen);
    for (auto item: second | vw::take(item_count)) {
        container.insert(item);
    }

    if (container.size() < item_count) {
        std::cout << "impossible interval (" << min_ << ", " << max_ << ") for items count is " << item_count << endl;
    }

}