#include <stdio.h>
#include "stack.h"

int main() {
    char *items[] = {"12", "123", "453", "31", "23", "34", "7", "4", "5678", "645"};
    stack s = init(10, items);
    PrintStack(&s);
    push(&s, "fuck");
    PrintStack(&s);
    return 0;
}
