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
    int ans = 0;
    int maxi=INT_MIN;
    void helper(TreeNode* root,queue<TreeNode*>q,int count) {
        if (!root)
            return;
        while (!q.empty()) {
            int n = q.size();
            int temp=0;
            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                temp+=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            if(temp>maxi){
                maxi=temp;
                ans=count;
            }
            count++;
        }
    }
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        helper(root,q,1);
        return ans;
    }
};