//
// Created by Daniil on 15.04.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_BENCHMARKS_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_BENCHMARKS_H
#include <iostream>
#include <Windows.h>

#include <list>
#include <set>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <functional>
#include <random>
#include <ranges>
#include <string>
#include <utility>

using namespace std;
namespace rng = ranges;
namespace vw = ranges::views;

vector<string> SetAsNode(int len);
vector<string> SetAsNodeClass(int len_of_set);
vector<string> SetAsList(int len_of_set);
vector<string> SetAsSet(int len_of_set);
vector<string> SetAsQueue(int len_of_set);

#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_BENCHMARKS_H
