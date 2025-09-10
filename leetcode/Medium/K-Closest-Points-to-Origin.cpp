class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            int num1 = (a.first * a.first + a.second * a.second);
            int num2 = (b.first * b.first + b.second * b.second);
            return num1 < num2;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (auto point : points) {
            pq.push({point[0], point[1]});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto pair = pq.top();
            ans.push_back({pair.first, pair.second});
            pq.pop();
        }
        sort(ans.begin(),ans.end(),[](auto&a,auto&b){
            int num1 = sqrt(a[0] * a[0] + a[1] * a[1]);
            int num2 = sqrt(b[0] * b[0] + b[1] * b[1]);
            return num1 < num2;
        });
        return ans;
    }
};