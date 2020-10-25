//
// Created by xuzh on 2020/10/29.
//
#include <stdio.h>
#include <string.h>
#include "9-11.h"

int min(int x, int y) {
    return x >= y ? x: y;
}

void chline(char * chs, int i, int j) {
    for(int a = 0, b = 1, c = 1; a < strlen(chs); a++, c++) {
        if(chs[a] == '\n'){
            b += 1;
            c = 0;
            continue;
        }
        if (b == j && c == i){
            printf("第%d行、第%d列的字符是%c\n", j, i, chs[a]);
        }
    }
}

/**
 * 调和平均数,先取倒数的和,再倒数
 * @param a
 * @param b
 * @return
 */
double Harmean(double a, double b) {
    if (a == 0 || b == 0){
        return 0.0;
    }
    double d_a = 1 / a;
    double d_b = 1 / b;
    double d_c = d_a + d_b;
    double c = 1 / d_c;
    return c;
}

/**
 * 将两个数中的较大的数赋值给两个数
 * @param a
 * @param b
 */
void larger_of(double * a, double * b) {
    if(a >= b) {
        *b = *a;
    } else {
        *a = *b;
    }
}

void sort(double * a, double * b, double * c) {
    if(*b >= *c) {
        double tmp = *b;
        *b = *c;
        *c = tmp;
    }
    if(*a >= *c) {
        double tmp = *a;
        *a = *c;
        *c = tmp;
    }
    if(*a >= *b) {
        double tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void GetString(){
    char n;
    while(1){
        n = getchar();
        if(n == EOF){
            break;
        }
        if('a' <= n && n <= 'z') {
            printf("%c -> %d", n, n - 'a' + 1);
        }
    }
}

long long fib(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

// 1,1,2,3,5,8,13,21,34,55,...
int fib_loop(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }
    for(int i = 3; i <= n; i++) {

    }
}