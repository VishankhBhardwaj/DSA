/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void helper(Node*root,vector<vector<int>>&ans,queue<Node*>&q){
        if(!root) return;
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                temp.push_back(node->val);
                for(auto &ptr:node->children){
                    q.push(ptr);
                }
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        helper(root,ans,q);
        return ans;
    }
};