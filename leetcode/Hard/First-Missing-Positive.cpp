class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for (auto i : nums) {
            if (i > 0 && (ans.empty() || i != ans.back()))
                ans.push_back(i);
        }

        sort(ans.begin(), ans.end());
        if (ans.empty() || ans[0] != 1)
            return 1;

        int i = 0;
        while (i < ans.size() - 1) {
            if (ans[i + 1] - ans[i] != 1)
                return ans[i] + 1;
            i++;
        }
        return ans[i] + 1;
    }
};