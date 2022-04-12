#include <iostream>
#include <Windows.h>
#include "SetLabQueue.h"


int main() {
    auto a = new SetLabQueue(6, 10, 60,
                         [](int i) { return (i >= 10 && i <= 60 && i % 10 > 7); }
    );
    cout << a->check_item(5) <<endl;
    return 0;
}
