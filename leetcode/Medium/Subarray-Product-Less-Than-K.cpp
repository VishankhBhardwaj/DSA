class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int cnt=0;
        int prod=1;
        int i=0;
        for(int j=0;j<nums.size();j++){
            prod*=nums[j];
            while(prod>=k && i<=j){
                prod/=nums[i++];
            }
            cnt += j-i+1;
        }
        return cnt;
    }
};