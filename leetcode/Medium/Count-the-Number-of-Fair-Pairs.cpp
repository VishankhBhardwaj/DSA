class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            long long cnt=0;
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++){
                int left=lower-nums[i];
                int right=upper-nums[i];
                int l = lower_bound(nums.begin() + i + 1, nums.end(), left)-nums.begin();
                int r = upper_bound(nums.begin() + i + 1, nums.end(), right)-nums.begin();
                cnt+=(r-l);
            }
            return cnt;
        }
    };