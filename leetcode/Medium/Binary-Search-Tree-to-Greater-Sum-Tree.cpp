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
    void traversal(TreeNode*root,stack<TreeNode*>&st){
        if(!root) return;
        traversal(root->left,st);
        st.push(root);
        traversal(root->right,st);
    }
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*>st;
        traversal(root,st);
        TreeNode*temp=new TreeNode(0);
        while(!st.empty()){
            auto node=st.top();
            st.pop();
            node->val+=temp->val;
            temp->val=node->val;
        }
        return root;
    }
};
/////ANOTHER APPROACH MORE OPTIMISED -
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
int sum=0;
    void reverseOrder(TreeNode*root){
        if(!root) return;
        reverseOrder(root->right);
        root->val+=sum;
        sum=root->val;
        reverseOrder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        reverseOrder(root);
        return root;
    }
};