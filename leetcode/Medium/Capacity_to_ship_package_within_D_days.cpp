class Solution {
public:
bool isShipped(vector<int>nums,int mid,int days){
    int count=1;
    int sum=0;
    for(auto i :nums){
        if(sum+i>mid){
            count++;
            sum=0;
        }
        sum+=i;
    }
    return count<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int ans=-1;
        int high=accumulate(weights.begin(),weights.end(),0);
        for(auto i:weights){
            low=max(low,i);
        }
        while(low<=high){
            int mid=(low+high)/2;
            
            if(isShipped(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return  ans;
    }
};