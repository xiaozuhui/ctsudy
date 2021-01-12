////
//// Created by xuzh on 2020/12/20.
////
//#include <stdio.h>
//#include <string.h>
//
//char * s_get(char * st, int n);
//
//#define MAXTITL  40
//#define MAXAUTL  40
//#define MAXBKS  100
//
//struct book {
//    char title[MAXTITL];
//    char author[MAXAUTL];
//    float value;
//};
//
//int main(void) {
//    struct book library[MAXBKS];
//
//    int count = 0;
//    int index;
//
//    printf("Please enter the book title./n");
//    printf("Press [enter] at the start of a line to stop.");
//    while(count < MAXBKS && s_get(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {
//        printf("Now enter a author.");
//        s_get(library[count].author, MAXAUTL);
//        printf("Now enter the value.");
//    }
//}
