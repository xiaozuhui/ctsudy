//
// Created by xuzh on 2020/11/16.
//

#include "Stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Stack InitStack(const char * chs) {
    Stack s;
    s.Count = DEFAULT_COUNT;
    s.Size = DEFAULT_SIZE;
    s.Items = (char *)malloc(DEFAULT_SIZE * CHAR_SIZE);
    int len = (int)strlen(chs);
    if(len > s.Size - s.Count){
        // 需要重新分配内存
        WEATHER success = ExtendSize(&s, BLOCK_SIZE);
        if(success != OK) {
            // 如果分配失败，则截取后塞入栈中
            len = s.Size - s.Count;
        }
    }
    for(int i  = 0; i < len; i++) {
        s.Items[i] = chs[i];
    }
    s.Count = len;
    return s;
}

int ExtendSize(Stack * s, int n) {
    char * p = (char *)realloc(s->Items, n * CHAR_SIZE);
    if(p != NULL) {
        *s->Items = *p;
        s->Size += n;
        return OK;
    }
    return FAIL;
}

void Print(const Stack * s) {
    if(s == NULL) {
        printf("堆栈不能为空指针\n");
        return;
    }
    printf("堆栈大小：%i\n", s->Size);
    printf("堆栈元素个数：%i\n", s->Count);
    printf("堆栈元素如下：\n");
    printf("-------\n");
    for(int i = 0; i < s->Count; i++) {
        if(i != 0 && i % 4 == 0) {
            printf("\n");
        }
        printf("%c\t", s->Items[i]);
    }
    printf("\n-------\n");
}

char Pop(Stack * s) {
    if(s->Count == 0) {
        return '\0';
    }
    char lastItem = s->Items[s->Count - 1];
    s->Items[s->Count - 1] = '\0';
    s->Count -= 1;
    if(s->Count <= DEFAULT_SIZE && s->Size > DEFAULT_SIZE) {
        // 如果元素个数少于默认长度，且当前长度大于默认长度
        // 释放原本的空间，重新分配空间
        char * p = s->Items;
        s->Items = (char *)malloc(DEFAULT_SIZE * CHAR_SIZE);
        for(int i = 0; i < s->Count; i++) {
            s->Items[i] = p[i];
        }
        free(p);
        s->Size = DEFAULT_SIZE;
    }
    return lastItem;
}

int Push(Stack * s, char c) {
    if(s->Count + 1 > s->Size) {
        // 分配内存空间
        WEATHER success = ExtendSize(s, BLOCK_SIZE);
        if(success != OK) {
            return FAIL;
        }
    }
    s->Items[s->Count] = c;
    s->Count ++;
    return s->Count;
}

int PushItems(Stack * s, const char * chs) {
    int len = (int)strlen(chs);
    int surplus = s->Size - s->Count;
    if (surplus < len) {
        // 分配内存
        WEATHER success = ExtendSize(s, BLOCK_SIZE * ((int)((len - surplus) / BLOCK_SIZE) + 1));
        if(success != OK) {
            return FAIL;
        }
    }
    for(int i = 0; i < len; i++) {
        s->Items[s->Count + i] = chs[i];
    }
    s->Count += len;
    return s->Count;
}

char Peek(const Stack * s, int idx) {
    if(idx != 0 && idx != -1) {
        return FAIL;
    }
    if(idx == 0) {
        return s->Items[0];
    } else {
        return s->Items[s->Count - 1];
    }
}

void Delete(Stack * s) {
    if(s != NULL) {
        free(s->Items);
        s->Count = 0;
        s->Size = 0;
    }
}

void ReInitStack(Stack * s) {
    s->Count = DEFAULT_COUNT;
    s->Size = DEFAULT_SIZE;
    s->Items = (char *)malloc(DEFAULT_SIZE * CHAR_SIZE);
}
