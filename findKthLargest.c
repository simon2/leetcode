/********* My naive solution by quicksort *********/
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

int findKthLargest(int* nums, int numsSize, int k){
    quickSort(nums, 0, numsSize-1);
    return nums[numsSize - k];
}
/********* end of my naive solution *******/

/********* better way using heap **********/

/********* end of heap solution ***********/

/********* best way using quick select **********/

/********* end of quick select solution ***********/