//
// Created by Daniil on 15.02.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_1_6_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_1_6_H
#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>

using namespace std;

struct Node{
    typedef Node iterator;
    typedef Node const_iterator;

    int item;
    Node* next = nullptr;

    auto operator<=>(const Node&) const = default;
    bool operator==(const Node&) const = default;

    Node* begin()
    {
        return this ;
    }
    Node* end()
    {
        return nullptr;
    }

    Node* operator ++() const
    {
        return next;
    }
    Node* operator ++(int i) const
    {
        return next;
    }

    int operator *()
    {
        return item;
    }
    int operator ->()
    {
        return item;
    }

//    int& operator *() { return *item; }
//    int* operator ->() { return *item; }
};


list<int> f1(); //create empty list

bool f2(list<int>& testing); // list is empty?

bool f3(int element, list<int>& testing); // принадлежит ли элемент списку

list<int> f4(list<int>& list_, int new_element, bool check_element(int));  // add a new element in list

#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_LAB_1_6_H

//
//#include <iterator>
//#include <iostream>
//#include <algorithm>
//#include <cstddef>
//
//template<class T>
//class Iterator;
//
//template<class T>
//class array
//{
//public:
//    typedef Iterator<T> iterator;
//    typedef size_t size_type;
//    typedef T* pointer;
//    typedef const T* const_pointer;
//    typedef T& reference;
//    typedef const T& const_reference;
//    typedef T value_type;
//
//
//    Iterator<T> begin()
//    {
//        return Iterator<T>(arr_);
//    }
//    Iterator<T> end()
//    {
//        return Iterator<T>(arr_ + sz_);
//    }
//    T& operator [](size_t idx)
//    {
//        return arr_[idx];
//    }
//    const T& operator [](size_t idx) const
//    {
//        return arr_[idx];
//    }
//
//private:
//
//    T* arr_;
//    size_t sz_;
//};
//
//template<class T>
//class Iterator
//{
//public:
//    typedef T value_type;
//    typedef T* pointer;
//    typedef T& reference;
//    typedef std::forward_iterator_tag iterator_category;
//    typedef ptrdiff_t difference_type;
//
//    Iterator(T* curr):current(curr)
//    {
//    }
//    Iterator& operator =(const Iterator& other)
//    {
//        if (this != &other)
//        {
//            current = other.current;
//        }
//        return *this;
//    }
//    Iterator& operator ++()
//    {
//        ++current;
//        return *this;
//    }
//    Iterator operator ++(int i)
//    {
//        Iterator tmp(current);
//        ++current;
//        return tmp;
//    }
//    T& operator *()
//    {
//        return *current;
//    }
//    T* operator ->()
//    {
//        return current;
//    }
//};

//int main()
//{
//    array<int> arr(5);
//    for (array<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
//    {
//        std::cout << *iter << std::endl;
//    }
//    for (array<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
//    {
//        *iter = 5;
//    }
//    for (array<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
//    {
//        std::cout << *iter << std::endl;
//    }
//    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, "\n"));
//}
