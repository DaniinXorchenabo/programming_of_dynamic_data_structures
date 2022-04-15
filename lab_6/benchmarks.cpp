//
// Created by Daniil on 15.04.2022.
//
#include <chrono>
#include "benchmarks.h"


#include "../base_class/BaseClass.h"
#include "../lab_2/lab_2_6.h"
#include "../lab_3/set_lab_3.h"
#include "../lab_4/SetLab4.h"
#include "../lab_5/SetLab5.h"
#include "../course_work_queue/SetLabQueue.h"


using std::string;
using std::string_view;
using std::chrono::milliseconds;
using std::chrono::nanoseconds;
using namespace std::chrono_literals;

vector<string> SetAsNode(int len_of_set){
//    list<string> ff = {};
//    return ff;

    list<std::chrono::nanoseconds> list_of_time = {};

    auto begin = std::chrono::steady_clock::now();
    NODE2 *A = create_set(len_of_set, 0, len_of_set + 10,
                         [](int i) { return true; });
    auto end = std::chrono::steady_clock::now();
    auto create_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(create_ms);

    begin = std::chrono::steady_clock::now();
    len(A);
    end = std::chrono::steady_clock::now();
    auto len_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(len_ms);

    NODE2 *B = create_set(len_of_set, 0, len_of_set + 10,
                         [](int i) { return true; });

    begin = std::chrono::steady_clock::now();
    is_subset(A, A);
    end = std::chrono::steady_clock::now();
    auto subset_AA_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subset_AA_ms);

    begin = std::chrono::steady_clock::now();
    is_subset(B, A);
    end = std::chrono::steady_clock::now();
    auto subset_AB_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subset_AB_ms);

    begin = std::chrono::steady_clock::now();
    is_equal(A, A);
    end = std::chrono::steady_clock::now();
    auto equal_AA_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(equal_AA_ms);

    begin = std::chrono::steady_clock::now();
    is_equal(A, B);
    end = std::chrono::steady_clock::now();
    auto equal_AB_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(equal_AB_ms);

    begin = std::chrono::steady_clock::now();
    union_sets(A, B);
    end = std::chrono::steady_clock::now();
    auto union_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(union_ms);

    begin = std::chrono::steady_clock::now();
    intersection_of_sets(A, B);
    end = std::chrono::steady_clock::now();
    auto intersection_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(intersection_ms);

    begin = std::chrono::steady_clock::now();
    subtraction_of_sets(A, B);
    end = std::chrono::steady_clock::now();
    auto subtraction_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subtraction_ms);

    begin = std::chrono::steady_clock::now();
    symmetric_difference_of_sets(A, B);
    end = std::chrono::steady_clock::now();
    auto symmetric_difference_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(symmetric_difference_ms);

//    auto f = (new std::chrono::milliseconds[] {create_ms, len_ms, subset_AA_ms, subset_AB_ms, equal_AA_ms, equal_AB_ms,
//            union_ms, intersection_ms, subtraction_ms, symmetric_difference_ms})
//            | vw::transform([](int i){return std::to_string(i) ;});

    auto f =  list_of_time | vw::transform([](std::chrono::nanoseconds i){
        return to_string(std::chrono::nanoseconds(i).count());
    }) ;

//        list<string> ff = {};
//    return ff;

    vector<string> d(f.begin(), f.end());
//    for(auto f: d){
//        cout << f << "\n";
//    }

    return d;
}

vector<string> SetAsNodeClass(int len_of_set){
//    list<string> ff = {};
//    return ff;
    int counter = 0;

    list<std::chrono::nanoseconds> list_of_time = {};

    auto begin = std::chrono::steady_clock::now();
    auto *A = new SetLab3(len_of_set, 0, len_of_set + 10,
               [](int i) { return true; });

    auto end = std::chrono::steady_clock::now();
    auto create_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(create_ms);


    begin = std::chrono::steady_clock::now();
    A->len();
    end = std::chrono::steady_clock::now();
    auto len_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(len_ms);

    auto *B = new SetLab3(len_of_set, 0, len_of_set + 10,
                          [](int i) { return true; });
    begin = std::chrono::steady_clock::now();
    A->is_subset(A);
    end = std::chrono::steady_clock::now();
    auto subset_AA_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subset_AA_ms);

    begin = std::chrono::steady_clock::now();
    A->is_subset(B);
    end = std::chrono::steady_clock::now();
    auto subset_AB_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subset_AB_ms);

    begin = std::chrono::steady_clock::now();
    A->is_equal(A);
    end = std::chrono::steady_clock::now();
    auto equal_AA_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(equal_AA_ms);

    begin = std::chrono::steady_clock::now();
    A->is_equal(B);
    end = std::chrono::steady_clock::now();
    auto equal_AB_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(equal_AB_ms);

    begin = std::chrono::steady_clock::now();
    A->union_sets(B);
    end = std::chrono::steady_clock::now();
    auto union_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(union_ms);

    begin = std::chrono::steady_clock::now();
    A->intersection_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto intersection_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(intersection_ms);

    begin = std::chrono::steady_clock::now();
    A->subtraction_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto subtraction_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subtraction_ms);

    begin = std::chrono::steady_clock::now();
    A->symmetric_difference_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto symmetric_difference_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(symmetric_difference_ms);

