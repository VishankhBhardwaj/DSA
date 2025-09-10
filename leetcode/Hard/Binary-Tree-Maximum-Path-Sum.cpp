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
    int Sum(TreeNode* root, int& maxSum) {
        if (root == NULL)
            return 0;
        int leftSum = max(0,Sum(root->left, maxSum));
        int rightSum = max(0,Sum(root->right, maxSum));
        int currentSum = leftSum + rightSum + root->val;
        maxSum = max(maxSum, currentSum);
        return root->val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int maxSum = root->val;
        Sum(root, maxSum);
        return maxSum;
    }
};