class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            vector<int>neg;
            vector<int>pos;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>0){
                    pos.push_back(nums[i]);
                }
                else{
                    neg.push_back(nums[i]);
                }
            }
            int i=0;
            int j=0;
            int k=0;
            while(i<neg.size() && j<pos.size()){
                if(k%2==0){
                    nums[k++]=pos[j++];
                }
                else{
                    nums[k++]=neg[i++];
                }
            }
            while(i<neg.size()){
                nums[k++]=neg[i++];
            }
            while(j<pos.size()){
                nums[k++]=pos[j++];
            }
            return nums;
        }
    };