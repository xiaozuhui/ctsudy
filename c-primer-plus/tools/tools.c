//
// Created by xuzh on 2020/11/1.
//
#include "tools.h"
#include <stdio.h>

void print_arr(const double * arr, int n) {
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%lf\t", arr[i]);
    }
    printf("\n");
}