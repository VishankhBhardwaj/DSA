class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>map;
        vector<int>freq;
        for(auto i:word){
            map[i]++;
        }
        for(auto i:map){
            if(find(freq.begin(),freq.end(),i.second)==freq.end()){
                freq.push_back(i.second);
            }
        }
        int ans=INT_MAX;
        for(auto targetfreq:freq){
            int deletions=0;
            for(auto i:map){
                if(i.second>targetfreq+k){
                    deletions+=i.second-(targetfreq+k);
                }
                else if(i.second<targetfreq){
                    deletions+=i.second;
                }
            }
            ans=min(ans,deletions);
        }
        return ans;
    }
};