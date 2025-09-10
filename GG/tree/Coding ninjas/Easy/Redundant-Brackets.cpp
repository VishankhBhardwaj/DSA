#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else if (ch == ')') {
            bool isRedundant = true;

            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;  // Found an operator, so not redundant
                }
                st.pop();
            }

            if (!st.empty()) st.pop(); // Pop the '(' bracket

            if (isRedundant) return true;
        }
    }

    return false;
}
