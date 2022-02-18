//
// Created by Daniil on 15.02.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_1_6_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_1_6_H

#define SIZEOF_NODE \
	sizeof(NODE)

#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>


using namespace std;

//typedef struct _NODE{
//    int item{};
//    NODE* next = nullptr;
//
//    auto operator<=>(const NODE&) const = default;
//    bool operator==(const NODE&) const = default;
//
//    NODE* begin()
//    {
//        return this ;
//    }
//    static NODE* end()
//    {
//        return nullptr;
//    }
//} NODE, *PNODE;

typedef struct NODE_
{
    NODE_ *pNext = nullptr;
    int item = INT_MAX;

    auto operator<=>(const NODE_&) const = default;
    bool operator==(const NODE_&) const = default;

} NODE, *PNODE;


PNODE Alloc();


NODE* create_empty_set(); //create empty list

bool is_empty_set(NODE* testing); // list is empty?

bool check_item(int element, NODE* testing); // принадлежит ли элемент списку

NODE* add_item(int new_element,  NODE* list_, bool check_element_func(int));  // add a new element in list

NODE* create_set(int item_count, int min_, int max_, bool check_element_func(int));

int len(NODE* set_);

std::string set_as_string(NODE* set_, const std::string& splitter = ", ");

NODE* delete_set(NODE* set_);


#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_1_6_H
