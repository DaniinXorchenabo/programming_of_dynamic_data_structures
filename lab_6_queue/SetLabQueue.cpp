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


bool SetLabQueue::check_item(int element) {
//    queue<int> copied_queue;
//    for(
//            int item = container.front();
//            !container.empty() || reverse_copied_in_queue(container, copied_queue);
//            item = get_next_item(container, copied_queue)
//            ){

    SET_FOR_EACH(container, item){
        if (item == element){
            return true;
        }
    }
    return false;
}

int SetLabQueue::len() {
    return container.size();
}

bool SetLabQueue::is_empty_set() const {
    return container.empty();
}

SetLabQueue::SetLabQueue(function<bool(int)> function1) {
    check_element_func = std::move(function1);
}

SetLabQueue::SetLabQueue(int item_count, int min_, int max_,
                 bool (*checkElementFunc)(int)
) : check_element_func(checkElementFunc) {
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());
    auto numbers_out = vw::iota(min_, max_) | vw::filter(check_element_func);

    std::vector<int> second(numbers_out.begin(), numbers_out.end());

    rng::shuffle(second, gen);
    for(auto item: second | vw::take(item_count)){
        container.push(item);
    }

    if (container.size() < item_count) {
        std::cout << "impossible interval (" << min_ << ", " << max_ << ") for items count is " << item_count << endl;
    }

}