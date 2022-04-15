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
#include "../base_class/BaseClass.h"
#include "../lab_3/set_lab_3.h"
#include "../lab_4/SetLab4.h"
#include "../lab_5/SetLab5.h"
#include "../course_work_queue/SetLabQueue.h"
#include "benchmarks.h"
#include "string_utils.h"


using namespace std;
namespace rng = ranges;
namespace vw = ranges::views;




int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Привет" << endl;

//    _setmode(_fileno(stdout), _O_U16TEXT);
//    _setmode(_fileno(stdin),  _O_U16TEXT);
//    _setmode(_fileno(stderr), _O_U16TEXT);
//
//    std::wcout << L"Unicode -- English -- Русский -- Ελληνικά -- Español." << std::endl;
    // или
//    wprintf(L"%s", L"Unicode -- English -- Русский -- Ελληνικά -- Español.\n");


//    setlocale(LC_ALL, "Russian");
//    auto d = SetLab3;
//    auto classes = {SetLab3,SetLab4, SetLab5 };

    vector<vector<string>> printed_array = {
            {"", "Односвязный список", "Класс 'Список'", "List", "Set", "Queue"},
            {"Создание множества"},
            {"Мощность множества"},
            {"Подмножество А|А"},
            {"Подмножество В|А"},
            {"Равенство А=А"},
            {"Равенство В=А"},
            {"Объединение множеств А и В"},
            {"Пересечение множеств А и В"},
            {"Разность А-В"},
            {"Симметричная разность А и В"},
    };

    int lennn = 100;
    auto data_ = new vector<vector<std::string>>{
            SetAsNode(lennn),
            SetAsNodeClass(lennn),
            SetAsList(lennn),
            SetAsSet(lennn),
            SetAsQueue(lennn)
    };
//    list<string> s1 = SetAsNode(lennn);
//    data_->push_back(s1);
//    data_->push_back(SetAsNodeClass(lennn));
//    data_->push_back(SetAsList(lennn));
//    data_->push_back(SetAsSet(lennn));
//    data_->push_back(SetAsQueue(lennn));

//    data_[0][0];
    int cell_ind = 0;
    for (auto cell: *data_) {
        int item_ind = 0;
        for (auto time_: cell) {
            string item;
            for (auto ch: time_) {
                item += ch;
                cout << ch;
            }
            printed_array[item_ind + 1].push_back(item);
            cout << "\t";
            item_ind++;
        }
        cout << "\n||||>>>>" << endl;
        cell_ind++;
    }


    auto gel_max_len =
            [printed_array](auto index_, int j){
                return  static_cast<int>(printed_array[index_][j].size());
            };
    vector<int> lens = {};
    for(int j = 0; j < printed_array[0].size(); j++){
        int max_len = 0;
        for(int index = 0; index < printed_array.size(); index++){
            cout << printed_array[index][j].size()<< "|"
            << (max_len < printed_array[index][j].size()) << "\t";
            if (max_len < printed_array[index][j].size()){
                max_len = static_cast<int>(printed_array[index][j].size());
            }
        }
        cout << endl;
        lens.push_back(max_len);
    }
    for(auto i: lens){
        cout << i << "\t|";
    }
    cout << endl;

    for(int index = 0; index < printed_array.size(); index++){
        for(int j = 0; j < printed_array[0].size(); j++){
            printed_array[index][j] = "| " + l_filling(printed_array[index][j], lens[j]) + " ";
        }
        printed_array[index][printed_array[0].size() - 1] += "|";
    }

    cout << endl;

    int string_len = 0;
    for(auto i: printed_array[0]){
        string_len += static_cast<int>(i.size());
    }
    string middle_border;
    cout << "**\n";
    for(int i = 0; i < string_len; i++){
        middle_border += "-";
    }
    cout << endl;
    for(int i = 0; i < string_len; i++){
        cout << "_";
    }
    cout << endl;
    int count = 0;
    for (auto cell: printed_array){
        if (count != 0) {
            cout << endl ;
            cout << middle_border << endl;
        }
        for(auto item: cell){
            cout << item;
        }
        count ++;
    }
    cout << endl;
    for(int i = 0; i < string_len; i++){
        cout << "#";
    }
    cout << endl;

//    cout<< l_filling("1234", 10, "*") << endl;

//        for(auto ch: time_) {
//            cout << ch ;
//        }
//        cout << "\t";
//    }
//    cout << endl;
//
//    for (int set_type_index = 0; set_type_index < data_->size(); set_type_index++) {
//        int index = 0;
//        for (auto coll: printed_array) {
//            if (index != 0) {
//                auto o = data_[set_type_index];
//                for(const auto& gg: o){
//                    for (auto ch: gg){
//                        cout << ch;
//                    }
//                    cout << "\t====\t";
//                }
//                cout <<endl;
//                coll.push_back("df");
//
//            }
//            index++;
//        }
//    }

    // ==============================================

//
//    for (const auto &i: SetAsNode(10000)) {
//        cout << i << endl;
//    }
//    for (const auto &i: SetAsNodeClass(10000)) {
//        cout << i << endl;
//    }
//    for (const auto &i: SetAsList(10000)) {
//        cout << i << endl;
//    }
//
//    for (const auto &i: SetAsSet(10000)) {
//        cout << i << endl;
//    }
//    for (const auto &i: SetAsQueue(10000)) {
//        cout << i << endl;
//    }
    string f;
//    cin>>f;
    return 0;
}
