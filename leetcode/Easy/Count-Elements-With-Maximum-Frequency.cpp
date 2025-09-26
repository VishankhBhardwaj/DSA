class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto num:nums){
            mpp[num]++;
        }
        int maxFreq=0;
        for(auto&[num,freq]:mpp){
            maxFreq=max(maxFreq,freq);
        }
        int ans=0;
        for(auto&[num,freq]:mpp){
            if(freq==maxFreq) ans+=freq;
        }
        return ans;
    }
};