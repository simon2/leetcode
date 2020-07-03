/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createTreeNode(int* nums, int start, int end){
    if(start >= end){
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp -> val = nums[start];
        temp -> left = NULL;
        temp -> right = NULL;
        return temp;
    }
    int mid = (start + end) >> 1;
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp -> val = nums[mid];
    if(mid == start){
        temp -> left = NULL;
    }else{
        temp -> left = createTreeNode(nums, start, mid - 1);
    }

    temp -> right = createTreeNode(nums, mid + 1, end);
    return temp;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize == 0){
        return NULL;
    }
    return createTreeNode(nums, 0, numsSize-1);
}