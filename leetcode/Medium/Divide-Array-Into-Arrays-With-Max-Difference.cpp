class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            v.push_back(nums[i]);
            cnt++;

            if (cnt == 3) {
                int val = v[2] - v[0];
                if (val > k)
                    return {};
                ans.push_back(v);
                v.clear();
                cnt = 0;
            }
        }

        return ans;
    }
};