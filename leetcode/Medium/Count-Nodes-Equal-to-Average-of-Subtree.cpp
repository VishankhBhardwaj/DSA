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
    int bfs(TreeNode* root) {
        if (!root)
            return -1;
        int size=0;
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            size+=n;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                sum+=node->val;
            }
        }
        return sum/size;
    }
    void dfs(TreeNode*root,int &ans){
        if(!root) return;
        int temp=bfs(root);
        if(root->val==temp) ans++;
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    int averageOfSubtree(TreeNode* root) {  
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};
///OPTIMISED
class Solution {
public:
    int ans = 0;

    // Returns a pair of (sum, count) for the subtree rooted at 'node'
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);

        int currSum = leftSum + rightSum + node->val;
        int currCount = leftCount + rightCount + 1;

        if (node->val == currSum / currCount) {
            ans++;
        }

        return {currSum, currCount};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
