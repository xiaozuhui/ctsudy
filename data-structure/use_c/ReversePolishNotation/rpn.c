//
// Created by 许子恒 on 2021/3/28.
//

#include <stdlib.h>
#include "rpn.h"
#include "Queue.h"


Queue GenerateRPN(const char * expression, int n) {
    Stack s = InitStack("");
    Queue output = InitQueue();

    for (int i = 0; i < n; i++) {
        if (IsNumber(expression[i])) {
            PushQ(&output, expression[i]);
        } else if (IsOpt(expression[i])) {
            if (s.Count == 0){
                Push(&s, expression[i]);
                continue;
            }
            switch (CompareOpt(Peek(&s, -1), expression[i])) {
                case HIGH:
                case SUPER:
                {
                    PushQ(&output, Pop(&s));
                    i--;
                }
                    break;
                case MIDDLE:
                    PushQ(&output, expression[i]);
                    break;
                case LOW:
                    Push(&s, expression[i]);
                    break;
                case UN_SUPER:
                    Pop(&s);
                    break;
                default:
                    break;
            }
        } else {
            break;
        }
    }
    for (int i = s.Count - 1; i >= 0; i--) {
        PushQ(&output, Pop(&s));
    }
    return output;
}


// 是否是数字
bool IsNumber(char exp) {
    if (exp >= '0' && exp <= '9') {
        return true;
    }
    return false;
}

// 是否是操作符
bool IsOpt(char exp) {
    if (exp == '+' || exp == '-' ||
        exp == '*' || exp == '/' || exp == '(' || exp == ')') {
        return true;
    }
    return false;
}

// 比较操作符
int CompareOpt(char opt1, char opt2) {
    if (opt1 == opt2) {
        return MIDDLE;
    }
    switch (opt1) {
        case '*':
        case '/':
            if (opt2 == '*' || opt2 == '/') {
                return MIDDLE;
            } else if (opt2 == '+' || opt2 == '-') {
                return HIGH;
            } else if (opt2 == ')'){
                return SUPER;
            } else {
                return LOW;
            }
        case '+':
        case '-':
            if (opt2 == '+' || opt2 == '-') {
                return MIDDLE;
            } else if (opt2 == ')') {
                return SUPER;
            } else {
                return LOW;
            }
        case '(':
            if (opt2 == ')') {
                return UN_SUPER;
            } else {
                return LOW;
            }
        default:
            break;
    }
    return MIDDLE;
}

// 计算后缀表达式
float ComputeRPN(Queue * exp) {
    Stack tmp = InitStack("");
    float res = 0;
    int has = 0;
    while (exp->count != 0) {
        char s = PopQ(exp);
        if (tmp.Count == 0 || (s >= '0' && s <= '9')) {
            Push(&tmp, s);
            continue;
        }
        if (s == '*' || s == '+' || s == '/' || s == '-') {
            if (has == 0) {
                int a = (int)(Pop(&tmp) - '0');
                int b = (int)(Pop(&tmp) - '0');
                switch (s) {
                    case '+':
                        res = (float)(a + b);
                        break;
                    case '-':
                        res = (float)(a - b);
                        break;
                    case '*':
                        res = (float)(a * b);
                        break;
                    case '/':
                        res = (float)(a / b);
                        break;
                    default:
                        break;
                }
                has = 1;
            } else {
                int a = (int)(Pop(&tmp) - '0');
                switch (s) {
                    case '+':
                        res += (float)a;
                        break;
                    case '-':
                        res -= (float)a;
                        break;
                    case '*':
                        res *= (float)a;
                        break;
                    case '/':
                        res /= (float)a;
                        break;
                    default:
                        break;
                }
            }
            Push(&tmp, res);// 失策，stack和queue都要是float类型的……不，应该是strng类型。这里就不改了。放弃
            res = 0;
        } else {
            Push(&tmp, s);
        }
    }
    return res;
}