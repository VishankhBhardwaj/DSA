class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini = INT_MAX;
        int temp=nums.size()-1;
        int l=0;
        while(temp>=0){
            if(nums[temp]>mini) l=temp;
            mini = min(mini,nums[temp]);
            temp--;
        }
        temp=0;
        int maxi=INT_MIN;
        int r=0;
        while(temp<nums.size()){
            if(nums[temp]<maxi) r =temp;
            maxi=max(maxi,nums[temp]);
            temp++;
        }
        if(l==0 && r==0) return l;
        return (r-l+1);
    }
};