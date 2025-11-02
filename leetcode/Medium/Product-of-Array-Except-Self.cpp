class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        int pre=1;
        for(int i=0;i<n;i++){
            int num=nums[i];
            prefix[i]=pre;
            pre=pre*num;
        }
        pre=1;
        for(int i=n-1;i>=0;i--){
            int num=nums[i];
            suffix[i]=pre;
            pre=pre*num;
        }
        for(int i=0;i<n;i++){
            nums[i]=prefix[i]*suffix[i];
        }
        return nums;
    }
};
//optimised approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Step 1️⃣: Store prefix products in ans
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Step 2️⃣: Multiply suffix products using a variable
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
