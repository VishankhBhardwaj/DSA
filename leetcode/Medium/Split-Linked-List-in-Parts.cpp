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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (!head) return vector<ListNode*>(k, nullptr);
        int n=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        int eachLen=n/k;
        int exc=n%k;
        temp=head;
        vector<ListNode*>ans;
        for(int i=0;i<exc && temp;i++){
            ListNode*ptr=temp;
            for(int i=0;i<eachLen && temp;i++){
                temp=temp->next;
            }
            ListNode*ptr2=temp;
            temp=temp->next;
            ptr2->next=NULL;
            ans.push_back(ptr);
        }
        k=k-exc;
        while(k>0 && temp){
            ListNode*ptr=temp;
            for(int i=0;i<eachLen-1;i++){
                temp=temp->next;
            }
            ListNode*ptr2=temp;
            temp=temp->next;
            ptr2->next=NULL;
            ans.push_back(ptr);
            k--;
        }
        while(k>0){
            ans.push_back(NULL);
            k--;
        }
        return ans;
    }
};