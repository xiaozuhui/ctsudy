#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

#define FALSE 0
#define TRUE 1

// 链表节点
typedef struct Node {
    int v;
    int is_header;
    struct Node * next;
} Node ;

// 判断节点是否是哨兵
int isHeader(Node *node);

// 判断链表是否为空（1、p为空；2、p为哨兵并且没有后续节点；）
int isEmpty(Node *p);

// 判断是否存在后续节点
int hasFollow(Node *node);

// 创建新的节点
Node* init(int val);

// 增加节点
Node* add(Node *p, int val);

// 获取某节点后第n个节点
Node* get(Node *p, int index);

// 创建多个节点
Node* generateList(Node *node, const int *values, int n);

// 打印整个链表
void print(Node *node);

#endif //LINKED_LIST_LINKED_LIST_H
