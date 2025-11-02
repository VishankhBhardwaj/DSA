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
    int ans=0;
    void dfs(TreeNode*root,int grandParent,int Parent){
        if(root==NULL) return;
        if(grandParent%2==0) ans+=root->val;
        dfs(root->left,Parent,root->val);
        dfs(root->right,Parent,root->val);
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root,-1,-1);
        return ans;
    }
};