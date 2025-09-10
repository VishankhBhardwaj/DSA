class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int left=0;
        int n=s.size();
        unordered_map<int,int>mpp;
        for(int right=0;right<n;right++){
            mpp[s[right]]++;
            while(mpp['a']>0 && mpp['b']>0 && mpp['c']>0){
                ans+=n-right;
                mpp[s[left]]--;
                left++;
            }
        }
        return ans;
    }
};