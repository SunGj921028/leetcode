#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **canvas;
    *returnSize = numRows;
    canvas = (int**)(malloc(numRows * sizeof(int*)));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i += 1) {
        (*returnColumnSizes)[i] = i + 1;
    }
    canvas = (int**)malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i += 1) {
        canvas[i] = (int*)malloc(numRows * sizeof(int));
        canvas[i][i] = 1;
        canvas[i][0] = 1;
    }
    for (int i = 0; i < numRows; i += 1) {
        for (int k = 1; k < i; k += 1) {
            canvas[i][k] = canvas[(i - 1)][(k - 1)] + canvas[(i - 1)][k];
        }
    }
    return canvas;
}

int main(){
    int numRows = 5;
    int returnSize = 0;
    int *returnColumnSizes;
    int **canvas = generate(numRows, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i += 1) {
        for (int k = 0; k < returnColumnSizes[i]; k += 1) {
            printf("%d ", canvas[i][k]);
        }
        printf("\n");
    }
    return 0;
}