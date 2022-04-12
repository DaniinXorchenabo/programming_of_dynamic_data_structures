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
    return  container.find(element)  != container.end();
}

int SetLab5::len() {
    return container.size();
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
    for(auto item: second | vw::take(item_count)){
        container.insert(item);
    }

    if (container.size() < item_count) {
        std::cout << "impossible interval (" << min_ << ", " << max_ << ") for items count is " << item_count << endl;
    }

}