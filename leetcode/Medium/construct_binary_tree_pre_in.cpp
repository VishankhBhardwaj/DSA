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
    TreeNode*buildTree(vector<int>&preorder,vector<int>&inorder,int preStart,int preEnd,int inStart,int inEnd,map<int,int>&Inorder_map){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode*root = new TreeNode(preorder[preStart]);
        int inRoot = Inorder_map[root->val];
        int numsLeft = inRoot-inStart;
        root->left = buildTree(preorder,inorder,preStart+1,preStart+numsLeft,inStart,inRoot-1,Inorder_map);
        root->right = buildTree(preorder,inorder,preStart+numsLeft+1,preEnd,inRoot+1,inEnd,Inorder_map);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>Inorder_map;
        for(int i=0;i<inorder.size();i++){
            Inorder_map[inorder[i]]=i;
        }
        TreeNode* tree = buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,Inorder_map);
        return tree;
    }
};