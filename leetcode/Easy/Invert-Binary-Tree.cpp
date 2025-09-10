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
    void helper(TreeNode* root, queue<TreeNode*> &q) {
        if (!root)
            return;
        while (!q.empty()) {
            int n = q.size();
            TreeNode* temp = nullptr;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
                temp = node->left;
                node->left = node->right;
                node->right = temp;
            }
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        helper(root, q);
        return root;
    }
};