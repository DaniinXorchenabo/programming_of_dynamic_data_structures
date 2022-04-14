//
// Created by Daniil on 12.04.2022.
//

#include <random>
#include <ranges>
#include <string>
#include <utility>

#include "defines.h"
#include "SetLabQueue.h"


namespace rng = ranges;
namespace vw = ranges::views;


int SetLabQueue::len() const {
    return container.size();
}

bool SetLabQueue::is_empty_set() const {
    return container.empty();
}

bool SetLabQueue::check_item(int element) {
    if (container.empty()){
        return false;
    }
    bool result = false;
    SET_FOR_EACH(container, item) {
        result = result || (item == element);
    }
    return result;
}

bool SetLabQueue::add_item(int new_element) {
    if (check_element_func(new_element) && !check_item(new_element)) {
        container.push(new_element);
        return true;
    }
    return false;
}


std::string SetLabQueue::set_as_string(const std::string &splitter) {
    if (is_empty_set()) {
        return "<empty set>";
    }
    std::string data;
    SET_FOR_EACH(container, item) {
        if (!data.empty()) {
            data += splitter;
        }
        data += std::to_string(item);
    }
    return "(<" + data + ">)";
}

bool SetLabQueue::is_subset(SetLabQueue *subset){
    bool result = true;
    SET_FOR_EACH(subset->container, item) {
        result = result && check_item(item);
    }
    return result;
}

bool SetLabQueue::is_equal(SetLabQueue *other) {
    return is_subset(other) && other->is_subset(this);
}

SetLabQueue *SetLabQueue::union_sets(SetLabQueue *other) {
    auto result = new SetLabQueue([this, other](int i){
        return this->check_element_func(i) || other->check_element_func(i);
    });
    SET_FOR_EACH(this->container, item1) {
        result->add_item(item1);
    }
    SET_FOR_EACH2(other->container, item2, copied_queue2) {
        result->add_item(item2);
    }
    return result;
}

SetLabQueue *SetLabQueue::intersection_of_sets(SetLabQueue *other) {
    auto result = new SetLabQueue([this, other](int i){
        return this->check_element_func(i) && other->check_element_func(i);
    });
    SET_FOR_EACH(this->container, item) {
        if (other->check_item(item)) {
            result->add_item(item);
        }
    }
    return result;
}

SetLabQueue *SetLabQueue::subtraction_of_sets(SetLabQueue *subtracted) {
    return subtraction_of_sets(subtracted, static_cast<function<bool(int)>>(check_element_func));
}

SetLabQueue *SetLabQueue::subtraction_of_sets(SetLabQueue *subtracted, const function<bool(int)>& function1) {
    auto result = new SetLabQueue(
            static_cast<function<bool(int)>>(function1));
    SET_FOR_EACH(this->container, item) {
        if (!subtracted->check_item(item)) {
            result->add_item(item);
        }
    }
    return result;
}


SetLabQueue *SetLabQueue::glue_sets(SetLabQueue *other) {
    SET_FOR_EACH(other->container, item) {
        container.push(item);
    }
    return this;
}

SetLabQueue *SetLabQueue::symmetric_difference_of_sets(SetLabQueue *other) {
    return this->subtraction_of_sets(
            other,
            static_cast<const function<bool(int)>>([this, other](int i){
                return this->check_element_func(i) || other->check_element_func(i);
            })
    )->glue_sets(other->subtraction_of_sets(this));
}


SetLabQueue::SetLabQueue(function<bool(int)> function1) {
    check_element_func = std::move(function1);
}

SetLabQueue::SetLabQueue(
        bool (*checkElementFunc)(int)
) : check_element_func(checkElementFunc) {

}

SetLabQueue::SetLabQueue(int item_count, int min_, int max_,
                         bool (*checkElementFunc)(int)
) : check_element_func(checkElementFunc) {
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());
    auto numbers_out = vw::iota(min_, max_) | vw::filter(check_element_func);

    std::vector<int> second(numbers_out.begin(), numbers_out.end());

    rng::shuffle(second, gen);
    for (auto item: second | vw::take(item_count)) {
        container.push(item);
    }

    if (container.size() < item_count) {
        std::cout << "impossible interval (" << min_ << ", " << max_ << ") for items count is " << item_count << endl;
    }

}

SetLabQueue::~SetLabQueue() {
    while (!container.empty()) {
        container.pop();
    }
}