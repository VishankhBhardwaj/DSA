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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        if(head==NULL) return {};
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int startingRow=0;
        int startingCol=0;
        int endingRow=m-1;
        int endingCol=n-1;
        int cnt=0;
        int total=m*n;
        ListNode*temp=head;
        while(cnt<total && temp){
            for(int i=startingCol;temp && i<=endingCol;i++){
                ans[startingRow][i]=temp->val;
                temp=temp->next;
                cnt++;
            }
            startingRow++;
            for(int i=startingRow;temp && i<=endingRow;i++){
                ans[i][endingCol]=temp->val;
                temp=temp->next;
                cnt++;
            }
            endingCol--;
            for(int i=endingCol;temp && i>=startingCol;i--){
                ans[endingRow][i]=temp->val;
                temp=temp->next;
                cnt++;
            }
            endingRow--;
            for(int i=endingRow;temp && i>=startingRow;i--){
                ans[i][startingCol]=temp->val;
                temp=temp->next;
                cnt++;
            }
            startingCol++;
        }
        return ans;
    }
};