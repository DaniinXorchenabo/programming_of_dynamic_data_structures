//
// Created by Daniil on 15.02.2022.
//

#include <random>
#include <ranges>
#include <string>
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

//SetLab3::SetLab3(const function<bool(int)> &checkElementFunc) : check_element_func(checkElementFunc) {}

//
//NODE *create_empty_set() {
//    NODE *first_element = Alloc();
//    first_element->item = INT_MAX;
//    first_element->pNext = nullptr;
//    return first_element;
//}
//
//bool is_empty_set(NODE *testing) {
//    return ((testing == nullptr) or (testing->item == INT_MAX));
//}
//
//bool check_item(int element, NODE *testing_list) {
//    SET_FOR_EACH(testing_list, iter) {
//        if (element == iter->item) {
//            return true;
//        }
//    }
//    return false;
//}
//
//NODE *add_item(int new_element, NODE *list_, bool check_element_func(int)) {
//    if (check_element_func(new_element) && !check_item(new_element, list_)) {
//        NODE *new_first_element = Alloc();
//        new_first_element->item = new_element;
//        new_first_element->pNext = list_;
//        return new_first_element;
//    }
//    return list_;
//}
//
//NODE *create_set(int item_count, int min_, int max_, bool check_element_func(int)) {
//    random_device rd;   // non-deterministic generator
//    mt19937 gen(rd());
//    auto numbers_out = vw::iota(min_, max_) | vw::filter(check_element_func);
//
//    std::vector<int> second(numbers_out.begin(), numbers_out.end());
//
//    rng::shuffle(second, gen);
//    NODE *first_node = nullptr;
//    int real_count = 0;
//    for (auto iter: second | vw::take(item_count)) {
//        first_node = add_item(iter, first_node, check_element_func);
//        real_count++;
//    }
//    if (real_count < item_count) {
//        std::cout << "impossible interval (" << min_ << ", " << max_ << ") for items count is " << item_count << endl;
//    }
//
//    if (real_count == 0) {
//        return create_empty_set();
//    }
//
//    return first_node;
//
//}
//
//int len(NODE *set_) {
//    if (is_empty_set(set_)) {
//        return 0;
//    }
//    int size = 0;
//    SET_FOR_EACH(set_, iter) {
//        size++;
//    }
//    return size;
//}
//
//std::string set_as_string(NODE *set_, const std::string &splitter) {
//    if (is_empty_set(set_)) {
//        return "<empty set>";
//    }
//    std::string data = "(<";
//    SET_FOR_EACH(set_, iter) {
//        data += std::to_string(iter->item);
//        if (iter->pNext && iter->pNext->item != INT_MAX) {
//            data += splitter;
//        }
//    }
//    data += ">)";
//    return data;
//}
//
//NODE *delete_set(NODE *set_) {
//    NODE *last_node = nullptr;
//    NODE *last_last_node = nullptr;
//
//    if (is_empty_set(set_)) {
//        return set_;
//    }
//    SET_FOR_EACH(set_, iter) {
//        if (last_node) {
//            if (last_last_node) {
//                free(last_node);
//            } else {
//                last_node->pNext = nullptr;
//                last_node->item = INT_MAX;
//            }
//
//        }
//        last_last_node = last_node;
//        last_node = iter;
//    }
//    return set_;
//}
//
//bool is_subset(NODE *subset, NODE *base_set) {
//
//    SET_FOR_EACH(subset, iter) {
//        if (!check_item(iter->item, base_set)) {
//            return false;
//        }
//    }
//    return true;
//
//}
//
//bool is_equal(NODE *one, NODE *two) {
//    return is_subset(one, two) && is_subset(two, one);
//}
//
//NODE *union_sets(NODE *big, NODE *small_) {
//    NODE *result = create_empty_set();
//    SET_FOR_EACH(small_, iter) {
//        result = add_item(iter->item, result);
//    }
//    SET_FOR_EACH(big, iter) {
//        if (!check_item(iter->item, small_)) {
//            result = add_item(iter->item, result);
//        }
//    }
//    return result;
//}
//
//
//NODE *glue_sets(NODE *big, NODE *small) {
//    NODE *last_item = nullptr;
//    SET_FOR_EACH(small, iter) {
//        last_item = iter;
//    }
//    if (last_item) {
//        last_item->pNext = big;
//        return small;
//    }
//    return big;
//}
//
//NODE *intersection_of_sets(NODE *big, NODE *small_) {
//    NODE *intersected_set = create_empty_set();
//    SET_FOR_EACH(small_, iter) {
//        if (check_item(iter->item, big)) {
//            intersected_set = add_item(iter->item, intersected_set);
//        }
//    }
//    return intersected_set;
//}
//
//NODE *subtraction_of_sets(NODE *reduced, NODE *subtracted) {
//    NODE *result = create_empty_set();
//    SET_FOR_EACH(reduced, iter) {
//        if (!check_item(iter->item, subtracted)) {
//            result = add_item(iter->item, result);
//        }
//    }
//    return result;
//}
//
//NODE *symmetric_difference_of_sets(NODE *one, NODE *two) {
//    return glue_sets(subtraction_of_sets(one, two), subtraction_of_sets(two, one));
//}
//
//
//PNODE Alloc() {
//    auto buff = static_cast<PNODE>(calloc(1, SIZEOF_NODE));
//    if (!buff) {
//        abort();
//    }
//    buff->pNext = nullptr;
//    return buff;
//}
