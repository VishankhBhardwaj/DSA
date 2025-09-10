class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0, sum = 0;
        int count = 0;
        int n = nums.size();
        while (j < n) {
            if (nums[j] % 2 == 1)
                sum++;
            while (i < j && sum > k) {
                if (nums[i] % 2 == 1)
                    sum--;
                i++;
            }
            if (sum == k) {
                int temp = i;
                int prefixEven = 0;
                while (temp < j && nums[temp] % 2 == 0) {
                    prefixEven++;
                    temp++;
                }
                 count += (prefixEven + 1);
            }
            j++;
        }
        return count;
    }
};