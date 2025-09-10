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
    unordered_map<int,int>freq;
    int maxi = 0;
    void helper(TreeNode* root, vector<int>& ans) {
        if (!root)
            return;
        freq[root->val]++;               
        maxi = max(maxi, freq[root->val]);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    vector<int> findMode(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ans;
        helper(root, ans);
        for(auto&p:freq){
            if(p.second==maxi) ans.push_back(p.first);
        }
        return ans;
    }
};