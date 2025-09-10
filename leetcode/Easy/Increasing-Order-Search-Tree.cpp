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
    void helper(TreeNode*root,stack<TreeNode*>&st){
        if(!root) return;
        helper(root->right,st);
        st.push(root);
        helper(root->left,st);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return nullptr;
        stack<TreeNode*>st;
        helper(root,st);
        TreeNode*parent=new TreeNode(-1);
        TreeNode*temp=parent;
        while(!st.empty()){
            auto node=st.top();
            st.pop();
            node->left=nullptr;
            temp->right=node;
            temp=temp->right;
        }
        temp->right=nullptr;
        return parent->right;
    }
};