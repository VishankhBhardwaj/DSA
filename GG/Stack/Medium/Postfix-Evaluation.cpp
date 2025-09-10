class Solution {
  public:
    int evaluate(vector<string>& arr) {
       stack<int> st;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] == "*") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b * a);
            } else if (arr[i] == "+") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b + a);
            } else if (arr[i] == "-") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b - a); // Order matters
            } else if (arr[i] == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b / a); // Order matters
            } else {
                st.push(stoi(arr[i]));
            }
        }

        return st.top();
    }
};