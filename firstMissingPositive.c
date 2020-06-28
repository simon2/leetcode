#include<math.h>

int firstMissingPositive(int* nums, int numsSize){
    int i; int count = 0;
    for(i=0;i<numsSize;i++){
        if(nums[i] == 1){
            break;
        }else{
            count++;
        }
    }
    if(count==numsSize){
        return 1;
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]<=0 || nums[i]>numsSize){
            nums[i] = 1;
        }
    }
    for(i=0;i<numsSize;i++){
        int temp = abs(nums[i])-1;
        nums[temp] = -abs(nums[temp]);
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]>0){
            break;
        }
    }
    return i+1;
}