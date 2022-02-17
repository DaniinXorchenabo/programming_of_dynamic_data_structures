//
// Created by Daniil on 15.02.2022.
//
#include <random>
#include <ranges>
#include <string>
//  #include <Windows.h>
#include "lab_1_6.h"
#include "defines.h"

namespace rng = std::ranges;
namespace vw = std::ranges::views;


NODE* create_empty_set(){
    NODE *first_element = Alloc();
    first_element->item = INT_MAX;
    first_element->pNext  = nullptr;
//    cout<<"create_empty_set is nullptr "<< first_element<<" "<<(first_element == nullptr)<<endl;

    return first_element;
}

bool is_empty_set(NODE* testing){
//    cout<<"is_empty_set "<<testing<<" "<<(testing == nullptr)<<endl;
    return ((testing == nullptr) or (testing->item == INT_MAX));
}

bool check_item(int element, NODE* testing_list){
//    cout<<"check_item "<<element<<endl;
//    cout<<"check_item "<<element<<endl;
    SET_FOR_EACH(testing_list, iter){
//        cout<<"check_item /1/ "<< (iter != nullptr) << " "<<iter->item<<endl;
        if (element == iter-> item){
            return true;
        }
    }
//    cout<<"check_item returned false "<<element<<endl;
    return false;
}

NODE* add_item(int new_element,  NODE* list_, bool check_element_func(int)){
//    cout<<"add_item "<<new_element<<endl;
    if (check_element_func(new_element) && !check_item(new_element, list_)){
//        cout<<"add_item /2/ "<<new_element<<endl;
        NODE *new_first_element = Alloc();
        new_first_element->item = new_element;
        new_first_element->pNext = list_;
//        cout<<"add_item /3/ "<<new_element<<endl;
        return new_first_element;
    }
    return list_;
}

NODE* create_set(int item_count, int min_, int max_, bool check_element_func(int)){
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());
    auto numbers_out = vw::iota(min_, max_) |
                vw::filter(check_element_func);

    std::vector<int> second(numbers_out.begin(), numbers_out.end());

    std::cout<<endl;
    rng::shuffle(second, gen);
    NODE* first_node = nullptr;
    for (auto iter: second | vw::take(item_count))
    {
        first_node = add_item(iter, first_node, check_element_func);
    }
    std::cout<<"set was created"<<endl;
    return first_node;

}

int len(NODE* set_){
    if (is_empty_set(set_)){
        return 0;
    }
    int size = 0;
    SET_FOR_EACH(set_, iter){
        size++;
    }
    return size;
}

std::string as_string(NODE* set_, const std::string& splitter = ", "){
    if (is_empty_set(set_)){
        return "";
    }
    std::string data = "";
    SET_FOR_EACH(set_, iter){
        data += std::to_string(iter->item);
        if (iter-> pNext){
            data += splitter;
        }
    }
    return data;
}

NODE* delete_set(NODE* set_){

}


PNODE Alloc()
{
    auto buff = static_cast<PNODE>(calloc(1, SIZEOF_NODE));
    if (!buff)
    {
        abort();
    }
    buff->pNext = nullptr;


    return buff;
}
