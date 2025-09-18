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
    int maxi=0;
    void helper(Node*root,int cnt){
        if(!root) return;
        maxi=max(maxi,cnt);
        for(auto&child:root->children){
            helper(child,cnt+1);
        }
    }
    int maxDepth(Node* root) {
        if(!root) return 0;
        helper(root,1);
        return maxi;
    }
};