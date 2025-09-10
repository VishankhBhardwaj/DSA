class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0 , j=0,sum=0,count=0;
        int n=nums.size();
        while(j<n){
            sum+=nums[j];
            while(i<j && sum>goal){
                sum-=nums[i];
                i++;
            }

            if(sum==goal){
                int temp=i;
                int zeroCount=0;
                while(temp<j && nums[temp]==0){
                    temp++;
                    zeroCount++;
                }
                count+=(zeroCount+1);
            }
            j++;
        }
        return count;
    }
};