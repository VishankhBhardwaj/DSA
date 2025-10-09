class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int k = 0;
        int size = target.size();
        int cnt = 0;
        vector<string> ans;
        stack<string> st;
        for (int i = 1; i <= n; i++) {
            if (k == size)
                break;
            if (i == target[k]) {
                while (!st.empty() && cnt > 0) {
                    st.push("Pop");
                    cnt--;
                }
                k++;
            } else if (i != target[k])
                cnt++;
            st.push("Push");
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};