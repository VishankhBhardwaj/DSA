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
bool ans=false;
void helper(TreeNode*root,int x,int y,queue<TreeNode*>&q){
    if(!root) return;
    while(!q.empty()){
        int n=q.size();
        bool temp1=false;
        bool temp2=false;
        for(int i=0;i<n;i++){
            auto node = q.front();
            q.pop();
            if (node->left && node->right) {
                    if ((node->left->val == x && node->right->val == y) ||
                        (node->left->val == y && node->right->val == x)) {
                        return; 
                    }
                }
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
            if(node->val==x) temp1=true;
            else if(node->val==y) temp2=true;
        }
        if(temp1 && temp2){
            ans=true;
            return;
        }
    }
}
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        queue<TreeNode*>q;
        q.push(root);
        helper(root,x,y,q);
        return ans;
    }
};