#include "linked_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 判断节点是否是哨兵
 * @param node
 * @return
 */
int isHeader(Node *node) {
    if(node == NULL) {
        return FALSE;
    }
    return node->is_header;
}

/**
 * 判断是否存在后续节点
 * @param node
 * @return
 */
int hasFollow(Node *node) {
    if(node == NULL) {
        return FALSE;
    }
    if (node->next != NULL) {
        return TRUE;
    }
    return FALSE;
}

/**
 * 判断链表是否为空
 * 1、p为空；
 * 2、p为哨兵并且没有后续节点；
 * @param p
 * @return
 */
int isEmpty(Node *p) {
    if(p == NULL) {
        return TRUE;
    }
    if(p->is_header) {
        return !hasFollow(p);
    }
    return FALSE;
}

/**
 * 创建一个有哨兵的新节点
 * @param val
 */
Node* init(int val) {
    Node *header = (struct Node*)malloc(sizeof(struct Node));
    Node *p = (struct Node*)malloc(sizeof(struct Node));
    header->is_header = TRUE;
    header->v = 0;
    p->is_header = FALSE;
    p->v = val;
    header->next = p;
    return header;
}

/**
 * 增加节点
 * 如果p为null，则使用init
 * 如果p为节点，无论是哨兵还是普通节点，则在最后一个节点后面增加新节点
 * @param p 之前的节点，最好是哨兵
 * @param val
 * @return
 */
Node* add(Node *p, int val) {
    if(p == NULL) {
        return init(val);
    }
    // 拿到第一个值，可能不是哨兵和也不是第一个值
    Node *header = &(*p);
    // 获取到p的最后一个节点
    while(p->next != NULL) {
        p = p->next;
    }
    Node *last = (struct Node*)malloc(sizeof(struct Node));
    last->v = val;
    last->is_header = FALSE;
    p->next = last;
    return header;
}

/**
 * 从给定的节点往后获取第n个节点
 * 如果p不存在，则返回null
 * index从1开始迭代
 * @param p
 * @param index
 * @return
 */
Node* get(Node *p, int index) {
    if(p == NULL) {
        return NULL;
    }
    for(int i = 1; i <= index && p->next != NULL; i++) {
        p = p->next;
    }
    return p;
}

/**
 * 创建多个节点
 * @param node
 * @param values
 * @return
 */
Node* generateList(Node *node, const int * values, int n) {
    if(node == NULL) {
        node = (struct Node*)malloc(sizeof(struct Node));
        node->is_header = TRUE;
        node->v = 0;
        node->next = NULL;
    }
    for(int i = 0; i < n; i++) {
        add(node, values[i]);
    }
    return node;
}

/**
 * 打印链表
 * @param node
 */
void print(Node *node) {
    if(node == NULL || isEmpty(node)) {
        printf("[] -> null\n");
        return;
    }
    if(node->is_header) {
        printf("header -> ");
    }
    while(node->next != NULL) {
        node = node->next;
        printf("%d -> ", node->v);
    }
    printf("null\n");
}
