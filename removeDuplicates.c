int removeDuplicates(int* nums, int numsSize){
    int slow = 0, fast = 1;
    int count = 1;
    if(numsSize == 0){
        return 0;
    }
    while(fast < numsSize){
        while(fast<numsSize && nums[slow] == nums[fast]){
            fast++;
        }
        if(fast >= numsSize){
            break;
        }
        nums[++slow] = nums[fast++];
        count++;
    }
    return count;
}