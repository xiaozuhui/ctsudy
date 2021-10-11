#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "rpn.h"
#include <string.h>

int main() {
    char *items[] = {"12", "123", "453", "31", "23", "34", "7", "4", "5678", "645"};
//    stack stk;
//    stk.count = 10;
//    stk.size = 10 * 2;
//    stk.items = (char **) malloc(sizeof(char *) * 10 * 2);
//    for (int i = 0; i < 10; i++) {
//        stk.items[i] = (char *) malloc(sizeof(char) * 100);
//        strcat(stk.items[i], items[i]);
//    }
//    stk.ptr = &stk.items[stk.count - 1];
//    print_stack(&stk);
//    for (int i = 0; i < stk.count; i++) {
//        free(stk.items[i]);
//    }
//    free(stk.items);


//    stack stk = init(10, items);
//    print_stack(&stk);
//    push(&stk, "fuck");
//    print_stack(&stk);
//    char *s = peek(&stk, 3);
//    printf("下标为3的元素是：%s\n", s);
//    char *append[] = {"43287", "wqeyhjgs", "dasj", "da", "", "321", "f", "dfgdf", " ", "", "dqwdfs"};
//    push_items(&stk, 11, append);
//    print_stack(&stk);
//    s = peek(&stk, 11);
//    printf("下标为11的元素是：%s\n", s);
//    s = peek(&stk, 12);
//    printf("下标为12的元素是：%s\n", s);
//    char *ss = pop(&stk);
//    printf("弹栈的元素是：%s\n", ss);
//    print_stack(&stk);
//    push(&stk, "垃圾");
//    print_stack(&stk);
//    clear(&stk);
//    print_stack(&stk);


    rpn r;
    char oe[100] = {'\0'};
    char fe[100] = {'\0'};
    char fm[100] = {'\0'};
    char *rpn_list[100] = {"\0"};
    r.origin_expression = oe;
    r.finishing_expression = fe;
    r.formula_list = rpn_list;
    r.formula = fm;
    r.result = 0.0;
    generate_rpn(&r, "23 * (12+45)");
    print_rpn(&r);
    return 0;
}
