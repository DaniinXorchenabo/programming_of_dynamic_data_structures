//
// Created by Daniil on 15.02.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_1_6_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_1_6_H
#include <list>

using namespace std;

list<int> f1(); //create empty list

bool f2(list<int>& testing); // list is empty?

bool f3(int element, list<int>& testing); // принадлежит ли элемент списку

list<int> f4(list<int>& list_, int new_element, bool check_element(int));  // add a new element in list

#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_1_6_H
