//
// Created by 张先森 on 2023/1/3.
//

#ifndef INC_12_4_2014_41_FUNCTION_H
#define INC_12_4_2014_41_FUNCTION_H
#include <stdio.h>
#include <stdlib.h>

typedef int BiElemType;
typedef struct BiTNode{
    BiElemType weight;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

typedef struct tag{
    BiTree p;
    struct tag *next;
}tag_t,*ptag_t;
#endif //INC_12_4_2014_41_FUNCTION_H
