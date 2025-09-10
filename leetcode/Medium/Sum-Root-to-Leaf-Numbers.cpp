/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string res="";
    void helper(TreeNode*root,int&ans){
        if(!root) return;
        res+=to_string(root->val);
        if(!root->left && !root->right){
            ans+=stoi(res);
            res.pop_back();
            return;
        }
        helper(root->left,ans);
        helper(root->right,ans);
        res.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        helper(root,ans);
        return ans;
    }
};