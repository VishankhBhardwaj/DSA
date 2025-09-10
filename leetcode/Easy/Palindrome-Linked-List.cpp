// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
//     private:
//     bool isPalindrome(vector<int>arr){
//         int n=arr.size();
//         int s=0;
//         int e=n-1;
//         while(s<=e){
//             if(arr[s]!=arr[e]){
//                 return 0;
//             }
//             s++;
//             e--;
//         }
//         return 1;
//     }
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> arr;
//         ListNode*temp=head;
//         while(temp!=NULL){
//             arr.push_back(temp->val);
//             temp=temp->next;
//         }
//         return isPalindrome(arr);
//     }
// };
//Another Approach
stack<int> st;
ListNode* temp = head;
while (temp) {
    st.push(temp->val);
    temp = temp->next;
}
temp = head;
while (temp) {
    if (temp->val != st.top()) return false;
    st.pop();
    temp = temp->next;
}
return true;



//O(1) space complexity code is as follows:-
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
        bool isPalindrome(ListNode* head) {
             if (!head || !head->next) return true;
    
            // Step 1: Find middle
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode*prev=NULL;
            ListNode*curr=slow->next;
            while (curr) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            ListNode*first=head;
            ListNode*second=prev;
            while(second){
                if(first->val!=second->val){
                    return false;
                }
                first=first->next;
                second=second->next;
            }
            return true;
        }
    };