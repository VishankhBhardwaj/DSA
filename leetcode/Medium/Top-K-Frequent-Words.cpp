class Solution {
public:
    struct cmp {
        bool operator()(const pair<string, int>& a,
                        const pair<string, int>& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        unordered_map<string, int> mpp;
        for (auto word : words) {
            mpp[word]++;
        }
        for (auto& [word, freq] : mpp) {
            pq.push({word, freq});
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};