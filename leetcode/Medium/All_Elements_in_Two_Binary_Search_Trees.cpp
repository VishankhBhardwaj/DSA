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
    void helper(TreeNode*root,vector<int>&ans){
        if(!root) return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return {};
        vector<int>arr1;
        vector<int>arr2;
        helper(root1,arr1);
        helper(root2,arr2);
        int len1 = arr1.size();
        int len2 = arr2.size();
        int i=0;int j=0;
        vector<int>output;
        while(i<len1 && j<len2){
            if(arr1[i]<=arr2[j]) output.push_back(arr1[i++]);
            else output.push_back(arr2[j++]);
        }
        while(i<len1) output.push_back(arr1[i++]);
        while(j<len2) output.push_back(arr2[j++]);
        return output; 
    }
};