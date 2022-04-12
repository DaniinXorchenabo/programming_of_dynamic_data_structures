#include <iostream>
#include <Windows.h>
#include "SetLab5.h"


int main() {
    auto a = new SetLab5(6, 10, 60,
                         [](int i) { return (i >= 10 && i <= 60 && i % 10 > 7); }
    );
    cout << a->len() <<endl;
    return 0;
}
