class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            int n = nums.size();
    
            for (int i = 0; i < n; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate i
                for (int j = i + 1; j < n; j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicate j
                    int s = j + 1;
                    int e = n - 1;
                    while (s < e) {
                        long long sum = (long long)nums[i] + nums[j] + nums[s] + nums[e];
                        if (sum == target) {
                            ans.push_back({nums[i], nums[j], nums[s], nums[e]});
                            s++;
                            e--;
                            while (s < e && nums[s] == nums[s - 1]) s++;  // Skip duplicate s
                            while (s < e && nums[e] == nums[e + 1]) e--;  // Skip duplicate e
                        } else if (sum < target) {
                            s++;
                        } else {
                            e--;
                        }
                    }
                }
            }
    
            return ans;
        }
    };
    