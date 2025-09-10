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
    void LevelOrdertraverse(TreeNode* root, map<int, int>& mpp,
                            queue<tuple<TreeNode*, int>>& q,vector<int>&ans) {
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [node, row] = q.front();
                q.pop();
                if (mpp.find(row) == mpp.end()) {
                    mpp[row] = node->val;
                }
                if(node->left!=NULL) q.push({node->left,row+1});
                if(node->right!=NULL) q.push({node->right,row+1});
            }
        }
        for(auto&[row,val]:mpp){
            ans.push_back(val);
        }
    }
    void rightTraverse(TreeNode* root, map<int, int>& mpp, int row) {
        if (root == NULL)
            return;
        if (mpp.find(row) == mpp.end()) {
            mpp[row] = root->val;
        }
        rightTraverse(root->right, mpp, row + 1);
        rightTraverse(root->left, mpp, row + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mpp;
        if (root == NULL)
            return {};
        int row = 0; 
        rightTraverse(root, mpp, row);
        queue<tuple<TreeNode*, int>> q;
        q.push({root, row});
        vector<int>ans;
        LevelOrdertraverse(root, mpp, q,ans);
        return ans;
    }
};