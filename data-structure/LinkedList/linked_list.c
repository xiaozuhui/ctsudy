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
 * @param node 链表任何一个节点
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
    if(p == NULL || index < 0) {
        return NULL;
    }
    if(index == 0){  // 如果是0，则返回哨兵
        return p;
    }
    // 得到index前一个节点
    for(int i = 1; i < index; i++) {
        if(p->next != NULL) {
            p = p->next;
        } else {
            return NULL;
        }
    }
    return hasFollow(p) ? p->next : NULL;
}

/**
 * 创建多个节点
 * @param node   哨兵节点
 * @param values 需要创建节点的值
 * @param n      节点的个数
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
 * @param node 该链表的哨兵节点，但是准确地说，可以是任何一个节点
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

/**
 * 打印节点本身
 * @param node
 */
void printNode(Node *node) {
    if(node == NULL) {
        printf("[]\n");
        return;
    }
    printf("值：%d\t是否头节点：%s\n", node->v, node->is_header ? "是" : "否");
}

/**
 * 删除指定下标的节点
 * 因为有哨兵，所以下标是从1开始迭代
 * @param node 该链表的哨兵
 * @param n    需要删除的节点的下标
 * @return 返回链表的哨兵节点
 */
Node* delete(Node *node, int n) {
    if (isEmpty(node)) {
        return NULL;
    }
    // 获取到哨兵, node作为哨兵，不动
    Node *preNode = node;
    // 获取到n节点的前一个节点
    for(int i = 1; i < n; i++) {
        if (preNode->next == NULL) {
            return NULL;
        }
        preNode = preNode->next;
    }
    // 没有n节点，所以返回0
    if (preNode->next == NULL) {
        return NULL;
    }
    // 获取到目标节点，以及后续节点
    Node *targetNode = preNode->next;
    // 如果目标节点后续没有节点，那么说明目标节点就是最后一个节点
    if(targetNode->next == NULL) {
        preNode->next = NULL;
    } else {
        Node *followUpNode = targetNode->next;
        preNode->next = followUpNode;
    }
    free(targetNode);
    return node;
}

/**
 * 删除末尾的节点
 * @param node
 */
Node* pop(Node *node) {
    if (isEmpty(node)) {
        return NULL;
    }
    Node *header = node;
    // 获取到倒数第二个数
    while(node->next != NULL && node->next->next != NULL) {
        node = node->next;
    }
    Node *lastNode = node->next;
    node->next = NULL;
    free(lastNode);
    return header;
}

/**
 * 清空所有的节点，除了哨兵
 * @param node 链表的哨兵节点
 */
Node* clear(Node *node) {
    if (isEmpty(node)) {
        return NULL;
    }
    if(!node->is_header) {
        return NULL;
    }
    while (node->next != NULL) {
        node = pop(node);
    }
    return node;
}

/**
 * 交换两个指定位置的节点的位置
 * 两个状况：两个节点相邻、两个节点不相邻
 * @param node 链表的哨兵节点
 * @param n    下标，大于等于1
 * @param m    下标，大于等于1
 * @return 返回链表的哨兵节点
 */
Node* swap(Node *node, int n, int m) {
    if (isEmpty(node)) {
        return NULL;
    }
    if (n == m || n <= 0 || m <= 0) {
        return NULL;
    }
    int pre = n < m ? n : m;
    int follow = n < m ? m : n;
    Node *preNode = get(node, pre - 1);
    Node *target1 = get(node, pre);
    Node *target2 = get(node, follow);
    Node *lastNode = get(node, follow + 1);
    if (pre + 1 == follow) {
        // 如果是相邻的节点
        preNode->next = target2;
        target2->next = target1;
        target1->next = lastNode;
    } else {
        // 如果不是相邻的节点
        Node *target1Follow = get(node, pre + 1);
        Node *preTarget2 = get(node, follow - 1);
        preNode->next = target2;
        target2->next = target1Follow;
        target1Follow->next = preTarget2;
        preTarget2->next = target1;
        target1->next = lastNode;
    }
    return node;
}
