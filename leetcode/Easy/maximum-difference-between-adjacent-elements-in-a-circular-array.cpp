class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int diff = 0;
            if (i == (nums.size() - 1)) {
                diff = abs(nums[i] - nums[0]);
            } else {
                diff = abs(nums[i] - nums[i + 1]);
            }
            maxDiff = max(maxDiff, diff);
        }
        return maxDiff;
    }
};