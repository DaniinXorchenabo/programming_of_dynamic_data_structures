//
// Created by Daniil on 15.04.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_STRING_UTILS_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_STRING_UTILS_H
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <clocale>
#include <iostream>
#include <io.h>
#include <fcntl.h>
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
#include "benchmarks.h"


using namespace std;
namespace rng = ranges;
namespace vw = ranges::views;

string r_filling(string str, int len, const std::string &splitter = (" "));
string l_filling(string str, int len, const std::string &splitter = (" "));
string center(string str, int len, const std::string &splitter = (" "));

#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_STRING_UTILS_H
