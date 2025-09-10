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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        ListNode*start=prev;
        ListNode*prevNode=NULL;
        ListNode* curr = prev->next;
        ListNode*subListHead=curr;
        ListNode* next = NULL;
        for (int i = 0; i <= right - left; i++) {
            next = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = next;
        }
        subListHead->next=next;
        start->next=prevNode;
        return dummy->next;
    }
};