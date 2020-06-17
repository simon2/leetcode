/**** my first code using recursive **********/
/**** did not pass the test, but I believe there is a bug in leetcode 
that my code can pass the test which fail when submit.*/
double median(int* nums, int numsSize){
    double median;
    if(numsSize & 1){
        median = (double)nums[numsSize/2];
    }else{
        median = ((double)nums[numsSize/2] + (double)nums[(numsSize/2)-1])/2;
    }
    return median;
}

int cancelless = 0, cancelmore = 0;

double recursiveFindMedian(int* big, int start1, int end1, int* small, int start2, int end2){
    double result;
    int l1 = end1 - start1 + 1;
    int l2 = end2 - start2 + 1;
    if(l1==2 && l2==2 && cancelmore == cancelless){
        if(big[start1] <= small[start2]){
            start1++; cancelless++;
        }else{
            start2++; cancelless++;
        }
        if(big[end1] >= small[end2]){
            end1--; cancelmore++;
        }else{
            end2--; cancelmore++;
        }
    }
    if(big[start1] >= small[end2]){
        if(cancelless >= cancelmore){
            end1 = end1 - (cancelless - cancelmore);
        }else{
            start2 = start2 + (cancelmore - cancelless); 
        }
        int length1 = end1 - start1 + 1;
        int length2 = end2 - start2 + 1;
        if(length1 == length2){
            result = ((double)big[start1] + (double)small[end2]) / 2;
        }else if(length1 > length2){
            end1 = end1 - length2;
            result = median(&big[start1], end1-start1+1);
        }else{
            start2 = start2 + length1;
            result = median(&small[start2], end2-start2+1);
        }
    }else{
        double median1 = median(&big[start1],end1-start1+1);
        double median2 = median(&small[start2],end2-start2+1);
        if(median1 == median2){
            if(cancelmore == cancelless){
                result = median1;
            }else{
                if(cancelmore > cancelless){
                    if(big[start1] < small[start2]){
                        start1++;
                        cancelless++;
                    }else{
                        start2++;
                        cancelless++;
                    }
                }else{
                    if(big[end1] > small[end2]){
                        end1--;
                        cancelmore++;
                    }else{
                        end2--;
                        cancelmore++;
                    }
                }
                median1 = median(&big[start1],end1-start1+1);
                median2 = median(&small[start2],end2-start2+1);
                if(median1 >= median2){
                    result = recursiveFindMedian(big, start1, end1, small, start2, end2);
                }else{
                    result = recursiveFindMedian(small, start2, end2, big, start1, end1);
                }
            }
        }else if(median1 > median2){
            int length1 = end1 - start1 + 1;
            int length2 = end2 - start2 + 1;
            int remove1 = length1 & 1 ? length1/2 : length1/2-1;
            int remove2 = length2 & 1 ? length2/2 : length2/2-1;
            cancelmore += remove1;
            cancelless += remove2;
            result = recursiveFindMedian(big, start1, end1-remove1, small, start2+remove2, end2);
        }else{
            int length1 = end1 - start1 + 1;
            int length2 = end2 - start2 + 1;
            int remove1 = length1 & 1 ? length1/2 : length1/2-1;
            int remove2 = length2 & 1 ? length2/2 : length2/2-1;
            cancelless += remove1;
            cancelmore += remove2;
            result = recursiveFindMedian(small, start2, end2-remove2, big, start1+remove1, end1);
        }
    }
    return result;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int start1 = 0, start2 = 0, end1 = nums1Size - 1, end2 = nums2Size - 1;
    double median1, median2;
    if(nums1Size == 0){
        return median(nums2, nums2Size);
    }
    if(nums2Size == 0){
        return median(nums1, nums1Size);
    }
    median1 = median(nums1, nums1Size);
    median2 = median(nums2, nums2Size);
    double result;
    if(median1 == median2){
        result = median1;
    }else if(median1 > median2){
        result = recursiveFindMedian(nums1, 0, end1, nums2, 0, end2);
    }else{
        result = recursiveFindMedian(nums2, 0, end2, nums1, 0, end1);
    }
    return result;
}
/********my first code end.***/


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int length12 = nums1Size + nums2Size;
    int position = (length12 + 1) / 2 - 1;
    double result;
    if(nums1Size == 0){
        if(nums2Size & 1){
            return (double)nums2[nums2Size/2];
        }else{
            return ((double)nums2[nums2Size/2] + (double)nums2[nums2Size/2-1]) / 2;
        }
    }
    if(nums2Size == 0){
        if(nums1Size & 1){
            return (double)nums1[nums1Size/2];
        }else{
            return ((double)nums1[nums1Size/2] + (double)nums1[nums1Size/2-1]) / 2;
        }
    }
    int start1 = 0, start2 = 0;
    int temp = position;
    while(temp > 0){
        int p = temp / 2 - 1 ;
        int a1 = p<(nums1Size-1) ? p : nums1Size-1;
        int a2 = p<(nums2Size-1) ? p : nums2Size-1;
        a1 = a1<0 ? 0 : a1;
        a2 = a2<0 ? 0 : a2;
        if(start1 > (nums1Size - 1)){
            result = (double)nums2[start2+temp];
            start2 += temp;
            break;
        }
        if(start2 > (nums2Size - 1)){
            result = (double)nums1[start1+temp];
            start1 += temp;
            break;
        }
        if(nums1[start1+a1] <= nums2[start2+a2]){
            temp -= (a1 + 1);
            result = (double)nums1[start1 + a1];
            start1 += a1 + 1;
        }else{
            temp -= (a2 + 1);
            result = (double)nums2[start2 + a2];
            start2 += a2 + 1;
        }
    }
    if(start1 > nums1Size - 1){
        result = (double)nums2[start2++];
    }else if(start2 > nums2Size - 1){
        result = (double)nums1[start1++];
    }else{
        if(nums1[start1] <= nums2[start2]){
            result = (double)nums1[start1++];
        }else{
            result = (double)nums2[start2++];
        }
    }
    if(length12 & 1){
        return result;
    }else{
        if(start1 > nums1Size - 1){
            result = (result + nums2[start2]) / 2;
        }else if(start2 > nums2Size - 1){
            result = (result + nums1[start1]) / 2;
        }else{
            if(nums1[start1]<=nums2[start2]){
                result = (result + nums1[start1]) / 2;
            }else{
                result = (result + nums2[start2]) / 2;
            }
        }
        return result;
    }
}

