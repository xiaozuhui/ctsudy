#include <stdio.h>
#include "Queue.h"
#include "CircleQueue.h"

int main() {
//    Queue q = InitQueue();
//    PushQ(&q, '1');
//    PrintQ(&q);
//    PushQ(&q, '2');
//    PrintQ(&q);
//    char * s = "a";
//    PushQItems(&q, s);
//    PrintQ(&q);
//    char x = PopQ(&q);
//    printf("队列中取走的元素是：%c\n", x);
//    PrintQ(&q);
//    x = PopQ(&q);
//    printf("队列中取走的元素是：%c\n", x);
//    PrintQ(&q);
//    x = PopQ(&q);
//    printf("队列中取走的元素是：%c\n", x);
//    PrintQ(&q);
    CircleQueue queue = InitCQ();
    PushCQ(&queue, 1);
    PrintCQ(&queue);
    PushCQ(&queue, 2);
    PrintCQ(&queue);
    PushCQ(&queue, 3);
    PushCQ(&queue, 4);
    PushCQ(&queue, 5);
    PrintCQ(&queue);
    PushCQ(&queue, 6);
    PrintCQ(&queue);
    PopCQ(&queue);
    PrintCQ(&queue);
    PopCQ(&queue);
    PrintCQ(&queue);
    PushCQ(&queue, 7);
    PrintCQ(&queue);
    PopCQ(&queue);
    PopCQ(&queue);
    PopCQ(&queue);
    PrintCQ(&queue);
    PopCQ(&queue);
    PrintCQ(&queue);
    PopCQ(&queue);
    PrintCQ(&queue);
    PushCQ(&queue, 8);
    PushCQ(&queue, 9);
    PushCQ(&queue, 10);
    PushCQ(&queue, 11);
    PushCQ(&queue, 12);
    PrintCQ(&queue);
}

/* 普通队列
 *
内存空间大小是：20
元素个数是：1
元素是： >- 1 -<
--------------
内存空间大小是：20
元素个数是：2
元素是： >- 1 2 -<
--------------
内存空间大小是：20
元素个数是：3
元素是： >- 1 2 a -<
--------------
队列中取走的元素是：1
内存空间大小是：20
元素个数是：2
元素是： >- 2 a -<
--------------
队列中取走的元素是：2
内存空间大小是：20
元素个数是：1
元素是： >- a -<
--------------
队列中取走的元素是：a
内存空间大小是：20
元素个数是：0
元素是： >- -<
--------------
*/

/* 循环队列
 *
内存空间大小是：5
元素个数是：1
元素是： >- 1 :|
--------------
内存空间大小是：5
元素个数是：2
元素是： >- 1 2 :|
--------------
内存空间大小是：5
元素个数是：5
元素是： >- 1 2 3 4 5 :|
--------------
内存空间大小是：5
元素个数是：5
元素是： >- 2 3 4 5 6 :|
--------------
内存空间大小是：5
元素个数是：4
元素是： >- 3 4 5 6 :|
--------------
内存空间大小是：5
元素个数是：3
元素是： >- 4 5 6 :|
--------------
内存空间大小是：5
元素个数是：4
元素是： >- 4 5 6 7 :|
--------------
内存空间大小是：5
元素个数是：1
元素是： >- 7 :|
--------------
内存空间大小是：5
元素个数是：0
元素是： >- :|
--------------
内存空间大小是：5
元素个数是：0
元素是： >- :|
--------------
内存空间大小是：5
元素个数是：5
元素是： >- 8 9 10 11 12 :|
--------------
 */