class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n=nums.size();
            int count1=0;
            int count2=0;
            int num1=INT_MIN;
            int num2=INT_MIN;
            for(int i=0;i<n;i++){
                if(count1==0 && num2!=nums[i]){
                    count1=1;
                    num1=nums[i];
                }
                else if(count2==0 && num1!=nums[i]){
                    count2=1;
                    num2=nums[i];
                }
                else if(nums[i]==num1){
                    count1++;
                }
                else if(nums[i]==num2){
                    count2++;
                }
                else{
                    count1--;
                    count2--;
                }
            }
            count1 = 0;
            count2 = 0;
            for (int num : nums) {
                if (num == num1) {
                    count1++;
                } else if (num == num2) {
                    count2++;
                }
            }
    
            vector<int> result;
            if (count1 > n / 3) result.push_back(num1);
            if (count2 > n / 3) result.push_back(num2);
    
            return result;
            
        }
    };