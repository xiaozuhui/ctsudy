//
// Created by xuzh on 2021/2/2.
//

#ifndef DOUBLE_LINKED_LIST_DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_DOUBLE_LINKED_LIST_H

/**
 * 双向链表节点结构体
 * 不使用哨兵
 * 如果一个节点的前置节点指向自己，那就是头节点
 * 如果一个节点的后置节点指向自己，那就是尾节点
 * TODO 会出现循环
 */
typedef struct DoLNode {
    char * value;
    char vt; // 如果是头节点，H；如果是尾节点，T; 普通节点，N;
    struct DoLNode *pre, *nxt;
} DoLNode;

// 生成一个节点
DoLNode* InitNode(char *val, _Bool isHead, _Bool isTrail);

// 根据arr数组生成一个链表，返回头节点
DoLNode* CreateList(char **arr, int n);

// 增加节点
DoLNode* Add(DoLNode *node, char * *arr, int n);

// 清空所有的节点
DoLNode* Clear(DoLNode *node);

// 删除整个链表
void DeleteList(DoLNode *node);

// 删除下标为i的节点，前序
DoLNode* Delete(int i);

// 删除节点，前序
DoLNode* DeleteNode(DoLNode *node);

// 删除第一个相符的数据所在的节点，前序
DoLNode* DeleteNodeWithValue(char *val);

// 打印整个链表
void printList(DoLNode *node);

// 前序遍历
void ergodic(DoLNode *node, void **out_params, void *(* function)(void **in_params));

// 后续遍历
void postorderTraversal(DoLNode *node, void **out_params, void *(* function)(void **in_params));

// 排序
DoLNode *Sorted(DoLNode *node);

// 交换
void Swap(DoLNode *n1, DoLNode *n2);

// 交换
DoLNode * Swapped(DoLNode *n1, DoLNode *n2);

// 交换
DoLNode * IdxSwap(DoLNode *node, int idx1, int idx2);

DoLNode *IndexOf(DoLNode *node, int idx);

void printNode(DoLNode *node[], int n);

int Count(DoLNode *node);

#endif //DOUBLE_LINKED_LIST_DOUBLE_LINKED_LIST_H
