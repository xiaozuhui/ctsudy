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
        node->pre = node;
        node->nxt = NULL;
    } else if (isTrail) {
        node->nxt = node;
        node->pre = NULL;
    } else {
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

/**
 * 排序
 * @param node
 * @return
 */
DoLNode *Sorted(DoLNode *node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->pre != node) {
        // 如果不是头节点
        while (node->pre != node) {
            node = node->pre;
        }
    }
    DoLNode *curr = node, *comp = node;  // 当前指针和基准指针
    while (curr->nxt != curr) {
        curr = curr->nxt;
        while (comp != curr) {
            if (curr->value < comp->value) {
                Swapped(curr, comp);
                break;
            }
            comp = comp->nxt;
        }
        comp = node;
    }
    return node;
}

/**
 * 交换两个双向链表节点
 * 原节点指针不交换
 * @param n1 节点1
 * @param n2 节点2
 */
void Swap(DoLNode *n1, DoLNode *n2) {
    if (n1 == NULL || n2 == NULL || n1 == n2) {
        return;
    }
    /*
     * 非相邻/相邻
     * 1、如果n1是头节点
     * 2、如果n1是尾节点
     * 3、如果n2是头节点
     * 4、如果n2是尾节点
     * */
    DoLNode *preN1 = n1->pre;
    DoLNode *fowN1 = n1->nxt;
    DoLNode *preN2 = n2->pre;
    DoLNode *fowN2 = n2->nxt;
    if (n1->pre == n1) {
        // n1头节点
        n2->pre = n2;
        if (n1->nxt == n2) {
            n2->nxt = n1;
            n1->pre = n2;
        } else {
            n2->nxt = fowN1;
            fowN1->pre = n2;
            n1->pre = preN2;
            preN2->nxt = n1;
        }
        if (n2->nxt == n2) {
            // n2尾节点
            n1->nxt = n1;
        } else {
            n1->nxt = fowN2;
        }
    } else if (n2->pre == n2) {
        n1->pre = n1;
        if (n2->nxt == n1) {
            n1->nxt = n2;
            n2->pre = n1;
        } else {
            n1->nxt = fowN2;
            fowN2->pre = n1;
            n2->pre = preN1;
            preN1->nxt = n2;
        }

        if (n1->nxt == n1) {
            n2->nxt = n2;
        } else {
            n2->nxt = fowN1;
        }
    } else {
        if (n1->nxt == n2) {
            n1->pre = n2;
            n1->nxt = fowN2;
            fowN2->pre = n1;
            n2->pre = preN1;
            preN1->nxt = n2;
            n2->nxt = n1;
        } else if (n1->pre == n2) {
            n1->pre = preN2;
            preN2->nxt = n1;
            n1->nxt = n2;
            n2->pre = n1;
            n2->nxt = fowN1;
            fowN1->pre = n2;
        } else {
            n1->pre = preN2;
            preN2->nxt = n1;
            n1->nxt = fowN2;
            fowN2->pre = n1;
            n2->pre = preN1;
            preN1->nxt = n2;
            n2->nxt = fowN1;
            fowN1->pre = n2;
        }
    }
}

/**
 * 两个节点交换，指针交换
 * @param n1 节点1
 * @param n2 节点2
 * @return 返回头指针
 */
DoLNode *Swapped(DoLNode *n1, DoLNode *n2) {
    DoLNode *head = n1;
    if (head->pre != head) {
        while (head->pre != head) {
            head = head->pre;
        }
    }
    Swap(n1, n2);
    DoLNode *tmp = n1;
    n1 = n2;
    n2 = tmp;
    return head;
}

/**
 * 通过下标交换两个节点，指针不交换
 * @param node 头节点
 * @param idx1 下标1
 * @param idx2 下标2
 * @return 返回头指针
 */
DoLNode *IdxSwap(DoLNode *node, int idx1, int idx2) {
    DoLNode *head = node;
    if (node->pre != node) {
        while (head->pre != head) {
            head = head->pre;
        }
    }
    DoLNode *n1 = IndexOf(head, idx1);
    DoLNode *n2 = IndexOf(head, idx2);
    DoLNode *arr[] = {n1, n2};
    printNode(arr, 2);
    head = Swapped(n1, n2);
    return head;
}

/**
 * 根据下标寻找节点
 * @param idx 下标，从零计数
 * @param node 头节点
 * @return
 */
DoLNode *IndexOf(DoLNode *node, int idx) {
    // 如果不是头节点，就返回NULL
    if (node->pre != node) {
        return NULL;
    }
    for(int i = 0; i < idx; i++) {
        node = node->nxt;
        // 如果没有到idx，并且node已经是尾节点，则返回NULL
        if (node->nxt == node) {
            return NULL;
        }
    }
    return node;
}

void printNode(DoLNode **node, int n) {
    for (int i = 0; i < n; ++i) {
        printf("{%s} - ", node[i]->value);
    }
    printf("\n");
}