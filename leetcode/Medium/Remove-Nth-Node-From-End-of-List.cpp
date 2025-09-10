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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode*ptr=head->next;
            ListNode*preptr=head;
            ListNode*temp=head;
            int cnt=0,k=0;
            while(temp!=NULL){
                temp=temp->next;
                cnt++;
            }
            if(n==cnt){
                ListNode*dummy=head;
                head=head->next;
                delete dummy;
                return head;
            }
            else{
                while(k!=cnt-n-1){
                    ptr=ptr->next;
                    preptr=preptr->next;
                    k++;
                }
                preptr->next=ptr->next;
                delete ptr;
                return head;
            }
        }
    };