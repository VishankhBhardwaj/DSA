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
    int dfs(TreeNode*root,unordered_map<int,int>&mpp){
        if(!root) return 0;
        int leftSum=dfs(root->left,mpp);
        int rightSum=dfs(root->right,mpp);
        int total=leftSum+rightSum+root->val;
        mpp[total]++;
        return total;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return {};
        unordered_map<int,int>mpp;
        dfs(root,mpp);
        vector<pair<int,int>>ans;
        for(auto [num,freq]:mpp){
            ans.push_back({freq,num});
        }
        sort(ans.rbegin(),ans.rend());
        int maxFreq=ans[0].first;
        vector<int>final;
        for(auto pair:ans){
            if(pair.first==maxFreq) final.push_back(pair.second);
        }
        return final;
    }
};