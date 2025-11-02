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
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode*curr=head;
        unordered_set<int>st(nums.begin(),nums.end());
        int cnt=0;
        while(curr!=NULL){
             if (st.count(curr->val) &&
                (curr->next == NULL || !st.count(curr->next->val))) {
                cnt++;
            }
            curr = curr->next;
        }
        return cnt;
    }
};