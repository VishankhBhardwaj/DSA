/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool ans=false;
    void check(TreeNode*root,ListNode*temp){
        if(temp==NULL){
            ans=true;
            return;
        }
        if(!root) return;
        if(root->val!=temp->val) return;
        check(root->left,temp->next);
        check(root->right,temp->next);
    }
    void helper(TreeNode*root,ListNode*head){
        if(!root || ans) return;
        if(root->val==head->val){
            ListNode*temp=head;
            check(root,temp);
        }
        helper(root->left,head);
        helper(root->right,head);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        helper(root,head);
        return ans;
    }
};