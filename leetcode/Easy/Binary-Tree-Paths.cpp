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
    string temp = "";
    vector<int> res;
    void helper(TreeNode* root, vector<string>& ans) {
        if (!root)
            return;
        res.push_back(root->val);
        if (!root->left && !root->right) {
            for (auto r : res) {
                temp += to_string(r);
                temp += "->";
            }
            temp = temp.substr(0, temp.size() - 2);
            ans.push_back(temp);
            res.pop_back();
            temp.clear();
            return ; 
        }
        helper(root->left, ans);
        helper(root->right, ans);
        res.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)
            return {};
        vector<string> ans;
        helper(root, ans);
        return ans;
    }
};