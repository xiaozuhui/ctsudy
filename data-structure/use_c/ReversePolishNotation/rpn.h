//
// Created by 许子恒 on 2021/3/28.
//

#ifndef RPN_H
#define RPN_H

#define HIGH 1    //
#define MIDDLE 0  // 直接压入output栈
#define LOW -1    // 先将栈弹出压入output栈，再比较
#define SUPER 2   //
#define UN_SUPER -2


#include "Stack.h"
#include "Queue.h"
#include <stdbool.h>


/**
 * 构造后缀表达式
 */
Queue GenerateRPN(const char * expression, int n);

// 是否是数字
bool IsNumber(char exp);

// 是否是操作符
bool IsOpt(char exp);

int CompareOpt(char opt1, char opt2);

float ComputeRPN(Queue * exp);

#endif //RPN_H
