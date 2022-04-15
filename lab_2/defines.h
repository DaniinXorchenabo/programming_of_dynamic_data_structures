//
// Created by Daniil on 17.02.2022.
//

#ifndef PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_DEFINES_2_H
#define PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_DEFINES_2_H

#define SET2_FOR_EACH(pHead, iter)           \
    for (                                   \
        PNODE2 (iter) = (pHead);             \
        (iter) && (iter)->item != INT_MAX;  \
        (iter) = (iter)->pNext)

#endif //PROGRAMMING_OF_DYNAMIC_DATA_STRUCTURES_DEFINES_2_H
