class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 2 * n - 1; i >= 0; i--) {
            int index = i % n;
            while (!st.empty() && nums[index] >= st.top()) {
                st.pop();
            }
            if (i < n) {
                if (!st.empty())
                    res[index] = st.top();
            }
            st.push(nums[index]);
        }
        return res;
    }
};