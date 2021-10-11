#ifndef C_STACK_UTILS_H
#define C_STACK_UTILS_H

#include <stdbool.h>

void split_exp(char res[100][100], char *exp, int n);

bool is_number(char exp);

bool is_operator(char exp);

bool is_number_str(char *exp);

bool is_operator_str(char *exp);

#endif //C_STACK_UTILS_H
