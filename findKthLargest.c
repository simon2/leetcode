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
void heapify(int* data, int index, int size){
  int left = index * 2 + 1;
  int right = index * 2 + 2;
  int smallest;
  if(left < size && data[left] < data[index]){
    smallest = left;
  }else{
    smallest = index;
  }
  if(right < size && data[right] < data[smallest]){
    smallest = right;
  }
  if(smallest != index){
    int temp = data[index];
    data[index] = data[smallest];
    data[smallest] = temp;
    heapify(data, smallest, size);
  }
}

void build_heap(int* data, int size){
  int i;
  for(i=(size-1)/2;i>=0;i--){
    heapify(data,i,size);
  }
}

int findKthLargest(int* nums, int numsSize, int k){
    build_heap(nums,k);
    int i = k;
    while(i < numsSize){
        if(nums[i] > nums[0]){
            nums[0] = nums[i];
            heapify(nums,0,k);
        }
        i++;
    }
    return nums[0];
}
/********* end of heap solution ***********/

/********* best way using quick select **********/

/********* end of quick select solution ***********/