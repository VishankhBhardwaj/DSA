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
    ListNode* swapPairs(ListNode* head) {
        if(!head || head->next==NULL) return head;
        ListNode*prev=nullptr;
        ListNode*curr=head;
        ListNode*forward=NULL;
        int k=2;
        while(k>0 && curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            k--;
        }
        head->next=swapPairs(forward);
        return prev;
    }
};