class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        int spaceCount = 0;
        string rev;

        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == ' ') {
                if (spaceCount >= 1) continue;

                if (!st.empty()) {
                    spaceCount++;
                    while (!st.empty()) {
                        rev += st.top();
                        st.pop();
                    }
                    rev += ' ';
                }
            } else {
                spaceCount = 0;
                st.push(s[j]);
                if (j == 0) {
                    while (!st.empty()) {
                        rev += st.top();
                        st.pop();
                    }
                }
            }
        }

        // Remove trailing space if exists
        if (!rev.empty() && rev.back() == ' ')
            rev.pop_back();

        return rev;
    }
};