//
// Created by xuzh on 2021/10/9.
//

#include "utils.h"
#include <string.h>
#include <stdbool.h>

void split_exp(char res[100][100], char *exp, int n) {

    char num[100] = {'\0'};
    int opt_count = 0;
    int opt_start = 0;
    for (int i = 0; i < n; i++) {
        if (is_number(exp[i])) { // 如果是数字
            num[i] = exp[i];
        } else if (is_operator(exp[i])) {
            // 如果是符号，则将之前排列的字符归类
            bool is_opt_count = false;
            for (int j = opt_start; j < i; j++) {
                if (num[j] == '\0') {
                    continue;
                }
                is_opt_count = true;
                res[opt_count][j - opt_start] = num[j];
            }
            opt_start = i + 1;
            if (is_opt_count) {
                res[opt_count + 1][0] = exp[i];
                opt_count += 2;
            } else {
                res[opt_count][0] = exp[i];
                opt_count += 1;
            }
        } else {
            continue;
        }
    }
}

// 是否是数字
bool is_number(char exp) {
    if (exp >= '0' && exp <= '9') {
        return true;
    }
    return false;
}

// 是否是操作符
bool is_operator(char exp) {
    if (exp == '+' || exp == '-' ||
        exp == '*' || exp == '/' || exp == '(' || exp == ')') {
        return true;
    }
    return false;
}

bool is_number_str(char *exp) {
    if (strlen(exp) == 1 && is_operator(exp[0])) {
        return false;
    }
    return true;
}

bool is_operator_str(char *exp) {
    if (is_number_str(exp)) {
        return false;
    }
    return true;
}
