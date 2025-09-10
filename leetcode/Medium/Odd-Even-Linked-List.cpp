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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        int cnt = 2;
        ListNode* temp = head->next->next;
        ListNode* oddHead = new ListNode(head->val);
        ListNode* tempodd = oddHead;
        ListNode* evenHead = new ListNode(head->next->val);
        ListNode* tempeven = evenHead;
        while (temp != NULL) {
            if (cnt % 2 == 0) {
                tempodd->next = temp;
                tempodd = tempodd->next;
            } else {
                tempeven->next = temp;
                tempeven = tempeven->next;
            }
            temp = temp->next;
            cnt++;
        }
        tempodd->next = evenHead;
        tempeven->next = NULL;
        return oddHead;
    }
};