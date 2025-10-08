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
    void reverse(ListNode*& head) {
        if (head == NULL || head->next == NULL)
            return;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;
        while (curr != nullptr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        if (head == nullptr)
            return {};
        reverse(head);
        vector<int> ans;
        stack<int> st;
        ListNode* ptr = head;
        while (ptr != NULL) {
            while (!st.empty() && st.top() <= ptr->val) {
                st.pop();
            }
            if (st.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(st.top());  
            }
            st.push(ptr->val);
            ptr = ptr->next;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};