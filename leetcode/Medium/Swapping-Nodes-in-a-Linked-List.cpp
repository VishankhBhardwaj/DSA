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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || head->next==nullptr) return head;
        int l=0;
        ListNode*temp=head;
        while(temp){
            temp=temp->next;
            l++;
        }
        ListNode*first=head;
        for(int i=1;i<k;i++){
            first=first->next;
        }
        ListNode*second=head;
        for(int i=1;i<l-k+1;i++){
            second=second->next;
        }
        swap(first->val,second->val);
        return head;
    }
};