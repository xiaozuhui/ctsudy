//
// Created by apple on 2021/10/8.
//

#ifndef C_STACK_STACK_H
#define C_STACK_STACK_H

#define DEFAULT_SIZE 15
#define CHAR_SIZE sizeof('a')
#define WEATHER int
#define OK 1
#define FAIL 0


/**
 * 栈结构体
 * @param count 元素个数
 * @param size 栈长度
 * @param items 底部指针
 * @param ptr 首位指针
 */
typedef struct Stack {
    int count; // 元素个数
    int size; // 堆栈长度
    char **items; // 元素底部指针
    char **ptr; // 首部指针
} stack;

/**
 * 初始化堆栈
 * @param n 元素的个数
 * @param items 元素的数组
 * @return 初始化后的堆栈
 */
stack init(int n, char **items);

/**
 * 扩展堆栈
 * @param stk 栈的引用
 * @param n 扩展的长度
 * @return
 */
WEATHER extend(stack *stk, int n);

/**
 * 弹栈
 * @param stk 栈的引用
 * @return 返回弹出的元素
 */
char *pop(stack *stk);

/**
 * 压栈
 * @param stk 栈的引用
 * @param item 压入的元素
 * @return 压入元素后是否成功，成功返回OK，失败返回FAIL
 */
WEATHER push(stack *stk, char *item);

/**
 * 压入多个元素
 * @param stk
 * @param n
 * @param items
 * @return 压入元素后是否成功，成功返回OK，失败返回FAIL
 */
WEATHER push_items(stack *stk, int n, char **items);

/**
 * 获取数据
 * 0代表最下层的栈元素，-1代表最上面的元素
 * @param stk
 * @param idx
 * @return 获取到指定位置的元素
 */
char *peek(const stack *stk, int idx);

/**
 * 清空整个堆栈
 * @param stk 栈的引用
 */
void clear(stack *stk);

/**
 * 打印栈
 * @param stk 栈的引用
 */
void PrintStack(const stack *stk);


#endif //C_STACK_STACK_H
