#include <iostream>
#include <Windows.h>
#include "SetLab4.h"


int main() {
    auto a = new SetLab4(6, 10, 60,
                         [](int i) { return (i >= 10 && i <= 60 && i % 10 > 7); }
                         );
    cout << a->check_item(9) <<endl;

    return 0;
}
