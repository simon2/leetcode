int searchInsert(int* nums, int numsSize, int target){
    int start = 0;
    int end = numsSize - 1;
    int med = (start + end) / 2;
    int temp;
    while(start < end){
        if(nums[med] < target){
            start = med + 1;
        }else if(nums[med] > target){
            end = med - 1;
        }else{
            temp = med - 1;
            while(temp > 0 && nums[med] == nums[temp]){
                temp--;
            }
            break;
        }
        med = (start + end) / 2;
    }
    if(start >= end){
        if(nums[start] >= target){
            return start;
        }else{
            return start+1;
        }
    }else{
        return temp+1;
    }
}