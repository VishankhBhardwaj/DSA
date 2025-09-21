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
// class Solution {
// public:
//     vector<int>temp;
//     bool isGreater(TreeNode*root){
//         if(!root) return false;
//         for(auto&num:temp){
//             if(num>root->val) return true;
//         }
//         return false;
//     }
//     void helper(TreeNode*root,int&ans){
//         if(!root) return;
//         temp.push_back(root->val);
//         if(!isGreater(root)){
//             ans++;
//         }
//         helper(root->left,ans);
//         helper(root->right,ans);
//         temp.pop_back();
//     }
//     int goodNodes(TreeNode* root) {
//         int ans=0;
//         helper(root,ans);
//         return ans;
//     }
// };

// for the above soln TC-O(n^2)
// SC-O(h)

// Optimised code :- TC-O(N) SC-O(h)
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
    void helper(TreeNode*root,int maxi,int&ans){
        if(!root) return;
        if(maxi<=root->val){
            ans++;
        }
        maxi = max(maxi, root->val);
        helper(root->left,maxi,ans);
        helper(root->right,maxi,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        helper(root,root->val,ans);
        return ans;
    }
};