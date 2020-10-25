#include <stdio.h>
#include <string.h>

void PrintLetter(void) {
    char letters[30];

    for(int i = 'a'; i <= 'z'; i++) {
        letters[i - 'a'] = i;
    }

    for (int i = 0; i < 26; i++) {
        if (i != 0 && i % 7 == 0) {
            printf("\n");
        }
        printf("%c\t", letters[i]);
    }
}

void PrintTriangleDollar(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++){
            printf("$");
        }
        printf("\n");
    }
}

void PrintTriangleLetter(char letter) {
    int n = letter - 'A' + 1;  // 判断有几行，如果letter是A的话，那就是一行。
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++) {
            printf("%c", letter - j);
        }
        printf("\n");
    }
}

void PrintTriangleLetter2(char letter) {
    /*
     * 这道题的解法存在问题，可以优化。
     * */
    char * letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int row_last = 0, row_first = 0;
    for(int i = 0;;i++){
        row_last = row_last + i;
        for (int j = row_first; j < row_last + 1; j++){
            printf("%c", letters[j]);
            if(letters[j] == letter) {
                return;
            }
        }
        row_first = row_last + 1;
        row_last = row_last + 1;
        printf("\n");
    }
}

void PrintTriangleLetter3(char letter){
    int n = letter - 'A' + 1;
    int m = 2*n - 1;
    for(int i = 0; i < n; i++){
        int tmp = m / 2 - i;
        char max = 0;
        for(int j = 0; j <= m / 2; j++){
            if(j >= tmp){
                printf("%c", 'A' + (j - tmp));
                max = 'A' + (j - tmp);
            } else {
                printf(" ");
            }
        }
        for(int j = m / 2 + 1; j < m; j++){
            if(j <= m - tmp - 1){
                printf("%c", max - (j - tmp - i));
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void ReverseString(const char * str) {
    unsigned long n = strlen(str);
    char newStr[n];

    for(int i = 0; i < n; i++) {
        newStr[i] = str[n - i - 1];
    }

    printf("new str: %s", newStr);
}


