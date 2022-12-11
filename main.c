#include <stdio.h>
#include <windows.h>
#include "Matrix.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int a1, b1;
    int a2, b2;
    int start1, finish1;
    int start2, finish2;

    printf("Кол-во строк матрицы 1: \n");
    scanf("%d", &a1);

    printf("Кол-во столбцов матрицы 1: \n");
    scanf("%d", &b1);

    printf("Введите начало диапазона 1: \n");
    scanf("%d", &start1);

    printf("Введите конец диапазона 1: \n");
    scanf("%d", &finish1);

    Neo* matrix1 = matrix(a1, b1);
    randomize(matrix1, start1, finish1);
    output(matrix1);

    printf("Кол-во строк матрицы 2: \n");
    scanf("%d", &a2);

    printf("Кол-во столбцов матрицы 2: \n");
    scanf("%d", &b2);

    printf("Введите начало диапазона 2: \n");
    scanf("%d", &start2);

    printf("Введите конец диапазона 2: \n");
    scanf("%d", &finish2);

    printf("Матрица 2:\n");

    Neo* matrix2 = matrix(a2, b2);
    randomize(matrix2, start2, finish2);
    output(matrix2);

    printf("Матрица 1 + Матрица 2:\n");
    output(addition(matrix1, matrix2));

    printf("Матрица 1 - Матрица 2:\n");
    output(subtraction(matrix1, matrix2));

    printf("Матрица 1 * Матрица 2:\n");
    output(multiplication(matrix1, matrix2));

    printf("Матрица 1 (копия):\n");
    output(copy(matrix1));

    printf("Матрица 2 (транспонирование):\n");
    output(transposition(matrix2));

    delete(matrix1);
    delete(matrix2);

    return 0;
}