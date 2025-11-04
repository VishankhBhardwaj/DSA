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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*tail=list2;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        ListNode*ptr=list1;
        int cnt=0;
        while(cnt!=a-1){
            ptr=ptr->next;
            cnt++;
        }
        ListNode*temp=ptr;
        while(cnt!=b){
            temp=temp->next;
            cnt++;
        }
        tail->next=temp->next;
        ptr->next=list2;
        return list1;
    }
};