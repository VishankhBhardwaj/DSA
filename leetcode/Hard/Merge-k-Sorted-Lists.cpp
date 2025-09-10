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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode*
    mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* tail = dummy;
        for (auto node : lists) {
           if(node!=NULL){
             minHeap.push(node);
           }
        }
        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();
            tail->next = top;
            tail = tail->next;
            if (top->next != NULL) {
                minHeap.push(top->next);
            }
        }
        return dummy->next;
    }
};