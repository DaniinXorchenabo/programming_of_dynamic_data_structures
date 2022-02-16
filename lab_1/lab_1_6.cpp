//
// Created by Daniil on 15.02.2022.
//

#include <ranges>
#include "lab_1_6.h"

// TODO: iterators was be returned
NODE* create_empty_set(){
    NODE *first_element = Alloc(1);
    return first_element;
}

bool is_empty(NODE* testing){
    return testing == nullptr;
}

bool check_item(int element, NODE* testing_list){
    for (auto iter = testing_list; iter != nullptr; iter=iter->pNext){
        if (element == iter-> item){
            return true;
        }
    }
    return false;
}

NODE* add_item(int new_element,  NODE* list_, bool check_element_func(int)){
    if (check_element_func(new_element) && check_item(new_element, list_)){
        NODE *new_first_element = Alloc(1);
        new_first_element->item = new_element;
        new_first_element->pNext = list_;
        return new_first_element;
    }
    return list_;
}

//NODE create_set(){
//
//}

PNODE Alloc(int n)
{
    auto buff = static_cast<PNODE>(malloc(SIZEOF_NODE * n));
    if (!buff)
    {
        abort();
    }

    return buff;
}

