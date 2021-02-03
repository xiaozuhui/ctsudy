//
// Created by xuzh on 2021/2/2.
//
#include <stdlib.h>
#include <stdio.h>
#include "double_linked_list.h"

/**
 * 生成一个节点
 * @param val     节点的值
 * @param isHead  是否头节点
 * @param isTrail 是否尾节点
 * @return 返回节点
 */
DoLNode* InitNode(char *val, _Bool isHead, _Bool isTrail) {
    DoLNode *node = (struct DoLNode *)malloc(sizeof(struct DoLNode));
    node->value = val;
    if (isHead) {
        node->vt = 'H';
        node->pre = node;
        node->nxt = NULL;
    } else if (isTrail) {
        node->vt = 'T';
        node->nxt = node;
        node->pre = NULL;
    } else {
        node->vt = 'N';
        node->nxt = NULL;
        node->pre = NULL;
    }
    return node;
}

/**
 * 创建链表
 * @param node 节点指针，如果没有会创建
 * @param arr  字符串数组
 * @param n    字符串数组的个数
 * @return 返回头节点
 */
DoLNode* CreateList(char **arr, int n) {
    if (n == 0) {
        return NULL;
    }
    DoLNode *head = InitNode(arr[0], 1, 0);
    DoLNode *node = head;
    for (int i = 1; i < n - 1; i++) {
        DoLNode *tmpN = InitNode(arr[i], 0, 0);
        node->nxt = tmpN;
        tmpN->pre = node;
        node = tmpN;
    }
    DoLNode *trail = InitNode(arr[n-1], 0, 1);
    node->nxt = trail;
    trail->pre = node;
    trail->nxt = trail;
    return head;
}

/**
 * 在节点后续增加节点
 * @param node 任意节点
 * @param arr  增加的节点，可以为数组
 * @param n    数组的数量
 * @return 返回当前节点，即尾节点; 如果node为NULL，则返回新链表的头节点
 */
DoLNode* Add(DoLNode *node, char **arr, int n) {
    if (node == NULL) {
        return CreateList(arr, n);
    }
    if (n == 0) {
        return node;
    }
    if (node->nxt != node) {
        // 如果不是尾节点，则遍历到尾节点
        while (node->nxt != node) {
            node = node->nxt;
        }
    }
    for (int i = 0; i < n; i++) {
        DoLNode *tmpN = InitNode(arr[i], 0, 1);
        node->nxt = tmpN;
        node->vt = 'N';
        tmpN->pre = node;
        node = tmpN;
    }
    return node;
}

/**
 * 打印链表
 * @param node
 */
void printList(DoLNode *node) {
    if (node == NULL) {
        printf("|<=>&");
    }
    if (node->nxt == node) {
        // 尾节点
        printf("&<=> ");
        while (node->pre != node) {
            printf("{%s} <=> ", node->value);
            node = node->pre;
        }
        printf("{%s} <=>|\n", node->value);
        return;
    } else if (node->pre == node) {
        // 头节点
    } else {
        while (node->pre != node) {
            node = node->pre;
        }
    }
    printf("|<=> ");
    while (node->nxt != node) {
        printf("{%s} <=> ", node->value);
        node = node->nxt;
    }
    printf("{%s} <=>&\n", node->value);
}
