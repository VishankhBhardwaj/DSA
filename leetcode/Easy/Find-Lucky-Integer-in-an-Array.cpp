class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(auto i:arr){
            mpp[i]++;
        }
        int maxi=-1;
        for(auto&[key,value]:mpp){
            if(key==value){
                maxi=max(maxi,key);
            }
        }
        return maxi;
    }
};