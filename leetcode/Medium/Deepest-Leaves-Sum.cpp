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
    void helper(TreeNode*root,queue<TreeNode*>&q,int &ans){
        if(!root) return;
        while(!q.empty()){
            int n=q.size();
            ans=0;
            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                ans+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        helper(root,q,ans);
        return ans;
    }
};