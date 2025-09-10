//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int findPosition(vector<int> in,int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node* solve(vector<int> in,vector<int> post,int &index,int inorderStart,int inorderEnd,int n){
        if (index<0||inorderStart >inorderEnd){
            return NULL;
        }
        int element = post[index--];
        Node*root=new Node(element);
        int position=findPosition(in,element,n);
        
        //recursive calls
        root->right=solve(in,post,index,position+1,inorderEnd,n);
        root->left=solve(in,post,index,inorderStart,position-1,n);
       
        return root;
    }
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here
        int n=inorder.size();
        int postOrderIndex=n-1;
        
        Node*ans=solve(inorder,postorder,postOrderIndex,0,n-1,n);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends