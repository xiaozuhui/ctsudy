//
// Created by 许子恒 on 2021/3/27.
//

#ifndef QUEUE_DEQUEUE_H
#define QUEUE_DEQUEUE_H

/**
 * 双端队列，同时也是循环队列
 * 队尾出队、队尾入队，队头出队、队头入队。
 */

typedef struct DoubleQueue {
    int values[5]; // 元素空间
    int _size;     // 元素空间大小
    int * head;    // 头指针
    int * tail;    // 尾指针
    int count;     // 有效元素个数
} Dequeue;

// 初始化循环队列
Dequeue CreateDeque();

// 释放队列
void DisposeDeque(Dequeue * queue);

// 从前端插入数据
int PushFront(Dequeue * queue, int value);

// 从后端插入数据
int PushTail(Dequeue * queue, int value);

// 从前端弹出数据
int PopFront(Dequeue * queue);

// 从后端弹出数据
int PopTail(Dequeue * queue);

// 打印队列
void PrintDeque(Dequeue * queue);

#endif //QUEUE_DEQUEUE_H
