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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr != NULL) {
            if (prev->val <= curr->val) {
                prev = curr;
                curr = curr->next;
            } else {
                prev->next = curr->next;
                curr->next = NULL;
                ListNode* temp = dummy;
                while (temp->next != nullptr && temp->next->val < curr->val) {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
                curr = prev->next;
            }
        }
        return dummy->next;
    }
};