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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        while (curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        if (head == NULL)
            return NULL;
        head = reverse(head);
        ListNode* temp = head;
        int carry = 0;
        while (temp != NULL) {
            int val = temp->val * 2 + carry;
            temp->val = val % 10;
            carry = val / 10;
            if (temp->next == NULL && carry) {
                temp->next = new ListNode(carry);
                carry = 0;
                break;
            }
            temp=temp->next;
        }
        head = reverse(head);
        return head;
    }
};
//Approach 2
class Solution {
public:
    int helper(ListNode* node) {
        if (!node) return 0;  // base case

        int carry = helper(node->next);  // process next first
        int val = node->val * 2 + carry;
        node->val = val % 10;
        return val / 10; // return carry to previous node
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = helper(head);

        // if carry remains after the most significant digit
        if (carry > 0) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            head = newHead;
        }

        return head;
    }
};
