#include "matrix_op.h"
#include <stdio.h>
void matrix_add(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}
void matrix_substract(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}
void matrix_element_wise_multiply(float A[SIZE][SIZE], float B[SIZE][SIZE], float result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = A[i][j] * B[i][j];
        }
    }
}
void matrix_multiply(float A[SIZE][SIZE], float B[SIZE][SIZE], float result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void matrix_transpose(float A[SIZE][SIZE], float result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = A[i][j];
        }
    }
}
float matrix_determinant(float A[SIZE][SIZE]) {
    return A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
           A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
           A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
}
void matrix_adjoint(float A[SIZE][SIZE], float result[SIZE][SIZE]) {
    float temp[SIZE][SIZE];
    temp[0][0] =  (A[1][1] * A[2][2] - A[1][2] * A[2][1]);
    temp[0][1] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]);
    temp[0][2] =  (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    
    temp[1][0] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]);
    temp[1][1] =  (A[0][0] * A[2][2] - A[0][2] * A[2][0]);
    temp[1][2] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]);
    
    temp[2][0] =  (A[0][1] * A[1][2] - A[0][2] * A[1][1]);
    temp[2][1] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]);
    temp[2][2] =  (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
    
    matrix_transpose(temp, result);
}
int matrix_inverse(float A[SIZE][SIZE], float result[SIZE][SIZE]) {
    float det = matrix_determinant(A);
    if (det == 0) {
        printf("Error: Determinant is 0, inverse does not exist.\n");
        return 0; 
    }
    
    float adj[SIZE][SIZE];
    matrix_adjoint(A, adj);
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = adj[i][j] / det;
        }
    }
    return 1; 
}