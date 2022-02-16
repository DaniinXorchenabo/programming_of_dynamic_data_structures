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
    NODE_ *pNext;
    int item;

    auto operator<=>(const NODE_&) const = default;
    bool operator==(const NODE_&) const = default;

} NODE, *PNODE;


PNODE Alloc(int n);


NODE* create_empty_set(); //create empty list

bool is_empty(NODE* testing); // list is empty?

bool check_item(int element, NODE* testing); // принадлежит ли элемент списку

NODE* add_item(int new_element,  NODE* list_, bool check_element_func(int));  // add a new element in list

#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_1_6_H
