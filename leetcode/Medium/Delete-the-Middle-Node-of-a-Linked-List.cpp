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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode*fast = head;
        if(head==NULL || head->next==NULL) {
            return NULL;
        }
        else if(head->next->next==NULL){
            head->next=nullptr;
            return head;
        }
        while (fast != NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        while (slow != nullptr) {
            slow->val = slow->next->val;
            if (slow->next->next == NULL) {
                slow->next = nullptr;
            }
            slow = slow->next;
        }

        return head;
    }
};