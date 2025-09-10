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
    void VerticalTraversal(TreeNode*root,queue<tuple<TreeNode*, int, int>> &q,vector<vector<int>>&ans){
        map<int,vector<pair<int,int>>>mpp;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto [node, col, row] = q.front();
                q.pop();
                mpp[col].push_back({row,node->val});
                if(node->left!=NULL){
                    q.push({node->left,col-1,row+1});
                }
                if(node->right!=NULL){
                    q.push({node->right,col+1,row+1});
                }
            }
        }
        for(auto&[col,vec]:mpp){
            vector<int>temp;
             sort(vec.begin(), vec.end());
            for(auto&[row,val]:vec){
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return {};
        queue<tuple<TreeNode*, int, int>> q;
        vector<vector<int>>ans;
        q.push({root,0,0});
        VerticalTraversal(root,q,ans);
        return ans;
    }
};