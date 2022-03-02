//
// Created by Daniil on 15.02.2022.
//

#include <random>
#include <ranges>
#include <string>
#include <utility>
//  #include <Windows.h>
#include "set_lab_3.h"
#include "defines.h"

namespace rng = std::ranges;
namespace vw = std::ranges::views;


SetLab3::SetLab3(
        bool (*checkElementFunc)(int)
) : check_element_func(checkElementFunc) {
    pHead = Alloc();
    pHead->item = INT_MAX;
    pHead->pNext = nullptr;
}

SetLab3::SetLab3(int item_count, int min_, int max_,
                 bool (*checkElementFunc)(int)
) : check_element_func(checkElementFunc) {
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());
    auto numbers_out = vw::iota(min_, max_) | vw::filter(check_element_func);

    std::vector<int> second(numbers_out.begin(), numbers_out.end());

    rng::shuffle(second, gen);
    pHead = nullptr;
    int real_count = 0;
    for (auto iter: second | vw::take(item_count)) {
        add_item(iter);
        real_count++;
    }
    if (real_count < item_count) {
        std::cout << "impossible interval (" << min_ << ", " << max_ << ") for items count is " << item_count << endl;
    }

    if (real_count == 0) {
        pHead = Alloc();
        pHead->item = INT_MAX;
        pHead->pNext = nullptr;
    }

}

SetLab3::SetLab3(function<bool(int)> function1) {
    check_element_func = std::move(function1);
    pHead = Alloc();
    pHead->item = INT_MAX;
    pHead->pNext = nullptr;
}

PNODE SetLab3::Alloc() {
    auto buff = static_cast<PNODE>(calloc(1, SIZEOF_NODE));
    if (!buff) {
        abort();
    }
    buff->pNext = nullptr;
    return buff;
}

SetLab3::~SetLab3() {
    NODE *last_node = nullptr;
    NODE *last_last_node = nullptr;

    if (is_empty_set()) {
        return;
    }
    SET_FOR_EACH(pHead, iter) {
        if (last_node) {
            if (last_last_node) {
                free(last_node);
            } else {
                last_node->pNext = nullptr;
                last_node->item = INT_MAX;
            }

        }
        last_last_node = last_node;
        last_node = iter;
    }
}

bool SetLab3::is_empty_set() const {
    return ((pHead == nullptr) or (pHead->item == INT_MAX));
}

bool SetLab3::check_item(int element) {
    SET_FOR_EACH(pHead, iter) {
        if (element == iter->item) {
            return true;
        }
    }
    return false;
}

NODE *SetLab3::add_item(int new_element) {
    if (check_element_func(new_element) && !check_item(new_element)) {
        NODE *new_first_element = Alloc();
        new_first_element->item = new_element;
        new_first_element->pNext = pHead;
        pHead = new_first_element;
        return pHead;
    }
    std::cout << "Element " << new_element << " is not correct for this set" << endl;
    return pHead;
}

int SetLab3::len() {
    if (is_empty_set()) {
        return 0;
    }
    int size = 0;
    SET_FOR_EACH(pHead, iter) {
        size++;
    }
    return size;
}

std::string SetLab3::set_as_string(const std::string &splitter) {
    if (is_empty_set()) {
        return "<empty set>";
    }
    std::string data = "(<";
    SET_FOR_EACH(pHead, iter) {
        data += std::to_string(iter->item);
        if (iter->pNext && iter->pNext->item != INT_MAX) {
            data += splitter;
        }
    }
    data += ">)";
    return data;
}

bool SetLab3::is_subset(SetLab3 *subset) {
    if (subset) {
        return false;
    }
    SET_FOR_EACH(subset->pHead, iter) {
        if (!check_item(iter->item)) {
            return false;
        }
    }

    return true;

}

bool SetLab3::is_equal(SetLab3 *other) {
    return is_subset(other) && other->is_subset(this);

}

SetLab3 *SetLab3::union_sets(SetLab3 *other) {
    auto *result = new SetLab3(
            static_cast<function<bool(int)>>(check_element_func));
    SET_FOR_EACH(this->pHead, iter) {
        result->add_item(iter->item);
    }
    SET_FOR_EACH(other->pHead, iter) {
        if (!this->check_item(iter->item)) {
            result->add_item(iter->item);
        }
    }
    return result;
}

SetLab3 *SetLab3::glue_sets(SetLab3 *other) {
    NODE *last_item = this->pHead;
    SET_FOR_EACH(this->pHead, iter) {
        last_item = iter;
    }
    if (last_item) {
        last_item->pNext = other->pHead;
        return this;
    }
    this->pHead = other->pHead;
    return this;
}

SetLab3 *SetLab3::intersection_of_sets(SetLab3 *other) {
    auto *result = new SetLab3(
            static_cast<function<bool(int)>>(check_element_func));
    SET_FOR_EACH(this->pHead, iter) {
        if (this->check_item(other->pHead->item)) {
            result->add_item(iter->item);
        }
    }
    return result;
}

SetLab3 *SetLab3::subtraction_of_sets(SetLab3 *subtracted) {
    auto *result = new SetLab3(
            static_cast<function<bool(int)>>(check_element_func));
    SET_FOR_EACH(this->pHead, iter) {
        if (!subtracted->check_item(iter->item)) {
            result->add_item(iter->item);
        }
    }
    return result;
}

SetLab3 *SetLab3::symmetric_difference_of_sets(SetLab3 *other) {
    auto *result = new SetLab3(
            static_cast<function<bool(int)>>(check_element_func));
    return this->subtraction_of_sets(
            other)->glue_sets(other->subtraction_of_sets(this));

}
