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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == NULL)
            return NULL;
        if(depth==1){
            TreeNode*node1=new TreeNode(val);
            node1->left=root;
            return node1;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [node, curr_depth] = q.front();
                q.pop();
                if(curr_depth==depth-1){
                    TreeNode*ptr1=node->left;
                    TreeNode*ptr2=node->right;
                    TreeNode*node1=new TreeNode(val);
                    TreeNode*node2=new TreeNode(val);
                    node->left=node1;
                    node->right=node2;
                    node1->left=ptr1;
                    node2->right=ptr2;
                }else{
                    if(node->left!=NULL) q.push({node->left,curr_depth+1});
                    if(node->right!=NULL)q.push({node->right,curr_depth+1});
                }
            }
        }
        return root;
    }
};