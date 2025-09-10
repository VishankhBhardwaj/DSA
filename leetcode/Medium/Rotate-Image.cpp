class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            vector<vector<int>>ans;
            vector<int>output;
            for(int j=0;j<matrix.size();j++){
                for(int i=matrix.size()-1;i>=0;i--){
                    output.push_back(matrix[i][j]);
                }
                ans.push_back(output);
                output.clear();
            }
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[i].size();j++){
                    matrix[i][j]=ans[i][j];
                }
            }
        }
    };