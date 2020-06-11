/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    *returnSize = TSize;
    int* R = (int*)malloc(sizeof(int) * TSize);
    int i;
    int* stack = (int*)malloc(sizeof(int) * TSize);
    int top = -1;
    for(i=0;i<TSize;i++){
        while(top > -1 && T[stack[top]]<T[i]){
            int a = stack[top--];
            R[a] = i - a;
        }
        stack[++top] = i;
    }
    while(top > -1){
        int a = stack[top--];
        R[a] = 0;
    }
    return R;
}