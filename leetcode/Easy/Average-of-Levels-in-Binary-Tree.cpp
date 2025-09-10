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
    void helper(TreeNode*root,vector<double>&ans,queue<TreeNode*>q){
        if(!root) return;
        while(!q.empty()){
            int n=q.size();
            double temp=0;
            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                temp+=node->val;
            }
            ans.push_back(temp/n);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        helper(root,ans,q);
        return ans;
    }
};