typedef struct {
    int* arr;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    int i;
    if (NULL == nums || numsSize < 0)
        return NULL;

    NumArray *obj = (NumArray*)malloc(sizeof(NumArray));
    if (NULL == obj) {
        return NULL;
    }

    obj->arr = (int*)malloc(sizeof(int) * (numsSize + 1));
    if (NULL == obj->arr) {
        free(obj);
        return NULL;
    }

    obj->arr[0] = 0;

    for (i = 1; i < numsSize + 1; i++) {
        obj->arr[i] = obj->arr[i-1] + nums[i-1];
    }

    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    if (NULL == obj)    return 0;
    return obj->arr[right + 1] - obj->arr[left];
}

void numArrayFree(NumArray* obj) {
    if (NULL == obj)    return ;

    if (obj) {
        if (obj->arr) {
            free(obj->arr);
        }
        free(obj);
    }

    return ;
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/