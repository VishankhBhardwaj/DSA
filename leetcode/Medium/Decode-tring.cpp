class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans = "";
        for (auto ch : s) {
            if (ch == ']') {
                string temp = "";
                while (!st.empty() && st.top() != '[') {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string numStr="";
                while(!st.empty() && isdigit(st.top())){
                    numStr=st.top()+numStr;
                    st.pop();
                }
                int count = stoi(numStr);
                string repeated = "";
                for (int i = 0; i < count; i++) {
                    repeated += temp;
                }
                for (char ch : repeated) {
                    st.push(ch);
                }
            } else {
                st.push(ch);
            }
        }
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};