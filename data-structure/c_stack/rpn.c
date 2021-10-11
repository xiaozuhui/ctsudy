//
// Created by xuzh on 2021/10/9.
//

#include "rpn.h"
#include "stack.h"
#include <string.h>
#include "utils.h"
#include <stdio.h>

void generate_rpn(rpn *r, char *exp) {
    unsigned long exp_len = strlen(exp);
    strcat(r->origin_expression, exp);
    char exp_list[100][100] = {{'\0'}};
    split_exp(exp_list, exp, (int) exp_len);
    for (int i = 0; i < exp_len; i++) {
        strcat(r->finishing_expression, exp_list[i]);
    }

    /**
     * ( > \*\/\/ > +\/- > )
     * 1、在括号内，低或平，弹数
     * 2、在括号内，高，押入
     * 3、遇到成对括号，整个括号的符号弹出，再弹数
     * 4、在括号外，低或平，先弹数，再弹符号，再押入符号
     * 5、遇到结束，先押入所有剩余的数字或符号，然后先弹出所有的数字，再弹出所有的符号
     */

    stack numbers;
    stack operator;
    int length = sizeof(exp_list) / sizeof(*exp_list);
    for (int i = 0; i < length; i++) {
        char *tmp = exp_list[i];
        if (is_number_str(tmp)) { // 数字
            push(&numbers, tmp);
        } else { // 符号
            if (operator.count == 0) {
                push(&operator, tmp);
            }
            char *opt = peek(&operator, 0);
            switch (opt[0]) {
                case '+':
                case '-':
                    if (tmp[0] == '+' || tmp[0] == '-') {

                    } else if (tmp[0] == '*' || tmp[0] == '/') {

                    } else if (tmp[0] == '(') {

                    } else if (tmp[0] == ')') {

                    } else {

                    }
                case '*':
                case '/':
                    if (tmp[0] == '+' || tmp[0] == '-') {

                    } else if (tmp[0] == '*' || tmp[0] == '/') {

                    } else if (tmp[0] == '(') {

                    } else if (tmp[0] == ')') {

                    } else {

                    }
                case '(':
                    if (tmp[0] == '+' || tmp[0] == '-') {

                    } else if (tmp[0] == '*' || tmp[0] == '/') {

                    } else if (tmp[0] == '(') {

                    } else if (tmp[0] == ')') {

                    } else {

                    }
                case ')':
                    if (tmp[0] == '+' || tmp[0] == '-') {

                    } else if (tmp[0] == '*' || tmp[0] == '/') {

                    } else if (tmp[0] == '(') {

                    } else if (tmp[0] == ')') {

                    } else {

                    }
                default:
                    continue;
            }
        }
    }

}


void print_rpn(const rpn *r) {
    printf("原公式：%s\n", r->origin_expression);
    printf("整理后的公式：%s\n", r->finishing_expression);
    printf("后缀表达：%s\n", r->formula);
    printf("计算结果：%lf\n", r->result);
}


