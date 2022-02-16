#include <iostream>
#include "lab_1_6.h"

int main() {
    std::cout << "Hello, World! from lab_1" << std::endl;
    Node s3 = {3};
    Node s2 = {2 , &s3};
    Node s1 = {1, &s2};




    for (auto iter = s1.begin(); iter != nullptr; ++iter)
    {
        std::cout << iter->item << std::endl;
    }
//    for (array<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
//    {
//        *iter = 5;
//    }
//    for (array<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
//    {
//        std::cout << *iter << std::endl;
//    }
//    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}
