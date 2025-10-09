#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// --------------------------------------------------
// ✅ Approach 1: Reverse Second Half In-Place
// Time: O(n), Space: O(1)
// --------------------------------------------------

class SolutionApproach1 {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;
        while (curr != nullptr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Find the middle of the list
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reverse the second half from the middle
        ListNode* second = reverse(slow);
        ListNode* first = head;

        int ans = INT_MIN;

        // Compare twin pairs
        while (second != nullptr) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};

// --------------------------------------------------
// ✅ Approach 2: Using Stack
// Time: O(n), Space: O(n)
// --------------------------------------------------

class SolutionApproach2 {
public:
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Find the middle
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Push second half values into stack
        stack<int> st;
        while (slow != nullptr) {
            st.push(slow->val);
            slow = slow->next;
        }

        // Compare values from stack and first half
        ListNode* ptr = head;
        int ans = INT_MIN;
        while (!st.empty()) {
            ans = max(ans, ptr->val + st.top());
            st.pop();
            ptr
