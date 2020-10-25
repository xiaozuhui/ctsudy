//
// Created by xuzh on 2020/11/1.
//

#include "10-13编成练习.h"

int max(const int * arr, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int index_of_max(const double * arr, int n) {
    double max = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (max < arr[i]){
            max = arr[i];
            idx = i;
        }
    }
    return idx;
}

void revser(double * arr, int n) {
    for (int i = 0; i < n; i++) {
        if(i >= n-1-i){
            break;
        }
        double t = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = t;
    }
}
