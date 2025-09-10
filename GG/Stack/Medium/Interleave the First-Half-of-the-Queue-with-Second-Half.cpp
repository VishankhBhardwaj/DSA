//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();
        stack<int> st;
        vector<int> v;

        // Step 1: Push first half of queue into stack
        for (int i = 0; i < n / 2; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Put stack elements back into queue (reversing first half)
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move first half of queue to the end (to restore order)
        for (int i = 0; i < n / 2; i++) {
            q.push(q.front());
            q.pop();
        }

        // Step 4: Push first half back into stack again
        for (int i = 0; i < n / 2; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 5: Interleave elements from stack and queue
        while (!st.empty()) {
            q.push(st.top());  // Push from stack
            st.pop();
            q.push(q.front()); // Push from queue
            q.pop();
        }

        // Step 6: Store final queue result in vector
        while (!q.empty()) {
            v.push_back(q.front());
            q.pop();
        }

        return v;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends