class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int pre=0;
        int minPre=INT_MAX;
        for(auto num:nums){
            pre=pre+num;
            minPre=min(minPre,pre);
        }
        if(minPre>0) return 1;
        else return abs(minPre)+1;
    }
};