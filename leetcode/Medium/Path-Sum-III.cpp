/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    void helper(TreeNode* root, long long targetSum, int& count) {
        if (!root)
            return;
        if (targetSum == root->val) {
            count++;
        }
        long long remainingSum = targetSum - root->val;
        helper(root->left, remainingSum, count);
        helper(root->right, remainingSum, count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        helper(root, targetSum, count);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};