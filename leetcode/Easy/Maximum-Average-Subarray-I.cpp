class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        int cnt=0;
        double sum=0;
        int i=0,j=0;
        while(j<nums.size()){
            sum+=nums[j];
            cnt++;
            while(cnt>k){
                sum-=nums[i];
                cnt--;
                i++;
            }
            if(cnt==k){
                ans=max(ans,(sum/k));
            }
            j++;
        }
        return ans;
    }
};