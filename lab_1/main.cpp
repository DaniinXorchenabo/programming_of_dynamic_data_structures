#include <iostream>
#include <Windows.h>
#include "lab_1_6.h"
#include "defines.h"


int main() {

    NODE* A = create_set(5, 10 ,13,
                                  [](int i){return (i >= 10 && i <=60 && i % 10 > 7);});
    NODE* B = create_set(5, 10 ,40,
                         [](int i){return (i >= 10 && i <=60 && i % 10 > 5);});

    std::cout<<"a set of A is: "<< set_as_string(A)<<endl;
    std::cout<<"a set of B is: "<< set_as_string(B)<<endl;
    std::cout<<"size the set of A is: "<< len(A)<<endl;
    std::cout<<"size the set of B is: "<< len(B)<<endl;
    std::cout<<"deleting sets  A and  B ..."<<endl;
    delete_set(A);
    delete_set(B);
    std::cout<<"a set of A after deleted is: "<< set_as_string(A)<<endl;
    std::cout<<"a set of B after deleted is: "<< set_as_string(B)<<endl;

    std::cout<<endl;

    return 0;
}
