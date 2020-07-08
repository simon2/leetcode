/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* divingBoard(int shorter, int longer, int k, int* returnSize){
    int diff = longer - shorter;
    int start = k * shorter;
    *returnSize = k + 1;
    int* result = (int*)malloc(sizeof(int)*(*returnSize));
    if(k == 0){
        *returnSize = 0;
        return result;
    }
    result;
    if(diff == 0){
        result[0] = start;
        *returnSize = 1;
        return result;
    }
    int i = 0;
    while(i<=k){
        result[i] = start + i * diff;
        i++;
    }
    return result;
}