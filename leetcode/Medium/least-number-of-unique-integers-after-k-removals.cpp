class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        unordered_map<int, int> mpp;
        for (auto num : arr) {
            mpp[num]++;
        }
        for (auto& [num, freq] : mpp) {
            pq.push({freq, num});
        }
        while (k > 0) {
            auto pair = pq.top();
            if (pair.first > k) {
                break;
            } else {
                k = k - pair.first;
                pq.pop();
            }
        }
        return pq.size();
    }
};