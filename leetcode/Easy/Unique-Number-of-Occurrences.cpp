class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(auto i:arr){
            mpp[i]++;
        }
        unordered_set<int>s;
        for(auto&[num,count]:mpp){
            if(s.count(count)) return false;
            s.insert(count);
        }
        return true;
    }
};