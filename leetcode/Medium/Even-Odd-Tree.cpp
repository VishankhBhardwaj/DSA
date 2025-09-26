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
    int cnt=0;
    bool ans=true;
    void helper(TreeNode*root,queue<TreeNode*>&q){
        if(!root) return;
        while(!q.empty()){
            int n=q.size();
            int temp = (cnt % 2 == 0) ? INT_MIN : INT_MAX;
            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                if(cnt%2==0){
                    if(node->val<=temp || node->val%2==0){
                        ans=false;
                        return;
                    }    
                }else{
                    if(node->val>=temp || node->val%2==1){
                        ans=false;
                        return;
                    }
                }
                temp = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            cnt++;
        }
    }
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return false;
        queue<TreeNode*>q;
        q.push(root);
        helper(root,q);
        return ans;
    }
};