//    auto f = (new std::chrono::milliseconds[] {create_ms, len_ms, subset_AA_ms, subset_AB_ms, equal_AA_ms, equal_AB_ms,
//            union_ms, intersection_ms, subtraction_ms, symmetric_difference_ms})
//            | vw::transform([](int i){return std::to_string(i) ;});
    auto f =  list_of_time | vw::transform([](std::chrono::nanoseconds i){
        return to_string(std::chrono::nanoseconds(i).count()) ;
    }) ;

//        list<string> ff = {};
//    return ff;

    vector<string> d(f.begin(), f.end());
    return d;
}

vector<string> SetAsList(int len_of_set){
//    list<string> ff = {};
//    return ff;
    int counter = 0;

    list<std::chrono::nanoseconds> list_of_time = {};

    auto begin = std::chrono::steady_clock::now();
    auto *A = new SetLab4(len_of_set, 0, len_of_set + 10,
                          [](int i) { return true; });

    auto end = std::chrono::steady_clock::now();
    auto create_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(create_ms);


    begin = std::chrono::steady_clock::now();
    A->len();
    end = std::chrono::steady_clock::now();
    auto len_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(len_ms);

    auto *B = new SetLab4(len_of_set, 0, len_of_set + 10,
                          [](int i) { return true; });
    begin = std::chrono::steady_clock::now();
    A->is_subset(A);
    end = std::chrono::steady_clock::now();
    auto subset_AA_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subset_AA_ms);

    begin = std::chrono::steady_clock::now();
    A->is_subset(B);
    end = std::chrono::steady_clock::now();
    auto subset_AB_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subset_AB_ms);

    begin = std::chrono::steady_clock::now();
    A->is_equal(A);
    end = std::chrono::steady_clock::now();
    auto equal_AA_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(equal_AA_ms);

    begin = std::chrono::steady_clock::now();
    A->is_equal(B);
    end = std::chrono::steady_clock::now();
    auto equal_AB_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(equal_AB_ms);

    begin = std::chrono::steady_clock::now();
    A->union_sets(B);
    end = std::chrono::steady_clock::now();
    auto union_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(union_ms);

    begin = std::chrono::steady_clock::now();
    A->intersection_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto intersection_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(intersection_ms);

    begin = std::chrono::steady_clock::now();
    A->subtraction_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto subtraction_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subtraction_ms);

    begin = std::chrono::steady_clock::now();
    A->symmetric_difference_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto symmetric_difference_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(symmetric_difference_ms);

//    auto f = (new std::chrono::milliseconds[] {create_ms, len_ms, subset_AA_ms, subset_AB_ms, equal_AA_ms, equal_AB_ms,
//            union_ms, intersection_ms, subtraction_ms, symmetric_difference_ms})
//            | vw::transform([](int i){return std::to_string(i) ;});
    auto f =  list_of_time | vw::transform([](std::chrono::nanoseconds i){
        return to_string(std::chrono::nanoseconds(i).count()) ;
    }) ;

//        list<string> ff = {};
//    return ff;

    vector<string> d(f.begin(), f.end());
    return d;
}

