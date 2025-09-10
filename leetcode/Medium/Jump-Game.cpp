class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int lastReachable=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=lastReachable){
                lastReachable=i;
            }
        }
        return lastReachable == 0;
    }
};