class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count=0;
        int i=0;
        while(i<nums.size()){
            int j=i+1;
            while(j<nums.size()){
                int k=j+1;
                while(k<nums.size()){
                    int l=k+1;
                    while(l<nums.size()){
                        if(nums[i]+nums[j]+nums[k]==nums[l]) count++;
                        l++;
                    }
                    k++;
                }
                j++;
            }
            i++;
        }
        return count;
    }
};