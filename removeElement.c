int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    while(i < numsSize){
        if(nums[i] == val){
            int temp = nums[i];
            nums[i] = nums[numsSize-1];
            nums[numsSize-1] = temp;
            numsSize--;
        }else{
            i++;
        }
    }
    return numsSize;
}