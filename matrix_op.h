#ifndef MATRIX_OP_H
#define MATRIX_OP_H
#define SIZE 3

void matrix_add(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]);
void matrix_subtract(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]);
void matrix_transpose(int A[SIZE][SIZE], int result[SIZE][SIZE]);

#endif
