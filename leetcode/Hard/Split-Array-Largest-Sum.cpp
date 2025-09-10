class Solution {
public:
bool isPossible(vector<int>nums,int mid,int k){
    int count=1;
    int sum=0;
    for(auto i:nums){
        if(i>mid) return false;
        if((sum+i)<=mid){
            sum+=i;
        }
        else{
            count++;
            sum=i;
        }
    }
    return count<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};