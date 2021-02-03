#include <stdio.h>
#include "double_linked_list.h"

int main() {
    char  * s[4] = {"测试1", "测试2", "测试106", "测试4"};
    char  * s2[7] = {"测试78", "测试6", "测试4", "测试43", "测试9", "测试10", "测试0"};
    DoLNode *node = CreateList(s, 4);
    printList(node);
    printf("--------------------\n");
    Add(node, s2, 7);
    printList(node);
    printf("--------------------\n");
}
