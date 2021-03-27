#include <stdio.h>
#include "Queue.h"

int main() {
    Queue q = InitQueue();
    Push(&q, '1');
    Print(&q);
    char * s = "abcdefg";
    PushItems(&q, s);
    Print(&q);
    char x = Pop(&q);
    printf("队列中取走的元素是：%c\n", x);
    Print(&q);
    x = Pop(&q);
    printf("队列中取走的元素是：%c\n", x);
    Print(&q);
}
