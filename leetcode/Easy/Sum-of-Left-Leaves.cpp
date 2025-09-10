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
int sum=0;
    void helper(TreeNode*root,int pos){
        if(!root) return;
        if(pos==1 && root->left==NULL && root->right==NULL) sum+=root->val;
        helper(root->left,1);
        helper(root->right,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        helper(root,0);
        return sum;
    }
};