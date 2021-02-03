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
    void * value;
    char vt; // 如果是头节点，H；如果是尾节点，T
    struct DoLNode *pre, *nxt;
} DoLNode;

// 生成一个节点
DoLNode* Init();

// 根据arr数组生成一个链表，返回头节点
DoLNode* CreateList(void * arr, int n);

// 清空所有的节点
DoLNode* clear(DoLNode *node);

// 删除整个链表
void deleteList(DoLNode *node);

// 删除下标为i的节点，前序
DoLNode* delete(int i);

// 删除节点，前序
DoLNode* deleteNode(DoLNode *node);

// 删除第一个相符的数据所在的节点，前序
DoLNode* deleteNodeWithValue(void *val);

#endif //DOUBLE_LINKED_LIST_DOUBLE_LINKED_LIST_H
