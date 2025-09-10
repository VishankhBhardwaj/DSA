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
    vector<int> temp;
    void findPath(TreeNode* root, int targetSum, vector<vector<int>>& ans) {
        if (!root)
            return;
        if (!root->right && !root->left) {
            if (root->val == targetSum) {
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
        } else {
            int remainingSum = targetSum - root->val;
            temp.push_back(root->val);
            findPath(root->left, remainingSum, ans);
            findPath(root->right, remainingSum, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return {};
        vector<vector<int>> ans;
        findPath(root, targetSum, ans);
        return ans;
    }
};