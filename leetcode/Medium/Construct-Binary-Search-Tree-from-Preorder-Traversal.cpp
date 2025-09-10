/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* root = nullptr;  
        for (auto i : preorder) {
            if (st.empty()) {
                root = new TreeNode(i);
                st.push(root);
                continue;
            }
            TreeNode* top = st.top();
            if (top->val > i) {
                top->left = new TreeNode(i);
                st.push(top->left);
            }
            else {
                TreeNode* temp = nullptr;
                while (!st.empty() && i > st.top()->val) {
                    temp = st.top();
                    st.pop();
                }
                temp->right = new TreeNode(i);
                st.push(temp->right);
            }
        }
        return root;
    }
};