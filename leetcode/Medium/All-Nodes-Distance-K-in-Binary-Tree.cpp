/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent_track,
                     TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if (current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track, target);
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        int curr_level = 0;
        while (!q.empty()) {
            int n = q.size();

            if (curr_level++ == k)
                break;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]]=true;
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};