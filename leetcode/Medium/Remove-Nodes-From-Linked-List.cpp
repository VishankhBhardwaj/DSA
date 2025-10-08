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
    void reverse(ListNode*&head){
        if(head==NULL || head->next==NULL) return;
        ListNode*prev=nullptr;
        ListNode*curr=head;
        ListNode*forward=nullptr;
        while(curr!=nullptr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        head=prev;
    }
    ListNode* removeNodes(ListNode* head) {
        int maxi=INT_MIN;
        reverse(head);
        ListNode*prev=nullptr;
        ListNode*curr=head;
        while(curr!=nullptr){
            if(curr==head){
                maxi=curr->val;
                prev=curr;
                curr=curr->next;
                continue;
            }
            else if(curr->val<maxi){
                prev->next=curr->next;
                curr=curr->next;
            }else if(curr->val>=maxi){
                maxi=curr->val;
                prev=curr;
                curr=curr->next;
            }
        }
        reverse(head);
        return head;
    }
};