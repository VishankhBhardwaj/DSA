//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    Node *moveToFront(Node *head) {
        Node*preptr=head;
        Node*ptr=head;
        ptr=ptr->next;
        while(ptr->next!=NULL){
            ptr=ptr->next;
            preptr=preptr->next;
        }
        preptr->next=NULL;
        ptr->next=head;
        head=ptr;
        return head;
    }
};
