//
// Created by 许子恒 on 2021/3/27.
//

#ifndef QUEUE_CIRCLEQUEUE_H
#define QUEUE_CIRCLEQUEUE_H

/**
 * 循环队列
 * 头指针标识取元素的位置
 * current指针标识插入元素的位置
 * 长度一定，不能申请新的空间
 * 当head指针和current指针重叠时，继续追加则先删除头部，再插入
 * head之前与current之后的空间永远可以插入数据
 * 是使用数组还是链表？？
 */

// 使用数组实现的循环队列
typedef struct CircleQueue {
    int values[5]; // 元素空间
    int _size;     // 元素空间大小
    int * head;    // 头指针
    int * tail;    // 尾指针
    int count;     // 有效元素个数
} CircleQueue ;

// 初始化循环队列
CircleQueue InitCQ();

// 置空
void MakeEmptyCQ(CircleQueue * queue);

// 插入数据
int PushCQ(CircleQueue * queue, int value);

// 弹出数据
int PopCQ(CircleQueue * queue);

void PrintCQ(CircleQueue * queue);

#endif //QUEUE_CIRCLEQUEUE_H
