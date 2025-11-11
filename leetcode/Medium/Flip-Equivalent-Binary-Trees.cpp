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
    bool ans = true;
    void dfs(TreeNode* root, unordered_map<int, pair<int, int>>& mpp,
             int parent) {
        if (!root)
            return;
        if (root->left && root->right)
            mpp[root->val] = {root->left->val, root->right->val};
        else if (root->left)
            mpp[root->val] = {root->left->val, -1};
        else if (root->right)
            mpp[root->val] = {-1, root->right->val};
        else
            mpp[root->val] = {-1, -1};
        dfs(root->left, mpp, root->val);
        dfs(root->right, mpp, root->val);
    }
    void check(TreeNode* root, unordered_map<int, pair<int, int>>& mpp) {
        if (!root)
            return;
        int leftVal = root->left ? root->left->val : -1;
        int rightVal = root->right ? root->right->val : -1;
        auto it = mpp.find(root->val);
        if (it == mpp.end()) {
            ans = false;
            return;
        }
        auto [a, b] = it->second;
        bool same = (a == leftVal && b == rightVal);
        bool flipped = (a == rightVal && b == leftVal);

        if (!same && !flipped) {
            ans = false;
            return;
        }
        check(root->left, mpp);
        check(root->right, mpp);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        unordered_map<int, pair<int, int>> mpp;
        dfs(root1, mpp, -1);
        check(root2, mpp);
        return ans;
    }
};