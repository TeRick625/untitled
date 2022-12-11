#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H

typedef struct matrix {
    int n, m;
    int** arr;
} Neo;

Neo* matrix(int n, int m);

void randomize(Neo* matrix, int start, int finish);

void output(Neo* matrix);

Neo* addition(Neo* matrix1, Neo* matrix2);

Neo* subtraction(Neo* matrix1, Neo* matrix2);

Neo* multiplication(Neo* matrix1, Neo* matrix2);

Neo* copy(Neo* duplicate);

Neo* transposition(Neo* revers);

void delete(Neo* matrix);

#endif //UNTITLED_MATRIX_H
