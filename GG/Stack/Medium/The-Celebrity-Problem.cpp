class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> st;
        int n = mat.size();

        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Step 1: Find the potential celebrity
        while (st.size() >= 2) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if (mat[a][b] == 1) {
                // a knows b, so a can't be celebrity
                st.push(b);
            } else {
                // a doesn't know b, so b can't be celebrity
                st.push(a);
            }
        }

        if (st.empty()) return -1; // No one left

        int celeb = st.top();

        // Step 2: Validate the celebrity
        for (int i = 0; i < n; i++) {
            if (i != celeb && (mat[celeb][i] == 1 || mat[i][celeb] == 0)) {
                return -1;
            }
        }

        return celeb;
    }
};