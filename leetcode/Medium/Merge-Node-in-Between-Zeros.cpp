class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* curr = head->next; // skip first zero
        int sum = 0;

        while (curr != nullptr) {
            if (curr->val == 0) {
                // reached end of a segment
                ListNode* new_node = new ListNode(sum);
                temp->next = new_node;
                temp = temp->next;
                sum = 0; // reset for next segment
            } else {
                sum += curr->val;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};
