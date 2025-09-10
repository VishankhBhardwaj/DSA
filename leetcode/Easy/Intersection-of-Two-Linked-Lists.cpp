/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int cntA = 0;
        int cntB = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1 != NULL) {
            temp1 = temp1->next;
            cntA++;
        }
        while (temp2 != NULL) {
            temp2 = temp2->next;
            cntB++;
        }
        int diff = abs(cntA - cntB);
        if (cntB > cntA) {
            ListNode* temp3 = headB;
            for (int i = 0; i < diff; i++) {
                temp3 = temp3->next;
            }
            ListNode* temp4 = headA;
            while (temp4 != temp3) {
                temp4 = temp4->next;
                temp3 = temp3->next;
            }
            return temp4;
        } else if (cntA == cntB) {
            ListNode* temp4 = headA;
            ListNode* temp3 = headB;
            while (temp4 != temp3) {
                temp4 = temp4->next;
                temp3 = temp3->next;
            }
            return temp4;
        } else {
            ListNode* temp3 = headA;
            for (int i = 0; i < diff; i++) {
                temp3 = temp3->next;
            }
            ListNode* temp4 = headB;
            while (temp4 != temp3) {
                temp4 = temp4->next;
                temp3 = temp3->next;
            }
            return temp4;
        }
        return nullptr;
    }
};