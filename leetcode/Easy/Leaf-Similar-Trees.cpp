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
    void helper(TreeNode*root,vector<int>&temp){
        if(!root) return;
        if(root->left==NULL && root->right==NULL)
            temp.push_back(root->val);
        helper(root->left,temp);
        helper(root->right,temp);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2) return false;
        vector<int>temp1,temp2;
        helper(root1,temp1);
        helper(root2,temp2);
        return temp1==temp2;
    }
};