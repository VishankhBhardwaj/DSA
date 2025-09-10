class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto &row : grid) {
            sort(row.begin(), row.end());
        }
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            int maxi=0;
            for(int j=n-1;j>=0;j--){
                maxi=max(maxi,grid[i][j]);
            }
            ans+=maxi;
        }
        return ans;
    }
};