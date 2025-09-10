class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;
            int row=matrix.size();
            int col=matrix[0].size();
            int count=0;
            int total=row*col;
            //index initialise
            int startingrow=0;
            int startingcol=0;
            int endingrow=row-1;
            int endingcol=col-1;
            while(count<total){
                //printing starting row
                for(int i=startingcol; count<total && i<=endingcol;i++){
                    ans.push_back(matrix[startingrow][i]);
                    count++;
                }
                 startingrow++;
    
                //printing ending col
                for(int i=startingrow; count<total && i<=endingrow;i++){
                    ans.push_back(matrix[i][endingcol]);
                    count++;
                }
                endingcol--;
                //printing endingrow
                for(int i=endingcol; count<total && i>=startingcol;i--){
                    ans.push_back(matrix[endingrow][i]);
                    count++;
                }
                 endingrow--;
                //printing starting col
                for(int i=endingrow; count<total && i>=startingrow;i--){
                    ans.push_back(matrix[i][startingcol]);
                    count++;
                }
                 startingcol++;
            }
            return ans;
        }
    };