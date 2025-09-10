class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int firstElement=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]-firstElement>k){
                cnt++;
                firstElement=nums[i];
            }
        }
        return ++cnt;
    }
};