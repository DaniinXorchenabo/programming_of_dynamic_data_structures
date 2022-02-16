//
// Created by Daniil on 15.02.2022.
//

#include <ranges>
#include "lab_1_6.h"

// TODO: iterators was be returned
list<int> f1(){
    return list<int>{};
}

bool f2(list<int>& testing){
    return testing.empty();
}

bool f3(int element, list<int>& testing_list){
    return ranges::find(testing_list, element) != testing_list.end();
}

list<int> f4(list<int>& list_, int new_element, bool check_element(int)){
    if (check_element(new_element) && f3(new_element, list_)){
        std::list<int> new_list = {new_element};
        auto iter3 = new_list.cend();
        new_list.insert(iter3, list_.begin(), list_.end());
        return new_list;
    }
    return list_;
}

//Node::iterator Node::begin() {
//    return iterator(this)
//}

