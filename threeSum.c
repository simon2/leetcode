/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void quickSort(int* a, int left, int right){
    int i,j,pivot;
    if(left < right){
        pivot = left;
        i = left;
        j = right;
        while(i < j){
            while(a[i] <= a[pivot] && i < right){
	            i++;
            }
            while(a[j] > a[pivot] && j > left){
	            j--;
            }
            if(i < j){
	            int temp = a[i];
	            a[i] = a[j];
	            a[j] = temp;
            }
        }
        int temp = a[j];
        a[j] = a[pivot];
        a[pivot] = temp;
        quickSort(a,left,j-1);
        quickSort(a,j+1,right);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, j, k;
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
    for(i=0;i<numsSize*numsSize;i++){
        (*returnColumnSizes)[i] = 3;
    }
    int** result = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    quickSort(nums,0,numsSize-1);
    for(i=0;i<numsSize;i++){
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
        j = i + 1; k = numsSize - 1;
        while(j < k){
            if(nums[j]+nums[k] < -nums[i]){
                j++;
            }else if(nums[j]+nums[k] > -nums[i]){
                k--;
            }else{
                result[*returnSize] = (int*)malloc(sizeof(int)*3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[j];
                result[*returnSize][2] = nums[k];
                (*returnSize)++;
                j++; k--;
                while(j<k && nums[j]==nums[j-1]){
                    j++;
                }
                while(j<k && j<numsSize && nums[k]==nums[k+1]){
                    k--;
                }
            }
        }
    }
    return result;
}