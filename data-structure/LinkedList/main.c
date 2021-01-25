#include <stdio.h>
#include "linked_list.h"

int main() {
    int arr[6] = {2, 5, 8, 2, 7, 0};
    Node *node = generateList(NULL, arr, 6);
    print(node);
    add(node, 12);
    print(node);
    printNode(get(node, 2));
    printNode(get(node, 7));
    printNode(get(node, -1));
    printNode(get(node, 0));
    printNode(get(node, 9));
    node = delete(node, 3);
    print(node);
    node = pop(node);
    print(node);
    // 相隔一个
    swap(node, 2,4);
    print(node);
    // 相邻
    swap(node, 1,2);
    print(node);
    // 相隔多个
    swap(node, 2, 5);
    print(node);
}
