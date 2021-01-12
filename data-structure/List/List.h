//
// 链表
// Created by xuzh on 2020/11/27.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

struct Node;
typedef struct Node *pNode;
typedef pNode List;
typedef pNode Position;

void MakeEmpty(List *list);
_Bool IsEmpty(List *list);
_Bool IsLast(Position *p, List *list);


#endif //LIST_LIST_H
