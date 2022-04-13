#include <iostream>
#include <Windows.h>
#include "SetLab4.h"


int main() {
    auto *A = new SetLab4(6, 10, 60,
                          [](int i) { return (i >= 10 && i <= 60 && i % 10 > 7); });
    auto *B = new SetLab4(6, 10, 60,
                          [](int i) { return (i >= 10 && i <= 60 && i % 10 > 5); });
    std::cout << "==========!! Third laboratory work !!==========" << endl;
    std::cout << "-----------------------------------------------" << endl;
    std::cout << "a set of A is: " << A->set_as_string() << endl;
    std::cout << "a set of B is: " << B->set_as_string() << endl;
    std::cout << "size the set of A is: " << A->len() << endl;
    std::cout << "size the set of B is: " << B->len() << endl;
    std::cout << "deleting sets  A and  B ..." << endl;

    auto *C = new SetLab4(4, 10, 60,
                          [](int i) { return (i >= 10 && i <= 60 && i % 10 > 7); });
    auto *D = new SetLab4(4, 10, 60,
                          [](int i) { return (i >= 10 && i <= 60 && i % 10 > 5); });
    auto *testing_subset = new SetLab4();

    int counter = 0;
    for(auto item: C->container){
        testing_subset->add_item(item);
        counter++;
        if (counter > 2) { break; }
    }

    std::cout << "set " << testing_subset->set_as_string() <<
              " is subset for " << C->set_as_string() <<
              " is " << (C->is_subset(testing_subset) ? "True" : "False") << endl;
    std::cout << "But, set " << D->set_as_string() <<
              " is subset for " << C->set_as_string() <<
              " is " << (D->is_subset(C) ? "True" : "False") << endl;

    auto *C_clone = new SetLab4();
    for(auto item: C->container) {
        C_clone->add_item(item);
    }
    std::cout << "set " << C->set_as_string()
              << (C->is_equal(C_clone) ? " == " : " != ")
              << C_clone->set_as_string()
              << endl;
    std::cout << "set " << C->set_as_string()
              << (C->is_equal(D) ? " == " : " != ")
              << D->set_as_string() << endl;

    std::cout << "Union a set " <<C->set_as_string()
              << " and a set " << D->set_as_string()
              << ". Result: " << C->union_sets(D)->set_as_string() << endl;
    std::cout << "Union a set " << C->set_as_string()
              << " and a set " << C_clone->set_as_string()
              << ". Result: " << C->union_sets(C_clone)->set_as_string() << endl;

    std::cout << "intersection of " << C->set_as_string() <<
              " && " << D->set_as_string() <<
              " is " << C->intersection_of_sets(D)->set_as_string() << endl;
    std::cout << "intersection of " << C->set_as_string() <<
              " && " << C_clone->set_as_string() <<
              " is " << C->intersection_of_sets(C_clone)->set_as_string() << endl;

    std::cout << C->set_as_string() <<
              " - " << D->set_as_string() <<
              " is " << C->subtraction_of_sets(D)->set_as_string() << endl;
    std::cout << D->set_as_string() <<
              " - " << C->set_as_string() <<
              " is " << D->subtraction_of_sets(C)->set_as_string() << endl;
    std::cout << C->set_as_string() <<
              " - " << testing_subset->set_as_string() <<
              " is " << C->subtraction_of_sets(testing_subset)->set_as_string() << endl;

    std::cout << "XOR (or symmetric difference of sets): " << C->set_as_string() <<
              " XOR " << D->set_as_string() <<
              " is " << C->symmetric_difference_of_sets(D)->set_as_string() << endl;

    std::cout << endl;

    return 0;
}
