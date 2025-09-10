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
    bool isCompleteTree(TreeNode* root) {
        if (!root)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        bool nullfound = false;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (node == NULL)
                    nullfound = true;
                else {
                    if (nullfound)
                        return false;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return true;
    }
};