#include <iostream>
#include <Windows.h>
#include "lab_1_6.h"
#include "defines.h"

//PNODE Init(VOID)
//{
//    PNODE _set = (PNODE)calloc(1, SIZEOF_NODE);
//    if (!_set)
//    {
//        abort();
//    }
//    return _set;
//}




int main() {
//PNODE _set = Init();
//    _set->item = 255;
    auto f = create_empty_set();

    std::cout << "Hello, World! from lab_1 "<< check_item(3, f) << std::endl;

    NODE* first_item = create_set(5, 10 ,15,
                                  [](int i){return ((i % 2) == 0);});

    SET_FOR_EACH(first_item, iter){
        std::cout << iter->item<<", ";

    }
    std::cout<<endl;

    return 0;
}
