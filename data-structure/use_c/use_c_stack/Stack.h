//
// Created by xuzh on 2020/11/16.
//

#ifndef CDS_STACK_H
#define CDS_STACK_H
#define DEFAULT_COUNT 0
#define DEFAULT_SIZE 15
#define OK 1
#define FAIL -1
#define WEATHER int
#define BLOCK_SIZE 20
#define CHAR_SIZE sizeof('a')

typedef struct Stack {
    int Count;
    int Size;
    char * Items;
} Stack;

/**
 * 初始化堆栈
 * @param chs
 * @return
 */
Stack InitStack(const char * chs);

/**
 * 扩展堆栈
 * @param n
 * @return
 */
int ExtendSize(Stack * s, int n);

/**
 * 弹栈
 * @return
 */
char Pop(Stack * s);

/**
 * 压栈
 * @param c
 * @return
 */
int Push(Stack * s, char c);

/**
 * 多元素压栈
 * @param chs
 * @return
 */
int PushItems(Stack * s, const char * chs);

/**
 * 获取数据，0代表最下层的栈元素，-1代表最上面的元素
 * @param idx 只能填0或-1
 * @return
 */
char Peek(const Stack * s, int idx);

/**
 * 打印数据
 * @param s
 */
void Print(const Stack * s);

/**
 * 删除整个堆栈
 * @param s
 */
void Delete(Stack * s);

void ReInitStack(Stack * s);

#endif //CDS_STACK_H
