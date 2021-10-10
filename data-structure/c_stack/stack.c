#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

stack init(int n, char **items) {
    stack stk;
    if (n == 0) {
        n = DEFAULT_SIZE;
    }
    stk.count = n;
    stk.size = n * 2;
    stk.items = (char **) malloc(sizeof(char *) * n * 2);
    /**
     * 这里稍作记录
     * 因为stk.items是一个字符串数组，即char **
     * 所以stk.items是整个数组的首地址，因此不会往后移动，便只能使用下标的方式来复制
     * 但是作为栈首部指针的ptr，必须要拿到items的最后一个元素的地址，所以使用&stk.items[stk.count - 1]的方式来获取
     */
    for (int i = 0; i < n; i++) {
        stk.items[i] = (char *) malloc(sizeof(char) * 100);
        stk.items[i] = *items;
        items++;
    }
    stk.ptr = &stk.items[stk.count - 1];
    return stk;
}

WEATHER extend(stack *stk, int n) {
    // 只分配数组空间，不分配字符串空间
    char **p = (char **) realloc(stk->items, n * sizeof(char *));
    if (p != NULL) {
        *stk->items = *p;
        stk->size += n;
        return OK;
    }
    return FAIL;
}

void print_stack(const stack *stk) {
    if (stk == NULL) {
        printf("堆栈不能为空指针\n");
        return;
    }
    printf("____________________\n");
    printf("堆栈大小：%i\n", stk->size);
    printf("堆栈元素个数：%i\n", stk->count);
    printf("堆栈元素如下：\n");
    printf("序号\t\t下标\t\t元素\n");
    printf("——\t\t——\t\t——\n");
    for (int i = 0; i < stk->count; i++) {
        printf("%d\t\t%d\t\t%s\n", stk->count - i, stk->count - 1 - i, stk->items[i]);
    }
    printf("--------------------\n");
}

WEATHER push_items(stack *stk, int n, char **items) {
    if (stk->count + n > stk->size) {
        // 需要申请空间
        WEATHER success = extend(stk, n * 2);
        if (success != OK) {
            return FAIL;
        }
    }
    for (int i = 0; i < n; i++) {
        stk->items[stk->count + i] = (char *) malloc(sizeof(char) * 100);
        stk->items[stk->count + i] = *items;
        items++;
    }
    stk->count += n;
    stk->ptr = &stk->items[stk->count - 1];
    return OK;
}

WEATHER push(stack *stk, char *item) {
    char *items[] = {item};
    return push_items(stk, 1, items);
}

char *peek(const stack *stk, int idx) {
    if (idx == 0) {
        return *stk->ptr;
    } else if (idx + 1 == stk->count) {
        return *stk->items;
    } else if (idx < 0 || idx + 1 > stk->count) {
        return "索引错误";
    }
    char **p = stk->ptr;
    for (int i = stk->count; i > stk->count - idx; i--, p--);
    return *p;
}


char *pop(stack *stk) {
    if (stk->count == 0 || stk->size == 0 || stk->ptr == NULL) {
        return "该栈是空的";
    }
    char *item = *stk->ptr;
    stk->count--;
    stk->ptr = &stk->items[stk->count - 1];
    return item;
}

void clear(stack *stk) {
    /**
     * free指针报错，这部分先放着吧，可能是指针指向的地址有问题
     */
//    for (int i = 0; i < stk->count; i++) {
//        free(stk->items[i]);
//    }
//    free(stk->items);
    stk->count = 0;
    stk->size = 0;
    stk->ptr = NULL;
    stk->items = NULL;
}
