class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int row=n;
        int col=n;
        int startingRow=0;
        int startingCol=0;
        int endingRow=n-1;
        int endingCol=n-1;
        int total=row*col;
        int cnt=1;
        while(cnt<=total){
            for(int i=startingCol;cnt<=total && i<=endingCol;i++){
                mat[startingRow][i]=cnt;
                cnt++;
            }
            startingRow++;
            for(int i=startingRow;cnt<=total && i<=endingRow;i++){
                mat[i][endingCol]=cnt;
                cnt++;
            }
            endingCol--;
            for(int i=endingCol;cnt<=total && i>=startingCol;i--){
                mat[endingRow][i]=cnt;
                cnt++;
            }
            endingRow--;
            for(int i=endingRow;cnt<=total && i>=startingRow;i--){
                mat[i][startingCol]=cnt;
                cnt++;
            }
            startingCol++;
        }
        return mat;
    }
};