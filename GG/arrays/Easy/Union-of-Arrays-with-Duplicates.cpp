class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> s;
        for(auto i : a) s.insert(i);
        for(auto i : b) s.insert(i);

        vector<int> ans(s.begin(), s.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};