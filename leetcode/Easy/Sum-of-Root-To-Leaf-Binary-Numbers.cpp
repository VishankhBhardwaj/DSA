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
    string s="";
    void helper(TreeNode*root,int&ans){
        if(!root) return;
        s+=to_string(root->val);
        helper(root->left,ans);
        helper(root->right,ans);
        if(!root->left && !root->right) ans+=stoi(s, nullptr, 2);
        s.pop_back(); 
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        helper(root,ans);
        return ans;
    }
};