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
    void dfs(TreeNode*root,vector<TreeNode*>&arr){
        if(!root) return;
        dfs(root->left,arr);
        arr.push_back(root);
        dfs(root->right,arr);
    }
    TreeNode* sortedArrayToBst(int start,int end,vector<TreeNode*>&arr){
        if(start>end) return NULL;
        int mid = (start+end)/2;
        TreeNode*root = arr[mid];
        root->left = sortedArrayToBst(start,mid-1,arr);
        root->right = sortedArrayToBst(mid+1,end,arr);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return root;
        vector<TreeNode*>arr;
        dfs(root,arr);
        return sortedArrayToBst(0,arr.size()-1,arr);
    }
};