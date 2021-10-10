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
    char * items;   // 元素
    int size;       // 申请的空间大小
    int count;      // 元素个数
    int _length;    // 用于计算已经使用的空间大小
    char * first;   // 头部元素指针
    char * current; // 当前元素指针
} Queue;

// 初始化队列
Queue InitQueue();

// 插入元素
void PushQ(Queue * queue, char item);

// 插入多个元素
void PushQItems(Queue * queue, const char * items);

// 弹出前端元素
char PopQ(Queue * queue);

// 查看顺序第n个元素的值
char PeekQ(const Queue * queue, int n);

// 私有函数，扩展空间
int _ExtendSize(Queue * queue, int n);

// 打印队列
void PrintQ(Queue * queue);

// 置空
void MakeEmpty(Queue * queue);

#endif //QUEUE_QUEUE_H
