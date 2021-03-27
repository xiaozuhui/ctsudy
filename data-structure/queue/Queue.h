//
// Created by 许子恒 on 2021/3/27.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
/***
 * 1、队列，可申请内存增加
 * 2、循环队列
 * 3、双端队列
 */
#define MALLOC_SIZE 20
#define CHAR_SIZE sizeof('a')

typedef struct Queue {
    char * items; // 元素
    int size;     // 申请的空间大小
    int count;    // 元素个数
} Queue;

Queue InitQueue();
void PushQ(Queue * queue, char item);
void PushQItems(Queue * queue, const char * items);
char PopQ(Queue * queue);
char PeekQ(const Queue * queue, int n);
int _ExtendSize(Queue * queue, int n);
void PrintQ(Queue * queue);

#endif //QUEUE_QUEUE_H
