class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>ans;
        priority_queue<int>pq;
        for (auto s : score) pq.push(s);
        int k=1;
        unordered_map<int,string>mpp;
        while(!pq.empty()){
            int num=pq.top();
            pq.pop();
            if(k==3){
                mpp[num]="Bronze Medal";
            }else if(k==2){
                mpp[num]="Silver Medal";
            }else if(k==1) mpp[num]="Gold Medal";
            else mpp[num]=to_string(k);
            k++;
        }
        for (int s : score) {
            ans.push_back(mpp[s]);
        }
        return ans;
    }
};