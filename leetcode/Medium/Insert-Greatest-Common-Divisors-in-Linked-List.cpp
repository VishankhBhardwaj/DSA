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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr != NULL) {
            // int a=min(prev->val,curr->val);
            // for(;a>=0;a--){
            //     if(prev->val%a==0 && curr->val%a==0){
            //         break;
            //     }
            // }
            // for ki jge ye bhi kr skte better method
            // int gcd(int a, int b) {
            //     while (b != 0) {
            //         int temp = b;
            //         b = a % b;
            //         a = temp;
            //     }
            //     return a;
            // }
            // loop ki jge ye built in function bhi use kr skte gcd apne aap
            // nikalke dedega greatest common divisor
            int g = std::gcd(prev->val, curr->val);
            ListNode* new_node = new ListNode(g);
            new_node->next = curr;
            prev->next = new_node;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};