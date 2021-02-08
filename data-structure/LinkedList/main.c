#include <stdio.h>
#include "linked_list.h"

int main() {
    int arr[6] = {2, 5, 8, 2, 7, 0};
    Node *node = generateList(NULL, arr, 6);
    print(node);  // header -> 2 -> 5 -> 8 -> 2 -> 7 -> 0 -> null
    add(node, 12);
    print(node);  // header -> 2 -> 5 -> 8 -> 2 -> 7 -> 0 -> 12 -> null
    printNode(get(node, 2));  // 值：5	是否头节点：否
    printNode(get(node, 7));  // 值：12	是否头节点：否
    printNode(get(node, -1)); // []
    printNode(get(node, 0));  // 值：0	是否头节点：是
    printNode(get(node, 9));  // []
    node = delete(node, 3);
    print(node);  // header -> 2 -> 5 -> 2 -> 7 -> 0 -> 12 -> null
    node = pop(node);
    print(node);  // header -> 2 -> 5 -> 2 -> 7 -> 0 -> null
    // 相隔一个
    swap(node, 2,4);
    print(node);  // header -> 2 -> 7 -> 2 -> 5 -> 0 -> null
    // 相邻
    swap(node, 1,2);
    print(node);  // header -> 7 -> 2 -> 2 -> 5 -> 0 -> null
    // 相隔多个
    swap(node, 2, 5);
    print(node);  // header -> 7 -> 0 -> 2 -> 5 -> 2 -> null
    printf("个数是: %d\n", len(node));  // 个数是: 5
    Node *n1 = get(node, 2);
    Node *n2 = get(node, 3);
    printNode(n1);  // 值：0	是否头节点：否
    printNode(n2);  // 值：2	是否头节点：否
    swapNode(node, n1, n2);
    print(node);  // header -> 7 -> 2 -> 0 -> 5 -> 2 -> null
    sort(node);
    print(node);  // header -> 0 -> 2 -> 2 -> 5 -> 7 -> null
    reserve(node);
    print(node);  // header -> 7 -> 5 -> 2 -> 2 -> 0 -> null
    node = reserved(sorted(node));  // 排序、反转
    print(node);
    printf("-------------\n");
    Node *n3 = getNegative(node, -4); // 值：5	是否头节点：否
    printNode(n3);

    // 构造一个环形链表
    add(node, 76);
    add(node, -1);
    add(node, 87);
    print(node);  // header -> 7 -> 5 -> 2 -> 2 -> 0 -> 76 -> -1 -> 87 -> null
    sort(node);
    print(node);  // header -> -1 -> 0 -> 2 -> 2 -> 5 -> 7 -> 76 -> 87 -> null

    Node *n4 = getNegative(node, -1);
    printNode(n4);  // 值：87	是否头节点：否
    Node *n5 = getNegative(node, -3);
    printNode(n5);  // 值：7	是否头节点：否
    n4->next = n5;
    // print(node);  // ... -> 7 -> 76 -> 87 -> 7 -> 76 -> 87 -> 7 -> 76 -> 87 -> 7 -> 76 -> 87 -> 7 -> 76 -> 87 -> 7 -> 76 -> 87 -> 7 -> 76 -> 87 -> 7 -> 76 -> 87 -> 7 -> 76 -> ...

    int isLoop = hasLoop(node);
    printf("是否存在环：%s", isLoop == 1 ? "是": "否");  // 是否存在环：是

}
