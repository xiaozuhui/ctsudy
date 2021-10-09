//
// Created by xuzh on 2021/10/9.
//

#ifndef C_STACK_RPN_H
#define C_STACK_RPN_H

#include "stack.h"

/**
 * RPN是构造后缀表达式以及计算后缀表达式的文件
 */
typedef struct RPN {
    char *expression; // 原公式
    char *formula; // 后缀表达式
    long long result; // 计算结果
} rpn;

rpn generate_rpn(char *exp);

long long compute_rpn(rpn *r);

#endif //C_STACK_RPN_H
