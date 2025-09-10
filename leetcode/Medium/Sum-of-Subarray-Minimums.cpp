class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       int n = arr.size();
        const int MOD = 1e9 + 7;
        using ll = long long;

        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;

        // Previous Less Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        // Clear stack
        st = stack<int>();

        // Next Less Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            ll count = static_cast<ll>(i - left[i]) * (right[i] - i) % MOD;
            sum = (sum + count * arr[i]) % MOD;
        }

        return sum;
    }
};