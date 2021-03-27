#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include "rpn.h"

int main() {
    Queue exp = GenerateRPN("1+2*3+(4*5+6)*7", 16);
    PrintQ(&exp);
    float res = ComputeRPN(&exp);
    printf("计算结果构：%.2lf", res);
    return 0;
}
