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
    int ans = INT_MIN;
    void dfs(TreeNode* root, int mini, int maxi) {
        if (!root)
            return;
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        ans = max(ans, abs(root->val - mini));
        ans = max(ans, abs(root->val - maxi));
        dfs(root->left, mini,maxi);
        dfs(root->right,mini,maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root, root->val,root->val);
        return ans;
    }
};