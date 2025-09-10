class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        vector<vector<int>> ans;
        while (i < firstList.size() && j < secondList.size()) {
            vector<int> first = firstList[i];
            vector<int> second = secondList[j];
            if ((second[0] >= first[0] && second[0] <= first[1]) ||
                (first[0] >= second[0] && first[0] <= second[1])) {
                ans.push_back(
                {max(first[0], second[0]), min(first[1], second[1])});
            }
            if(first[1]<second[1]) i++;
            else{
                j++;
            }
        }
        return ans;
    }
};Minimum Number of Arrows to Burst Balloons