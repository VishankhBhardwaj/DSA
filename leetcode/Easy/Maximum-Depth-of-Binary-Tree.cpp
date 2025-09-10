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
void depth(TreeNode*root,int d,int &maxDepth){
    if(root==NULL) return ;
    maxDepth=max(maxDepth,d);
    depth(root->left,d+1,maxDepth);
    depth(root->right,d+1,maxDepth);
    
}
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int maxDepth=1;
        depth(root,1,maxDepth);
        return maxDepth;
    }
};