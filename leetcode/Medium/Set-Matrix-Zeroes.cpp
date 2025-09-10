class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
    
            vector<int> row(m, 0); // if there are m rows
            vector<int> col(n, 0); // if there are n columns
    
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[i].size();j++){
                    if(matrix[i][j]==0){
                        row[i]=1;
                        col[j]=1;
                    }
                }
            }
            for(int i=0;i<row.size();i++){
                if(row[i]==1){
                    for(int j=0;j<n;j++){
                        matrix[i][j]=0;
                    }
                }
            }
            for(int j=0;j<col.size();j++){
                if(col[j]==1){
                    for(int i=0;i<m;i++){
                        matrix[i][j]=0;
                    }
                }
            }
        }
    };