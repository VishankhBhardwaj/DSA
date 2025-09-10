class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int cnt=0;
        unordered_map<int,int>freq;
        for(int j=0;j<nums.size();j++){
            freq[nums[j]]++;
        }
        if(freq.size()==1) return 0;
        for(auto& [key, val] : freq){
            if(freq.count(key+1)){
                cnt=max(cnt,val+freq[key+1]);
            }
        }
        return cnt;
    }
};