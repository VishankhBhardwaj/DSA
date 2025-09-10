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
    priority_queue<long long,vector<long long>,greater<>>pq;
    void helper(TreeNode*root,queue<TreeNode*>&q,int k ){
        if(!root) return;
        while(!q.empty()){
            int n=q.size();
            long long temp=0;
            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                temp+=node->val;
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            pq.push(temp);
            while(pq.size()>k) pq.pop();
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        helper(root,q,k);
        return pq.size()>=k?pq.top():-1;
    }
};