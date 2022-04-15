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

    int cell_ind = 0;
    for (auto cell: *data_) {
        int item_ind = 0;
        for (auto time_: cell) {
            string item;
            for (auto ch: time_) {
                item += ch;
            }
            printed_array[item_ind + 1].push_back(item);
            item_ind++;
        }
        cell_ind++;
    }

    vector<int> lens = {};
    for(int j = 0; j < printed_array[0].size(); j++){
        int max_len = 0;
        for(int index = 0; index < printed_array.size(); index++){
            if (max_len < printed_array[index][j].size()){
                max_len = static_cast<int>(printed_array[index][j].size());
            }
        }
        lens.push_back(max_len);
    }

    for(int index = 0; index < printed_array.size(); index++){
        for(int j = 0; j < printed_array[0].size(); j++){
            printed_array[index][j] = "| " + l_filling(printed_array[index][j], lens[j]) + " ";
        }
        printed_array[index][printed_array[0].size() - 1] += "|";
    }


    int string_len = 0;
    for(auto i: printed_array[0]){
        string_len += static_cast<int>(i.size());
    }
    string middle_border;
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
    return 0;
}
