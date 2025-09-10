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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || head->next==NULL) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode*p1=dummy;
        ListNode*p2=head;
        ListNode*p3=head->next;
        bool flag=false;
        while(p3!=NULL){
            if(p2->val==p3->val){
                flag=true;
                p3=p3->next;
            }else{
                if(flag){
                    p1->next=p3;
                    p2=p3;
                    p3=p3->next;
                    flag=false;
                    continue;
                }
                p1=p2;
                p2=p3;
                p3=p3->next;
            }
        }
        if(flag){
            p1->next=NULL;
        }
        return dummy->next;
    }
};