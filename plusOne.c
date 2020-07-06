/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int)*(digitsSize+1));
    int i = digitsSize - 1;
    int carry = 1;
    while(i >= 0){
        int r = digits[i] + carry;
        if(r > 9){
            r = r - 10;
            carry = 1;
        }else{
            carry = 0;
        }
        result[i+1] = r;
        i--;
    }
    if(carry == 1){
        result[0] = 1;
        *returnSize = digitsSize + 1;
    }else{
        result = &result[1];
        *returnSize = digitsSize;
    }
    return result;
}