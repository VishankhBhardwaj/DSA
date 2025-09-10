class Solution {
public:
    bool can_we_make(vector<int> nums, int mid, int m, int k) {
        int count = 0;
        int noBoq = 0;
        for (auto i : nums) {
            if(i<=mid){
                count++;
                if(count==k){
                    noBoq++;
                    count=0;
                }
            }
            else{
                count=0;
            }
        }
        return noBoq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total_numbers = 1LL * m * k;
        int ans = -1;
        if (total_numbers > bloomDay.size()) {
            return -1;
        } else {
            int low = 0;
            int high = *max_element(bloomDay.begin(), bloomDay.end());
            while (low <= high) {
                int mid =(low + high) / 2;
                if (can_we_make(bloomDay, mid, m, k)) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return ans;
    }
};