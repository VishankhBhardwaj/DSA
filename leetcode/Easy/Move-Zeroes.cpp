class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            vector<int>nums2;
            int c=0;
            for(auto i:nums){
                if(i==0){
                    c++;
                }
                else{nums2.push_back(i);}
            }
            nums.clear();
            nums=nums2;
            while(c){
                nums.push_back(0);
                c--;
            }
            
        }
    };