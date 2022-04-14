//
// Created by Daniil on 12.04.2022.
//
#include <random>
#include <ranges>
#include <string>
#include <utility>
#include <algorithm>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "SetLab4.h"

namespace rng = ranges;
namespace vw = ranges::views;

bool SetLab4::check_item(int element) {
    return rng::find(container, element) != container.end();
}

bool SetLab4::is_empty_set() const {
    return container.empty();
}

bool SetLab4::add_item(int new_element) {
    if (check_element_func(new_element) && !check_item(new_element)) {
        container.push_back(new_element);
        return true;
    }
    return false;
}

int SetLab4::len() {
    return static_cast<int>(container.size());
}

string SetLab4::set_as_string(const std::string &splitter) {

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

bool SetLab4::is_subset(SetLab4 *subset) {
    for (auto item: subset->container) {
        if (!check_item(item)) {
            return false;
        }
    }
    return true;
}

bool SetLab4::is_equal(SetLab4 *other) {
    return is_subset(other) && other->is_subset(this);
}


SetLab4 *SetLab4::union_sets(SetLab4 *other) {
    auto result = new SetLab4([this, other](int i) {
        return this->check_element_func(i) || other->check_element_func(i);
    });
    for (auto item: other->container) {
        result->add_item(item);
    }
    for (auto item: container) {
        result->add_item(item);
    }
    return result;
}

SetLab4 *SetLab4::intersection_of_sets(SetLab4 *other) {
    auto result = new SetLab4([this, other](int i) {
        return this->check_element_func(i) && other->check_element_func(i);
    });

    for (auto item: container) {
        if (other->check_item(item)) {
            result->add_item(item);
        }
    }

    return result;
}

SetLab4 *SetLab4::subtraction_of_sets(SetLab4 *subtracted) {
    return subtraction_of_sets(subtracted, static_cast<function<bool(int)>>(check_element_func));
}

SetLab4 *SetLab4::subtraction_of_sets(SetLab4 *subtracted, const function<bool(int)> &function1) {
    auto result = new SetLab4(static_cast<function<bool(int)>>(function1));

    for (auto item: container) {
        if (!subtracted->check_item(item)) {
            result->add_item(item);
        }
    }

    return result;
}

SetLab4 *SetLab4::glue_sets(SetLab4 *other) {
    for (auto item: other->container) {
        container.push_back(item);
    }
    return this;
}


SetLab4 *SetLab4::symmetric_difference_of_sets(SetLab4 *other) {
    auto result = this->subtraction_of_sets(
            other,
            static_cast<const function<bool(int)>>([this, other](int i) {
                return this->check_element_func(i) || other->check_element_func(i);
            })
    )->glue_sets(other->subtraction_of_sets(this));

    return result;
}


SetLab4::SetLab4(
        bool (*checkElementFunc)(int)
) : check_element_func(checkElementFunc) {

}

SetLab4::SetLab4(int item_count, int min_, int max_,
                 bool (*checkElementFunc)(int)
) : check_element_func(checkElementFunc) {
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());
    auto numbers_out = vw::iota(min_, max_) | vw::filter(check_element_func);

    std::vector<int> second(numbers_out.begin(), numbers_out.end());

    rng::shuffle(second, gen);
    for (auto item: second | vw::take(item_count)) {
        container.push_back(item);
    }

    if (container.size() < item_count) {
        std::cout << "impossible interval (" << min_ << ", " << max_ << ") for items count is " << item_count << endl;
    }

}

SetLab4::~SetLab4() {

}

SetLab4::SetLab4(function<bool(int)> function1) {
    check_element_func = std::move(function1);
}
