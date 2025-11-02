class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        for (auto num : arr) {
            mpp[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto ele : mpp) {
            pq.push({ele.second, ele.first});
        }
        int cnt = 0;
        while (n > arr.size() / 2) {
            auto p = pq.top();
            pq.pop();
            n -= p.first;
            cnt++;
        }
        return cnt;
    }
};