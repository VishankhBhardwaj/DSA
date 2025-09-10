class Solution {
public:
    bool check(vector<int>nums,int mid,int target){
        int sum=0;
        for(int i=0;i<mid;i++){
            sum+=nums[i];
            
        }
        if(sum>=target) return true;
        for(int i=mid;i<nums.size();++i){
            sum+=nums[i];
            sum-=nums[i-mid];
            if(sum>=target) return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        int high=nums.size();
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(nums,mid,target)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};