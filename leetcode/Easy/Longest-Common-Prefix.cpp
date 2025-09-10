class Solution {
public:
    // Helper to count matching characters from the beginning
    int checkisequal(const string& str, stack<char> st) {
        int i = 0;
        int mino = 0;
        while (!st.empty() && i < str.size()) {
            if (str[i] == st.top()) {
                mino++;
                st.pop();
                i++;
            } else {
                break;
            }
        }
        return mino;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Initialize the stack with the first string (in reverse)
        stack<char> st;
        for (int i = strs[0].size() - 1; i >= 0; i--) {
            st.push(strs[0][i]);
        }

        int commonLength = strs[0].size();

        // Compare with the rest of the strings
        for (int i = 1; i < strs.size(); i++) {
            int len = checkisequal(strs[i], st);
            commonLength = min(commonLength, len); // Update common length
            // Rebuild stack with only `commonLength` characters from current string
            stack<char> temp;
            for (int j = commonLength - 1; j >= 0; j--) {
                 temp.push(strs[0][j]);
            }
            st = temp;
        }

        // Return substring from first string
        return strs[0].substr(0, commonLength);
    }
};
