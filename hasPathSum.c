/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum(struct TreeNode* root, int sum){
    if(root == NULL){
        return false;
    }
    if(root->left == NULL && root->right == NULL){
        if(sum == root->val){
            return true;
        }else{
            return false;
        }
    }
    bool left_result = false;
    bool right_result = false;
    if(root->left != NULL){
        left_result = hasPathSum(root->left, sum-root->val);
    }
    if(root->right != NULL){
        right_result = hasPathSum(root->right, sum-root->val);
    }
    return (left_result || right_result);
}