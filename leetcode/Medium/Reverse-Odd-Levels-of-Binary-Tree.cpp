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
    int count = 1;
    void helper(TreeNode* root, queue<TreeNode*>&q) {
        if (!root)
            return;
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> temp;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (node->left!=nullptr && node->right!=nullptr && count % 2 == 1){
                    temp.push_back(node->left);
                    temp.push_back(node->right);
                }
                    
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (count % 2 == 1) {
                int i = 0;
                int j = temp.size() - 1;
                while (i <= j) {
                    swap(temp[i]->val, temp[j]->val);
                    i++;
                    j--;
                }
            }
            count++;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        helper(root, q);
        return root;
    }
};