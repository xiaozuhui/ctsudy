//
// Created by xuzh on 2021/10/9.
//

#include "utils.h"
#include <string.h>
#include <stdbool.h>

char **split_exp(char *exp) {
    unsigned long exp_len = strlen(exp);
    char num[exp_len];
    for (int i = 0; i < exp_len; i++) {
        if (IsNumber(exp[i])) { // 如果是数字

        } else if (IsOpt(exp[i])) {
            // 如果是符号，则将之前排列的字符归类
        } else {
            continue;
        }
    }
}

// 是否是数字
bool IsNumber(char exp) {
    if (exp >= '0' && exp <= '9') {
        return true;
    }
    return false;
}

// 是否是操作符
bool IsOpt(char exp) {
    if (exp == '+' || exp == '-' ||
        exp == '*' || exp == '/' || exp == '(' || exp == ')') {
        return true;
    }
    return false;
}