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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode*temp=head;
        int cnt=1;
        while(temp->next!=NULL){
            temp=temp->next;
            cnt++;
        }
        temp->next=head;
        int diff=cnt - (k % cnt);
        while(diff){
            temp=temp->next;
            diff--;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};