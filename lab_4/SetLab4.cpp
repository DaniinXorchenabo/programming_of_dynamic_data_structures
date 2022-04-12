//
// Created by Daniil on 12.04.2022.
//
#include <random>
#include <ranges>
#include <string>
#include <utility>
#include "SetLab4.h"

namespace rng = ranges;
namespace vw = ranges::views;

bool SetLab4::check_item(int element) {
    return rng::find(container, element)  != container.end();
}


SetLab4::SetLab4(function<bool(int)> function1) {
    check_element_func = std::move(function1);
}

SetLab4::SetLab4(int item_count, int min_, int max_,
                 bool (*checkElementFunc)(int)
) : check_element_func(checkElementFunc) {
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());
    auto numbers_out = vw::iota(min_, max_) | vw::filter(check_element_func);

    std::vector<int> second(numbers_out.begin(), numbers_out.end());

    rng::shuffle(second, gen);
    for(auto item: second | vw::take(item_count)){
        container.push_back(item);
    }

    if (container.size() < item_count) {
        std::cout << "impossible interval (" << min_ << ", " << max_ << ") for items count is " << item_count << endl;
    }

}