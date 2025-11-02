class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int num=0;
        for(int i=0;i<nums.size();i++){
            num=num+nums[i];
            ans.push_back(num);
        }
        return ans;
    }
};