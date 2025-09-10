class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>>temp;
        int cnt=0;
        for(auto point:points){
            if(temp.empty() || !(point[0]>=temp.back()[0] && point[0]<=temp.back()[1]) ){
                temp.push_back(point);
                cnt++;
            }else if(point[0]>=temp.back()[0] && point[0]<=temp.back()[1]){
                temp.back()[1]=min(temp.back()[1],point[1]);
            } 
        }
        return cnt;
    }
};