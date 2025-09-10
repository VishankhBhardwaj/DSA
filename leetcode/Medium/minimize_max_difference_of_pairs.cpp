class Solution {
public:
bool canSolve(vector<int>nums,int mid,int p){
    int cnt=0;
    for(int i=0;i<nums.size()-1;){
        if(abs(nums[i+1]-nums[i])<=mid){
            cnt++;
            i+=2;
        }
        else{
            i+=1;
        }
    }
    return cnt>=p;
}
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[nums.size() - 1] - nums[0];
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(canSolve(nums,mid,p)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};