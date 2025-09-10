class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int index=0;
        priority_queue<pair<int,int>>pq;
        for(auto vec:mat){
            int count=0;
            for(auto num:vec){
                if(num==1) count++;
            }
            pq.push({count,index++});
            while(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};