vector<string> SetAsSet(int len_of_set){
//    list<string> ff = {};
//    return ff;
    int counter = 0;

    list<std::chrono::nanoseconds> list_of_time = {};

    auto begin = std::chrono::steady_clock::now();
    auto *A = new SetLab5(len_of_set, 0, len_of_set + 10,
                          [](int i) { return true; });

    auto end = std::chrono::steady_clock::now();
    auto create_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(create_ms);


    begin = std::chrono::steady_clock::now();
    A->len();
    end = std::chrono::steady_clock::now();
    auto len_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(len_ms);

    auto *B = new SetLab5(len_of_set, 0, len_of_set + 10,
                          [](int i) { return true; });
    begin = std::chrono::steady_clock::now();
    A->is_subset(A);
    end = std::chrono::steady_clock::now();
    auto subset_AA_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subset_AA_ms);

    begin = std::chrono::steady_clock::now();
    A->is_subset(B);
    end = std::chrono::steady_clock::now();
    auto subset_AB_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subset_AB_ms);

    begin = std::chrono::steady_clock::now();
    A->is_equal(A);
    end = std::chrono::steady_clock::now();
    auto equal_AA_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(equal_AA_ms);

    begin = std::chrono::steady_clock::now();
    A->is_equal(B);
    end = std::chrono::steady_clock::now();
    auto equal_AB_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(equal_AB_ms);

    begin = std::chrono::steady_clock::now();
    A->union_sets(B);
    end = std::chrono::steady_clock::now();
    auto union_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(union_ms);

    begin = std::chrono::steady_clock::now();
    A->intersection_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto intersection_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(intersection_ms);

    begin = std::chrono::steady_clock::now();
    A->subtraction_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto subtraction_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subtraction_ms);

    begin = std::chrono::steady_clock::now();
    A->symmetric_difference_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto symmetric_difference_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(symmetric_difference_ms);

//    auto f = (new std::chrono::milliseconds[] {create_ms, len_ms, subset_AA_ms, subset_AB_ms, equal_AA_ms, equal_AB_ms,
//            union_ms, intersection_ms, subtraction_ms, symmetric_difference_ms})
//            | vw::transform([](int i){return std::to_string(i) ;});
    auto f =  list_of_time | vw::transform([](std::chrono::nanoseconds i){
        return to_string(std::chrono::nanoseconds(i).count()) ;
    }) ;

//        list<string> ff = {};
//    return ff;

    vector<string> d(f.begin(), f.end());
    return d;
}

vector<string> SetAsQueue(int len_of_set){
//    list<string> ff = {};
//    return ff;
    int counter = 0;

    list<std::chrono::nanoseconds> list_of_time = {};

    auto begin = std::chrono::steady_clock::now();
    auto *A = new SetLabQueue(len_of_set, 0, len_of_set + 10,
                          [](int i) { return true; });

    auto end = std::chrono::steady_clock::now();
    auto create_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(create_ms);


    begin = std::chrono::steady_clock::now();
    A->len();
    end = std::chrono::steady_clock::now();
    auto len_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(len_ms);

    auto *B = new SetLabQueue(len_of_set, 0, len_of_set + 10,
                          [](int i) { return true; });
    begin = std::chrono::steady_clock::now();
    A->is_subset(A);
    end = std::chrono::steady_clock::now();
    auto subset_AA_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subset_AA_ms);

    begin = std::chrono::steady_clock::now();
    A->is_subset(B);
    end = std::chrono::steady_clock::now();
    auto subset_AB_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subset_AB_ms);

    begin = std::chrono::steady_clock::now();
    A->is_equal(A);
    end = std::chrono::steady_clock::now();
    auto equal_AA_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(equal_AA_ms);

    begin = std::chrono::steady_clock::now();
    A->is_equal(B);
    end = std::chrono::steady_clock::now();
    auto equal_AB_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(equal_AB_ms);

    begin = std::chrono::steady_clock::now();
    A->union_sets(B);
    end = std::chrono::steady_clock::now();
    auto union_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(union_ms);

    begin = std::chrono::steady_clock::now();
    A->intersection_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto intersection_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(intersection_ms);

    begin = std::chrono::steady_clock::now();
    A->subtraction_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto subtraction_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(subtraction_ms);

    begin = std::chrono::steady_clock::now();
    A->symmetric_difference_of_sets(B);
    end = std::chrono::steady_clock::now();
    auto symmetric_difference_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    list_of_time.push_back(symmetric_difference_ms);

//    auto f = (new std::chrono::milliseconds[] {create_ms, len_ms, subset_AA_ms, subset_AB_ms, equal_AA_ms, equal_AB_ms,
//            union_ms, intersection_ms, subtraction_ms, symmetric_difference_ms})
//            | vw::transform([](int i){return std::to_string(i) ;});
    auto f =  list_of_time | vw::transform([](std::chrono::nanoseconds i){
        return to_string(std::chrono::nanoseconds(i).count()) ;
    }) ;

//        list<string> ff = {};
//    return ff;

    vector<string> d(f.begin(), f.end());
    return d;
}
