#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

stack init(int n, char **items) {
    stack stk;
    if (n == 0) {
        stk.count = 0;
        stk.size = DEFAULT_SIZE;
        stk.items = (char **) malloc(CHAR_SIZE * 100 * DEFAULT_SIZE);
        stk.ptr = stk.items;
        return stk;
    }
    stk.count = n;
    stk.size = n * 2;
    stk.items = (char **) malloc((CHAR_SIZE * 100) * (n * 2));
    /**
     * 这里稍作记录
     * 因为stk.items是一个字符串数组，即char **
     * 所以stk.items是整个数组的首地址，因此不会往后移动，便只能使用下标的方式来复制
     * 但是作为栈首部指针的ptr，必须要拿到items的最后一个元素的地址，所以使用&stk.items[stk.count - 1]的方式来获取
     */
    for (int i = 0; i < n; i++) {
        stk.items[i] = *items;
        items++;
    }
    stk.ptr = &stk.items[stk.count - 1];
    return stk;
}

WEATHER extend(stack *stk, int n) {
    char **p = (char **) realloc(stk->items, n * (CHAR_SIZE * 100));
    if (p != NULL) {
        *stk->items = *p;
        stk->size += n;
        return OK;
    }
    return FAIL;
}

void PrintStack(const stack *stk) {
    if (stk == NULL) {
        printf("堆栈不能为空指针\n");
        return;
    }
    printf("-------\n");
    printf("堆栈大小：%i\n", stk->size);
    printf("堆栈元素个数：%i\n", stk->count);
    printf("堆栈元素如下：\n");
    char **p = stk->items;
    char **end = stk->ptr + 1;
    while (p != end) {
        printf("%s\n", *p);
        p++;
    }
    printf("-------\n");
}

WEATHER push(stack *stk, char *item) {
    if (stk->count + 1 > stk->size) {
        // 分配内存空间
        WEATHER success = extend(stk, stk->size);
        if (success != OK) {
            return FAIL;
        }
    }
    stk->items[stk->count] = item;
    stk->ptr = &stk->items[stk->count];
    stk->count++;
    return OK;
}


