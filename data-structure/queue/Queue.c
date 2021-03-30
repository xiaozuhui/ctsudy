//
// Created by 许子恒 on 2021/3/27.
//

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>
#include "Queue.h"

/**
 * 初始化队列
 * @return
 */
Queue InitQueue() {
    Queue q;
    q.count = 0;
    q.items = (char *)malloc(MALLOC_SIZE * CHAR_SIZE);
    q.size = MALLOC_SIZE;
    q.first = &q.items[0]; // 获取到头部
    q.current = q.first;   // 当前指针
    q._length = 0;
    return q;
}

void MakeEmpty(Queue * queue) {
    // 释放
    free(queue->items);
    // 重置
    queue->count = 0;
    queue->items = (char *)malloc(MALLOC_SIZE * CHAR_SIZE);
    queue->size = MALLOC_SIZE;
    queue->first = &queue->items[0];
    queue->current = queue->first;
    queue->_length = 0;
}

/**
 * 从后端插入元素
 * @param queue
 * @param item
 */
void PushQ(Queue * queue, char item) {
    if (queue == NULL) {
        *queue = InitQueue();
    }
    // 如果元素数量超过申请的空间数量，那么就需要重新申请空间
    if (queue->_length >= queue->size) {
        _ExtendSize(queue, 2);
    }
    queue->items[queue->count] = item;
    queue->count++;
    queue->_length++;
    if (queue->count > 1) {
        queue->current++; // 当前指针往后移动
    }
}

/**
 * 从后端插入多个元素
 * @param queue
 * @param items
 */
void PushQItems(Queue * queue, const char * items) {
    if (queue == NULL) {
        *queue = InitQueue();
    }
    int len = (int)strlen(items);
    if (len >= queue->size - queue->_length) {
        _ExtendSize(queue, 2);
    }
    for (int i = 0; i < len; i++) {
        queue->items[queue->count + i] = items[i];
        queue->current++;
    }
    queue->count += len;
    queue->_length += len;
}

/**
 * 从前端弹出元素
 * 如果head指针与current指针重合，则删除前端未被释放的空间
 * @param queue
 * @return
 */
char PopQ(Queue * queue) {
    if (queue == NULL || queue->count == 0) {
        return '\0';
    }
    char res = '\0';
    if (queue->current == queue->first) {
        res = *queue->current;
        MakeEmpty(queue);
        return res;
    }
    queue->count--;
    res = *queue->first;
    queue->first++;
    return res;
}

/**
 * 申请更多空间，私有函数
 * @param queue
 * @param n
 * @return
 */
int _ExtendSize(Queue * queue, int n) {
    if (queue == NULL) {
        *queue = InitQueue();
    }
    char * p = (char *)realloc(queue->items, n * MALLOC_SIZE * CHAR_SIZE);
    if (p != NULL) {
        queue->items = p;
        queue->size += n * MALLOC_SIZE;
        return queue->size;
    }
    return 0;
}

/**
 * 打印队列
 * @param queue
 */
void PrintQ(Queue * queue) {
    printf("内存空间大小是：%d\n", queue->size);
    printf("元素个数是：%d\n", queue->count);
    printf("元素是： >- ");
    char * p = queue->first;
    for (int i = 0; i < queue->count; i++) {
        printf("%c ", *p);
        p++;
    }
    printf("-<\n");
    printf("--------------\n");
}
