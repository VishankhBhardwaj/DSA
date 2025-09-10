class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newIntervalStart = newInterval[0];
        int newIntervalEnd = newInterval[1];
        int n = intervals.size();
        vector<vector<int>> ans;
        bool merged = false;

        for (int i = 0; i < n; i++) {
            if (newIntervalStart > intervals[i][1]) {
                ans.push_back(intervals[i]);
            }
            else if (!merged && newIntervalEnd < intervals[i][0]) {
                ans.push_back({newIntervalStart, newIntervalEnd});
                ans.push_back(intervals[i]);
                merged = true;
            }
            else if (!merged && !(newIntervalEnd < intervals[i][0] || newIntervalStart > intervals[i][1])) {
                newIntervalStart = min(newIntervalStart, intervals[i][0]);
                newIntervalEnd = max(newIntervalEnd, intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        if (!merged) {
            ans.push_back({newIntervalStart, newIntervalEnd});
        }

        return ans;
    }
};