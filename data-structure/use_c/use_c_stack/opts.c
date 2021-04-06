//
// Created by 许子恒 on 2021/3/27.
//

#include "opts.h"

Stack GenerateRPN(const char * expression, int n) {
    Stack s = InitStack("");
    Stack output = InitStack("");

    for (int i = 0; i < n; i++) {
        if (IsNumber(expression[i])) {
            Push(&output, expression[i]);
        } else if (IsOpt(expression[i])) {
            if (s.Count == 0){
                Push(&s, expression[i]);
                continue;
            }
            switch (CompareOpt(Peek(&s, -1), expression[i])) {
                case HIGH:
                case SUPER:
                {
                    Push(&output, Pop(&s));
                    i--;
                }
                break;
                case MIDDLE:
                    Push(&output, expression[i]);
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
        Push(&output, Pop(&s));
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
float ComputeRPN(Stack * exp) {
    Stack tmp = InitStack("");
    float res = 0;
    int has = 0;
    while (exp->Count != 0) {
        char s = Pop(exp);
        if (tmp.Count == 0) {
            Push(&tmp, s);
        }
        if (s == '*' || s == '+' || s == '/' || s == '-') {
            if (has == 0) {
                int a = (int)Pop(&tmp);
                int b = (int)Pop(&tmp);
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
                int a = (int)Pop(&tmp);
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
        } else {
            Push(&tmp, s);
        }
    }
    return res;
}