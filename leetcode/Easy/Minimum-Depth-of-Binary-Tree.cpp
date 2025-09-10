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
    int ans = INT_MAX;
    void helper(TreeNode* root, int count) {
        if (!root)
            return;
        if(!root->left && !root->right) ans = min(ans, count);
        helper(root->left, count + 1);
        helper(root->right, count + 1);
    }
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        helper(root, 1);
        return ans;
    }
};