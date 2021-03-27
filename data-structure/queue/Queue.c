//
// Created by 许子恒 on 2021/3/27.
//

#include <stddef.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include "Queue.h"

Queue InitQueue() {
    Queue q;
    q.count = 0;
    q.items = (char *)malloc(MALLOC_SIZE * CHAR_SIZE);
    q.size = MALLOC_SIZE;
    return q;
}

void PushQ(Queue * queue, char item) {
    if (queue == NULL) {
        *queue = InitQueue();
    }
    // 如果元素数量超过申请的空间数量，那么就需要重新申请空间
    if (queue->count >= queue->size) {
        _ExtendSize(queue, 2);
    }
    queue->items[queue->count] = item;
    queue->count ++;
}

void PushQItems(Queue * queue, const char * items) {
    if (queue == NULL) {
        *queue = InitQueue();
    }
    if (queue->count >= queue->size) {
        _ExtendSize(queue, 2);
    }
    int len = (int)strlen(items);
    if (len >= queue->size - queue->count) {
        _ExtendSize(queue, 2);
    }
    for (int i = 0; i < len; i++) {
        queue->items[queue->count + i] = items[i];
    }
    queue->count += len;
}

char PopQ(Queue * queue) {
    if (queue == NULL || queue->count == 0) {
        return '\0';
    }
    char * s = queue->items;
    int len = (int)strlen(s);
    int n = 1;
    if (len > MALLOC_SIZE) {
        n = (int)(len / MALLOC_SIZE) + 1;
    }
    queue->items = (char *)malloc(n * MALLOC_SIZE * CHAR_SIZE);
    for (int i = 1; i < len; i++) {
        queue->items[i - 1] = s[i];
    }
    char res = s[0];
    free(s);
    queue->count --;
    return res;
}

// 申请更多空间，私有函数
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

void PrintQ(Queue * queue) {
    printf("内存空间大小是：%d\n", queue->size);
    printf("元素个数是：%d\n", queue->count);
    printf("元素是： >- ");
    for (int i = 0; i < queue->count; ++i) {
        printf("%c ", queue->items[i]);
    }
    printf("-<\n");
    printf("--------------\n");
}
