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
}
