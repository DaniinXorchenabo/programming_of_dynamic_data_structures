//
// Created by Daniil on 02.03.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SET_LAB_3_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SET_LAB_3_H

#define SIZEOF_NODE \
    sizeof(NODE)

#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <functional>


using namespace std;


typedef struct NODE_ {
    NODE_ *pNext = nullptr;
    int item = INT_MAX;

    auto operator<=>(const NODE_ &) const = default;

    bool operator==(const NODE_ &) const = default;

} NODE, *PNODE;

class SetLab3 {
public:

    NODE* pHead = nullptr;

    static PNODE Alloc();
    SetLab3(bool (*checkElementFunc)(int) =  [](int i) { return true; });


    ~SetLab3();

    [[nodiscard]] bool is_empty_set() const;
    bool check_item(int element);
    NODE *add_item(int new_element);

private:
    function<bool(int)> check_element_func = [](int i) { return true; };

};

#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_SET_LAB_3_H
