class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int>pq;
        vector<int>ans;
        for(auto query:queries){
            pq.push(abs(query[0]) + abs(query[1]));
            if(pq.size()<k){
                ans.push_back(-1);
                continue;
            }else if(pq.size()>k) pq.pop();
            ans.push_back(pq.top());
        }
        return ans;
    }
};