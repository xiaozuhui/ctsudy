#include <stdio.h>
#include "stack.h"

int main() {
    char *items[] = {"12", "123", "453", "31", "23", "34", "7", "4", "5678", "645"};
    stack stk = init(10, items);
    print_stack(&stk);
    push(&stk, "fuck");
    print_stack(&stk);
    char *s = peek(&stk, 3);
    printf("下标为3的元素是：%s\n", s);
    char *append[] = {"43287", "wqeyhjgs", "dasj", "da", "", "321", "f", "dfgdf", " ", "", "dqwdfs"};
    push_items(&stk, 11, append);
    print_stack(&stk);
    s = peek(&stk, 11);
    printf("下标为11的元素是：%s\n", s);
    s = peek(&stk, 12);
    printf("下标为12的元素是：%s\n", s);
    char *ss = pop(&stk);
    printf("弹栈的元素是：%s\n", ss);
    print_stack(&stk);
    push(&stk, "垃圾");
    print_stack(&stk);
//    clear(&stk);
//    print_stack(&stk);
    return 0;
}
