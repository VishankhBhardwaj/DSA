class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (n == 2) {
            if (nums[0] > nums[1]) {
                return 0;
            } else {
                return 1;
            }
        }
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid == 0 && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (mid == high && nums[mid] > nums[mid - 1]) {
                return mid;
            }
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            } else if (nums[mid + 1] > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};