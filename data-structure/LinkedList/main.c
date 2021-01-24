#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
    int arr[6] = {2, 5, 8, 2, 7, 0};
    Node *node = generateList(NULL, arr, 6);
    print(node);
    add(node, 12);
    print(node);
//    Node *node2 = init(23);
//    print(node2);
//    Node *node3 = (struct Node*)malloc(sizeof(struct Node));
//    node3->is_header = TRUE;
//    node3->v = 0;
//    print(node3);
//    printf("%d\n", isHeader(node3));
//    printf("%d\n", isEmpty(node3));
    printf("第%d个节点是：%d", 2, get(node, 2)->v);
}
