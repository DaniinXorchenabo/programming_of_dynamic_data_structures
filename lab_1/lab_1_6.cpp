//
// Created by Daniil on 15.02.2022.
//
#include <random>
#include <ranges>
//  #include <Windows.h>
#include "lab_1_6.h"



namespace rng = std::ranges;
namespace vw = std::ranges::views;

#define SET_FOR_EACH(pHead, iter)           \
    for (                                   \
        PNODE (iter) = (pHead);             \
        (iter) && (iter)->item == INT_MAX;  \
        (iter) = (iter)->pNext)

NODE* create_empty_set(){
    NODE *first_element = Alloc();
    first_element->item = INT_MAX;
    first_element->pNext  = nullptr;
    cout<<"create_empty_set is nullptr "<< first_element<<" "<<(first_element == nullptr)<<endl;

    return first_element;
}

bool is_empty_set(NODE* testing){
    cout<<"is_empty_set "<<testing<<" "<<(testing == nullptr)<<endl;
    return testing == nullptr;
}

bool check_item(int element, NODE* testing_list){
    cout<<"check_item "<<element<<endl;
//    if (is_empty_set(testing_list)){
//        cout<<"check_item returned false "<<element<<endl;
//        return false;
//    }
    cout<<"check_item "<<element<<endl;
    SET_FOR_EACH(testing_list, iter){
        cout<<"check_item /1/ "<< (iter != nullptr) << " "<<iter->item<<endl;
        if (element == iter-> item){
            return true;
        }
    }
    cout<<"check_item returned false "<<element<<endl;
    return false;
}

NODE* add_item(int new_element,  NODE* list_, bool check_element_func(int)){
    cout<<"add_item "<<new_element<<endl;
    if (check_element_func(new_element) && !check_item(new_element, list_)){
        cout<<"add_item /2/ "<<new_element<<endl;
        NODE *new_first_element = Alloc();
        new_first_element->item = new_element;
        new_first_element->pNext = list_;
        cout<<"add_item /3/ "<<new_element<<endl;
        return new_first_element;
    }
    return list_;
}

NODE* create_set(int item_count, int min_, int max_, bool check_element_func(int)){
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());
    auto numbers_out = vw::iota(min_, max_) |
                vw::filter(check_element_func);
//    auto f = numbers_out.begin();
    std::vector<int> second(numbers_out.begin(), next(numbers_out.begin()));
//    shuffle(second.begin(), second.end(), gen());
    rng::shuffle(second, gen);
    NODE* first_node = create_empty_set();
    for (auto iter: second)
    {

        std::cout<<iter<<endl;
        first_node = add_item(iter, first_node, check_element_func);
        std::cout<<iter<<endl;
    }
    std::cout<<"set was created"<<endl;
    return first_node;

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
