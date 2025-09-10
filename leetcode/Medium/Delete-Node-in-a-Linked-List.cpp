/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void deleteNode(ListNode* node) {
            ListNode* temp=node;
            ListNode* ptr=node->next;
            while(ptr->next!=NULL){
                temp->val=temp->next->val;
                temp=temp->next;
                ptr=ptr->next;
            }
            temp->val=temp->next->val;
            temp->next=NULL;
        }
    };