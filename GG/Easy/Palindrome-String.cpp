//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string &s) {
        stack<char> st;
        string p = "";  // Corrected initialization

        // Push all characters onto the stack
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
        }

        // Pop characters and build the reversed string
        while (!st.empty()) {
            char val = st.top();
            st.pop();
            p.push_back(val); // Corrected appending
        }

        // Check if reversed string is equal to original
        return (p == s);
    }
};



//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        string s;
        cin >> s; // Read the string

        Solution ob; // Create an instance of Solution
        if (ob.isPalindrome(s)) {
            cout << "true"; // Print true if palindrome
        } else {
            cout << "false"; // Print false if not a palindrome
        }
        cout << "\n~\n"; // Print newline after each result
    }

    return 0;
}

// } Driver Code Ends