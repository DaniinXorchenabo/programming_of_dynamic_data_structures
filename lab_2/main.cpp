#include <iostream>
#include <Windows.h>
#include "lab_2_6.h"
#include "defines.h"


int main() {

    NODE *A = create_set(5, 10, 13,
                         [](int i) { return (i >= 10 && i <= 60 && i % 10 > 7); });
    NODE *B = create_set(5, 10, 40,
                         [](int i) { return (i >= 10 && i <= 60 && i % 10 > 5); });
    std::cout << "==========!! First laboratory work !!==========" << endl;
    std::cout << "-----------------------------------------------" << endl;
    std::cout << "a set of A is: " << set_as_string(A) << endl;
    std::cout << "a set of B is: " << set_as_string(B) << endl;
    std::cout << "size the set of A is: " << len(A) << endl;
    std::cout << "size the set of B is: " << len(B) << endl;
    std::cout << "deleting sets  A and  B ..." << endl;
    A = delete_set(A);
    B = delete_set(B);
    std::cout << "a set of A after deleted is: " << set_as_string(A) << endl;
    std::cout << "a set of B after deleted is: " << set_as_string(B) << endl;
    std::cout << "\n==========!! Second laboratory work !!==========" << endl;
    std::cout << "--------------------------------------------------" << endl;

    NODE *C = create_set(4, 10, 40,
                         [](int i) { return (i >= 10 && i <= 60 && i % 10 > 7); });
    NODE *D = create_set(4, 10, 40,
                         [](int i) { return (i >= 10 && i <= 60 && i % 10 > 5); });
    NODE *testing_subset = create_empty_set();
    int counter = 0;
    SET_FOR_EACH(C, iter) {
        testing_subset = add_item(iter->item, testing_subset);
        counter++;
//        std::cout << iter->item << " | " << counter << endl;
        if (counter > 2) { break; }
    }

    std::cout << "set " << set_as_string(testing_subset) <<
              " is subset for " << set_as_string(C) <<
              " is " << (is_subset(testing_subset, C) ? "True" : "False") << endl;
    std::cout << "But, set " << set_as_string(D) <<
              " is subset for " << set_as_string(C) <<
              " is " << (is_subset(D, C) ? "True" : "False") << endl;

    NODE *C_clone = create_empty_set();
    SET_FOR_EACH(C, iter) {
        C_clone = add_item(iter->item, C_clone);
    }
    std::cout << "set " << set_as_string(C)
              << (is_equal(C, C_clone) ? " == " : " != ")
              << set_as_string(C_clone)
              << endl;
    std::cout << "set " << set_as_string(C)
              << (is_equal(C, D) ? " == " : " != ")
              << set_as_string(D) << endl;

    std::cout << "Union a set " << set_as_string(C)
              << " and a set " << set_as_string(D)
              << ". Result: " << set_as_string(union_sets(C, D)) << endl;
    std::cout << "Union a set " << set_as_string(C)
              << " and a set " << set_as_string(C_clone)
              << ". Result: " << set_as_string(union_sets(C, C_clone)) << endl;

    std::cout << "intersection of " << set_as_string(C) <<
              " && " << set_as_string(D) <<
              " is " << set_as_string(intersection_of_sets(C, D)) << endl;
    std::cout << "intersection of " << set_as_string(C) <<
              " && " << set_as_string(C_clone) <<
              " is " << set_as_string(intersection_of_sets(C, C_clone)) << endl;

    std::cout << set_as_string(C) <<
              " - " << set_as_string(D) <<
              " is " << set_as_string(subtraction_of_sets(C, D)) << endl;
    std::cout << set_as_string(D) <<
              " - " << set_as_string(C) <<
              " is " << set_as_string(subtraction_of_sets(D, C)) << endl;
    std::cout << set_as_string(C) <<
              " - " << set_as_string(testing_subset) <<
              " is " << set_as_string(subtraction_of_sets(C, testing_subset)) << endl;

    std::cout << "XOR (or symmetric difference of sets): " << set_as_string(C) <<
              " XOR " << set_as_string(D) <<
              " is " << set_as_string(symmetric_difference_of_sets(C, D)) << endl;

    std::cout << endl;

    return 0;
}
