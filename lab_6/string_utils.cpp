//
// Created by Daniil on 15.04.2022.
//

#include "string_utils.h"

string r_filling(string str, int len, const std::string &splitter) {
    int iter_count = len - static_cast<int>(str.size());
    for (int i = 0; i < iter_count; i++) {
        for (auto ch: splitter) {
            str += ch;
            i++;
            if (i >= iter_count) {
                break;
            }
        }
        i--;
    }

    return str;
}

string l_filling(string str, int len, const std::string &splitter) {
    int iter_count = len - static_cast<int>(str.size());
    for (int i = 0; i < iter_count; i++) {
        for (auto ch: splitter) {
            str = ch + str;
            i++;
            if (i >= iter_count) {
                break;
            }
        }
        i--;
    }

    return str;
}

string center(string str, int len, const std::string &splitter) {
    int iter_count = len - static_cast<int>(str.size());
    for (int i = 0; i < iter_count; i++) {
        if ((int) (i / static_cast<int>(splitter.size())) % 2 == 0) {
            for (auto ch: splitter) {
                str += ch;
                i++;
                if (i >= iter_count) {
                    break;
                }

            }
            i--;
        } else {
            for (auto ch: splitter) {
                str = ch + str;
                i++;
                if (i >= iter_count) {
                    break;
                }
            }
            i--;
        }
    }

    return str;
}
