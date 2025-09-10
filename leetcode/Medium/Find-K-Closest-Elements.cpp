int global_x;
class Solution {
public:
    struct Compare {
        bool operator()(auto& a, auto& b) {
            if (abs(a - global_x) == abs(b - global_x))
                return a < b;
            return abs(a - global_x) < abs(b - global_x);
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        global_x = x;
        priority_queue<int, vector<int>, Compare> pq;
        for (auto num : arr) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};