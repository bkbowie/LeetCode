typedef struct {
    int **sum;
    int row;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix *rval = malloc(sizeof(NumMatrix));
    rval->sum = malloc(sizeof(int*) * (matrixSize + 1));
    rval->row = matrixSize + 1;
    for(int i = 0; i < matrixSize + 1; i++) {
        rval->sum[i] = calloc(matrixColSize[0] + 1, sizeof(int));
    }

    //calculate
    for(int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            rval->sum[i+1][j+1] = rval->sum[i][j+1] + 
                                  rval->sum[i+1][j] - 
                                  rval->sum[i][j] +
                                  matrix[i][j];
        }
    }
    return rval;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    return obj->sum[row2+1][col2+1] -
           obj->sum[row2+1][col1] -
           obj->sum[row1][col2+1] +
           obj->sum[row1][col1];
}

void numMatrixFree(NumMatrix* obj) {
    for (int i = 0; i < obj->row; i++) {
        free(obj->sum[i]);
    }
    free(obj->sum);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/