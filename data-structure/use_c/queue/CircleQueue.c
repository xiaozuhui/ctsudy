//
// Created by 许子恒 on 2021/3/27.
//

#include "CircleQueue.h"
#include <stdio.h>

/**
 * 初始化循环队列
 * @return
 */
CircleQueue InitCQ() {
    CircleQueue queue;
    queue.count = 0;
    queue.head = &queue.values[0];
    queue.tail = NULL;
    queue._size = 5;
    return queue;
}

/**
 * 置空循环队列
 * @param queue
 */
void MakeEmptyCQ(CircleQueue * queue) {
    queue->head = &queue->values[0];
    queue->tail = queue->head;
    queue->count = 0;
}

/**
 * 插入元素
 * @param value
 * @return 返回有效元素个数
 */
int PushCQ(CircleQueue * queue, int value) {
    if (queue->tail != NULL) {
        if (queue->tail == &queue->values[queue->_size - 1]) {
            queue->tail = &queue->values[0];
        } else {
            queue->tail++;
        }
        if (queue->tail == queue->head) {
            PopCQ(queue);
        }
    } else {
        queue->tail = queue->head;
    }
    *queue->tail = value;
    queue->count++;
    return queue->count;
}

/**
 * 弹出元素
 * @return 返回被弹出的元素的值
 */
int PopCQ(CircleQueue * queue) {
    if (queue->count <= 0) {
        return 0;
    }
    int res = *queue->head;
    if (queue->head == &queue->values[queue->_size - 1]) {
        // 如果head指针在数组最后端，则跳到第一个位置
        queue->head = &queue->values[0];
    } else {
        queue->head++;
    }
    queue->count--;
    return res;
}

void PrintCQ(CircleQueue * queue) {
    printf("内存空间大小是：%d\n", queue->_size);
    printf("元素个数是：%d\n", queue->count);
    printf("元素是： >- ");
    int *p = queue->head;
    int count = 0;
    while (count < queue->count) {
        printf("%d ", *p);
        if (p == &queue->values[queue->_size - 1]) {
            p = &queue->values[0];
        } else {
            p++;
        }
        count++;
    }
    printf(":|\n");
    printf("--------------\n");
}
