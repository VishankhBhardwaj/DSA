class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char, int> mpp;
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]] = i;
        }
        unordered_map<char, bool> visited;
        for (int i = 0; i < s.size(); i++) {
            if (visited[s[i]])
                continue;
            while (!st.empty() && st.top() > s[i] && mpp[st.top()] > i){
                visited[st.top()]=false;
                st.pop();
            }
            
            st.push(s[i]);
            visited[s[i]] = true;
        }
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};