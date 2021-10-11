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
    char *origin_expression; // 原公式
    char *finishing_expression;// 整理后的公式
    char *formula; // 后缀表达式
    char **formula_list; // 后缀表达式的数组表达
    double result; // 计算结果
} rpn;

void generate_rpn(rpn *r, char *exp);

long long compute_rpn(rpn *r);

void print_rpn(const rpn *r);

#endif //C_STACK_RPN_H
