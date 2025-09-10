class Solution {
public:
int atMostK(vector<int>& nums, int k) {
        int i = 0, ans = 0;
        unordered_map<int, int> mpp;

        for (int j = 0; j < nums.size(); j++) {
            mpp[nums[j]]++;

            while (mpp.size() > k) {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i++;
            }

            ans += j - i + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};