#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

//Выделение памяти
Neo* matrix(int n, int m) {
    Neo* matrix = (Neo*)malloc(sizeof(Neo));
    matrix->n = n;
    matrix->m = m;
    int** arr = (int**)malloc(matrix->n * sizeof(int*));
    for (int i = 0; i < matrix->n; i++) {
        arr[i] = (int*)malloc(matrix->m * sizeof(int));
    }
    matrix->arr = arr;
    return matrix;
}

//Рандомное заполнение
void randomize(Neo* matrix, int start, int finish) {
    for (int i = 0; i < matrix->n; i++) {
        for (int j = 0; j < matrix->m; j++) {
            matrix->arr[i][j] = start + rand() % (finish - start + 1);
        }
    }
}

//Вывод матрицы
void output(Neo* matrix) {
    if (matrix == NULL) {
        printf("Вывод невозможен \n");
    } else {
        for (int i = 0; i < matrix->n; i++) {
            for (int j = 0; j < matrix->m; j++) {
                printf("| %d ", matrix->arr[i][j]);
            }
            puts("| \n");
        }
    }
}

//Сложение матриц
Neo* addition(Neo* matrix1, Neo* matrix2){
    if ((matrix1->n == matrix2->n) && (matrix1->m == matrix2->m)){
        Neo* matrixAdd = matrix(matrix1->n, matrix1->m);
        for (int i = 0; i < matrix1->n; i++){
            for (int j = 0; j < matrix1->m; j++){
                matrixAdd->arr[i][j] = matrix1->arr[i][j] + matrix2->arr[i][j];
            }
        }
        return matrixAdd;
    } else{
        return NULL;
    }
}

//Разность матриц
Neo* subtraction(Neo* matrix1, Neo* matrix2){
    if ((matrix1->n == matrix2->n) && (matrix1->m == matrix2->m)){
        Neo* matrixSub = matrix(matrix1->n, matrix1->m);
        for (int i = 0; i < matrix1->n; i++){
            for (int j = 0; j < matrix1->m; j++){
                matrixSub->arr[i][j] = matrix1->arr[i][j] - matrix2->arr[i][j];
            }
        }
        return matrixSub;
    } else{
        return NULL;
    }
}

//Умножение матриц
Neo* multiplication(Neo* matrix1, Neo* matrix2){
    if (matrix1->m == matrix2->n){
        Neo* matrixMulti = matrix(matrix1->n, matrix2->m);
        for (int i = 0; i < matrix1->n; i++){
            for (int j = 0; j < matrix2->m; j++){
                matrixMulti->arr[i][j] = 0;
                for (int g = 0; g < matrix1->m; g++){
                    matrixMulti->arr[i][j] += matrix1->arr[i][g] * matrix2->arr[g][j];
                }
            }
        }
        return matrixMulti;
    } else{
        return NULL;
    }
}

//Копирование матриц
Neo* copy(Neo* duplicate){
    Neo* matrixCopy = matrix(duplicate->n, duplicate->m);
    for (int i = 0; i < duplicate->n; i++){
        for (int j = 0; j < duplicate->m; j++){
            matrixCopy->arr[i][j] = duplicate->arr[i][j];
        }
    }
    return matrixCopy;
}

//Транспонирование матриц
Neo* transposition(Neo* revers){
    Neo* matrixTrans = matrix(revers->m, revers->n);
    for (int i = 0; i < revers->m; i++){
        for (int j = 0; j < revers->n; j++){
            matrixTrans->arr[i][j] = revers->arr[j][i];
        }
    }
    return matrixTrans;
}

//Очищение памяти
void delete(Neo* matrix){
    for (int i = 0; i < matrix->n; i++){
        free(matrix->arr[i]);
    }
    free(matrix->arr);
    free(matrix);
}
