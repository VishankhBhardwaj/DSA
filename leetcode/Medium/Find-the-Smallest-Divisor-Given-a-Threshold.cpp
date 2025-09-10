class Solution {
public:
bool isSum(vector<int>nums,int mid,int threshold){
    int sum=0;
    for(auto i:nums){
        sum += (i + mid - 1) / mid;

    }
    return sum<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high = *std::max_element(nums.begin(), nums.end());

        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isSum(nums,mid,threshold)){
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